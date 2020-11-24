;;kernal.asm
bits 32         ;nasm directive - 32bit not an assembly instruction this is strictly for the assembler
section .text
        ;multiboot spec
        align 4
        dd 0x1BADB002   ;magic
        dd 0x00         ;flag
        dd - (0x1BADB002 + 0x00) ;checksum

global start     ;another instruction for the assembler this sets symbol var to global start is the entry point, this is defined in the c program
extern kmain     ;kmain is defined in the c file, extern lets the assembler know that this var will be defined externally

start:           ;start calls the kmain function as defined below then halts the CPU
    cli          ;blocks interrupts, short for clear-interrupts
    mov esp, stack_space ;set stack pointer below we define memory space for this.
    call kmain
    hlt           ;halt the CPU

section .bas
resb 8192         ;8KB for stack
stack_space: