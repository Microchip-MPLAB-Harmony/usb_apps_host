/*
 * Instance header file for PIC32CM5164LE00100
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

/* file generated from device description file (ATDF) version 2022-09-09T06:08:26Z */
#ifndef _PIC32CMLE00_DMAC_INSTANCE_
#define _PIC32CMLE00_DMAC_INSTANCE_


/* ========== Instance Parameter definitions for DMAC peripheral ========== */
#define DMAC_CHANNEL0_INT_SRC                    (15)       /* DMA Channel 0 Interrupt */
#define DMAC_CHANNEL10_INT_SRC                   (19)       /* DMA Channel 10 Interrupt */
#define DMAC_CHANNEL11_INT_SRC                   (19)       /* DMA Channel 11 Interrupt */
#define DMAC_CHANNEL12_INT_SRC                   (19)       /* DMA Channel 12 Interrupt */
#define DMAC_CHANNEL13_INT_SRC                   (19)       /* DMA Channel 13 Interrupt */
#define DMAC_CHANNEL14_INT_SRC                   (19)       /* DMA Channel 14 Interrupt */
#define DMAC_CHANNEL15_INT_SRC                   (19)       /* DMA Channel 15 Interrupt */
#define DMAC_CHANNEL1_INT_SRC                    (16)       /* DMA Channel 1 Interrupt */
#define DMAC_CHANNEL2_INT_SRC                    (17)       /* DMA Channel 2 Interrupt */
#define DMAC_CHANNEL3_INT_SRC                    (18)       /* DMA Channel 3 Interrupt */
#define DMAC_CHANNEL4_INT_SRC                    (19)       /* DMA Channel 4 Interrupt */
#define DMAC_CHANNEL5_INT_SRC                    (19)       /* DMA Channel 5 Interrupt */
#define DMAC_CHANNEL6_INT_SRC                    (19)       /* DMA Channel 6 Interrupt */
#define DMAC_CHANNEL7_INT_SRC                    (19)       /* DMA Channel 7 Interrupt */
#define DMAC_CHANNEL8_INT_SRC                    (19)       /* DMA Channel 8 Interrupt */
#define DMAC_CHANNEL9_INT_SRC                    (19)       /* DMA Channel 9 Interrupt */
#define DMAC_CH_BITS                             (4)        /* Number of bits to select channel */
#define DMAC_CH_NUM                              (16)       /* Number of channels */
#define DMAC_EVIN_NUM                            (8)        /* Number of input events */
#define DMAC_EVOUT_NUM                           (8)        /* Number of output events */
#define DMAC_INSTANCE_ID                         (35)       /* Instance index for DMAC */
#define DMAC_LVL_BITS                            (2)        /* Number of bit to select level priority */
#define DMAC_LVL_NUM                             (4)        /* Enable priority level number */
#define DMAC_QOSCTRL_D_RESETVALUE                (2)        /* QOS dmac ahb interface reset value */
#define DMAC_QOSCTRL_F_RESETVALUE                (2)        /* QOS dmac fetch interface reset value */
#define DMAC_QOSCTRL_WRB_RESETVALUE              (2)        /* QOS dmac write back interface reset value */
#define DMAC_SPLIT_IRQ_NUM                       (4)        /* Number of IRQ split out */
#define DMAC_TRIG_BITS                           (6)        /* Number of bits to select trigger source */
#define DMAC_TRIG_NUM                            (51)       /* Number of peripheral triggers */

#endif /* _PIC32CMLE00_DMAC_INSTANCE_ */
