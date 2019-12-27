.text
.global max
max:
imul %rsi,%rdx  # n=m*n
mov $0,%rcx     # i=0
mov $0,%eax     # max_value=0
.loop:
cmp %rdx,%rcx
j e .exit
movl (%rdi),%r10d  #r10=array[i]
add $4,%rdi
inc %rcx
cmpl %r10d,%eax
jl .change
jmp .loop

.change:
movl %r10d,%eax
jmp .loop
.exit:
ret

