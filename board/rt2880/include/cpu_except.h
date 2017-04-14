
/******************************************************************************
 *
 * (c) Copyright 1996-2001, Palmchip Corporation
 *
 * This document is an unpublished work protected under the copyright laws
 * of the United States containing the confidential, proprietary and trade
 * secret information of Palmchip Corporation. This document may not be
 * copied or reproduced in any form whatsoever without the express written
 * permission of Palmchip Corporation.
 *
 ******************************************************************************
 *
 *  File Name: cpu_except.h
 *     Author: Linda Yang
 *
 ******************************************************************************
 *
 * Revision History:
 *
 *      Date    Name  Comments
 *    --------  ---   ------------------------------------
 *    12/08/00  LYT   Created.
 *    01/23/01  IST   Deprecated and removed unnecessary functionality.
 *
 *****************************************************************************/


/* FILE_DESC ******************************************************************
//
// Purpose:
//    This file contains headers for exception routines.
//
// Sp. Notes:
//
// ***************************************************************************/

#ifndef CPU_EXCEPT_H
#define CPU_EXCEPT_H

/*=====================*
 *  Include Files      *
 *=====================*/
#include "mem_map.h"


/*=====================*
 *  Defines            *
 *=====================*/
/* 
** If code is in rom, cannot write to the abort handler location.  This means
** that InstallExceptVec() will not work if given the address of the abort
** handler an argument.
** In this case, define the DATA_ABORT_VEC_LOC as the location of the
** bev0 general exception vector, which should always be writable.
** This means that, after InstallExceptVec() is called with DATA_ABORT_VEC_LOC
** as an argument, bev0 general exceptions will only be handled by the newly
** installed abort handler.
** If code is not in rom, the abort handler location is writable and should
** be used, so that the usual general exception processing is done.
*/
#ifdef CODE_IN_ROM
#define DATA_ABORT_VEC_LOC	EXCEPT_VEC_LOC
#else
#define DATA_ABORT_VEC_LOC	(AbortHandlerJump)
#endif


/*=====================*
 *  External Variables *
 *=====================*/
PUBLIC uint32 *AbortHandlerJump;


/*=====================*
 *  External Functions *
 *=====================*/
// This function is not required to be implemented for MIPS, but is used
// in the generic AVTS test files.
#define InstallIrqHandlers()


#endif /* CPU_EXCEPT_H */
