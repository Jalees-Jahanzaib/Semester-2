.text
.global merge
merge:
mov $0,%r8
mov $0,%r9
lea (%rdi,%rsi,4),%r10
.loop:
cmp %rsi,%r8
je .exit1
cmp %rcx,%r9
je .exit1
lea (%rdi,%r8,4),%r11
movl (%r11),%r13d
lea (%rdx,%r9,4),%r12
mov (%r12),%r14d
cmp %r14d,%r13d
jle .st
jg  .op
.st:
movl %r13d,(%r10)
inc %r8
add $4,%r10
jmp .loop
.op:
movl %r14d,(%r10)
inc %r9
add $4,%r10
jmp .loop

.exit1:
.loop1:
cmp %r8,%rsi
je  .loop2
lea (%rdi,%r8,4),%r11
movl (%r11),%r13d
movl %r13d,(%r10)
inc %r8
add $4,%r10
jmp .loop1

.loop2:
cmp %r9,%rcx
je .exit2
lea (%rdx,%r9,4),%r11
movl (%r11),%r14d
movl %r14d,(%r10)
inc %r9
add $4,%r10
jmp .loop2

.exit2:
ret
