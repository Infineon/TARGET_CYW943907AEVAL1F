/*
 * Copyright 2020, Cypress Semiconductor Corporation or a subsidiary of
 * Cypress Semiconductor Corporation. All Rights Reserved.
 *
 * This software, associated documentation and materials ("Software"),
 * is owned by Cypress Semiconductor Corporation
 * or one of its subsidiaries ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products. Any reproduction, modification, translation,
 * compilation, or representation of this Software except as specified
 * above is prohibited without the express written permission of Cypress.
 *
 * Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 * reserves the right to make changes to the Software without notice. Cypress
 * does not assume any liability arising out of the application or use of the
 * Software or any product or circuit described in the Software. Cypress does
 * not authorize its products for use in any products where a malfunction or
 * failure of the Cypress product may reasonably be expected to result in
 * significant property damage, injury or death ("High Risk Product"). By
 * including Cypress's product in a High Risk Product, the manufacturer
 * of such system or application assumes all risk of such use and in doing
 * so agrees to indemnify Cypress against all liability.
 */

/* Mapping of platform interrupts over the top of generic versions */

/* Temporary defines */
START_STACK_SIZE = 8000;
SYS_STACK_SIZE = 0;
IRQ_STACK_SIZE = 1024;
FIQ_STACK_SIZE = 0;

reset_handler = _low_start;

/* Force system to reset via ROM bootloader & serial flash.  This works around A0 issue that FLOPS is not reset by SRSTn */
irq_instruction_vector_low_reset = 0xB03EF000;

/* DMA descriptors table must be within single 64KB page, and last descriptor must have EOT flag. Let's put all out descriptors in single page and avoid last descriptor. */
DMA_DESCRIPTORS_SIZE = (64 * 1024 - 16);

ENTRY( _low_start );

/* INCLUDE GCC_bootloader_memory.ld */
MEMORY
{
    ROM              (rx)   : ORIGIN = 0x00400000, LENGTH = 640K /* ROM bootloader and hard-coded routines region */
    FLOPS            (rwx)  : ORIGIN = 0x00000000, LENGTH = 32  /* Stores instructions for branching to interrupt vectors */
    SRAM_NOLOAD      (rwx)  : ORIGIN = 0x004A0000, LENGTH = 737K /* Used for heap, stack, bss. Unusable as a first app due to ROM bootloader */
    ROM_BOOTLOADER   (rwx)  : ORIGIN = 0x00554000, LENGTH = 2K   /* BSS and globals for ROM bootloader */
    SRAM             (rwx)  : ORIGIN = 0x00554800, LENGTH = 1357K /* Used for app text. Need to account for ROM bootloader SRAM usage */
    BOOTLOADER_SRAM  (rwx)  : ORIGIN = 0x00696000, LENGTH = 36K  /* Not used. Future use for WICED-style bootloader */
    DDR              (rwx)  : ORIGIN = 0x40000000, LENGTH = 0 /* Not used. Future use when needed */
}

SECTIONS
{
    .text :
    {
        . = ALIGN(32);

        link_code_location = .;
        KEEP(*(.text.startup)) /* has to be first */
        *(.text .text.* .gnu.linkonce.t.*)
        *(.sleep_event_handlers.*)
        KEEP(*(.text.vPortSVCHandler    .text.xPortPendSVHandler .text.xPortSysTickHandler ))
        KEEP(*(.text.__tx_SVCallHandler .text.__tx_PendSVHandler .text.__tx_SysTickHandler ))
        KEEP(*(.text.platform_tick_isr ))
        KEEP(*(.text.irq ))
        KEEP(*(.text.sdio_rtos_irq .text.sdio_irq ))
        KEEP(*(.text.uart_rtos_irq .text.uart_irq ))
        KEEP(*(.text.dma_rtos_irq  .text.dma_irq  ))
        KEEP(*(.text.gpio_rtos_irq .text.gpio_irq ))
        KEEP(*(.text.dbg_watchdog_rtos_irq  .text.dbg_watchdog_irq  ))
        KEEP(*(.text.usart1_rtos_irq .text.usart1_irq ))
        KEEP(*(.text.usart2_rtos_irq .text.usart2_irq ))
        KEEP(*(.text.usart1_tx_dma_rtos_irq .text.usart1_tx_dma_irq ))
        KEEP(*(.text.usart2_tx_dma_rtos_irq .text.usart2_tx_dma_irq ))
        KEEP(*(.text.usart1_rx_dma_rtos_irq .text.usart1_rx_dma_irq ))
        KEEP(*(.text.usart2_rx_dma_rtos_irq .text.usart2_rx_dma_irq ))
        link_code_end = .;
    } > SRAM

    .rodata :
    {
        . = ALIGN(32);

        link_const_variable_data_location = .;
        *(.rodata .rodata.* .gnu.linkonce.r.*)
        link_const_variable_data_end = .;

        . = ALIGN(4);

        link_sleep_event_registrations_location = .;
        KEEP(*(.sleep_event_registrations.*))
        link_sleep_event_registrations_end = .;

        . = ALIGN(4);

        link_constructors_location = .;
        KEEP(*(.preinit_array))
        KEEP(*(.init_array))
        KEEP (*crtbegin.o(.ctors))
        KEEP (*(EXCLUDE_FILE (*crtend.o) .ctors))
        KEEP (*(SORT(.ctors.*)))
        KEEP (*crtend.o(.ctors))
        link_constructors_end = .;

        . = ALIGN(4);

        link_destructors_location = .;
        KEEP (*crtbegin.o(.dtors))
        KEEP (*(EXCLUDE_FILE (*crtend.o) .dtors))
        KEEP (*(SORT(.dtors.*)))
        KEEP (*crtend.o(.dtors))
        link_destructors_end = .;

        /* Important: link_interrupt_vectors_copyfrom needs to be correctly aligned */
        . = ALIGN(32);
    } > SRAM

    .vectors_copyfrom :
    {
        link_interrupt_vectors_copyfrom = LOADADDR(.vectors_copyfrom);
        KEEP(*(.vectors_copyfrom))
    } > FLOPS AT > SRAM

    /*
     * The .ARM.exidx and .ARM.extab sections are used for C++ exception handling.
     * It is located here for completeness. Bare-metal ARM projects
     * typically cannot afford the overhead associated with C++
     * exceptions handling.
     */
    .ARM.exidx :
    {
        __exidx_start = ALIGN(4);
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        __exidx_end = .;
    } > SRAM

    .ARM.extab :
    {
        __extab_start = ALIGN(4);
        *(.ARM.extab*)
        __extab_end = .;
    } > SRAM

    .data : /* Contains the non-zero initialised global variables */
    {
        . = ALIGN(32);

        *(.data*)
    } > SRAM

    .dma (NOLOAD) : /* Zero initialised memory used DMA descriptors */
    {
        . = ALIGN(32);

        link_dma_location = .;
        *(.dma.*)
        link_dma_end = ALIGN(4);
    } > SRAM

    .bss (NOLOAD) : /* Zero initialised memory used for zero initialised variables */
    {
        . = ALIGN(4);

        link_bss_location = .;
        *(.bss*)
        *(COMMON)
        link_bss_end = ALIGN(4);
    } > SRAM_NOLOAD

    .stack_start (NOLOAD) :
    {
        . = ALIGN(8);

        link_stack_location = .;
        . = MAX(link_stack_location + START_STACK_SIZE , .);
        link_stack_end = ALIGN(8);
    } > SRAM_NOLOAD

    .stack_isr (NOLOAD) :
    {
        . = ALIGN(8);

        link_stack_isr_location = .;
        . = . + link_stack_isr_location + SYS_STACK_SIZE + IRQ_STACK_SIZE + FIQ_STACK_SIZE + 3 * 8;
        link_stack_isr_end = ALIGN(8);
        /*
         * Stack is full descending.
         * Here we give choice to RTOS to pre-allocate frame,
         * so on entry to ISR sp register points to empty frame.
         */
        KEEP(*(.isr_stack_initial_frame))
        link_heap_start = ALIGN(8);
    } > SRAM_NOLOAD

    /* INCLUDE GCC/ddr.ld */
.ddr_text :
{
    . = ALIGN(32);
    *(.ddr_text*)
} > DDR

.ddr_data :
{
    . = ALIGN(32);
    *(.ddr_data*)
} > DDR

.ddr_bss (NOLOAD) : /* Zero initialised memory used for zero initialised variables */
{
    . = ALIGN(4);

    link_ddr_bss_location = .;
    *(.ddr_bss*)
    link_ddr_bss_end = ALIGN(4);
} > DDR

.ddr_heap (NOLOAD) :
{
    . = ALIGN(4);

    link_ddr_heap_location = .;
    KEEP(*(.ddr_heap*))
    link_ddr_heap_end = ALIGN(4);

    link_ddr_free_location = ALIGN(4);
} > DDR

    /DISCARD/ :
    {
        *(.ARM.attributes*)
        *(.comment)
        *(.init)
        *(.preinit)
        *(.fini)
        *(.fini_array)
        *(.ARM.exidx*)
        *(.gnu.linkonce.armexidx.*)
        *(.eh_frame_hdr)
        *(.eh_frame)
        *(.gnu.linkonce.armextab.*)
        *(.v4_bx)
        *(.vfp11_veneer)
        *(.gcc_except_table)
        *(.eh_frame_hdr)
        *(.eh_frame)
        *(.glue*)
    }
}

/* Declare libc Heap to start at end of allocated RAM and end at top of RAM, aligned 8 byte */
PROVIDE( __HeapBase = link_heap_start );
PROVIDE( __HeapLimit = ALIGN( ORIGIN( SRAM_NOLOAD ) + LENGTH( SRAM_NOLOAD ) - 8, 8 ) );

/* Declare ThreadX free memory (passed to app as tx_application_define() func's argument) */
PROVIDE( __RAM_segment_used_end__ = link_stack_isr_end );

