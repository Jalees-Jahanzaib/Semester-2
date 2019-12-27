#include <platform.h>
#include <gpio.h>
#include "delay.h"
void GPIO_init() {
	gpio_set_mode(P_SPEAKER, Output);
	gpio_set_mode(P_SW, PullDown);
}
void play_tone(unsigned int, _Bool*);
void update_buttons(_Bool *state){
	if(!(gpio_get(P_SW))){
		return ;
	}
	delay_ms(500);
	play_tone(9000, state);	
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

void lcd_write_cmd(uint8_t c) {
	wait_while_busy();

	gpio_set(P_LCD_RS, 0);
	lcd_write_4bit(c>>4);
	lcd_write_4bit(c);
}
void play_tone(unsigned int dur, _Bool* state){
	if(!(*state)){
		unsigned int period=800;
		unsigned int count=(dur * 2000)/(period);
		*state=1;
		while(count--){
			gpio_toggle(P_SPEAKER);
			delay_us(period/2);
			update_buttons(state);
		}
	}
	else {
		gpio_set(P_SPEAKER, 0);
		*state=0;
		delay_ms(1000);
	}
}
int main(){
	_Bool state = 0;
	GPIO_init();
	while(1){
		update_buttons(&state);
	}
}