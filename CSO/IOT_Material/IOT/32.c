#include "platform.h"
#include "delay.h"
#include <gpio.h>
#include "leds.h"
#include <stdlib.h>
#include <stdio.h>

volatile unsigned int k=0;
static unsigned int counter=0;
void isr(){
	k = 1;
	gpio_set(P_SPEAKER, 0);
}

void lcd_init(void) {
	// Set all LCD pins as outputs
	gpio_set_mode(P_LCD_RS, Output);
	gpio_set_mode(P_LCD_RW, Output);
	gpio_set_mode(P_LCD_E, Output);
	set_data_dir(Output);
	// Have to wait 100ms or more after Power on
	delay_ms(100);
	
	// Run LCD initialisation sequence
	
	// Set the device to change mode from 8-bit to 4-bit
	lcd_write_cmd(0x30);	
	delay_ms(5);
	lcd_write_cmd(0x30);	
	delay_us(100);
	lcd_write_cmd(0x30);	
	delay_us(100);
	lcd_write_cmd(0x20);
	delay_us(100);
	
	// The device is in 8-bit mode when powered up
	// At this point it switches to 4-bit mode
	
	// Configure operating mode (number of rows/lines)
	lcd_write_cmd(0x28);
	delay_us(60);
	// Set display off, under-line off and block cursor off
	lcd_write_cmd(0x08);
	delay_us(60);
	// Clear display
	lcd_write_cmd(0x01);
	delay_ms(4);
	// Set the direction of address counter to increment
	// and no display shift on data read/write
	lcd_write_cmd(0x06);
	delay_us(60);
	// Set display on, under-line off and block cursor off
	lcd_write_cmd(0x0C);
	delay_us(60);
	
	lcd_set_cursor(0,0);
	lcd_set_cursor_visible(0);
}

void lcd_set_cursor_visible(int visible) {
	lcd_write_cmd(0x0C | ((!!visible) << 1));
}

void lcd_write_4bit(uint8_t c) {
	int i = 0;
	gpio_set(P_LCD_RW, 0);
	gpio_set(P_LCD_E, 1);
	
	for(i=0; i<4; i++) {
		gpio_set(P_LCD_DATA[i], (c & (0x1<<i))>>i);
	}
	
	delay_us(1);
	gpio_set(P_LCD_E, 0);
	delay_us(1);
}

static void lcd_write_data(uint8_t c) {
	wait_while_busy();

	gpio_set(P_LCD_RS, 1);
	lcd_write_4bit((c>>4) & 0x0F);
	lcd_write_4bit(c & 0x0F);
}

int main(){
	leds_init();
	gpio_set_mode(P_SPEAKER, Output);
	gpio_set_mode(P_SW, PullDown);
	gpio_set_trigger(P_SW, Falling);
	gpio_set_callback(P_SW, isr);
	int time = -1;
	while(time >= -1)
	{
		time=-1;
		gpio_set(P_SPEAKER, 0);
		delay_ms(rand()%2000 + 1000);
		if(time<0) 
			gpio_set(P_SPEAKER, 1);
		k=0;
		while(k==0){
			delay_ms(1000);
			time++;
		}
		k = 0;
		gpio_set(P_SPEAKER, 0);
		delay_ms(500);
	}
}