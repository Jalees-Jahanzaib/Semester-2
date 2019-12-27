.data
N:
.byte  10  
.text
.global fib
fib:
pushq %rbp      
movq %rsp,%rbp
cmpq  $2, %rdi     # compare n
jle .basecase      # basecase 
pushq %rdi         # save n
subq $1,%rdi       # n=n-1
callq fib          # call fib(n-1)
popq %rdi         # restore n
pushq %rax         # save the result of fib(n-1)
pushq %rdi         # save n
subq $2,%rdi       # n=n-2
callq fib          # call fib(n-2)
popq %rdi          # restore n
popq %rcx          # rcx gets fib(n-1)
addq %rcx,%rax     #  rax=fib(n-1)+fib(n-2)
movq %rbp,%rsp
popq %rbp
ret
.basecase:
movq %rdi,%rax
subq $1,%rax    # rax=n-1
movq %rbp,%rsp
popq %rbp
ret
.global main
main:
movq  $0, %rax        #ans=0 initially
mov   N@GOTPCREL(%rip), %rbx        
movzbq  (%rbx), %rdi    # N <-> %rdi
callq fib # after this answer will be in rax
ret
