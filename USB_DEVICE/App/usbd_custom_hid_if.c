/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : usbd_custom_hid_if.c
  * @version        : v1.0_Cube
  * @brief          : USB Device Custom HID interface file.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "usbd_custom_hid_if.h"

/* USER CODE BEGIN INCLUDE */

/* USER CODE END INCLUDE */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/** @addtogroup STM32_USB_OTG_DEVICE_LIBRARY
  * @brief Usb device.
  * @{
  */

/** @addtogroup USBD_CUSTOM_HID
  * @{
  */

/** @defgroup USBD_CUSTOM_HID_Private_TypesDefinitions USBD_CUSTOM_HID_Private_TypesDefinitions
  * @brief Private types.
  * @{
  */

/* USER CODE BEGIN PRIVATE_TYPES */

/* USER CODE END PRIVATE_TYPES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Defines USBD_CUSTOM_HID_Private_Defines
  * @brief Private defines.
  * @{
  */

/* USER CODE BEGIN PRIVATE_DEFINES */

/* USER CODE END PRIVATE_DEFINES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Macros USBD_CUSTOM_HID_Private_Macros
  * @brief Private macros.
  * @{
  */

/* USER CODE BEGIN PRIVATE_MACRO */

/* USER CODE END PRIVATE_MACRO */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_Variables USBD_CUSTOM_HID_Private_Variables
  * @brief Private variables.
  * @{
  */

/** Usb HID report descriptor. */
__ALIGN_BEGIN static uint8_t CUSTOM_HID_ReportDesc_FS[USBD_CUSTOM_HID_REPORT_DESC_SIZE] __ALIGN_END =
{
  /* USER CODE BEGIN 0 */
		0x05, 0x01,        //(GLOBAL) USAGE_PAGE         0x0001 Generic Desktop Page
		0x09, 0x05,        //(LOCAL)  USAGE              0x00010005 Game Pad (Application Collection)
		0xA1, 0x01,        //(MAIN)   COLLECTION         0x01 Application (Usage=0x00010005: Page=Generic Desktop Page, Usage=Game Pad, Type=Application Collection)
		0xA1, 0x00,          //(MAIN)   COLLECTION         0x00 Physical (Usage=0x0: Page=, Usage=, Type=) <-- Error: COLLECTION must be preceded by a known USAGE <-- Warning: USAGE type should be CP (Physical Collection)
		0x09, 0x30,            //(LOCAL)  USAGE              0x00010030 X (Dynamic Value)
		0x09, 0x31,            //(LOCAL)  USAGE              0x00010031 Y (Dynamic Value)
		0x15, 0x00,            //(GLOBAL) LOGICAL_MINIMUM    0x00 (0)  <-- Info: Consider replacing 15 00 with 14
		0x26, 0xFF, 0xFF,          //(GLOBAL) LOGICAL_MAXIMUM    0xFFFF (-1)  <-- Info: Consider replacing 26 FFFF with 25 FF
		0x35, 0x00,            //(GLOBAL) PHYSICAL_MINIMUM   0x00 (0)  <-- Info: Consider replacing 35 00 with 34
		0x46, 0xFF, 0xFF,          //(GLOBAL) PHYSICAL_MAXIMUM   0xFFFF (-1)  <-- Info: Consider replacing 46 FFFF with 45 FF
		0x95, 0x02,            //(GLOBAL) REPORT_COUNT       0x02 (2) Number of fields
		0x75, 0x10,            //(GLOBAL) REPORT_SIZE        0x10 (16) Number of bits per field
		0x81, 0x02,            //(MAIN)   INPUT              0x00000002 (2 fields x 16 bits) 0=Data 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 0=NonVolatile 0=Bitmap  <-- Error: LOGICAL_MAXIMUM (-1) is less than LOGICAL_MINIMUM (0) <-- Error: PHYSICAL_MAXIMUM (-1) is less than PHYSICAL_MINIMUM (0)
		0xC0,             //(MAIN)   END_COLLECTION     Physical  <-- Warning: Physical units are still in effect PHYSICAL(MIN=0,MAX=-1) UNIT(0x,EXP=0)
		0xA1, 0x00,          //(MAIN)   COLLECTION         0x00 Physical (Usage=0x0: Page=, Usage=, Type=) <-- Error: COLLECTION must be preceded by a known USAGE <-- Warning: USAGE type should be CP (Physical Collection)
		0x09, 0x33,            //(LOCAL)  USAGE              0x00010033 Rx (Dynamic Value)
		0x09, 0x34,            //(LOCAL)  USAGE              0x00010034 Ry (Dynamic Value)
		0x15, 0x00,            //(GLOBAL) LOGICAL_MINIMUM    0x00 (0) <-- Redundant: LOGICAL_MINIMUM is already 0 <-- Info: Consider replacing 15 00 with 14
		0x26, 0xFF, 0xFF,          //(GLOBAL) LOGICAL_MAXIMUM    0xFFFF (-1) <-- Redundant: LOGICAL_MAXIMUM is already -1 <-- Info: Consider replacing 26 FFFF with 25 FF
		0x35, 0x00,            //(GLOBAL) PHYSICAL_MINIMUM   0x00 (0) <-- Redundant: PHYSICAL_MINIMUM is already 0 <-- Info: Consider replacing 35 00 with 34
		0x46, 0xFF, 0xFF,          //(GLOBAL) PHYSICAL_MAXIMUM   0xFFFF (-1) <-- Redundant: PHYSICAL_MAXIMUM is already -1 <-- Info: Consider replacing 46 FFFF with 45 FF
		0x95, 0x02,            //(GLOBAL) REPORT_COUNT       0x02 (2) Number of fields <-- Redundant: REPORT_COUNT is already 2
		0x75, 0x10,            //(GLOBAL) REPORT_SIZE        0x10 (16) Number of bits per field <-- Redundant: REPORT_SIZE is already 16
		0x81, 0x02,            //(MAIN)   INPUT              0x00000002 (2 fields x 16 bits) 0=Data 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 0=NonVolatile 0=Bitmap  <-- Error: LOGICAL_MAXIMUM (-1) is less than LOGICAL_MINIMUM (0) <-- Error: PHYSICAL_MAXIMUM (-1) is less than PHYSICAL_MINIMUM (0)
		0xC0,             //(MAIN)   END_COLLECTION     Physical  <-- Warning: Physical units are still in effect PHYSICAL(MIN=0,MAX=-1) UNIT(0x,EXP=0)
		0xA1, 0x00,          //(MAIN)   COLLECTION         0x00 Physical (Usage=0x0: Page=, Usage=, Type=) <-- Error: COLLECTION must be preceded by a known USAGE <-- Warning: USAGE type should be CP (Physical Collection)
		0x09, 0x32,            //(LOCAL)  USAGE              0x00010032 Z (Dynamic Value)
		0x15, 0x00,            //(GLOBAL) LOGICAL_MINIMUM    0x00 (0) <-- Redundant: LOGICAL_MINIMUM is already 0 <-- Info: Consider replacing 15 00 with 14
		0x26, 0xFF, 0xFF,          //(GLOBAL) LOGICAL_MAXIMUM    0xFFFF (-1) <-- Redundant: LOGICAL_MAXIMUM is already -1 <-- Info: Consider replacing 26 FFFF with 25 FF
		0x35, 0x00,            //(GLOBAL) PHYSICAL_MINIMUM   0x00 (0) <-- Redundant: PHYSICAL_MINIMUM is already 0 <-- Info: Consider replacing 35 00 with 34
		0x46, 0xFF, 0xFF,          //(GLOBAL) PHYSICAL_MAXIMUM   0xFFFF (-1) <-- Redundant: PHYSICAL_MAXIMUM is already -1 <-- Info: Consider replacing 46 FFFF with 45 FF
		0x95, 0x01,            //(GLOBAL) REPORT_COUNT       0x01 (1) Number of fields
		0x75, 0x10,            //(GLOBAL) REPORT_SIZE        0x10 (16) Number of bits per field <-- Redundant: REPORT_SIZE is already 16
		0x81, 0x02,            //(MAIN)   INPUT              0x00000002 (1 field x 16 bits) 0=Data 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 0=NonVolatile 0=Bitmap  <-- Error: LOGICAL_MAXIMUM (-1) is less than LOGICAL_MINIMUM (0) <-- Error: PHYSICAL_MAXIMUM (-1) is less than PHYSICAL_MINIMUM (0)
		0xC0,             //(MAIN)   END_COLLECTION     Physical  <-- Warning: Physical units are still in effect PHYSICAL(MIN=0,MAX=-1) UNIT(0x,EXP=0)
		0x05, 0x09,          //(GLOBAL) USAGE_PAGE         0x0009 Button Page
		0x19, 0x01,          //(LOCAL)  USAGE_MINIMUM      0x00090001 Button 1 Primary/trigger (Selector, On/Off Control, Momentary Control, or One Shot Control)
		0x29, 0x0A,          //(LOCAL)  USAGE_MAXIMUM      0x0009000A Button 10 (Selector, On/Off Control, Momentary Control, or One Shot Control)
		0x95, 0x0A,          //(GLOBAL) REPORT_COUNT       0x0A (10) Number of fields
		0x75, 0x01,          //(GLOBAL) REPORT_SIZE        0x01 (1) Number of bits per field
		0x81, 0x02,          //(MAIN)   INPUT              0x00000002 (10 fields x 1 bit) 0=Data 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 0=NonVolatile 0=Bitmap  <-- Error: LOGICAL_MAXIMUM (-1) is less than LOGICAL_MINIMUM (0) <-- Error: PHYSICAL_MAXIMUM (-1) is less than PHYSICAL_MINIMUM (0)
		0x05, 0x01,          //(GLOBAL) USAGE_PAGE         0x0001 Generic Desktop Page
		0x09, 0x39,          //(LOCAL)  USAGE              0x00010039 Hat switch (Dynamic Value)
		0x15, 0x01,          //(GLOBAL) LOGICAL_MINIMUM    0x01 (1)
		0x25, 0x08,          //(GLOBAL) LOGICAL_MAXIMUM    0x08 (8)
		0x35, 0x00,          //(GLOBAL) PHYSICAL_MINIMUM   0x00 (0) <-- Redundant: PHYSICAL_MINIMUM is already 0 <-- Info: Consider replacing 35 00 with 34
		0x46, 0x3B, 0x10,        //(GLOBAL) PHYSICAL_MAXIMUM   0x103B (4155)
		0x66, 0x0E, 0x00,        //(GLOBAL) UNIT               0x000E  (E=Reserved <-- Error: Measurement system type (E) is reserved)  <-- Info: Consider replacing 66 0E00 with 65 0E
		0x75, 0x04,          //(GLOBAL) REPORT_SIZE        0x04 (4) Number of bits per field
		0x95, 0x01,          //(GLOBAL) REPORT_COUNT       0x01 (1) Number of fields
		0x81, 0x42,          //(MAIN)   INPUT              0x00000042 (1 field x 4 bits) 0=Data 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 1=Null 0=NonVolatile 0=Bitmap
		0x75, 0x02,          //(GLOBAL) REPORT_SIZE        0x02 (2) Number of bits per field
		0x95, 0x01,          //(GLOBAL) REPORT_COUNT       0x01 (1) Number of fields <-- Redundant: REPORT_COUNT is already 1
		0x81, 0x03,          //(MAIN)   INPUT              0x00000003 (1 field x 2 bits) 1=Constant 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 0=NonVolatile 0=Bitmap
		0x75, 0x08,          //(GLOBAL) REPORT_SIZE        0x08 (8) Number of bits per field
		0x95, 0x02,          //(GLOBAL) REPORT_COUNT       0x02 (2) Number of fields
		0x81, 0x03,         //(MAIN)   INPUT              0x00000003 (2 fields x 8 bits) 1=Constant 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 0=NonVolatile 0=Bitmap
   //(MAIN)   END_COLLECTION     Application  <-- Warning: Physical units are still in effect PHYSICAL(MIN=0,MAX=4155) UNIT(0x0000000E,EXP=0)
	0x00,
  /* USER CODE END 0 */
  0xC0    /*     END_COLLECTION	             */
};

/* USER CODE BEGIN PRIVATE_VARIABLES */

/* USER CODE END PRIVATE_VARIABLES */

/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Exported_Variables USBD_CUSTOM_HID_Exported_Variables
  * @brief Public variables.
  * @{
  */
extern USBD_HandleTypeDef hUsbDeviceFS;

/* USER CODE BEGIN EXPORTED_VARIABLES */

/* USER CODE END EXPORTED_VARIABLES */
/**
  * @}
  */

/** @defgroup USBD_CUSTOM_HID_Private_FunctionPrototypes USBD_CUSTOM_HID_Private_FunctionPrototypes
  * @brief Private functions declaration.
  * @{
  */

static int8_t CUSTOM_HID_Init_FS(void);
static int8_t CUSTOM_HID_DeInit_FS(void);
static int8_t CUSTOM_HID_OutEvent_FS(uint8_t* buff);

/**
  * @}
  */

USBD_CUSTOM_HID_ItfTypeDef USBD_CustomHID_fops_FS =
{
  CUSTOM_HID_ReportDesc_FS,
  CUSTOM_HID_Init_FS,
  CUSTOM_HID_DeInit_FS,
  CUSTOM_HID_OutEvent_FS
};

/** @defgroup USBD_CUSTOM_HID_Private_Functions USBD_CUSTOM_HID_Private_Functions
  * @brief Private functions.
  * @{
  */

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_Init_FS(void)
{
  /* USER CODE BEGIN 4 */
  return (USBD_OK);
  /* USER CODE END 4 */
}

/**
  * @brief  DeInitializes the CUSTOM HID media low layer
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_DeInit_FS(void)
{
  /* USER CODE BEGIN 5 */
  return (USBD_OK);
  /* USER CODE END 5 */
}

/**
  * @brief  Manage the CUSTOM HID class events
  * @param  event_idx: Event index
  * @param  state: Event state
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
static int8_t CUSTOM_HID_OutEvent_FS(uint8_t* buff)
{
  /* USER CODE BEGIN 6 */

	// Read the first 8 bytes of buff
	uint8_t* byte0 = buff[0];
	uint8_t* byte1 = buff[1];
	uint8_t* byte2 = buff[2];
	uint8_t* byte3 = buff[3];
	uint8_t* byte4 = buff[4];
	uint8_t* byte5 = buff[5];
	uint8_t* byte6 = buff[6];
	uint8_t* byte7 = buff[7];
	uint8_t* byte8 = buff[8];


  /* Start next USB packet transfer once data processing is completed */
  if (USBD_CUSTOM_HID_ReceivePacket(&hUsbDeviceFS) != (uint8_t)USBD_OK)
  {
    return -1;
  }

  return (USBD_OK);
  /* USER CODE END 6 */
}

/* USER CODE BEGIN 7 */
/**
  * @brief  Send the report to the Host
  * @param  report: The report to be sent
  * @param  len: The report length
  * @retval USBD_OK if all operations are OK else USBD_FAIL
  */
/*
static int8_t USBD_CUSTOM_HID_SendReport_FS(uint8_t *report, uint16_t len)
{
  return USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, report, len);
}
*/
/* USER CODE END 7 */

/* USER CODE BEGIN PRIVATE_FUNCTIONS_IMPLEMENTATION */

/* USER CODE END PRIVATE_FUNCTIONS_IMPLEMENTATION */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

