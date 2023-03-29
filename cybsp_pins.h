/***************************************************************************************************
 * \copyright
 * Copyright 2018-2022 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **************************************************************************************************/

#pragma once

#define CYBSP_LED1      (PIN_PWM_3)
#define CYBSP_USER_LED  (CYBSP_LED1)
#define CYBSP_USER_LED1 (CYBSP_LED1)

#define CYBSP_LED2      (PIN_GPIO_9)
#define CYBSP_USER_LED2 (CYBSP_LED2)

#define CYBSP_SW1       (PIN_GPIO_8)
#define CYBSP_SW3       (PIN_PWM_5)

#define CYBSP_I2C_SCL   (PIN_I2C0_CLK)
#define CYBSP_I2C_SDA   (PIN_I2C0_SDATA)

#define CYBSP_J10_1     (PIN_GPIO_0)
#define CYBSP_J10_2     (PIN_GPIO_1)
#define CYBSP_J10_3     (PIN_GPIO_13)
#define CYBSP_J10_4     (PIN_GPIO_7)
#define CYBSP_J10_5     (PIN_GPIO_14)
#define CYBSP_J10_6     (PIN_GPIO_16)
#define CYBSP_J10_7     (PIN_GPIO_15)
#define CYBSP_J10_8     (PIN_I2S_SDATAI0)

#define CYBSP_J12_1     (PIN_I2S_SDATAI1)
#define CYBSP_J12_2     (PIN_PWM_4)
#define CYBSP_J12_3     (PIN_GPIO_11)
#define CYBSP_J12_4     (PIN_GPIO_10)
#define CYBSP_J12_5     (PIN_GPIO_12)
#define CYBSP_J12_6     (PIN_GPIO_9)
/* J12.7 is GND, J12.8 is ARD_AREF. */
#define CYBSP_J12_9     (PIN_I2C1_SDATA)
#define CYBSP_J12_10    (PIN_I2C1_CLK)

#define CYBSP_J6_1      (PIN_PWM_4)
#define CYBSP_J6_2      (PIN_PWM_5)
#define CYBSP_J6_3      (PIN_I2S_MCLK0)
#define CYBSP_J6_4      (PIN_I2S_SCLK0)
#define CYBSP_J6_5      (PIN_I2S_SDATAO0)
#define CYBSP_J6_6      (PIN_I2S_LRCLK0)
#define CYBSP_J6_7      (PIN_PWM_3)
/* J6.8 is GND */
#define CYBSP_J6_9      (PIN_SPI_1_CLK)
#define CYBSP_J6_10     (PIN_I2S_SDATAO1)
#define CYBSP_J6_11     (PIN_SPI_1_MISO)
#define CYBSP_J6_12     (PIN_SPI_0_CLK)
#define CYBSP_J6_13     (PIN_SPI_1_MOSI)
#define CYBSP_J6_14     (PIN_SPI_0_MOSI)
#define CYBSP_J6_15     (PIN_SPI_1_CS)
#define CYBSP_J6_16     (PIN_SPI_0_CS)
#define CYBSP_J6_17     (PIN_SPI_0_MISO)
#define CYBSP_J6_18     (PIN_UART0_RXD)
/* J6.19 is GND */
#define CYBSP_J6_20     (PIN_UART0_TXD)
/* J6.21 is USB2_HOST_DEV_SEL which is not a GPIO */
#define CYBSP_J6_22     (PIN_UART0_CTS)
#define CYBSP_J6_23     (PIN_I2C0_CLK)
#define CYBSP_J6_24     (PIN_UART0_RTS)
#define CYBSP_J6_25     (PIN_I2C0_SDATA)
#define CYBSP_J6_26     (PIN_I2S_MCLK1)
#define CYBSP_J6_27     (PIN_I2S_LRCLK1)
/* J6.28 is GND */
#define CYBSP_J6_29     (PIN_I2S_SCLK1)
#define CYBSP_J6_30     (PIN_SDIO_DATA_1)
#define CYBSP_J6_31     (PIN_SDIO_DATA_0)
#define CYBSP_J6_32     (PIN_SDIO_CLK)
#define CYBSP_J6_33     (PIN_SDIO_CMD)
#define CYBSP_J6_34     (PIN_SDIO_DATA_3)
#define CYBSP_J6_35     (PIN_SDIO_DATA_2)
#define CYBSP_J6_36     (PIN_RF_SW_CTRL_6)
#define CYBSP_J6_37     (PIN_RF_SW_CTRL_7)
#define CYBSP_J6_38     (PIN_RF_SW_CTRL_8)
#define CYBSP_J6_39     (PIN_RF_SW_CTRL_9)
/* J6.40 is HIB_WAKE which is not a GPIO */
/* J6.41 is HIB_LPO_SEL which is not a GPIO */
/* J6.42 is HIB_REG_ON_IN which is not a GPIO */
/* J6.43 is USB2_DN which is not a GPIO */
/* J6.44 is USB2_DP which is not a GPIO */

#define CYBSP_D0        (CYBSP_J10_1)
#define CYBSP_D1        (CYBSP_J10_2)
#define CYBSP_D2        (CYBSP_J10_3)
#define CYBSP_D3        (CYBSP_J10_4)
#define CYBSP_D4        (CYBSP_J10_5)
#define CYBSP_D5        (CYBSP_J10_6)
#define CYBSP_D6        (CYBSP_J10_7)
#define CYBSP_D7        (CYBSP_J10_8)
#define CYBSP_D8        (CYBSP_J12_1)
#define CYBSP_D9        (CYBSP_J12_2)
#define CYBSP_D10       (CYBSP_J12_3)
#define CYBSP_D11       (CYBSP_J12_4)
#define CYBSP_D12       (CYBSP_J12_5)
#define CYBSP_D13       (CYBSP_J12_6)

#define CYBSP_DEBUG_UART_RX (PIN_RF_SW_CTRL_6)
#define CYBSP_DEBUG_UART_TX (PIN_RF_SW_CTRL_7)
