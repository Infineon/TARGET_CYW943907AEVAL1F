# CYW943907AEVAL1F BSP Release Notes
The CYW943907AEVAL1F Evaluation kit enables you to evaluate and develop single-chip Wi-Fi applications using CYW43907 devices. The kit uses a module based on CYW43907 device. CYW43907 is a single-chip 802.11n dual-band (2.4 GHz and 5 GHz) Wi-Fi SoC that features 320-MHz Arm® Cortex®-R4 MCU for application subsystem and various on-chip interfaces like Ethernet (RMII/MII), UART, SPI/QSPI and I2C that in totality offers a very small-footprint IoT solution.

NOTE: BSPs are versioned by family. This means that version 1.2.0 of any BSP in a family (eg: PSoC™ 6) will have the same software maturity level. However, not all updates are necessarily applicable for each BSP in the family so not all version numbers will exist for each board. Additionally, new BSPs may not start at version 1.0.0. In the event of adding a common feature across all BSPs, the libraries are assigned the same version number. For example if BSP_A is at v1.3.0 and BSP_B is at v1.2.0, the event will trigger a version update to v1.4.0 for both BSP_A and BSP_B. This allows the common feature to be tracked in a consistent way.

### What's Included?
The CYW943907AEVAL1F library includes the following:
* BSP specific makefile to configure the build process for the board
* cybsp.c/h files to initialize the board and any system peripherals
* cybsp_types.h file describing basic board setup
* Linker script & startup code for GCC and ARM toolchains
* Configurator design files (and generated code) to setup board specific peripherals
* .lib file references for all dependent libraries
* API documentation

### What Changed?
#### v1.1.0
* Added functionality to enable BSP Assistant chip flow
* Added macros `CYBSP_DEBUG_UART_CTS` and  `CYBSP_DEBUG_UART_RTS` to cybsp_hw_config.h
#### v1.0.0
Note: This revision is only compatible with ModusToolbox Tools 3.0 and newer.
* Initial production release supporting C applications with the GCC_ARM compiler.
#### v0.5.0
* Initial pre-production release supporting C applications with the GCC_ARM compiler.

### Known Issues
* Of the 2M of SRAM on this device, a maximum of 1357K is available for application code. The remaining SRAM space can be used for heap, bss, and stack.
* The only supported CPU frequency is 160 MHz.
* C++ applications are not supported.
* FreeRTOS is the only supported implementation for abstraction-rtos on this device.

### Supported Software and Tools
This version of the CYW943907AEVAL1F BSP was validated for compatibility with the following Software and Tools:

| Software and Tools                        | Version |
| :---                                      | :----:  |
| ModusToolbox™ Software Environment        | 3.1.0   |
| GCC Compiler                              | 12.2.1  |

Minimum required ModusToolbox™ Software Environment: v3.0.0

### More information
* [CYW943907AEVAL1F BSP API Reference Manual][api]
* [CYW943907AEVAL1F Documentation](https://www.cypress.com/documentation/development-kitsboards/cyw943907aeval1f-evaluation-kit)
* [Cypress Semiconductor, an Infineon Technologies Company](http://www.cypress.com)
* [Infineon GitHub](https://github.com/infineon)
* [ModusToolbox™](https://www.cypress.com/products/modustoolbox-software-environment)

[api]: https://infineon.github.io/TARGET_CYW943907AEVAL1F/html/modules.html

---
© Cypress Semiconductor Corporation (an Infineon company) or an affiliate of Cypress Semiconductor Corporation, 2019-2022.