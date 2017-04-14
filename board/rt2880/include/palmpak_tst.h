
/******************************************************************************
*
* (c) Copyright 1996-2000, Palmchip Corporation
*
* This document is an unpublished work protected under the copyright laws
* of the United States containing the confidential, proprietary and trade
* secret information of Palmchip Corporation. This document may not be
* copied or reproduced in any form whatsoever without the express written
* permission of Palmchip Corporation.
*
*******************************************************************************
*
*  File Name: palmpak_tst.h
*     Author: Robin Bhagat 
*
*    Purpose: All the PalmPak ASIC test related definitions, externs, etc.
*
*  Sp. Notes:
*
*
*******************************************************************************
*
* Revision History:
*
*      Date    Name  Comments
*    --------  ---   ------------------------------------
*    08/11/97  RWB   Created.
*    09/14/99  MAS   Modified Functions for PalmBeach usage.
*    11/08/00  LRF   Modified functions to use LCD block independent 
*                    functions.
*
*
*
*******************************************************************************/

#ifndef PALMPAK_TST_H
#define PALMPAK_TST_H

/*=====================*
 *  Include Files      *
 *=====================*/
#include "lcd.h"
#include "mem_map.h"
#include "pio.h"
#include "pubdefs.h"
#include "sysc.h"


/*=====================*
 *  Defines            *
 *=====================*/

#define TIMEOUT_REG	((uint32)(PALMPAK_BASE + 0xFFFC))
#define timeout(uSec)	(*((uint32 *) TIMEOUT_REG)) = uSec;

#define TEST_PASS	((uint32)0xCAFECAFE)
#define TEST_FAIL	((uint32)0xBADDBEEF)
#define TEST_NA	        ((uint32)0xBAD0CAFE)
#define USE_DATA	((uint32)0x000000FF)


/* Macro to write to test status 2 register */
#define SetTestStat2(val)						\
do									\
{									\
    *(uint32 *)(TEST_RESULT2_REG) = (val);				\
} while (0)


/* These macros are wrappers for functions provided by palmpaklib.
** They will work for both hw simulation and target boards.
** In simulation, the test register will display 0xCAFECAFE for Pass,
** and 0xBADxxynn, where xx is the BlkNum set by SetBlockNumber()
** y is the TstNum set by SetTestNumber(), and nn is the error number.
*/

#define TestFailError(errNum)		Assert(FALSE, (errNum))

#define Assert(cond, code) 						\
{									\
if (!(cond))								\
  {									\
  AssertFunction( code ); /* Call Platform dependent routine */		\
  }									\
}

#define TestPass()		TestEnd(TEST_PASS, "TEST PASS")
#define TestFail()		TestEnd(TEST_FAIL, "TEST FAIL")
#define TestNotApplicable()	TestEnd(TEST_NA, "TEST NOT APPLICABLE")


/*=====================*
 *  External Variables *
 *=====================*/

/*=====================*
 *  External Functions *
 *=====================*/
PUBLIC void AssertFunction( uint32 subcode );
PUBLIC void TestEnd( uint32 teststatus, int8 * msg );
PUBLIC void SetBlockNumber( uint32 BlockNumber );
PUBLIC void SetTestNumber( uint32 TestNumber );
PUBLIC uint8 GetBlockNumber( void );
PUBLIC uint8 GetTestNumber( void );

PUBLIC void LcdClearLineLib( lcdRegs *lcdPtr, uint32 line );
PUBLIC void LcdPuthexLib( lcdRegs *lcdPtr, int8 hexchar );
PUBLIC void LcdPrintStringLib( lcdRegs *lcdPtr, const int8 *thestring );

#endif /* PALMPAK_TST_H */
