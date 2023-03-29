/***************************************************************************//**
* \file cybsp.c
*
* Description:
* Provides initialization code for starting up the hardware contained on the
* 43907 board.
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

#include "cybsp.h"
#if defined(CY_USING_HAL)
#include "cyhal_hwmgr.h"
#include "cyhal_syspm.h"
#endif

#ifndef CY_CFG_PWR_VDDA_MV
    #define CY_CFG_PWR_VDDA_MV              (3300)
#endif

#if defined(__cplusplus)
extern "C" {
#endif

//--------------------------------------------------------------------------------------------------
// cybsp_init
//--------------------------------------------------------------------------------------------------
cy_rslt_t cybsp_init(void)
{
    // Setup hardware manager to track resource usage then initialize all system (clock/power) board
    // configuration
    #if defined(CY_USING_HAL)
    cy_rslt_t result = cyhal_hwmgr_init();

    if (CY_RSLT_SUCCESS == result)
    {
        result = cyhal_syspm_init();
    }

    #ifdef CY_CFG_PWR_VDDA_MV
    if (CY_RSLT_SUCCESS == result)
    {
        cyhal_syspm_set_supply_voltage(CYHAL_VOLTAGE_SUPPLY_VDDA, CY_CFG_PWR_VDDA_MV);
    }
    #endif

    #else // if defined(CY_USING_HAL)
    cy_rslt_t result = CY_RSLT_SUCCESS;
    #endif // if defined(CY_USING_HAL)

    #if defined(CYBSP_CUSTOM_SYSCLK_PM_CALLBACK)
    result = cybsp_register_custom_sysclk_pm_callback();
    #endif // No default syspm callback on this device

    return result;
}


#if defined(__cplusplus)
}
#endif
