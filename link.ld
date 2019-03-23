MEMORY
{
  RAM   (xrw) : ORIGIN = 0x20000000, LENGTH = 8K
  FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 64K
}

ENTRY(Reset_Handler)

_estack    = ORIGIN(RAM) + LENGTH(RAM);
_min_stack = 2K;

SECTIONS
{
  .isr_vector ORIGIN(FLASH) :
  {
    KEEP(*(.isr_vector))
  } > FLASH

  .text : ALIGN(4)
  {
    *(.text)
    *(.text*)
    *(.glue_7)
    *(.glue_7t)
    *(.eh_frame)

    KEEP(*(.init))
    KEEP(*(.fini))

    . = ALIGN(4);
  } > FLASH

  .rodata : ALIGN(4)
  {
    *(.rodata)
    *(.rodata*)

    . = ALIGN(4);
  } > FLASH

  .preinit_array :
  {
    KEEP(*(.preinit_array*))
  } > FLASH

  PROVIDE_HIDDEN(__preinit_array_start = ADDR(.preinit_array));
  PROVIDE_HIDDEN(__preinit_array_end   = ADDR(.preinit_array) + SIZEOF(.preinit_array));

  .init_array :
  {
    KEEP(*(SORT(.init_array.*)))
    KEEP(*(.init_array*))
  } > FLASH

  PROVIDE_HIDDEN(__init_array_start = ADDR(.init_array));
  PROVIDE_HIDDEN(__init_array_end   = ADDR(.init_array) + SIZEOF(.init_array));

  .fini_array :
  {
    KEEP(*(SORT(.fini_array.*)))
    KEEP(*(.fini_array*))
  } > FLASH

  PROVIDE_HIDDEN(__fini_array_start = ADDR(.fini_array));
  PROVIDE_HIDDEN(__fini_array_end   = ADDR(.fini_array) + SIZEOF(.fini_array));

  .data : ALIGN(4)
  {
    *(.data)
    *(.data*)

    . = ALIGN(4);
  } >RAM AT> FLASH

  _sdata  = ADDR(.data);
  _edata  = ADDR(.data) + SIZEOF(.data);
  _sidata = LOADADDR(.data);

  .bss : ALIGN(4)
  {
    *(.bss)
    *(.bss*)
    *(COMMON)

    . = ALIGN(4);
  } > RAM

  _sbss = ADDR(.bss);
  _ebss = ADDR(.bss) + SIZEOF(.bss);

  ._user_stack_check : ALIGN(8)
  {
    . = . + _min_stack;
    . = ALIGN(8);
  } > RAM

  /DISCARD/ :
  {
    libc.a(*)
    libm.a(*)
    libgcc.a(*)
    *(.ARM.extab* .gnu.linkonce.armextab.*)
    *(.ARM.exidx*)
  }

  .ARM.attributes 0 : {
    *(.ARM.attributes)
  }
}

