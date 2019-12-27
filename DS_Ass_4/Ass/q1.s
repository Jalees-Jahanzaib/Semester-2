/* Global data section starts */
.data

N:
.byte  10  
/* Code section starts */
.text
.global main
main:
movl  $0, %eax        #p1=0
mov   N@GOTPCREL(%rip), %rbx        
movzbl  (%rbx), %ebx    # N <-> %ebx
movl $1,%edx       #p2=1
.Lback:
cmpl  $1, %ebx
je .Lloopexit
movl %edx,%ecx   # third=p2
addl %eax, %ecx         # third=third+p2 
movl %edx,%eax               # p1=p2
movl %ecx,%edx               # p=third
dec   %ebx                   # n--
jmp .Lback
.Lloopexit:
ret
