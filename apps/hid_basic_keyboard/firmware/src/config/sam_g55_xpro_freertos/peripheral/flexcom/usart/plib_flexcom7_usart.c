/*******************************************************************************
  FLEXCOM7 USART PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_flexcom7_usart.c

  Summary:
    FLEXCOM7 USART PLIB Implementation File

  Description
    This file defines the interface to the FLEXCOM7 USART
    peripheral library. This library provides access to and control of the
    associated peripheral instance.

  Remarks:
    None.
*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "plib_flexcom7_usart.h"
#include "interrupts.h"

// *****************************************************************************
// *****************************************************************************
// Section: FLEXCOM7 USART Implementation
// *****************************************************************************
// *****************************************************************************

#define FLEXCOM_USART_RHR_8BIT_REG      (*(volatile uint8_t* const)((USART7_BASE_ADDRESS + US_RHR_REG_OFST)))
#define FLEXCOM_USART_RHR_9BIT_REG      (*(volatile uint16_t* const)((USART7_BASE_ADDRESS + US_RHR_REG_OFST)))

#define FLEXCOM_USART_THR_8BIT_REG      (*(volatile uint8_t* const)((USART7_BASE_ADDRESS + US_THR_REG_OFST)))
#define FLEXCOM_USART_THR_9BIT_REG      (*(volatile uint16_t* const)((USART7_BASE_ADDRESS + US_THR_REG_OFST)))

volatile static FLEXCOM_USART_OBJECT flexcom7UsartObj;

void static FLEXCOM7_USART_ErrorClear( void )
{
    if ((USART7_REGS->US_CSR & (US_CSR_OVRE_Msk | US_CSR_FRAME_Msk | US_CSR_PARE_Msk)) != 0U)
    {
        USART7_REGS->US_CR = US_CR_RSTSTA_Msk;

        /* Flush existing error bytes from the RX FIFO */
        while ((USART7_REGS->US_CSR & US_CSR_RXRDY_Msk) != 0U)
        {
            (void)USART7_REGS->US_RHR;
        }
    }
}



void __attribute__((used)) FLEXCOM7_InterruptHandler( void )
{
    /* Channel status */
    uint32_t channelStatus = USART7_REGS->US_CSR;

    USART7_REGS->US_PTCR = US_PTCR_ERRCLR_Msk;

    if (((USART7_REGS->US_PTSR & US_PTSR_RXTEN_Msk) != 0U) && ((channelStatus & US_CSR_ENDRX_Msk) != 0U))
    {
        if(flexcom7UsartObj.rxBusyStatus == true)
        {
            flexcom7UsartObj.rxBusyStatus = false;
            USART7_REGS->US_PTCR = US_PTCR_RXTDIS_Msk;
            USART7_REGS->US_IDR = US_IDR_ENDRX_Msk;

            if( flexcom7UsartObj.rxCallback != NULL )
            {
                uintptr_t rxContext = flexcom7UsartObj.rxContext;
                
                flexcom7UsartObj.rxCallback(rxContext);
            }
        }
    }

    if (((USART7_REGS->US_PTSR & US_PTSR_TXTEN_Msk) != 0U) && ((channelStatus & US_CSR_ENDTX_Msk) != 0U))
    {
        if(flexcom7UsartObj.txBusyStatus == true)
        {
            flexcom7UsartObj.txBusyStatus = false;
            USART7_REGS->US_PTCR = US_PTCR_TXTDIS_Msk;
            USART7_REGS->US_IDR = US_IDR_ENDTX_Msk;

            if( flexcom7UsartObj.txCallback != NULL )
            {
                uintptr_t txContext = flexcom7UsartObj.txContext;
                
                flexcom7UsartObj.txCallback(txContext);
            }
        }
    }
}

void FLEXCOM7_USART_Initialize( void )
{
    /* Set FLEXCOM USART operating mode */
    FLEXCOM7_REGS->FLEXCOM_MR = FLEXCOM_MR_OPMODE_USART;

    /* Reset FLEXCOM7 USART */
    USART7_REGS->US_CR = (US_CR_RSTRX_Msk | US_CR_RSTTX_Msk | US_CR_RSTSTA_Msk);

    /* Enable FLEXCOM7 USART */
    USART7_REGS->US_CR = (US_CR_TXEN_Msk | US_CR_RXEN_Msk);

    /* Configure FLEXCOM7 USART mode */
    USART7_REGS->US_MR = ((US_MR_USCLKS_MCK) | US_MR_CHRL_8_BIT | US_MR_PAR_NO | US_MR_NBSTOP_1_BIT | (0UL << US_MR_OVER_Pos));

    /* Configure FLEXCOM7 USART Baud Rate */
    USART7_REGS->US_BRGR = US_BRGR_CD(54) | US_BRGR_FP(2);

    /* Initialize instance object */
    flexcom7UsartObj.rxBuffer = NULL;
    flexcom7UsartObj.rxSize = 0;
    flexcom7UsartObj.rxProcessedSize = 0;
    flexcom7UsartObj.rxBusyStatus = false;
    flexcom7UsartObj.rxCallback = NULL;
    flexcom7UsartObj.errorStatus = FLEXCOM_USART_ERROR_NONE;
    flexcom7UsartObj.txBuffer = NULL;
    flexcom7UsartObj.txSize = 0;
    flexcom7UsartObj.txProcessedSize = 0;
    flexcom7UsartObj.txBusyStatus = false;
    flexcom7UsartObj.txCallback = NULL;
}

FLEXCOM_USART_ERROR FLEXCOM7_USART_ErrorGet( void )
{
    FLEXCOM_USART_ERROR errorStatus = flexcom7UsartObj.errorStatus;

    flexcom7UsartObj.errorStatus = FLEXCOM_USART_ERROR_NONE;

    /* All errors are cleared, but send the previous error state */
    return errorStatus;
}

static void FLEXCOM7_USART_BaudCalculate(uint32_t srcClkFreq, uint32_t reqBaud, uint8_t overSamp, uint32_t* cd, uint32_t* fp, uint32_t* baudError)
{
    uint32_t actualBaud = 0U;

    *cd = srcClkFreq / (reqBaud * 8U * (2U - overSamp));

    if (*cd > 0U)
    {
        *fp = ((srcClkFreq / (reqBaud * (2U - (uint32_t)overSamp))) - ((*cd) * 8U));
        actualBaud = (srcClkFreq / (((*cd) * 8U) + (*fp))) / (2U - (uint32_t)overSamp);
        *baudError = ((100U * actualBaud)/reqBaud) - 100U;
    }
}

bool FLEXCOM7_USART_SerialSetup( FLEXCOM_USART_SERIAL_SETUP *setup, uint32_t srcClkFreq )
{
    uint32_t baud = 0U;
    uint32_t overSampVal = 0U;
    uint32_t usartMode;
    uint32_t cd0, fp0, cd1, fp1, baudError0, baudError1;
    bool status = false;

    cd0 = 0U;
    fp0 = 0U;
    cd1 = 0U;
    fp1 = 0U;
    baudError0 = 0U;
    baudError1 = 0U;

    bool rxBusyStatus = flexcom7UsartObj.rxBusyStatus;
    
    if((flexcom7UsartObj.txBusyStatus == true) || (rxBusyStatus == true))
    {
        /* Transaction is in progress, so return without updating settings */
        return false;
    }

    if (setup != NULL)
    {
        baud = setup->baudRate;

        if(srcClkFreq == 0U)
        {
            srcClkFreq = FLEXCOM7_USART_FrequencyGet();
        }

        /* Calculate baud register values for 8x/16x oversampling values */

        FLEXCOM7_USART_BaudCalculate(srcClkFreq, baud, 0, &cd0, &fp0, &baudError0);
        FLEXCOM7_USART_BaudCalculate(srcClkFreq, baud, 1, &cd1, &fp1, &baudError1);

        if ( !(cd0 > 0U && cd0 <= 65535U) && !(cd1 > 0U && cd1 <= 65535U) )
        {
            /* Requested baud cannot be generated with current clock settings */
            return status;
        }

        if ( (cd0 > 0U && cd0 <= 65535U) && (cd1 > 0U && cd1 <= 65535U) )
        {
            /* Requested baud can be generated with both 8x and 16x oversampling. Select the one with less % error. */
            if (baudError1 < baudError0)
            {
                cd0 = cd1;
                fp0 = fp1;
                overSampVal = (1UL << US_MR_OVER_Pos) & US_MR_OVER_Msk;
            }
        }
        else
        {
            /* Requested baud can be generated with either with 8x oversampling or with 16x oversampling. Select valid one. */
            if (cd1 > 0U && cd1 <= 65535U)
            {
                cd0 = cd1;
                fp0 = fp1;
                overSampVal = (1UL << US_MR_OVER_Pos) & US_MR_OVER_Msk;
            }
        }

        /* Configure FLEXCOM7 USART mode */
        usartMode = USART7_REGS->US_MR;
        usartMode &= ~(US_MR_CHRL_Msk | US_MR_MODE9_Msk | US_MR_PAR_Msk | US_MR_NBSTOP_Msk | US_MR_OVER_Msk);
        USART7_REGS->US_MR = usartMode | ((uint32_t)setup->dataWidth | (uint32_t)setup->parity | (uint32_t)setup->stopBits | overSampVal);

        /* Configure FLEXCOM7 USART Baud Rate */
        USART7_REGS->US_BRGR = US_BRGR_CD(cd0) | US_BRGR_FP(fp0);
        status = true;
    }

    return status;
}

bool FLEXCOM7_USART_Read( void *pBuffer, const size_t size )
{
    bool status = false;

    if(pBuffer != NULL)
    {
        /* Check if receive request is in progress */
        if(flexcom7UsartObj.rxBusyStatus == false)
        {
            /* Clear errors that may have got generated when there was no active read request pending */
            FLEXCOM7_USART_ErrorClear();

            status = true;

            flexcom7UsartObj.rxBuffer = pBuffer;
            flexcom7UsartObj.rxSize = size;
            flexcom7UsartObj.rxProcessedSize = 0;
            flexcom7UsartObj.rxBusyStatus = true;
            flexcom7UsartObj.errorStatus = FLEXCOM_USART_ERROR_NONE;

            USART7_REGS->US_RPR = (uint32_t)(uint8_t*)pBuffer;
            USART7_REGS->US_RCR = (uint32_t) size;
            USART7_REGS->US_PTCR = US_PTCR_RXTEN_Msk;
            USART7_REGS->US_IER = US_IER_ENDRX_Msk;
        }
    }

    return status;
}

bool FLEXCOM7_USART_Write( void *pBuffer, const size_t size )
{
    bool status = false;

    if(pBuffer != NULL)
    {
        /* Check if transmit request is in progress */
        if(flexcom7UsartObj.txBusyStatus == false)
        {
            status = true;

            flexcom7UsartObj.txBuffer = (uint8_t*)pBuffer;
            flexcom7UsartObj.txSize = size;
            flexcom7UsartObj.txProcessedSize = 0;
            flexcom7UsartObj.txBusyStatus = true;


            USART7_REGS->US_TPR = (uint32_t)(uint8_t*)pBuffer;
            USART7_REGS->US_TCR = (uint32_t) size;
            USART7_REGS->US_PTCR = US_PTCR_TXTEN_Msk;
            USART7_REGS->US_IER = US_IER_ENDTX_Msk;

        }
    }
    return status;
}

void FLEXCOM7_USART_WriteCallbackRegister( FLEXCOM_USART_CALLBACK callback, uintptr_t context )
{
    flexcom7UsartObj.txCallback = callback;
    flexcom7UsartObj.txContext = context;
}

void FLEXCOM7_USART_ReadCallbackRegister( FLEXCOM_USART_CALLBACK callback, uintptr_t context )
{
    flexcom7UsartObj.rxCallback = callback;
    flexcom7UsartObj.rxContext = context;
}

bool FLEXCOM7_USART_WriteIsBusy( void )
{
    return flexcom7UsartObj.txBusyStatus;
}

bool FLEXCOM7_USART_ReadIsBusy( void )
{
    return flexcom7UsartObj.rxBusyStatus;
}

size_t FLEXCOM7_USART_WriteCountGet( void )
{
    return (flexcom7UsartObj.txSize - USART7_REGS->US_TCR);
}

size_t FLEXCOM7_USART_ReadCountGet( void )
{
    return (flexcom7UsartObj.rxSize - USART7_REGS->US_RCR);
}

bool FLEXCOM7_USART_ReadAbort(void)
{
    if (flexcom7UsartObj.rxBusyStatus == true)
    {
        /* Disable PDA channel transfer */
        USART7_REGS->US_RCR = (uint32_t) 0U;
        USART7_REGS->US_PTCR = US_PTCR_RXTDIS_Msk;
        USART7_REGS->US_IDR = US_IDR_ENDRX_Msk;

        flexcom7UsartObj.rxBusyStatus = false;

        /* If required application should read the num bytes processed prior to calling the read abort API */
        flexcom7UsartObj.rxSize = 0;
        flexcom7UsartObj.rxProcessedSize = 0;
    }

    return true;
}


bool FLEXCOM7_USART_TransmitComplete( void )
{
    bool status = false;

    if ((USART7_REGS->US_CSR & US_CSR_TXEMPTY_Msk) != 0U)
    {
        status = true;
    }

    return status;
}