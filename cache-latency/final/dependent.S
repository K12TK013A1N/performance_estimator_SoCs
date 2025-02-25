.text
.global main

_start:

main:
  sub  sp, sp, #16
  mov  x1, sp
  str  x1, [x1]
  mov x2, x1
  mov  x19, 0

.L1:
  mov x0, 1073741823  // 2^30 iterations
  cmp x19, x0
  bhi .L2

  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0
  ldr x1, [x2]
  add x2, x1, 0

  add x19, x19, 1
  b .L1

.L2:
  mov     x8, #93                 // Exit syscall
  svc     #0                       // Make system call
