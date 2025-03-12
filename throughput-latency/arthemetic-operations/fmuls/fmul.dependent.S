.text
.global main

_start:

main:
    mov     x19, 0 
.L26:
    mov     x0, 268435455   // 2^28
    cmp     x19, x0
    bhi     .L25                    // Exit loop if x19 > x0
    fmul    s8, s7, s6
    fmul    s6, s8, s7
    fmul    s8, s7, s6
    fmul    s6, s8, s7
    fmul    s8, s7, s6
    fmul    s6, s8, s7
    fmul    s8, s7, s6
    fmul    s6, s8, s7
    fmul    s8, s7, s6
    fmul    s6, s8, s7
    fmul    s8, s7, s6
    fmul    s6, s8, s7
    fmul    s8, s7, s6
    fmul    s6, s8, s7
    fmul    s8, s7, s6
    fmul    s6, s8, s7
    fmul    s8, s7, s6
    fmul    s6, s8, s7
    fmul    s8, s7, s6
    fmul    s6, s8, s7
    fmul    s8, s7, s6
    fmul    s6, s8, s7
    fmul    s8, s7, s6
    fmul    s6, s8, s7
    fmul    s8, s7, s6
    fmul    s6, s8, s7
    fmul    s8, s7, s6
    fmul    s6, s8, s7
    fmul    s8, s7, s6
    fmul    s6, s8, s7
    fmul    s8, s7, s6
    fmul    s6, s8, s7

    add     x19, x19, 1             // Increment loop counter
    b       .L26                    // Repeat loop

.L25:
    mov     x8, #93                 // Exit syscall
    svc     #0                       // Make system call
