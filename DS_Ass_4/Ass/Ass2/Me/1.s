.text
.global sum
sum:
imul %rdx,%rsi # n=m*m  no of terms
mov $0,%rax # sum
mov $0,%rcx # i=0
.loop:
cmp %rsi, %rcx
je .exit
mov (%rdi),%r8
add $4 ,%rdi
inc  %rcx
test $1,%r8
jz .even
jmp .loop
.even:
add %r8 , %rax

jmp .loop 
.exit:
ret
