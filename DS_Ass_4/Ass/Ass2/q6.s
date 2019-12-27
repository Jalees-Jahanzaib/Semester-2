.text
.global isPrime
isPrime:
cmp $1,%rdi
jle .no
cmp $2,%rdi
je  .yes
movl $2,%ecx
.loop:
movl $0,%edx
movl %edi,%eax
idiv %ecx
cmp $0,%edx
je .no
movl %ecx,%r10d
imul %r10d,%r10d
cmpl %r10d,%edi
jle .yes
inc %ecx
jmp .loop
.no:
movl $0,%eax
ret
.yes:
movl $1,%eax
ret
