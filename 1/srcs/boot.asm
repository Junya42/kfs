; boot.asm - A simple bootloader that loads and starts a kernel
section .multiboot
align 4
mb_header:
    dd 0x1BADB002               ; magic number
    dd 0x0                      ; flags
    dd -(0x1BADB002 + 0x0)      ; checksum

section .text
global start
extern kmain

start:
    ; Set up the stack
    cli                         ; Clear interrupts
    xor eax, eax
    mov ds, eax
    mov es, eax
    mov fs, eax
    mov gs, eax

    mov esp, 0x9fc00            ; Set stack pointer
    mov ebp, esp                ; Set base pointer

    ; Call kernel main function
    call kmain

hang:
    cli                         ; Disable interrupts
    hlt                         ; Halt the CPU
    jmp hang                    ; Infinite loop to prevent further execution
