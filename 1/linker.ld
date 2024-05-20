/* linker.ld */
ENTRY(start)
SECTIONS
{
    . = 0x100000;  /* Start address for the kernel */
    .text :
    {
        *(.multiboot)
        *(.text)
    }
    .rodata :
    {
        *(.rodata)
    }
    .data :
    {
        *(.data)
    }
    .bss :
    {
        *(.bss)
    }
}
