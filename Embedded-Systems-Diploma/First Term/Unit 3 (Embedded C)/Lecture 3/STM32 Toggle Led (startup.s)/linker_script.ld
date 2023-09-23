/* ARM Corex M3 Linker Script
By: Eng. Amr Zidan */

MEMORY
{
    flash(RX) : ORIGIN = 0x08000000 , LENGTH = 128K
    sram(RWX) : ORIGIN = 0x20000000 , LENGTH = 20K 
}

SECTIONS
{
    .text :
    {
        *(.vectors*)
        *(.text*)
        *(.rodata)
    }> flash

    .data :
    {
        *(.data*)
    }> flash

    .bss :
    {
        *(.bss*)
    }> sram

    

    
}