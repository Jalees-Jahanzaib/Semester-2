.data
N:
.byte 7  
array:
.long 7,4,3,8,1,2,2
.text
.global main
main:
movl  $1, %ecx        #i <-> %ecx
mov   N@GOTPCREL(%rip), %rdx 
movzbl  (%rdx), %edx    # N <-> %edx
mov array@GOTPCREL(%rip),%rbx      # base address <-> %rbx
movzbl (%rbx),%r8d        # r8 = array[0]
mov %r8,%r10   # r10 <-> sum   sum=array[0]
mov $0,%rax    # %rax <-> max_value
.Lback:
cmpl  %ecx, %edx    # compare i and n
je .Lloopexit
lea (%ebx,%ecx,4),%r8   
movzbl (%r8),%r9d   # array[i] <->%r9
add %r9,%r10        # sum+=array[i]
cmp %r9,%rax        #  compare  max_value  and array[i] 
jl .max
inc   %rcx                   # i++
jmp .Lback
.max:
mov %r9,%rax       # max_value = array[i]
inc %rcx
jmp .Lback
.Lloopexit:
ret
# max value is in %rax and sum is in %r10
