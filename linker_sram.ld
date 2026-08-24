ENTRY(Reset_Handler)

MEMORY
{
  RAM (xrw) : ORIGIN = 0x20000000, LENGTH = 48K
}

SECTIONS
{
  .vector_table :
  {
    . = ALIGN(4);
    KEEP(*(.vector_table))
    . = ALIGN(4);
  } > RAM

  .text :
  {
    . = ALIGN(4);
    *(.text)
    *(.text*)
    *(.rodata)
    *(.rodata*)
    . = ALIGN(4);
  } > RAM

  .data :
  {
    . = ALIGN(4);
    *(.data)
    *(.data*)
    . = ALIGN(4);
  } > RAM

  .bss :
  {
    . = ALIGN(4);
    *(.bss)
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
  } > RAM

  /* Установка указателя стека на конец RAM */
  _estack = ORIGIN(RAM) + LENGTH(RAM);
}
