/***************************************************************************//**
* \file cybsp.h
*
* \brief
* Basic API for setting up boards containing a 43907 MCU.
*
********************************************************************************
* \copyright
* Copyright 2021-2022 Cypress Semiconductor Corporation (an Infineon company) or
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
#include "cybsp_hw_config.h"

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * \cond INTERNAL
 */

/* Macros that don't really belong here, but provided for compatibility with
 * middleware libraries that expect them. This will be reviewed in a future
 * release when we explore removing them from other board types too.
 */
#define CY_CFG_PWR_MODE_ACTIVE          (0x00UL)
#define CY_CFG_PWR_MODE_SLEEP           (0x01UL)
#define CY_CFG_PWR_MODE_DEEPSLEEP       (0x02UL)

/* Default to use Deep Sleep */
#ifndef CY_CFG_PWR_SYS_IDLE_MODE
#define CY_CFG_PWR_SYS_IDLE_MODE        (CY_CFG_PWR_MODE_ACTIVE)
#endif

#define CY_CFG_PWR_DEEPSLEEP_LATENCY    (24UL)  /* Min. 24 for this device */

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

#if defined(CYBSP_CUSTOM_SYSCLK_PM_CALLBACK)
//--------------------------------------------------------------------------------------------------
// cybsp_register_custom_sysclk_pm_callback
//
// Registers a power management callback that prepares the clock system for entering deep sleep mode
// and restore the clocks upon wakeup from deep sleep. The application should implement this
// function and define `CYBSP_CUSTOM_SYSCLK_PM_CALLBACK` if it needs to replace the default SysClk
// DeepSleep callback behavior with application specific logic.
// NOTE: This is called automatically as part of \ref cybsp_init
//--------------------------------------------------------------------------------------------------
cy_rslt_t cybsp_register_custom_sysclk_pm_callback(void);
#endif // defined(CYBSP_CUSTOM_SYSCLK_PM_CALLBACK)

/** \} group_bsp_functions */

#ifdef __cplusplus
}
#endif /* __cplusplus */
