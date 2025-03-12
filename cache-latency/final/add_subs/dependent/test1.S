.text
.global main

_start:

main:
    mov     x19, 0 
.L26:
    mov     x0, 268435455   // 2^28
    cmp     x19, x0
    bhi     .L25                    // Exit loop if x19 > x0
    fadd    s1, s2, s3
    fadd    s3, s2, s1
    fadd    s1, s2, s3
    fadd    s3, s2, s1
    fadd    s1, s2, s3
    fadd    s3, s2, s1
    fadd    s1, s2, s3
    fadd    s3, s2, s1
    fadd    s1, s2, s3
    fadd    s3, s2, s1
    fadd    s1, s2, s3
    fadd    s3, s2, s1
    fadd    s1, s2, s3
    fadd    s3, s2, s1
    fadd    s1, s2, s3
    fadd    s3, s2, s1
    fadd    s1, s2, s3
    fadd    s3, s2, s1
    fadd    s1, s2, s3
    fadd    s3, s2, s1
    fadd    s1, s2, s3
    fadd    s3, s2, s1
    fadd    s1, s2, s3
    fadd    s3, s2, s1
    fadd    s1, s2, s3
    fadd    s3, s2, s1
    fadd    s1, s2, s3
    fadd    s3, s2, s1
    fadd    s1, s2, s3
    fadd    s3, s2, s1
    fadd    s1, s2, s3
    fadd    s3, s2, s1

    add     x19, x19, 1             // Increment loop counter
    b       .L26                    // Repeat loop

.L25:
    mov     x8, #93                 // Exit syscall
    svc     #0                       // Make system call
