.text
.global main

_start:

main:
    mov     x19, 0                  // Loop counter
.L26:
    mov     x0, 1073741823          // Loop limit
    cmp     x19, x0
    bhi     .L25                    // Exit loop if x19 > x0
    fmul    s8, s0, s0              // Perform eight multiplications
    fmul    s9, s8, s0              // Perform eight multiplications
    fmul    s8, s9, s0              // Perform eight multiplications
    fmul    s9, s8, s0              // Perform eight multiplications
    fmul    s8, s9, s0              // Perform eight multiplications
    fmul    s9, s8, s0              // Perform eight multiplications
    fmul    s8, s9, s0              // Perform eight multiplications
    fmul    s9, s8, s0              // Perform eight multiplications
    fmul    s8, s9, s0              // Perform eight multiplications
    fmul    s9, s8, s0              // Perform eight multiplications
    fmul    s8, s9, s0              // Perform eight multiplications
    fmul    s9, s8, s0              // Perform eight multiplications
    fmul    s8, s9, s0              // Perform eight multiplications
    fmul    s9, s8, s0              // Perform eight multiplications
    fmul    s8, s9, s0              // Perform eight multiplications
    fmul    s9, s8, s0              // Perform eight multiplications
    fmul    s8, s9, s0              // Perform eight multiplications
    fmul    s9, s8, s0              // Perform eight multiplications
    fmul    s8, s9, s0              // Perform eight multiplications
    fmul    s9, s8, s0              // Perform eight multiplications
    fmul    s8, s9, s0              // Perform eight multiplications
    fmul    s9, s8, s0              // Perform eight multiplications
    fmul    s8, s9, s0              // Perform eight multiplications
    fmul    s9, s8, s0              // Perform eight multiplications
    fmul    s8, s9, s0              // Perform eight multiplications
    fmul    s9, s8, s0              // Perform eight multiplications
    fmul    s8, s9, s0              // Perform eight multiplications
    fmul    s9, s8, s0              // Perform eight multiplications
    fmul    s8, s9, s0              // Perform eight multiplications
    fmul    s9, s8, s0              // Perform eight multiplications
    fmul    s8, s9, s0              // Perform eight multiplications
    fmul    s9, s8, s0              // Perform eight multiplications


    add     x19, x19, 1             // Increment loop counter
    b       .L26                    // Repeat loop

.L25:
    mov     x8, #93                 // Exit syscall
    svc     #0                       // Make system call
