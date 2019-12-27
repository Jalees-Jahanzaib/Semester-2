 .text
.global sum
sum:
imul %rsi,%rdx # m=m*n
mov $0,%rax  # sum is stored in rax
mov $0,%rcx  # i=0
.loop:
cmp %rdx,%rcx
je .exit
mov (%rdi),%r10 # r10=array[i]
add $4,%rdi
inc %rcx
test $1,%r10
jz .even
jmp .loop
.even:
add %r10,%rax
jmp .loop
.exit:
ret
