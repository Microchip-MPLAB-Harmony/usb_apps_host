/*******************************************************************************
  System Initialization File

  File Name:
    initialization.c

  Summary:
    This file contains source code necessary to initialize the system.

  Description:
    This file contains source code necessary to initialize the system.  It
    implements the "SYS_Initialize" function, defines the configuration bits,
    and allocates any necessary global system resources,
 *******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "configuration.h"
#include "definitions.h"
#include "device.h"


// ****************************************************************************
// ****************************************************************************
// Section: Configuration Bits
// ****************************************************************************
// ****************************************************************************

/*** FUSERID ***/
#pragma config USER_ID =      0xffffU

/*** DEVCFG0 ***/
#pragma config SWOEN =      ON
#pragma config TROEN =      OFF
#pragma config ADCPOVR =      HW
#pragma config CPENFILT =      OFF
#pragma config RTCIN0_ALTEN =      PA3
#pragma config RTCOUT_ALTEN =      PA4
#pragma config USBSSEN =      0
#pragma config EPLLHWMD =      OFF
#pragma config UPLLHWMD =      OFF
#pragma config HPLUGDIS =      OFF
#pragma config USBIDIO =      1
#pragma config VBUSONIO =      1
#pragma config SMBUS3EN2 =      0
#pragma config PCM =      SFR
#pragma config INT0E =      OFF
#pragma config INT0P =      NEG
#pragma config FECCCON =         OFF
#pragma config FRECCDIS =      OFF
#pragma config CMEN =      1



/*** DEVCFG1 ***/
#pragma config CAN0_PIN_EN =      0
#pragma config TRCEN =      ON
#pragma config ZBTWKSYS =      OFF
#pragma config CMP0_OE =      OFF
#pragma config CMP1_OE =      OFF
#pragma config SMCLR =      NO_POR
#pragma config QSCHE_EN =      OFF
#pragma config QSPI_HSEN =      PPS
#pragma config SCOM0_HSEN =      DIRECT
#pragma config SCOM1_HSEN =      PPS
#pragma config SCOM2_HSEN =      PPS
#pragma config CCL_OE =      OFF
#pragma config WDTPSS =      PSS1048576
#pragma config QSPIDDRM =      OFF
#pragma config CLKZBREF =      OFF
#pragma config USBDMFTRIM =      DEFAULT
#pragma config USBDMRTRIM =      DEFAULT
#pragma config USBDPFTRIM =      DEFAULT
#pragma config USBDPRTRIM =      DEFAULT
#pragma config CAN1_PIN_EN =      0

/*** DEVCFG2 ***/
#pragma config ACMP_CYCLE =      _32US
#pragma config DMTINTV =      WIN_127_128
#pragma config PMUTEST_VDD_EN =      VDD_DIV_2
#pragma config POSCMOD =      HS
#pragma config WDTRMCS =      LPRC
#pragma config SOSCSEL =      XTAL
#pragma config WAKE2SPD =      ON
#pragma config CKSWEN =      ON
#pragma config FSCMEN =      ON
#pragma config WDTPSR =      PS1048576
#pragma config WDTSPGM =      STOPS
#pragma config WINDIS =      NORMAL
#pragma config WDTEN =      OFF
#pragma config WDTWINSZ =    WINSZ_25
#pragma config DMTCNT =      DMT31
#pragma config DMTEN =      OFF


/*** DEVCFG4 ***/
#pragma config SOSCCFG =    0x0U
#pragma config RTCEVENT_SEL =      ONE_SEC
#pragma config RTCEVENT_EN =      OFF
#pragma config VBKP_1KCSEL =      _32K
#pragma config VBKP_32KCSEL =      FRC
#pragma config VBKP_DIVSEL =      DIV_31_25
#pragma config LPCLK_MOD =      DIV_1
#pragma config RTCEVTYPE =      OUT
#pragma config CPEN_DLY =      _8_LPRC
#pragma config DSZPBOREN =      OFF
#pragma config DSWDTPS =      DSPS5
#pragma config DSWDTOSC =    LPRC
#pragma config DSWDTEN =      OFF
#pragma config DSEN =    OFF
#pragma config UVREGROVR =      CONTROLLED
#pragma config LPOSCEN =      OFF
#pragma config RTCNTM_CSEL =      RAW

/*** FBCFG0 ***/
#pragma config BINFOVALID =      VALID
#pragma config PCSCMODE =      DUAL

/*** FCPN0 ***/
#pragma config CP =      DISABLED





// *****************************************************************************
// *****************************************************************************
// Section: Driver Initialization Data
// *****************************************************************************
// *****************************************************************************
/* Following MISRA-C rules are deviated in the below code block */
/* MISRA C-2012 Rule 7.2 - Deviation record ID - H3_MISRAC_2012_R_7_2_DR_1 */
/* MISRA C-2012 Rule 11.1 - Deviation record ID - H3_MISRAC_2012_R_11_1_DR_1 */
/* MISRA C-2012 Rule 11.3 - Deviation record ID - H3_MISRAC_2012_R_11_3_DR_1 */
/* MISRA C-2012 Rule 11.8 - Deviation record ID - H3_MISRAC_2012_R_11_8_DR_1 */



// *****************************************************************************
// *****************************************************************************
// Section: System Data
// *****************************************************************************
// *****************************************************************************
/* Structure to hold the object handles for the modules in the system. */
SYSTEM_OBJECTS sysObj;

// *****************************************************************************
// *****************************************************************************
// Section: Library/Stack Initialization Data
// *****************************************************************************
// *****************************************************************************
// <editor-fold defaultstate="collapsed" desc="File System Initialization Data">

 const SYS_FS_MEDIA_MOUNT_DATA sysfsMountTable[SYS_FS_VOLUME_NUMBER] =
{
    {
        .mountName = SYS_FS_MEDIA_IDX0_MOUNT_NAME_VOLUME_IDX0,
        .devName   = SYS_FS_MEDIA_IDX0_DEVICE_NAME_VOLUME_IDX0,
        .mediaType = SYS_FS_MEDIA_TYPE_IDX0,
        .fsType   = SYS_FS_TYPE_IDX0
    },
    {
        .mountName = SYS_FS_MEDIA_IDX1_MOUNT_NAME_VOLUME_IDX0,
        .devName   = SYS_FS_MEDIA_IDX1_DEVICE_NAME_VOLUME_IDX0,
        .mediaType = SYS_FS_MEDIA_TYPE_IDX1,
        .fsType   = SYS_FS_TYPE_IDX1
    },
};


static const SYS_FS_FUNCTIONS FatFsFunctions =
{
    .mount             = FATFS_mount,
    .unmount           = FATFS_unmount,
    .open              = FATFS_open,
    .read_t              = FATFS_read,
    .close             = FATFS_close,
    .seek              = FATFS_lseek,
    .fstat             = FATFS_stat,
    .getlabel          = FATFS_getlabel,
    .currWD            = FATFS_getcwd,
    .getstrn           = FATFS_gets,
    .openDir           = FATFS_opendir,
    .readDir           = FATFS_readdir,
    .closeDir          = FATFS_closedir,
    .chdir             = FATFS_chdir,
    .chdrive           = FATFS_chdrive,
    .write_t             = FATFS_write,
    .tell              = FATFS_tell,
    .eof               = FATFS_eof,
    .size              = FATFS_size,
    .mkdir             = FATFS_mkdir,
    .remove_t            = FATFS_unlink,
    .setlabel          = FATFS_setlabel,
    .truncate          = FATFS_truncate,
    .chmode            = FATFS_chmod,
    .chtime            = FATFS_utime,
    .rename_t            = FATFS_rename,
    .sync              = FATFS_sync,
    .putchr            = FATFS_putc,
    .putstrn           = FATFS_puts,
    .formattedprint    = FATFS_printf,
    .testerror         = FATFS_error,
    .formatDisk        = (FORMAT_DISK)FATFS_mkfs,
    .partitionDisk     = FATFS_fdisk,
    .getCluster        = FATFS_getclusters
};




static const SYS_FS_REGISTRATION_TABLE sysFSInit [ SYS_FS_MAX_FILE_SYSTEM_TYPE ] =
{
    {
        .nativeFileSystemType = FAT,
        .nativeFileSystemFunctions = &FatFsFunctions
    }
};
// </editor-fold>

/******************************************************
 * USB Driver Initialization
 ******************************************************/
 
static uint8_t __attribute__((aligned(512))) USB_ALIGN endPointTable1[DRV_USBFS_ENDPOINTS_NUMBER * 32];

static void DRV_USB_VBUSPowerEnable(uint8_t port, bool enable)
{
    /* Note: USB Host applications should have a way for Enabling/Disabling the 
       VBUS. Applications can use a GPIO to turn VBUS on/off through a switch. 
       In MHC Pin Settings select the pin used as VBUS Power Enable as output and 
       name it to "VBUS_AH". If you a see a build error from this function either 
       you have not configured the VBUS Power Enable in MHC pin settings or the 
       Pin name entered in MHC is not "VBUS_AH". */ 
    if (enable == true)
    {
        /* Enable the VBUS */
        VBUS_AH_PowerEnable();
    }
    else
    {
        /* Disable the VBUS */
        VBUS_AH_PowerDisable();
    }
}

static const DRV_USBFS_INIT drvUSBFSInit =
{
     /* Assign the endpoint table */
    .endpointTable= endPointTable1,

    /* Interrupt Source for USB module */
    .interruptSource = USB_IRQn,
    
    /* USB Controller to operate as USB Host */
    .operationMode = DRV_USBFS_OPMODE_HOST,
    
    .operationSpeed = USB_SPEED_FULL,
 
    /* Stop in idle */
    .stopInIdle = false,
    
    /* Suspend in sleep */
    .suspendInSleep = false,
 
    /* Identifies peripheral (PLIB-level) ID */
    .usbID = USB_ID_1,
    
    /* USB Host Power Enable. USB Driver uses this function to Enable the VBUS */ 
    .portPowerEnable = DRV_USB_VBUSPowerEnable,
    
    /* Root hub available current in milliamperes */
    .rootHubAvailableCurrent = 500,

};








// *****************************************************************************
// *****************************************************************************
// Section: System Initialization
// *****************************************************************************
// *****************************************************************************

static const SYS_DEBUG_INIT debugInit =
{
    .moduleInit = {0},
    .errorLevel = SYS_DEBUG_GLOBAL_ERROR_LEVEL,
    .consoleIndex = 0,
};


// <editor-fold defaultstate="collapsed" desc="SYS_TIME Initialization Data">

static const SYS_TIME_PLIB_INTERFACE sysTimePlibAPI = {
    .timerCallbackSet = (SYS_TIME_PLIB_CALLBACK_REGISTER)RTC_Timer32CallbackRegister,
    .timerStart = (SYS_TIME_PLIB_START)RTC_Timer32Start,
    .timerStop = (SYS_TIME_PLIB_STOP)RTC_Timer32Stop,
    .timerFrequencyGet = (SYS_TIME_PLIB_FREQUENCY_GET)RTC_Timer32FrequencyGet,
    .timerPeriodSet = (SYS_TIME_PLIB_PERIOD_SET)NULL,
};

static const SYS_TIME_INIT sysTimeInitData =
{
    .timePlib = &sysTimePlibAPI,
    .hwTimerIntNum = RTC_IRQn,
};

// </editor-fold>
// <editor-fold defaultstate="collapsed" desc="SYS_CONSOLE Instance 0 Initialization Data">


static const SYS_CONSOLE_UART_PLIB_INTERFACE sysConsole0UARTPlibAPI =
{
    .read_t = (SYS_CONSOLE_UART_PLIB_READ)SERCOM0_USART_Read,
    .readCountGet = (SYS_CONSOLE_UART_PLIB_READ_COUNT_GET)SERCOM0_USART_ReadCountGet,
    .readFreeBufferCountGet = (SYS_CONSOLE_UART_PLIB_READ_FREE_BUFFFER_COUNT_GET)SERCOM0_USART_ReadFreeBufferCountGet,
    .write_t = (SYS_CONSOLE_UART_PLIB_WRITE)SERCOM0_USART_Write,
    .writeCountGet = (SYS_CONSOLE_UART_PLIB_WRITE_COUNT_GET)SERCOM0_USART_WriteCountGet,
    .writeFreeBufferCountGet = (SYS_CONSOLE_UART_PLIB_WRITE_FREE_BUFFER_COUNT_GET)SERCOM0_USART_WriteFreeBufferCountGet,
};

static const SYS_CONSOLE_UART_INIT_DATA sysConsole0UARTInitData =
{
    .uartPLIB = &sysConsole0UARTPlibAPI,
};

static const SYS_CONSOLE_INIT sysConsole0Init =
{
    .deviceInitData = (const void*)&sysConsole0UARTInitData,
    .consDevDesc = &sysConsoleUARTDevDesc,
    .deviceIndex = 0,
};



// </editor-fold>




// *****************************************************************************
// *****************************************************************************
// Section: Local initialization functions
// *****************************************************************************
// *****************************************************************************

/* MISRAC 2012 deviation block end */

/*******************************************************************************
  Function:
    void SYS_Initialize ( void *data )

  Summary:
    Initializes the board, services, drivers, application and other modules.

  Remarks:
 */

void SYS_Initialize ( void* data )
{

    /* MISRAC 2012 deviation block start */
    /* MISRA C-2012 Rule 2.2 deviated in this file.  Deviation record ID -  H3_MISRAC_2012_R_2_2_DR_1 */

  
    CLOCK_Initialize();
    /* MISRAC 2012 deviation block start */
    /* MISRA C-2012 Rule 11.1 deviated 1 time. Deviation record ID -  H3_MISRAC_2012_R_11_1_DR_1 */
    /* Configure Prefetch, Wait States by calling the ROM function whose address is available at address 0xF2D0 */
    typedef void (*FUNC_PCHE_SETUP)(uint32_t setup);
    (void)((FUNC_PCHE_SETUP)(*(uint32_t*)0xF2D0))((PCHE_REGS->PCHE_CHECON & (~(PCHE_CHECON_PFMWS_Msk | PCHE_CHECON_ADRWS_Msk | PCHE_CHECON_PREFEN_Msk)))
                                    | (PCHE_CHECON_PFMWS(1) | PCHE_CHECON_PREFEN(1) | PCHE_CHECON_ADRWS(1)));
    /* MISRA C-2012 Rule 11.1 deviation block end */



	GPIO_Initialize();

    SERCOM0_USART_Initialize();

    EVSYS_Initialize();

    RTC_Initialize();

	BSP_Initialize();

    /* MISRAC 2012 deviation block start */
    /* Following MISRA-C rules deviated in this block  */
    /* MISRA C-2012 Rule 11.3 - Deviation record ID - H3_MISRAC_2012_R_11_3_DR_1 */
    /* MISRA C-2012 Rule 11.8 - Deviation record ID - H3_MISRAC_2012_R_11_8_DR_1 */


    /* MISRA C-2012 Rule 11.3, 11.8 deviated below. Deviation record ID -  
     H3_MISRAC_2012_R_11_3_DR_1 & H3_MISRAC_2012_R_11_8_DR_1*/
        
    sysObj.sysDebug = SYS_DEBUG_Initialize(SYS_DEBUG_INDEX_0, (SYS_MODULE_INIT*)&debugInit);

    /* MISRAC 2012 deviation block end */
    /* MISRA C-2012 Rule 11.3, 11.8 deviated below. Deviation record ID -  
    H3_MISRAC_2012_R_11_3_DR_1 & H3_MISRAC_2012_R_11_8_DR_1*/
        
    sysObj.sysTime = SYS_TIME_Initialize(SYS_TIME_INDEX_0, (SYS_MODULE_INIT *)&sysTimeInitData);
    
    /* MISRAC 2012 deviation block end */
    /* MISRA C-2012 Rule 11.3, 11.8 deviated below. Deviation record ID -  
     H3_MISRAC_2012_R_11_3_DR_1 & H3_MISRAC_2012_R_11_8_DR_1*/
        sysObj.sysConsole0 = SYS_CONSOLE_Initialize(SYS_CONSOLE_INDEX_0, (SYS_MODULE_INIT *)&sysConsole0Init);
   /* MISRAC 2012 deviation block end */

    /* Initialize the USB Host layer */
    sysObj.usbHostObject0 = USB_HOST_Initialize (( SYS_MODULE_INIT *)& usbHostInitData );    

    /*** File System Service Initialization Code ***/
    (void) SYS_FS_Initialize( (const void *) sysFSInit );

    /* Initialize USB Driver */ 
    sysObj.drvUSBFSObject = DRV_USBFS_Initialize(DRV_USBFS_INDEX_0, (SYS_MODULE_INIT *) &drvUSBFSInit);    


    /* MISRAC 2012 deviation block end */
    APP_Initialize();


    NVIC_Initialize();


    /* MISRAC 2012 deviation block end */
}

/*******************************************************************************
 End of File
*/
