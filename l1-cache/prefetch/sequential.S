.section .text
.global _start

_start:
    add x0, sp, #0              // get the first index
    sub sp, sp, #4194304          // Allocate space for 64KB array
    add x1, sp, #0              //store last index
    add x2, x1, #8             // store 2 index prior to last index    
    mov x3, x0                  // copy of first index

fill_arr:
    mov x4, x3                  // create a copy of current index
    sub x3, x3, #8             // get the next index
    str x3, [x4, #0]            // store next index at curr index
    cmp x3, x2
    bgt fill_arr             
    str x0, [x2, #0]            // loop back to first index
    mov x4, x0                  // stores the index to access
    mov x3, #1073741824         // size of loop
    mov x0, #0                  // stores the loop index

run_arr:
    ldr x4, [x4, #0]            // get the next access index
    add x0, x0, #1             // increase the loop index by 1
    cmp x0, x3
    blt run_arr

loop_arr:
    mov x8, #93           // Exit syscall
    mov x0, #0
    svc #0
