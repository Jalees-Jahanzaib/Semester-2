.data
N: 
 .byte 10
.text
.global main
fibo:
cmp $1, %rdi
jl  .RR  
sub $1, %rdi
push %rdi
call fibo

pop %rdi
push %rax
sub $1 , %rdi
call fibo
pop %rbx
add %rbx, %rax
.RR:
mov %rdi, %rax
ret
main:
mov   N@GOTPCREL(%rip), %rbx
movzb (%rbx), %rdi
call fibo
ret


