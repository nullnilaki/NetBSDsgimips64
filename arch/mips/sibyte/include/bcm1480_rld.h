/*  *********************************************************************
    *  BCM1280/BCM1480 Board Support Package
    *
    *  Remote line directory constants and macros	File: bcm1480_rld.h
    *
    *  This module contains constants useful for manipulating the
    *  BCM1280/BCM1480 remote line directory (part of the node controller).
    *
    *  BCM1400 specification level:  1X55_1X80-UM100-D4 (11/24/03)
    *
    *********************************************************************
    *
    *  Copyright 2000,2001,2002,2003,2004
    *  Broadcom Corporation. All rights reserved.
    *
    *  This software is furnished under license and may be used and
    *  copied only in accordance with the following terms and
    *  conditions.  Subject to these conditions, you may download,
    *  copy, install, use, modify and distribute modified or unmodified
    *  copies of this software in source and/or binary form.  No title
    *  or ownership is transferred hereby.
    *
    *  1) Any source code used, modified or distributed must reproduce
    *     and retain this copyright notice and list of conditions
    *     as they appear in the source file.
    *
    *  2) No right is granted to use any trade name, trademark, or
    *     logo of Broadcom Corporation.  The "Broadcom Corporation"
    *     name may not be used to endorse or promote products derived
    *     from this software without the prior written permission of
    *     Broadcom Corporation.
    *
    *  3) THIS SOFTWARE IS PROVIDED "AS-IS" AND ANY EXPRESS OR
    *     IMPLIED WARRANTIES, INCLUDING BUT NOT LIMITED TO, ANY IMPLIED
    *     WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
    *     PURPOSE, OR NON-INFRINGEMENT ARE DISCLAIMED. IN NO EVENT
    *     SHALL BROADCOM BE LIABLE FOR ANY DAMAGES WHATSOEVER, AND IN
    *     PARTICULAR, BROADCOM SHALL NOT BE LIABLE FOR DIRECT, INDIRECT,
    *     INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    *     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
    *     GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
    *     BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
    *     OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
    *     TORT (INCLUDING NEGLIGENCE OR OTHERWISE), EVEN IF ADVISED OF
    *     THE POSSIBILITY OF SUCH DAMAGE.
    ********************************************************************* */

#ifndef _BCM1480_RLD_H
#define _BCM1480_RLD_H

#include "sb1250_defs.h"

/*
 * RLD Field Way Enable Register (Table 185)
 */

#define S_BCM1480_RLD_WAY_ENABLE            0
#define M_BCM1480_RLD_WAY_ENABLE            _SB_MAKEMASK(8,S_BCM1480_RLD_WAY_ENABLE)
#define V_BCM1480_RLD_WAY_ENABLE(x)         _SB_MAKEVALUE(x,S_BCM1480_RLD_WAY_ENABLE)
#define G_BCM1480_RLD_WAY_ENABLE(x)         _SB_GETVALUE(x,S_BCM1480_RLD_WAY_ENABLE,M_BCM1480_RLD_WAY_ENABLE)

/*
 * RLD Random LFSR Seed Register (Table 186)
 */

#define S_BCM1480_RLD_RANDOM_SEED           0
#define M_BCM1480_RLD_RANDOM_SEED           _SB_MAKEMASK(8,S_BCM1480_RLD_RANDOM_SEED)
#define V_BCM1480_RLD_RANDOM_SEED(x)        _SB_MAKEVALUE(x,S_BCM1480_RLD_RANDOM_SEED)
#define G_BCM1480_RLD_RANDOM_SEED(x)        _SB_GETVALUE(x,S_BCM1480_RLD_RANDOM_SEED,M_BCM1480_RLD_RANDOM_SEED)

/*
 * RLD Field Register (Table 187)
 */

#define S_BCM1480_RLD_FIELD_OFFSET          0
#define M_BCM1480_RLD_FIELD_OFFSET          _SB_MAKEMASK(5,S_BCM1480_RLD_FIELD_OFFSET)
#define V_BCM1480_RLD_FIELD_OFFSET(x)       _SB_MAKEVALUE(x,S_BCM1480_RLD_FIELD_OFFSET)
#define G_BCM1480_RLD_FIELD_OFFSET(x)       _SB_GETVALUE(x,S_BCM1480_RLD_FIELD_OFFSET,M_BCM1480_RLD_FIELD_OFFSET)

#define S_BCM1480_RLD_FIELD_INDEX           5
#define M_BCM1480_RLD_FIELD_INDEX           _SB_MAKEMASK(11,S_BCM1480_RLD_FIELD_INDEX)
#define V_BCM1480_RLD_FIELD_INDEX(x)        _SB_MAKEVALUE(x,S_BCM1480_RLD_FIELD_INDEX)
#define G_BCM1480_RLD_FIELD_INDEX(x)        _SB_GETVALUE(x,S_BCM1480_RLD_FIELD_INDEX,M_BCM1480_RLD_FIELD_INDEX)

#define S_BCM1480_RLD_FIELD_TAG             16
#define M_BCM1480_RLD_FIELD_TAG             _SB_MAKEMASK(20,S_BCM1480_RLD_FIELD_TAG)
#define V_BCM1480_RLD_FIELD_TAG(x)          _SB_MAKEVALUE(x,S_BCM1480_RLD_FIELD_TAG)
#define G_BCM1480_RLD_FIELD_TAG(x)          _SB_GETVALUE(x,S_BCM1480_RLD_FIELD_TAG,M_BCM1480_RLD_FIELD_TAG)

#define S_BCM1480_RLD_FIELD_WAY_SELECT      36
#define M_BCM1480_RLD_FIELD_WAY_SELECT      _SB_MAKEMASK(3,S_BCM1480_RLD_FIELD_WAY_SELECT)
#define V_BCM1480_RLD_FIELD_WAY_SELECT(x)   _SB_MAKEVALUE(x,S_BCM1480_RLD_FIELD_WAY_SELECT)
#define G_BCM1480_RLD_FIELD_WAY_SELECT(x)   _SB_GETVALUE(x,S_BCM1480_RLD_FIELD_WAY_SELECT,M_BCM1480_RLD_FIELD_WAY_SELECT)

#define M_BCM1480_RLD_FIELD_VALID           _SB_MAKEMASK1(39)
#define M_BCM1480_RLD_FIELD_MODIFIED        _SB_MAKEMASK1(40)

#define S_BCM1480_RLD_FIELD_NODE_VECTOR     41
#define M_BCM1480_RLD_FIELD_NODE_VECTOR     _SB_MAKEMASK(11,S_BCM1480_RLD_FIELD_NODE_VECTOR)
#define V_BCM1480_RLD_FIELD_NODE_VECTOR(x)  _SB_MAKEVALUE(x,S_BCM1480_RLD_FIELD_NODE_VECTOR)
#define G_BCM1480_RLD_FIELD_NODE_VECTOR(x)  _SB_GETVALUE(x,S_BCM1480_RLD_FIELD_NODE_VECTOR,M_BCM1480_RLD_FIELD_NODE_VECTOR)

#define S_BCM1480_RLD_FIELD_ECC_BITS        52
#define M_BCM1480_RLD_FIELD_ECC_BITS        _SB_MAKEMASK(7,S_BCM1480_RLD_FIELD_ECC_BITS)
#define V_BCM1480_RLD_FIELD_ECC_BITS(x)     _SB_MAKEVALUE(x,S_BCM1480_RLD_FIELD_ECC_BITS)
#define G_BCM1480_RLD_FIELD_ECC_BITS(x)     _SB_GETVALUE(x,S_BCM1480_RLD_FIELD_ECC_BITS,M_BCM1480_RLD_FIELD_ECC_BITS)

#define M_BCM1480_RLD_FIELD_NEW_ECC         _SB_MAKEMASK1(59)
#define M_BCM1480_RLD_FIELD_CHECK_ECC       _SB_MAKEMASK1(60)

/*
 * RLD Trigger Register (Table 188)
 */

#define S_BCM1480_RLD_TRIGGER_TAG           0
#define M_BCM1480_RLD_TRIGGER_TAG           _SB_MAKEMASK(20,S_BCM1480_RLD_TRIGGER_TAG)
#define V_BCM1480_RLD_TRIGGER_TAG(x)        _SB_MAKEVALUE(x,S_BCM1480_RLD_TRIGGER_TAG)
#define G_BCM1480_RLD_TRIGGER_TAG(x)        _SB_GETVALUE(x,S_BCM1480_RLD_TRIGGER_TAG,M_BCM1480_RLD_TRIGGER_TAG)

#define M_BCM1480_RLD_TRIGGER_VALID         _SB_MAKEMASK1(20)
#define M_BCM1480_RLD_TRIGGER_MODIFIED      _SB_MAKEMASK1(21)

#define S_BCM1480_RLD_TRIGGER_NODE_VECTOR   22
#define M_BCM1480_RLD_TRIGGER_NODE_VECTOR   _SB_MAKEMASK(11,S_BCM1480_RLD_TRIGGER_NODE_VECTOR)
#define V_BCM1480_RLD_TRIGGER_NODE_VECTOR(x) _SB_MAKEVALUE(x,S_BCM1480_RLD_TRIGGER_NODE_VECTOR)
#define G_BCM1480_RLD_TRIGGER_NODE_VECTOR(x) _SB_GETVALUE(x,S_BCM1480_RLD_TRIGGER_NODE_VECTOR,M_BCM1480_RLD_TRIGGER_NODE_VECTOR)

#define S_BCM1480_RLD_TRIGGER_ECC_BITS      33
#define M_BCM1480_RLD_TRIGGER_ECC_BITS      _SB_MAKEMASK(7,S_BCM1480_RLD_TRIGGER_ECC_BITS)
#define V_BCM1480_RLD_TRIGGER_ECC_BITS(x)   _SB_MAKEVALUE(x,S_BCM1480_RLD_TRIGGER_ECC_BITS)
#define G_BCM1480_RLD_TRIGGER_ECC_BITS(x)   _SB_GETVALUE(x,S_BCM1480_RLD_TRIGGER_ECC_BITS,M_BCM1480_RLD_TRIGGER_ECC_BITS)

#define M_BCM1480_RLD_TRIGGER_S_BERR        _SB_MAKEMASK1(40)
#define M_BCM1480_RLD_TRIGGER_D_BERR        _SB_MAKEMASK1(41)

/*
 * RLD Uncorrectable ECC Error Counter (Table 189)
 */

#define S_BCM1480_RLD_BAD_ECC               0
#define M_BCM1480_RLD_BAD_ECC               _SB_MAKEMASK(8,S_BCM1480_RLD_BAD_ECC)
#define V_BCM1480_RLD_BAD_ECC(x)            _SB_MAKEVALUE(x,S_BCM1480_RLD_BAD_ECC)
#define G_BCM1480_RLD_BAD_ECC(x)            _SB_GETVALUE(x,S_BCM1480_RLD_BAD_ECC,M_BCM1480_RLD_BAD_ECC)

/*
 * RLD Correctable ECC Error Counter (Table 190)
 */

#define S_BCM1480_RLD_COR_ERR               0
#define M_BCM1480_RLD_COR_ERR               _SB_MAKEMASK(8,S_BCM1480_RLD_COR_ERR)
#define V_BCM1480_RLD_COR_ERR(x)            _SB_MAKEVALUE(x,S_BCM1480_RLD_COR_ERR)
#define G_BCM1480_RLD_COR_ERR(x)            _SB_GETVALUE(x,S_BCM1480_RLD_COR_ERR,M_BCM1480_RLD_COR_ERR)

/*
 * RLD ECC Content Status Register (Table 191)
 */

#define S_BCM1480_RLD_ECC_CS_OFFSET         0
#define M_BCM1480_RLD_ECC_CS_OFFSET         _SB_MAKEMASK(5,S_BCM1480_RLD_ECC_CS_OFFSET)
#define V_BCM1480_RLD_ECC_CS_OFFSET(x)      _SB_MAKEVALUE(x,S_BCM1480_RLD_ECC_CS_OFFSET)
#define G_BCM1480_RLD_ECC_CS_OFFSET(x)      _SB_GETVALUE(x,S_BCM1480_RLD_ECC_CS_OFFSET,M_BCM1480_RLD_ECC_CS_OFFSET)

#define S_BCM1480_RLD_ECC_CS_INDEX          5
#define M_BCM1480_RLD_ECC_CS_INDEX          _SB_MAKEMASK(11,S_BCM1480_RLD_ECC_CS_INDEX)
#define V_BCM1480_RLD_ECC_CS_INDEX(x)       _SB_MAKEVALUE(x,S_BCM1480_RLD_ECC_CS_INDEX)
#define G_BCM1480_RLD_ECC_CS_INDEX(x)       _SB_GETVALUE(x,S_BCM1480_RLD_ECC_CS_INDEX,M_BCM1480_RLD_ECC_CS_INDEX)

#define S_BCM1480_RLD_ECC_CS_TAG            16
#define M_BCM1480_RLD_ECC_CS_TAG            _SB_MAKEMASK(20,S_BCM1480_RLD_ECC_CS_TAG)
#define V_BCM1480_RLD_ECC_CS_TAG(x)         _SB_MAKEVALUE(x,S_BCM1480_RLD_ECC_CS_TAG)
#define G_BCM1480_RLD_ECC_CS_TAG(x)         _SB_GETVALUE(x,S_BCM1480_RLD_ECC_CS_TAG,M_BCM1480_RLD_ECC_CS_TAG)

#define S_BCM1480_RLD_ECC_CS_WAY_SELECT     36
#define M_BCM1480_RLD_ECC_CS_WAY_SELECT     _SB_MAKEMASK(3,S_BCM1480_RLD_ECC_CS_WAY_SELECT)
#define V_BCM1480_RLD_ECC_CS_WAY_SELECT(x)  _SB_MAKEVALUE(x,S_BCM1480_RLD_ECC_CS_WAY_SELECT)
#define G_BCM1480_RLD_ECC_CS_WAY_SELECT(x)  _SB_GETVALUE(x,S_BCM1480_RLD_ECC_CS_WAY_SELECT,M_BCM1480_RLD_ECC_CS_WAY_SELECT)

#define M_BCM1480_RLD_ECC_CS_VALID          _SB_MAKEMASK1(39)
#define M_BCM1480_RLD_ECC_CS_MODIFIED       _SB_MAKEMASK1(40)

#define S_BCM1480_RLD_ECC_CS_NODE_VECTOR    41
#define M_BCM1480_RLD_ECC_CS_NODE_VECTOR    _SB_MAKEMASK(11,S_BCM1480_RLD_ECC_CS_NODE_VECTOR)
#define V_BCM1480_RLD_ECC_CS_NODE_VECTOR(x) _SB_MAKEVALUE(x,S_BCM1480_RLD_ECC_CS_NODE_VECTOR)
#define G_BCM1480_RLD_ECC_CS_NODE_VECTOR(x) _SB_GETVALUE(x,S_BCM1480_RLD_ECC_CS_NODE_VECTOR,M_BCM1480_RLD_ECC_CS_NODE_VECTOR)

#define S_BCM1480_RLD_ECC_CS_ECC_BITS       52
#define M_BCM1480_RLD_ECC_CS_ECC_BITS       _SB_MAKEMASK(7,S_BCM1480_RLD_ECC_CS_ECC_BITS)
#define V_BCM1480_RLD_ECC_CS_ECC_BITS(x)    _SB_MAKEVALUE(x,S_BCM1480_RLD_ECC_CS_ECC_BITS)
#define G_BCM1480_RLD_ECC_CS_ECC_BITS(x)    _SB_GETVALUE(x,S_BCM1480_RLD_ECC_CS_ECC_BITS,M_BCM1480_RLD_ECC_CS_ECC_BITS)

#define M_BCM1480_RLD_ECC_CS_SINGLE_BIT_ERR _SB_MAKEMASK1(59)
#define M_BCM1480_RLD_ECC_CS_DOUBLE_BIT_ERR _SB_MAKEMASK1(60)

#endif /* _BCM1480_BCM1480_RLD_H */
