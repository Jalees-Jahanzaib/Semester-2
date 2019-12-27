.data
N: 
 .byte 10
.text
sum:
   .long   
.global main

main:
    movl $1 , %eax              #  bb=1 
    movl $1 , %ecx              # c=1
    movl $0 , %edx              # a=0
    movl  $0 , %esi       # temp
mov   N@GOTPCREL(%rip), %rbx
movzbl (%rbx) ,  %ebx        # ebi has N
  
.loop_start:
cmpl $2, %ebx   
jl .loop_end  
addl %edx , %esi    # Ad a to temp 
addl %eax , %esi
movl %esi , %ecx
movl %eax , %edx 
movl %ecx ,%eax
dec %ebx 
jmp .loop_start 
.loop_end:
 mov sum@GOTPCREL(%rip), %rbx # reuse register %rbx
mov %eax, (%rbx)
ret

    
