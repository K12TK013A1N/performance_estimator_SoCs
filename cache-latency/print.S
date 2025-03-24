.global main

.section .text
main:
    // Number to print (example: 42)
    mov x0, #42              // Load the number 42 into register x0
    bl print_number          // Call the print_number subroutine

    // Exit the program gracefully
    mov x8, #93              // Linux syscall number for exit (93)
    mov x0, #0               // Exit code 0 (success)
    svc #0                   // Make syscall

// Subroutine to print a number in decimal
print_number:
    mov x1, x0               // Copy the number to x1 for processing
    adr x2, buffer           // Load the address of the buffer
    add x2, x2, #19          // Point to the end of the buffer
    mov w3, #0               // Digit count (for string length)
