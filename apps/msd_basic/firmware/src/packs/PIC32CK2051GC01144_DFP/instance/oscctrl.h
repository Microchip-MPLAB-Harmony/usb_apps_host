/*
 * Instance header file for PIC32CK2051GC01144
 *
 * Copyright (c) 2024 Microchip Technology Inc. and its subsidiaries.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/* file generated from device description file (ATDF) version 2024-04-02T09:16:01Z */
#ifndef _PIC32CKGC01_OSCCTRL_INSTANCE_
#define _PIC32CKGC01_OSCCTRL_INSTANCE_


/* ========== Instance Parameter definitions for OSCCTRL peripheral ========== */
#define OSCCTRL_DFLL48M_ATEST_IMPLEMENTED        (1)        /* DFLL48M ATEST register implemented */
#define OSCCTRL_DFLL48M_ATEST_SIZE               (8)        /* number of effective bits in DFLL48M ATEST register */
#define OSCCTRL_DFLL48M_IS_STARTUP_OSCILLATOR    (1)        /* DFLL48M is startup oscillator */
#define OSCCTRL_DFLL48M_RC48MCAL0_PORVAL         (0)        /* Defines the RC48MCAL0 register reset value after POR. */
#define OSCCTRL_DIV_8MHZ_NUM                     (2)        
#define OSCCTRL_FRACDIVS_NUM                     (1)        /* Number of FRACDIVs */
#define OSCCTRL_FRACDIV_DIVIDER_RESET_VAL        (32)       /* Fracdiv Divider reset value */
#define OSCCTRL_FRACDIV_PLLSRC                   (0)        /* Indice of the PLL that is source of the FRACDIV */
#define OSCCTRL_GCLK_ID_DFLL48M                  (0)        /* Index of Generic Clock for DFLL48 */
#define OSCCTRL_GCLK_ID_PLL                      (1)        /* Index of Generic Clock for PLL */
#define OSCCTRL_INSTANCE_ID                      (6)        /* Instance index for OSCCTRL */
#define OSCCTRL_MCLK_ID_APB                      (38)       /* Index for OSCCTRL APB clock */
#define OSCCTRL_PAC_ID                           (6)        /* Index for OSCCTRL registers write protection */
#define OSCCTRL_PLL0_OUTPUTS_NUM                 (6)        /* number of clock outputs for PLL0 */
#define OSCCTRL_PLL1_OUTPUTS_NUM                 (0)        /* number of clock outputs for PLL1 */
#define OSCCTRL_PLLS_NUM                         (1)        /* Number of PLLs */
#define OSCCTRL_USBHS_NUM                        (1)        /* Number of usbhs clock requests */
#define OSCCTRL_XOSC_ATEST_IMPLEMENTED           (1)        /* XOSC ATEST register implemented */
#define OSCCTRL_XOSC_ATEST_SIZE                  (4)        /* number of effective bits in XOSC ATEST register */
#define OSCCTRL_XOSC_CFD_CLK_SELECT_SIZE         (4)        /* Clock fail prescaler size */
#define OSCCTRL_XOSC_CFD_HAS_RETENTION           (0)        /* Clock fail detected for xosc is in tetention domain */

#endif /* _PIC32CKGC01_OSCCTRL_INSTANCE_ */
