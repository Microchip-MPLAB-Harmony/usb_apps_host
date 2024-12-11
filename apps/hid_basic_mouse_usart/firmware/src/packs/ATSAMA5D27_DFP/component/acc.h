/*
 * Component description for ACC
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

/* file generated from device description file (ATDF) version 2024-06-24T14:43:55Z */
#ifndef _SAMA5D2_ACC_COMPONENT_H_
#define _SAMA5D2_ACC_COMPONENT_H_

/* ************************************************************************** */
/*   SOFTWARE API DEFINITION FOR ACC                                          */
/* ************************************************************************** */

/* -------- ACC_CR : (ACC Offset: 0x00) ( /W 32) Control Register -------- */
#define ACC_CR_SWRST_Pos                      _UINT32_(0)                                          /* (ACC_CR) Software Reset Position */
#define ACC_CR_SWRST_Msk                      (_UINT32_(0x1) << ACC_CR_SWRST_Pos)                  /* (ACC_CR) Software Reset Mask */
#define ACC_CR_SWRST(value)                   (ACC_CR_SWRST_Msk & (_UINT32_(value) << ACC_CR_SWRST_Pos)) /* Assigment of value for SWRST in the ACC_CR register */
#define ACC_CR_Msk                            _UINT32_(0x00000001)                                 /* (ACC_CR) Register Mask  */


/* -------- ACC_MR : (ACC Offset: 0x04) (R/W 32) Mode Register -------- */
#define ACC_MR_ACEN_Pos                       _UINT32_(8)                                          /* (ACC_MR) Analog Comparator Enable Position */
#define ACC_MR_ACEN_Msk                       (_UINT32_(0x1) << ACC_MR_ACEN_Pos)                   /* (ACC_MR) Analog Comparator Enable Mask */
#define ACC_MR_ACEN(value)                    (ACC_MR_ACEN_Msk & (_UINT32_(value) << ACC_MR_ACEN_Pos)) /* Assigment of value for ACEN in the ACC_MR register */
#define   ACC_MR_ACEN_DIS_Val                 _UINT32_(0x0)                                        /* (ACC_MR) Analog comparator disabled.  */
#define   ACC_MR_ACEN_EN_Val                  _UINT32_(0x1)                                        /* (ACC_MR) Analog comparator enabled.  */
#define ACC_MR_ACEN_DIS                       (ACC_MR_ACEN_DIS_Val << ACC_MR_ACEN_Pos)             /* (ACC_MR) Analog comparator disabled. Position  */
#define ACC_MR_ACEN_EN                        (ACC_MR_ACEN_EN_Val << ACC_MR_ACEN_Pos)              /* (ACC_MR) Analog comparator enabled. Position  */
#define ACC_MR_INV_Pos                        _UINT32_(12)                                         /* (ACC_MR) Invert Comparator Output Position */
#define ACC_MR_INV_Msk                        (_UINT32_(0x1) << ACC_MR_INV_Pos)                    /* (ACC_MR) Invert Comparator Output Mask */
#define ACC_MR_INV(value)                     (ACC_MR_INV_Msk & (_UINT32_(value) << ACC_MR_INV_Pos)) /* Assigment of value for INV in the ACC_MR register */
#define   ACC_MR_INV_DIS_Val                  _UINT32_(0x0)                                        /* (ACC_MR) Analog comparator output is directly processed.  */
#define   ACC_MR_INV_EN_Val                   _UINT32_(0x1)                                        /* (ACC_MR) Analog comparator output is inverted prior to being processed.  */
#define ACC_MR_INV_DIS                        (ACC_MR_INV_DIS_Val << ACC_MR_INV_Pos)               /* (ACC_MR) Analog comparator output is directly processed. Position  */
#define ACC_MR_INV_EN                         (ACC_MR_INV_EN_Val << ACC_MR_INV_Pos)                /* (ACC_MR) Analog comparator output is inverted prior to being processed. Position  */
#define ACC_MR_Msk                            _UINT32_(0x00001100)                                 /* (ACC_MR) Register Mask  */


/* -------- ACC_WPMR : (ACC Offset: 0xE4) (R/W 32) Write Protection Mode Register -------- */
#define ACC_WPMR_WPEN_Pos                     _UINT32_(0)                                          /* (ACC_WPMR) Write Protection Enable Position */
#define ACC_WPMR_WPEN_Msk                     (_UINT32_(0x1) << ACC_WPMR_WPEN_Pos)                 /* (ACC_WPMR) Write Protection Enable Mask */
#define ACC_WPMR_WPEN(value)                  (ACC_WPMR_WPEN_Msk & (_UINT32_(value) << ACC_WPMR_WPEN_Pos)) /* Assigment of value for WPEN in the ACC_WPMR register */
#define ACC_WPMR_WPKEY_Pos                    _UINT32_(8)                                          /* (ACC_WPMR) Write Protection Key Position */
#define ACC_WPMR_WPKEY_Msk                    (_UINT32_(0xFFFFFF) << ACC_WPMR_WPKEY_Pos)           /* (ACC_WPMR) Write Protection Key Mask */
#define ACC_WPMR_WPKEY(value)                 (ACC_WPMR_WPKEY_Msk & (_UINT32_(value) << ACC_WPMR_WPKEY_Pos)) /* Assigment of value for WPKEY in the ACC_WPMR register */
#define   ACC_WPMR_WPKEY_PASSWD_Val           _UINT32_(0x414343)                                   /* (ACC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0.  */
#define ACC_WPMR_WPKEY_PASSWD                 (ACC_WPMR_WPKEY_PASSWD_Val << ACC_WPMR_WPKEY_Pos)    /* (ACC_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0. Position  */
#define ACC_WPMR_Msk                          _UINT32_(0xFFFFFF01)                                 /* (ACC_WPMR) Register Mask  */


/* -------- ACC_WPSR : (ACC Offset: 0xE8) ( R/ 32) Write Protection Status Register -------- */
#define ACC_WPSR_WPVS_Pos                     _UINT32_(0)                                          /* (ACC_WPSR) Write Protection Violation Status Position */
#define ACC_WPSR_WPVS_Msk                     (_UINT32_(0x1) << ACC_WPSR_WPVS_Pos)                 /* (ACC_WPSR) Write Protection Violation Status Mask */
#define ACC_WPSR_WPVS(value)                  (ACC_WPSR_WPVS_Msk & (_UINT32_(value) << ACC_WPSR_WPVS_Pos)) /* Assigment of value for WPVS in the ACC_WPSR register */
#define ACC_WPSR_Msk                          _UINT32_(0x00000001)                                 /* (ACC_WPSR) Register Mask  */


/** \brief ACC register offsets definitions */
#define ACC_CR_REG_OFST                _UINT32_(0x00)      /* (ACC_CR) Control Register Offset */
#define ACC_MR_REG_OFST                _UINT32_(0x04)      /* (ACC_MR) Mode Register Offset */
#define ACC_WPMR_REG_OFST              _UINT32_(0xE4)      /* (ACC_WPMR) Write Protection Mode Register Offset */
#define ACC_WPSR_REG_OFST              _UINT32_(0xE8)      /* (ACC_WPSR) Write Protection Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/** \brief ACC register API structure */
typedef struct
{
  __O   uint32_t                       ACC_CR;             /**< Offset: 0x00 ( /W  32) Control Register */
  __IO  uint32_t                       ACC_MR;             /**< Offset: 0x04 (R/W  32) Mode Register */
  __I   uint8_t                        Reserved1[0xDC];
  __IO  uint32_t                       ACC_WPMR;           /**< Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I   uint32_t                       ACC_WPSR;           /**< Offset: 0xE8 (R/   32) Write Protection Status Register */
} acc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _SAMA5D2_ACC_COMPONENT_H_ */
