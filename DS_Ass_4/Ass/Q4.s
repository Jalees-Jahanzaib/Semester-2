/* Global data section starts */
.data
N:
.byte  10  
/* Code section starts */
.text
.global fib
.global main
main:
mov   N@GOTPCREL(%rip), %rbx        
movzbq  (%rbx), %rdi   # N <-> %ebx
callq fib

ret
