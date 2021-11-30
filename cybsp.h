/***************************************************************************//**
* \file cybsp.h
*
* \brief
* Basic API for setting up boards containing a 43907 MCU.
*
********************************************************************************
* \copyright
* Copyright 2021 Cypress Semiconductor Corporation (an Infineon company) or
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
*******************************************************************************/

#pragma once

#include "cy_result.h"
#include "cybsp_pins.h"
#include "cybsp_types.h"
#include "platform_mcu_peripheral.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define CYBSP_WIFI_INTERFACE_TYPE        CYBSP_M2M_INTERFACE

/**
 * \cond INTERNAL
 */
/* Macros that don't really belong here, but provided for compatability with middleware libraries
 * that expect them. This will be reviewed in a future release when we explore removing them from
 * other board types too. */
#define CY_CFG_PWR_MODE_ACTIVE          (0x00UL)
#define CY_CFG_PWR_MODE_SLEEP           (0x01UL)
#define CY_CFG_PWR_MODE_DEEPSLEEP       (0x02UL)
/* M2M for WHD needs high-speed clock */
#define CY_CFG_PWR_SYS_IDLE_MODE        (CY_CFG_PWR_MODE_ACTIVE)
#define CY_CFG_PWR_DEEPSLEEP_LATENCY    (0UL)
/** \endcond */

/**
 * \addtogroup group_bsp_functions Functions
 * \{
 * All functions exposed by the board.
 */

/**
 * \brief Initialize all hardware on the board
 * \returns CY_RSLT_SUCCESS if the board is successfully initialized, if there is
 *          a problem initializing any hardware it returns an error code specific
 *          to the hardware module that had a problem.
 */
cy_rslt_t cybsp_init(void);

/** \} group_bsp_functions */

#ifdef __cplusplus
}
#endif /* __cplusplus */
