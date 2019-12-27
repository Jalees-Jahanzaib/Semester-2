.text
.global sum
sum:
cmp $1,%rdi
je .basecase
push %rdi
dec %rdi
call sum
pop %rdi
add %rdi,%rax
ret
.basecase:
mov $1,%rax
ret
