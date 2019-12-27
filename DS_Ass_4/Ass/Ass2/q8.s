.text
.global reverse
reverse:
mov $0,%rcx
.loop:
lea (%rdi,%rcx,1),%r8
movb (%r8),%r10b
cmpb $0,%r10b
je .exit
inc %rcx
jmp .loop
.exit:
# length <->%rd
mov $0,%r8    # l<->%r8
mov %rcx,%r9  # f<->%r9
dec %r9
.loop1:
cmpb %r8b,%r9b
jle .ex
lea (%rdi,%r8,1),%r10
movb (%r10),%r12b
lea (%rdi,%r9,1),%r11
movb (%r11),%r13b
movb %r12b,(%r11)
movb %r13b,(%r10)
incb %r8b
decb %r9b
jmp .loop1
.ex:
ret
