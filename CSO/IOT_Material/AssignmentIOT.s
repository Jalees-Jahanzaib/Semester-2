_asm int my_sqrt(int x){
    
    
    PUSH {R4-R7} ;
    LDR R1, =0      ;done = 0
    LDR R7, =0 ;a=0
    LDR R2, =0xFFFF ;b=2^31 -1
    LDR R3, =0xFFFFFFFF ;c=-1
DO_WHILE
    MOV  R4, R3    ;c_old = c HERE R4 is being considered as c_old
    ADDS R5, R2, R7 ;R5 = a+b
    ASRS R5, R5, #1 ;R5 >> 1 which is nothing but (a+b/2) 
    MOV  R3, R5 ;c = (a+b)/2
    MOV  R6,R3
    MULS R6, R3, R6       ;R6 = c*c
    CMP  R6,R0 ;compare c*c and x (input integer)
    BEQ  DONE
    BLT LESS_THAN
    MOV  R2, R3 ;setting b=cb
    B FINAL
 
LESS_THAN
    MOV R7,R3 ;setting a=c
    B FINAL
 
 
DONE
    LDR R1, =1 ;setting done = 1
    B FINAL ;return C
 
 
FINAL
    CMP R1, #1 ;compare done = 1
    BEQ END
    BNE COMPARE
 
 
COMPARE
    CMP R4, R3 ;compare c_old and c
    BNE DO_WHILE
    BEQ END
 
 
END
    MOV R0, R3
    POP {R4-R7}
    BX LR