
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
*  File Name: mem_tst.h
*     Author: Linda Yang
*
*******************************************************************************
*
* Revision History:
*
*      Date    Name  Comments
*    --------  ---   ------------------------------------
*    03/14/00  LYT   Created from functions originally in mac_bufram.c.
*
*
*******************************************************************************/

/* FILE_DESC ******************************************************************/
//
// Purpose:
//    This file has all the definitions, enums, prototype for the different 
//    memory testing functions. 
//
// Sp. Notes:
//
/******************************************************************************/

#ifndef MEM_TST_H
#define MEM_TST_H

/*=====================*
 *  Include Files      *
 *=====================*/
#include "pubdefs.h"
#include "product.h"


/*=====================*
 *  Defines            *
 *=====================*/
/* Assert failure codes */
/* Only bits 0-3 of error used so that bits 4-7 can be used as a subTestNum */
#define MEM_ADDR_WRAP_1_FAILCODE		(0x1)
#define MEM_ADDR_WRAP_2_FAILCODE		(0x2)

#define MEM_BAD_WORD_WRITE_READ_FAILCODE	(0x3)
#define MEM_BAD_BYTE_READ_FAILCODE		(0x4)
#define MEM_BAD_HALFWORD_READ_1_FAILCODE	(0x5)
#define MEM_BAD_HALFWORD_READ_2_FAILCODE	(0x6)
#define MEM_BAD_BYTE_WRITE_FAILCODE		(0x7)
#define MEM_BAD_HALFWORD_WRITE_FAILCODE		(0x8)


/*=====================*
 *  External Variables *
 *=====================*/


/*=====================*
 *  External Functions *
 *=====================*/
PUBLIC uint32 GetDefaultWrapOffset(uint32 memSize);
PUBLIC uint8 CheckMemAddrWrap(uint32 Addr1, uint32 Addr2);
PUBLIC uint8 CheckMemAccess(uint32 Addr);



#endif /* MEM_TST_H */
