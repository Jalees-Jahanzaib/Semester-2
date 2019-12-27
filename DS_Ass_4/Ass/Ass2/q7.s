
.text
.global parityCheck
parityCheck:
cmp $0,%rdi
je .zero          # zero means num of odd numbers are even and  vice versa
cmp $1,%rdi
je .one
movl $0,%edx
movl %edi,%eax
movl $2,%ecx
idiv %ecx
cm p $1,%edx
je .odd
movl %eax,%edi
movl $0,%eax
.h:
push %rax
call parityCheck
pop %rdi
add %edi,%eax
test $1,%eax
jz .zero
jmp .one
.odd:
movl %eax,%edi
movl $1,%eax
jmp .h
.zero:
movl $0,%eax
ret
.one:
movl $1,%eax
ret
