.text
.global matrix
matrix:
imul %rsi ,%rdx # no of terms
mov $0,%rax
mov $0,%rcx
mov (%rdi),%r10
cmp %rdx ,%rcx
je .exit

cmp  %r10 , 
mov (%rdi),%r10



.exit
ret
