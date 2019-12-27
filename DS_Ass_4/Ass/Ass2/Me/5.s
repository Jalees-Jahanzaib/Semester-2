.text
.global fun
fun:
mov $0,%rax
cmp $1,%rdi

jle .exit
push %rdi
dec %rdi
call fun
pop %rdi
add %rdi , %rax
ret
.exit:
add $1,%rax
ret
