.text
.global binarysearch
binarysearch:
mov $0,%r8  # l<->%r8
mov $0,%r9   
mov $0,%r10
mov %rsi,%r9  #f<->%r9
dec %r9
.loop:
cmp %r8,%r9
jl .no
mov %r8,%r10
add %r9,%r10
shr $1,%r10
lea (%rdi,%r10,4),%r13
movl (%r13),%r14d
cmpl %r14d,%edx
je .yes
jl .goleft
jg .goright

.goleft:
mov %r10,%r9
dec %r9
jmp .loop
.goright:
mov %r10,%r8
inc %r8
jmp .loop

.no:
mov $0,%rax
ret

.yes:

mov $1,%eax
ret

