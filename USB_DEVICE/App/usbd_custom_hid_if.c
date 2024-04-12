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
//	0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
//	0x09, 0x05,                    // USAGE (Game Pad)
//	0xa1, 0x01,                    // COLLECTION (Application)
//		0x85, 0x01,						// REPORT_ID (1)
//		0x05, 0x09,                    //     USAGE_PAGE (Button)
//		0x19, 0x01,                    //     USAGE_MINIMUM (Button 1)
//		0x29, 0x03,                    //     USAGE_MAXIMUM (Button 3)
//		0x15, 0x00,                    //     LOGICAL_MINIMUM (0)
//		0x25, 0x01,                    //     LOGICAL_MAXIMUM (1)
//		0x95, 0x03,                    //     REPORT_COUNT (3)
//		0x75, 0x01,                    //     REPORT_SIZE (1)
//		0x81, 0x02,                    //     INPUT (Data,Var,Abs)
//		0x75, 0x05,                    //     REPORT_SIZE (5)
//		0x95, 0x01,                    //     REPORT_COUNT (1)
//		0x81, 0x03,                    //     INPUT (Cnst,Var,Abs)
//		0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
//		0x09, 0x32,                    // USAGE (Z)
//		0x15, 0x00,                    // LOGICAL_MINIMUM (0)
//		0x26, 0xFF, 0x0F,              // LOGICAL_MAXIMUM (4095)
//		0x95, 0x01,                    // REPORT_COUNT (1)
//		0x75, 0x0c,                    // REPORT_SIZE (12)
//		0x81, 0x02,                    // INPUT (Data,Var,Abs)
//		0x15, 0x00,                    // LOGICAL_MINIMUM (0)
//		0x25, 0x00,                    // LOGICAL_MAXIMUM (0)
//		0x75, 0x04,                    // REPORT_SIZE (4)
//		0x95, 0x01,                    // REPORT_COUNT (1)
//		0x81, 0x03,                    // INPUT (Cnst,Var,Abs)
//
//		0x09, 0x21,          // (LOCAL)  USAGE              0x000F0021 Set Effect Report (Logical Collection)
//		0x85, 0x03,          // (GLOBAL) REPORT_ID          0x03 (3)
//		0xA1, 0x02,          // (MAIN)   COLLECTION         0x02 Logical (Usage=0x000F0021: Page=Physical Interface Device Page, Usage=Set Effect Report, Type=Logical Collection)
//		0x09, 0x97,            // (LOCAL)  USAGE              0x000F0097 DC Enable Actuators (Selector)
//		0x15, 0x00,            // (GLOBAL) LOGICAL_MINIMUM    0x00 (0) <-- Redundant: LOGICAL_MINIMUM is already 0 <-- Info: Consider replacing 15 00 with 14
//		0x25, 0x01,            // (GLOBAL) LOGICAL_MAXIMUM    0x01 (1)
//		0x75, 0x04,            // (GLOBAL) REPORT_SIZE        0x04 (4) Number of bits per field
//		0x95, 0x01,            // (GLOBAL) REPORT_COUNT       0x01 (1) Number of fields <-- Redundant: REPORT_COUNT is already 1
//		0x91, 0x02,            // (MAIN)   OUTPUT             0x00000002 (1 field x 4 bits) 0=Data 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 0=NonVolatile 0=Bitmap
//		0x15, 0x00,            // (GLOBAL) LOGICAL_MINIMUM    0x00 (0) <-- Redundant: LOGICAL_MINIMUM is already 0 <-- Info: Consider replacing 15 00 with 14
//		0x25, 0x00,            // (GLOBAL) LOGICAL_MAXIMUM    0x00 (0)  <-- Info: Consider replacing 25 00 with 24
//		0x75, 0x04,            // (GLOBAL) REPORT_SIZE        0x04 (4) Number of bits per field <-- Redundant: REPORT_SIZE is already 4
//		0x95, 0x01,            // (GLOBAL) REPORT_COUNT       0x01 (1) Number of fields <-- Redundant: REPORT_COUNT is already 1
//		0x91, 0x03,            // (MAIN)   OUTPUT             0x00000003 (1 field x 4 bits) 1=Constant 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 0=NonVolatile 0=Bitmap
//		0x09, 0x70,            // (LOCAL)  USAGE              0x000F0070 Magnitude (Dynamic Value)
//		0x15, 0x00,            // (GLOBAL) LOGICAL_MINIMUM    0x00 (0) <-- Redundant: LOGICAL_MINIMUM is already 0 <-- Info: Consider replacing 15 00 with 14
//		0x25, 0x64,            // (GLOBAL) LOGICAL_MAXIMUM    0x64 (100)
//		0x75, 0x08,            // (GLOBAL) REPORT_SIZE        0x08 (8) Number of bits per field
//		0x95, 0x04,            // (GLOBAL) REPORT_COUNT       0x04 (4) Number of fields
//		0x91, 0x02,            // (MAIN)   OUTPUT             0x00000002 (4 fields x 8 bits) 0=Data 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 0=NonVolatile 0=Bitmap
//		0x09, 0x50,            // (LOCAL)  USAGE              0x000F0050 Duration (Dynamic Value)
//		0x66, 0x10, 0x10,          // (GLOBAL) UNIT               0x1001 Time in seconds [1 s units] (1=System=SI Linear, 1=Time=Seconds)
//		0x55, 0x0E,            // (GLOBAL) UNIT_EXPONENT      0x0E (Unit Value x 10�?�²)
//		0x15, 0x00,            // (GLOBAL) LOGICAL_MINIMUM    0x00 (0) <-- Redundant: LOGICAL_MINIMUM is already 0 <-- Info: Consider replacing 15 00 with 14
//		0x26, 0xFF, 0x00,          // (GLOBAL) LOGICAL_MAXIMUM    0x00FF (255)
//		0x75, 0x08,            // (GLOBAL) REPORT_SIZE        0x08 (8) Number of bits per field <-- Redundant: REPORT_SIZE is already 8
//		0x95, 0x01,            // (GLOBAL) REPORT_COUNT       0x01 (1) Number of fields
//		0x91, 0x02,            // (MAIN)   OUTPUT             0x00000002 (1 field x 8 bits) 0=Data 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 0=NonVolatile 0=Bitmap
//		0x09, 0xA7,            // (LOCAL)  USAGE              0x000F00A7 Start Delay (Dynamic Value)
//		0x15, 0x00,            // (GLOBAL) LOGICAL_MINIMUM    0x00 (0) <-- Redundant: LOGICAL_MINIMUM is already 0 <-- Info: Consider replacing 15 00 with 14
//		0x26, 0xFF, 0x00,          // (GLOBAL) LOGICAL_MAXIMUM    0x00FF (255) <-- Redundant: LOGICAL_MAXIMUM is already 255
//		0x75, 0x08,            // (GLOBAL) REPORT_SIZE        0x08 (8) Number of bits per field <-- Redundant: REPORT_SIZE is already 8
//		0x95, 0x01,            // (GLOBAL) REPORT_COUNT       0x01 (1) Number of fields <-- Redundant: REPORT_COUNT is already 1
//		0x91, 0x02,            // (MAIN)   OUTPUT             0x00000002 (1 field x 8 bits) 0=Data 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 0=NonVolatile 0=Bitmap
//		0x65, 0x00,            // (GLOBAL) UNIT               0x00 No unit (0=None)  <-- Info: Consider replacing 65 00 with 64
//		0x55, 0x00,            // (GLOBAL) UNIT_EXPONENT      0x00 (Unit Value x 10�?�)  <-- Info: Consider replacing 55 00 with 54
//		0x09, 0x7C,            // (LOCAL)  USAGE              0x000F007C Loop Count (Dynamic Value)
//		0x15, 0x00,            // (GLOBAL) LOGICAL_MINIMUM    0x00 (0) <-- Redundant: LOGICAL_MINIMUM is already 0 <-- Info: Consider replacing 15 00 with 14
//		0x26, 0xFF, 0x00,          // (GLOBAL) LOGICAL_MAXIMUM    0x00FF (255) <-- Redundant: LOGICAL_MAXIMUM is already 255
//		0x75, 0x08,            // (GLOBAL) REPORT_SIZE        0x08 (8) Number of bits per field <-- Redundant: REPORT_SIZE is already 8
//		0x95, 0x01,            // (GLOBAL) REPORT_COUNT       0x01 (1) Number of fields <-- Redundant: REPORT_COUNT is already 1
//		0x91, 0x02,            // (MAIN)   OUTPUT             0x00000002 (1 field x 8 bits) 0=Data 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 0=NonVolatile 0=Bitmap
//		0xC0,             // (MAIN)   END_COLLECTION     Logical

//		0x05, 0x0F,            		   // USAGE_PAGE  0x000F Physical Interface Device Page
//
//		// 55 bytes
//
//		// EFFECT REPORT
//		0x09, 0x21,					   // USAGE (Set Effect Report)
//		0xA1, 0x02,					   	// COLLECTION (Logical)
//			0x09, 0x22,						// USAGE (Effect Block Index)
//			0x25, 0x7F,						// LOGICAL_MAXIMUM (127)
//			0x75, 0x07,						// REPORT_SIZE (7)
//			0x95, 0x01,						// REPORT_COUNT (1)
//			0x91, 0x02,						// OUTPUT (Data,Var,Abs)
//			0x09, 0x24,						// USAGE (ROM Flag)
//			0x25, 0x01,						// LOGICAL_MAXIMUM (1)
//			0x75, 0x01,						// REPORT_SIZE (1)
//			0x91, 0x02,						// OUTPUT (Data,Var,Abs)
//			// EFFECT TYPE DEFINITION
//			0x09, 0x25, //USAGE (Effect Type)
//			0xA1, 0x02, //COLLECTION (Logical)
//				0x09, 0x26, //USAGE (ET Constant Force)
//				0x15, 0x01, //LOGICAL_MINIMUM (1)
//				0x25, 0x01, //LOGICAL_MAXIMUM (1)
//				0x75, 0x08, //REPORT_SIZE (8)
//				0x91, 0x00, //OUTPUT (Data,Ary,Abs)
//			0xC0, //END_COLLECTION
//
//			0x09, 0x50,			// USAGE (Duration)
//			0x09, 0x54,			// USAGE (Trigger Repeat Interval)
//			0x15, 0x00,			// LOGICAL_MINIMUM (0)
//			0x26, 0x10, 0x27,	// LOGICAL_MAXIMUM (10000)
//			0x46, 0x10, 0x27,	// PHYSICAL_MAXIMUM (10000)
//			0x75, 0x10,			// REPORT_SIZE (16)
//			0x66, 0x03, 0x10,	// UNIT (Eng Lin:Time)
//			0x55, 0x0D,			// UNIT_EXPONENT (-3)
//			0x95, 0x02,			// REPORT_COUNT (2)
//			0x91, 0x02,			// OUTPUT (Data,Var,Abs)
//			0x55, 0x0A,			// UNIT_EXPONENT (-6)
//			0x09, 0x51,			// USAGE (Sample Period)
//			0x95, 0x01,			// REPORT_COUNT (1)
//			0x91, 0x02,			// OUTPUT (Data,Var,Abs)
//			0x45, 0x00,			// PHYSICAL_MAXIMUM (0)
//			0x55, 0x00,			// UNIT_EXPONENT (0)
//			0x65, 0x00,			// UNIT (None)
//			0x09, 0x52,			// USAGE (Gain)
//			0x09, 0x53,			// USAGE (Trigger Button)
//			0x25, 0x7F,			// LOGICAL_MAXIMUM (127)
//			0x75, 0x08,			// REPORT_SIZE (8)
//			0x95, 0x02,			// REPORT_COUNT (2)
//			0x91, 0x02,			// OUTPUT (Data,Var,Abs)
//			0x05, 0x0F, // USAGE_PAGE (Physical Interface)
//			0x09, 0x58, // USAGE (Type Specific Block Offset)
//			0xA1, 0x02, // COLLECTION (Logical)
//				0x0B, 0x01, 0x00, 0x0A, 0x00, // USAGE (Ordinals:Instance 1)
//				0x0B, 0x02, 0x00, 0x0A, 0x00, // USAGE (Ordinals:Instance 2)
//				0x26, 0xFD, 0x7F, // LOGICAL_MAXIMUM (32765) ; 32K RAM or ROM max.
//				0x75, 0x10, // REPORT_SIZE (16)
//				0x95, 0x02, // REPORT_COUNT (2)
//				0x91, 0x02, // OUTPUT (Data,Var,Abs)
//			0xC0, // END_COLLECTION
//		0xC0, 				//END_COLLECTION
//
//		// ENVELOPE REPORT
//		0x09, 0x5A, 		// USAGE (Set Envelope Report)
//		0xA1, 0x02, 		// COLLECTION (Logical)
//			0x85, 0x02, 		// REPORT_ID (2)
//			0x09, 0x23, 		// USAGE (Parameter Block Offset)
//			0x26, 0xFD, 0x7F, 	// LOGICAL_MAXIMUM (32765) ; 32K RAM or ROM max
//			0x75, 0x0F,			// REPORT_SIZE (15)
//			0x95, 0x01, 		// REPORT_COUNT (1)
//			0x91, 0x02, 		// OUTPUT (Data,Var,Abs)
//			0x09, 0x24, 		// USAGE (ROM Flag)
//			0x25, 0x01, 		// LOGICAL_MAXIMUM (1)
//			0x75, 0x01, 		// REPORT_SIZE (1)
//			0x91, 0x02, 		// OUTPUT (Data,Var,Abs)
//			0x09, 0x5B, 		// USAGE (Attack Level)
//			0x09, 0x5D, 		// USAGE (Fade Level)
//			0x26, 0xFF, 0x00, 	// LOGICAL_MAXIMUM (255)
//			0x75, 0x08,			// REPORT_SIZE (8)
//			0x95, 0x02, 		// REPORT_COUNT (2)
//			0x91, 0x02, 		// OUTPUT (Data,Var,Abs)
//			0x09, 0x5C, 		// USAGE (Attack Time)
//			0x09, 0x5E, 		// USAGE (Fade Time)
//			0x26, 0x10, 0x27,	// LOGICAL_MAXIMUM (10000)
//			0x46, 0x10, 0x27, 	// PHYSICAL_MAXIMUM (10000)
//			0x66, 0x03, 0x10,	// UNIT (Eng Lin:Time)
//			0x55, 0x0D, 		// UNIT_EXPONENT (-3)
//			0x75, 0x10, 		// REPORT_SIZE (16)
//			0x91, 0x02, 		// OUTPUT (Data,Var,Abs)
//			0x45, 0x00, 		// PHYSICAL_MAXIMUM (0)
//			0x65, 0x00, 		// UNIT (None)
//			0x55, 0x00, 		// UNIT_EXPONENT (0)
//		0xC0, 				// END_COLLECTION
//
//		// CONSTANT FORCE REPORT
//		0x09, 0x73, 		// USAGE (Set Constant Force Report)
//		0xA1, 0x02,			// COLLECTION (Logical)
//			0x85, 0x03, 		// REPORT_ID (3)
//			0x09, 0x23, 		// USAGE (Parameter Block Offset)
//			0x26, 0xFD, 0x7F, 	// LOGICAL_MAXIMUM (32765)
//			0x75, 0x0F, 		// REPORT_SIZE (15)
//			0x95, 0x01, 		// REPORT_COUNT (1)
//			0x91, 0x02, 		// OUTPUT (Data,Var,Abs)
//			0x09, 0x24, 		// USAGE (ROM Flag)
//			0x25, 0x01, 		// LOGICAL_MAXIMUM (1)
//			0x75, 0x01, 		// REPORT_SIZE (1)
//			0x91, 0x02, 		// OUTPUT (Data,Var,Abs)
//			0x09, 0x70,			// USAGE (Magnitude)
//			0x26, 0xFF, 0x00, 	// LOGICAL_MAXIMUM (255)
//			0x75, 0x08, 		// REPORT_SIZE (8)
//			0x91, 0x02, 		// OUTPUT (Data,Var,Abs)
//		0xC0, 				// END_COLLECTION
//
//		//EFFECT OPERATION REPORT
//		0x09, 0x77, // USAGE (Effect Operation Report)
//		0xA1, 0x02, // COLLECTION (Logical)
//			0x85, 0x04, // REPORT_ID (4)
//			0x09, 0x22, // USAGE (Effect Block Index)
//			0x25, 0x7F, // LOGICAL_MAXIMUM (127)
//			0x75, 0x07, // REPORT_SIZE (7)
//			0x95, 0x01, // REPORT_COUNT (1)
//			0x91, 0x02, // OUTPUT (Data,Var,Abs)
//			0x09, 0x24, // USAGE (ROM Flag)
//			0x25, 0x01, // LOGICAL_MAXIMUM (1)
//			0x75, 0x01, // REPORT_SIZE (1)
//			0x91, 0x02, // OUTPUT (Data,Var,Abs)
//			0x09, 0x78, // USAGE (Effect Operation)
//			0xA1, 0x02, // COLLECTION (Logical)
//				0x09, 0x79, // USAGE (Op Effect Start)
//				0x09, 0x7A, // USAGE (Op Effect Start Solo)
//				0x09, 0x7B, // USAGE (Op Effect Stop)
//				0x15, 0x01, // LOGICAL_MINIMUM (1)
//				0x25, 0x03, // LOGICAL_MAXIMUM (3)
//				0x75, 0x08, // REPORT_SIZE (8)
//				0x91, 0x00, // OUTPUT (Data,Ary,Abs)
//			0xC0, // END_COLLECTION
//			0x09, 0x7C, // USAGE (Loop Count)
//			0x15, 0x00, // LOGICAL_MINIMUM (0)
//			0x26, 0xFF, 0x00, // LOGICAL_MAXIMUM (255)
//			0x91, 0x02, // OUTPUT (Data,Var,Abs)
//		0xC0, // END_COLLECTION
//
//		// PID POOL REPORT
//		0x09, 0x7F, // USAGE (PID Pool Report)
//		0xA1, 0x02, // COLLECTION (Logical)
//			0x85, 0x01, // REPORT_ID (1)
//			0x09, 0x80, // USAGE (RAM Pool Size)
//			0x09, 0x81, // USAGE (ROM Pool Size)
//			0x09, 0x82, // USAGE (ROM Effect Block Count)
//			0x26, 0xFD, 0x7F, // LOGICAL_MAXIMUM (32765)
//			0x95, 0x03, // REPORT_COUNT (3)
//			0x75, 0x10, // REPORT_SIZE (16)
//			0xB1, 0x02, // FEATURE (Data,Var,Abs)
//			0x09, 0xA8, // USAGE (Parameter Block Size)
//			0xA1, 0x02, // COLLECTION (Logical)
//				0x09, 0x21, // USAGE (Set Effect Report)
//				0x09, 0x5A, // USAGE (Set Envelope Report)
//				0x09, 0x73, // USAGE (Set Constant Force Report)
//				0x26, 0xFF, 0x00, // LOGICAL_MAXIMUM (255)
//				0x75, 0x08, // REPORT_SIZE (8)
//				0x95, 0x03, // REPORT_COUNT (3)
//				0xB1, 0x02, // FEATURE (Data,Var,Abs)
//			0xC0, // END_COLLECTION
//		0xC0, // END_COLLECTION
//
//		0x09, 0x92, // USAGE (PID State Report)
//		0xA1, 0x02, // COLLECTION (Logical)
//			0x85, 0x02, // REPORT_ID (2)
//			0x09, 0x22, // USAGE (Effect Block Index)
//			0x25, 0x7F, // LOGICAL_MAXIMUM (127)
//			0x75, 0x07, // REPORT_SIZE (7)
//			0x95, 0x01, // REPORT_COUNT (1)
//			0x81, 0x02, // INPUT (Data,Var,Abs)
//			0x09, 0x24, // USAGE (ROM Flag)
//			0x25, 0x01, // LOGICAL_MAXIMUM (1)
//			0x75, 0x01, // REPORT_SIZE (1)
//			0x95, 0x01, // REPORT_COUNT (1)
//			0x81, 0x02, // INPUT (Data,Var,Abs)
//			0x09, 0x94, // USAGE (Effect Playing)
//			0x09, 0xA0, // USAGE (Actuators Enabled)
//			0x09, 0xA4, // USAGE (Safety Switch)
//			0x09, 0xA6, // USAGE (Actuator Power)
//			0x75, 0x01, // REPORT_SIZE (1)
//			0x95, 0x04, // REPORT_COUNT (4)
//			0x81, 0x02, // INPUT (Data,Var,Abs)
//			0x81, 0x03, // INPUT (Cnst,Var,Abs) ; 4-bit pad
//		0xC0, // END_COLLECTION
//
//		// CONTROL REPORT
//		0x09, 0x95, // USAGE (PID Device Control Report)
//		0xA1, 0x02, // COLLECTION (Logical)
//			0x85, 0x05, // REPORT_ID (5)
//			0x09, 0x96, // USAGE (PID Device Control)
//			0xA1, 0x02, // COLLECTION (LOGICAL)
//				0x09, 0x97, // USAGE (DC Enable Actuators)
//				0x09, 0x98, // USAGE (DC Disable Actuators)
//				0x09, 0x99, // USAGE (DC Stop All Effects)
//				0x09, 0x9A, // USAGE (DC Reset)
//				0x09, 0x9B, // USAGE (DC Pause)
//				0x09, 0x9C, // USAGE (DC Continue)
//				0x15, 0x01, // LOGICAL_MINIMUM (1)
//				0x25, 0x06, // LOGICAL_MAXIMUM (6)
//				0x75, 0x01, // REPORT_SIZE (1)
//				0x95, 0x08, // REPORT_COUNT (4)
//				0x91, 0x02, // OUTPUT(Data,Ary,Abs)
//			0xC0, // END_COLLECTION
//		0xC0, // END_COLLECTION


		// Switch Controller Descriptor
		0x05, 0x01,        // (GLOBAL) USAGE_PAGE         0x0001 Generic Desktop Page
		0x15, 0x00,        // (GLOBAL) LOGICAL_MINIMUM    0x00 (0)  <-- Info: Consider replacing 15 00 with 14
		0x09, 0x04,        // (LOCAL)  USAGE              0x00010004 Joystick (Application Collection)
		0xA1, 0x01,        // (MAIN)   COLLECTION         0x01 Application (Usage=0x00010004: Page=Generic Desktop Page, Usage=Joystick, Type=Application Collection)
		0x85, 0x30,          // (GLOBAL) REPORT_ID          0x30 (48) '0'
		0x05, 0x01,          // (GLOBAL) USAGE_PAGE         0x0001 Generic Desktop Page <-- Redundant: USAGE_PAGE is already 0x0001
		0x05, 0x09,          // (GLOBAL) USAGE_PAGE         0x0009 Button Page
		0x19, 0x01,          // (LOCAL)  USAGE_MINIMUM      0x00090001 Button 1 Primary/trigger (Selector, On/Off Control, Momentary Control, or One Shot Control)
		0x29, 0x0A,          // (LOCAL)  USAGE_MAXIMUM      0x0009000A Button 10 (Selector, On/Off Control, Momentary Control, or One Shot Control)
		0x15, 0x00,          // (GLOBAL) LOGICAL_MINIMUM    0x00 (0) <-- Redundant: LOGICAL_MINIMUM is already 0 <-- Info: Consider replacing 15 00 with 14
		0x25, 0x01,          // (GLOBAL) LOGICAL_MAXIMUM    0x01 (1)
		0x75, 0x01,          // (GLOBAL) REPORT_SIZE        0x01 (1) Number of bits per field
		0x95, 0x0A,          // (GLOBAL) REPORT_COUNT       0x0A (10) Number of fields
		0x55, 0x00,          // (GLOBAL) UNIT_EXPONENT      0x00 (Unit Value x 10�?�) <-- Redundant: UNIT_EXPONENT is already 0 <-- Info: Consider replacing 55 00 with 54
		0x65, 0x00,          // (GLOBAL) UNIT               0x00 No unit (0=None) <-- Redundant: UNIT is already 0x00000000 <-- Info: Consider replacing 65 00 with 64
		0x81, 0x02,          // (MAIN)   INPUT              0x00000002 (10 fields x 1 bit) 0=Data 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 0=NonVolatile 0=Bitmap
		0x05, 0x09,          // (GLOBAL) USAGE_PAGE         0x0009 Button Page <-- Redundant: USAGE_PAGE is already 0x0009
		0x19, 0x0B,          // (LOCAL)  USAGE_MINIMUM      0x0009000B Button 11 (Selector, On/Off Control, Momentary Control, or One Shot Control)
		0x29, 0x0E,          // (LOCAL)  USAGE_MAXIMUM      0x0009000E Button 14 (Selector, On/Off Control, Momentary Control, or One Shot Control)
		0x15, 0x00,          // (GLOBAL) LOGICAL_MINIMUM    0x00 (0) <-- Redundant: LOGICAL_MINIMUM is already 0 <-- Info: Consider replacing 15 00 with 14
		0x25, 0x01,          // (GLOBAL) LOGICAL_MAXIMUM    0x01 (1) <-- Redundant: LOGICAL_MAXIMUM is already 1
		0x75, 0x01,          // (GLOBAL) REPORT_SIZE        0x01 (1) Number of bits per field <-- Redundant: REPORT_SIZE is already 1
		0x95, 0x04,          // (GLOBAL) REPORT_COUNT       0x04 (4) Number of fields
		0x81, 0x02,          // (MAIN)   INPUT              0x00000002 (4 fields x 1 bit) 0=Data 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 0=NonVolatile 0=Bitmap
		0x75, 0x01,          // (GLOBAL) REPORT_SIZE        0x01 (1) Number of bits per field <-- Redundant: REPORT_SIZE is already 1
		0x95, 0x02,          // (GLOBAL) REPORT_COUNT       0x02 (2) Number of fields
		0x81, 0x03,          // (MAIN)   INPUT              0x00000003 (2 fields x 1 bit) 1=Constant 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 0=NonVolatile 0=Bitmap
		0x0B, 0x01, 0x00, 0x01, 0x00,    // (LOCAL)  USAGE              0x00010001 Generic Desktop Page: Pointer (CP=Physical Collection)
		0xA1, 0x00,          // (MAIN)   COLLECTION         0x00 Physical (Usage=0x00010001: Page=Generic Desktop Page, Usage=Pointer, Type=Physical Collection)
		0x0B, 0x30, 0x00, 0x01, 0x00,      // (LOCAL)  USAGE              0x00010030 Generic Desktop Page: X (DV=Dynamic Value)
		0x0B, 0x31, 0x00, 0x01, 0x00,      // (LOCAL)  USAGE              0x00010031 Generic Desktop Page: Y (DV=Dynamic Value)
		0x0B, 0x32, 0x00, 0x01, 0x00,      // (LOCAL)  USAGE              0x00010032 Generic Desktop Page: Z (DV=Dynamic Value)
		0x0B, 0x35, 0x00, 0x01, 0x00,      // (LOCAL)  USAGE              0x00010035 Generic Desktop Page: Rz (DV=Dynamic Value)
		0x15, 0x00,            // (GLOBAL) LOGICAL_MINIMUM    0x00 (0) <-- Redundant: LOGICAL_MINIMUM is already 0 <-- Info: Consider replacing 15 00 with 14
		0x27, 0xFF, 0xFF, 0x00, 0x00,      // (GLOBAL) LOGICAL_MAXIMUM    0x0000FFFF (65535)
		0x75, 0x10,            // (GLOBAL) REPORT_SIZE        0x10 (16) Number of bits per field
		0x95, 0x04,            // (GLOBAL) REPORT_COUNT       0x04 (4) Number of fields
		0x81, 0x02,            // (MAIN)   INPUT              0x00000002 (4 fields x 16 bits) 0=Data 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 0=NonVolatile 0=Bitmap
		0xC0,             // (MAIN)   END_COLLECTION     Physical
		0x0B, 0x39, 0x00, 0x01, 0x00,    // (LOCAL)  USAGE              0x00010039 Generic Desktop Page: Hat switch (DV=Dynamic Value)
		0x15, 0x00,          // (GLOBAL) LOGICAL_MINIMUM    0x00 (0) <-- Redundant: LOGICAL_MINIMUM is already 0 <-- Info: Consider replacing 15 00 with 14
		0x25, 0x07,          // (GLOBAL) LOGICAL_MAXIMUM    0x07 (7)
		0x35, 0x00,          // (GLOBAL) PHYSICAL_MINIMUM   0x00 (0)  <-- Info: Consider replacing 35 00 with 34
		0x46, 0x3B, 0x01,        // (GLOBAL) PHYSICAL_MAXIMUM   0x013B (315)
		0x65, 0x14,          // (GLOBAL) UNIT               0x14 Rotation in degrees [1° units] (4=System=English Rotation, 1=Rotation=Degrees)
		0x75, 0x04,          // (GLOBAL) REPORT_SIZE        0x04 (4) Number of bits per field
		0x95, 0x01,          // (GLOBAL) REPORT_COUNT       0x01 (1) Number of fields
		0x81, 0x02,          // (MAIN)   INPUT              0x00000002 (1 field x 4 bits) 0=Data 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 0=NonVolatile 0=Bitmap
		0x05, 0x09,          // (GLOBAL) USAGE_PAGE         0x0009 Button Page <-- Redundant: USAGE_PAGE is already 0x0009
		0x19, 0x0F,          // (LOCAL)  USAGE_MINIMUM      0x0009000F Button 15 (Selector, On/Off Control, Momentary Control, or One Shot Control)
		0x29, 0x12,          // (LOCAL)  USAGE_MAXIMUM      0x00090012 Button 18 (Selector, On/Off Control, Momentary Control, or One Shot Control)
		0x15, 0x00,          // (GLOBAL) LOGICAL_MINIMUM    0x00 (0) <-- Redundant: LOGICAL_MINIMUM is already 0 <-- Info: Consider replacing 15 00 with 14
		0x25, 0x01,          // (GLOBAL) LOGICAL_MAXIMUM    0x01 (1)
		0x75, 0x01,          // (GLOBAL) REPORT_SIZE        0x01 (1) Number of bits per field
		0x95, 0x04,          // (GLOBAL) REPORT_COUNT       0x04 (4) Number of fields
		0x81, 0x02,          // (MAIN)   INPUT              0x00000002 (4 fields x 1 bit) 0=Data 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 0=NonVolatile 0=Bitmap
		0x75, 0x08,          // (GLOBAL) REPORT_SIZE        0x08 (8) Number of bits per field
		0x95, 0x34,          // (GLOBAL) REPORT_COUNT       0x34 (52) Number of fields
		0x81, 0x03,          // (MAIN)   INPUT              0x00000003 (52 fields x 8 bits) 1=Constant 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 0=NonVolatile 0=Bitmap
		0x06, 0x00, 0xFF,        // (GLOBAL) USAGE_PAGE         0xFF00 Vendor-defined
		0x85, 0x21,          // (GLOBAL) REPORT_ID          0x21 (33)
		0x09, 0x01,          // (LOCAL)  USAGE              0xFF000001 <-- Warning: Undocumented usage (document it by inserting 0001 into file FF00.conf)
		0x75, 0x08,          // (GLOBAL) REPORT_SIZE        0x08 (8) Number of bits per field <-- Redundant: REPORT_SIZE is already 8
		0x95, 0x3F,          // (GLOBAL) REPORT_COUNT       0x3F (63) Number of fields
		0x81, 0x03,          // (MAIN)   INPUT              0x00000003 (63 fields x 8 bits) 1=Constant 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 0=NonVolatile 0=Bitmap
		0x85, 0x81,          // (GLOBAL) REPORT_ID          0x81 (129)
		0x09, 0x02,          // (LOCAL)  USAGE              0xFF000002 <-- Warning: Undocumented usage (document it by inserting 0002 into file FF00.conf)
		0x75, 0x08,          // (GLOBAL) REPORT_SIZE        0x08 (8) Number of bits per field <-- Redundant: REPORT_SIZE is already 8
		0x95, 0x3F,          // (GLOBAL) REPORT_COUNT       0x3F (63) Number of fields <-- Redundant: REPORT_COUNT is already 63
		0x81, 0x03,          // (MAIN)   INPUT              0x00000003 (63 fields x 8 bits) 1=Constant 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 0=NonVolatile 0=Bitmap
		0x85, 0x01,          // (GLOBAL) REPORT_ID          0x01 (1)
		0x09, 0x03,          // (LOCAL)  USAGE              0xFF000003 <-- Warning: Undocumented usage (document it by inserting 0003 into file FF00.conf)
		0x75, 0x08,          // (GLOBAL) REPORT_SIZE        0x08 (8) Number of bits per field <-- Redundant: REPORT_SIZE is already 8
		0x95, 0x3F,          // (GLOBAL) REPORT_COUNT       0x3F (63) Number of fields <-- Redundant: REPORT_COUNT is already 63
		0x91, 0x83,          // (MAIN)   OUTPUT             0x00000083 (63 fields x 8 bits) 1=Constant 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 1=Volatile 0=Bitmap
		0x85, 0x10,          // (GLOBAL) REPORT_ID          0x10 (16)
		0x09, 0x04,          // (LOCAL)  USAGE              0xFF000004 <-- Warning: Undocumented usage (document it by inserting 0004 into file FF00.conf)
		0x75, 0x08,          // (GLOBAL) REPORT_SIZE        0x08 (8) Number of bits per field <-- Redundant: REPORT_SIZE is already 8
		0x95, 0x3F,          // (GLOBAL) REPORT_COUNT       0x3F (63) Number of fields <-- Redundant: REPORT_COUNT is already 63
		0x91, 0x83,          // (MAIN)   OUTPUT             0x00000083 (63 fields x 8 bits) 1=Constant 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 1=Volatile 0=Bitmap
		0x85, 0x80,          // (GLOBAL) REPORT_ID          0x80 (128)
		0x09, 0x05,          // (LOCAL)  USAGE              0xFF000005 <-- Warning: Undocumented usage (document it by inserting 0005 into file FF00.conf)
		0x75, 0x08,          // (GLOBAL) REPORT_SIZE        0x08 (8) Number of bits per field <-- Redundant: REPORT_SIZE is already 8
		0x95, 0x3F,          // (GLOBAL) REPORT_COUNT       0x3F (63) Number of fields <-- Redundant: REPORT_COUNT is already 63
		0x91, 0x83,          // (MAIN)   OUTPUT             0x00000083 (63 fields x 8 bits) 1=Constant 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 1=Volatile 0=Bitmap
		0x85, 0x82,          // (GLOBAL) REPORT_ID          0x82 (130)
		0x09, 0x06,          // (LOCAL)  USAGE              0xFF000006 <-- Warning: Undocumented usage (document it by inserting 0006 into file FF00.conf)
		0x75, 0x08,          // (GLOBAL) REPORT_SIZE        0x08 (8) Number of bits per field <-- Redundant: REPORT_SIZE is already 8
		0x95, 0x3F,          // (GLOBAL) REPORT_COUNT       0x3F (63) Number of fields <-- Redundant: REPORT_COUNT is already 63
		0x91, 0x83,          // (MAIN)   OUTPUT             0x00000083 (63 fields x 8 bits) 1=Constant 1=Variable 0=Absolute 0=NoWrap 0=Linear 0=PrefState 0=NoNull 1=Volatile 0=Bitmap
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
static int8_t CUSTOM_HID_OutEvent_FS(uint8_t event_idx, uint8_t state);

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
static int8_t CUSTOM_HID_OutEvent_FS(uint8_t event_idx, uint8_t state)
{
  /* USER CODE BEGIN 6 */
  HAL_GPIO_WritePin(GPIOC, LED0_Pin, GPIO_PIN_SET);
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

