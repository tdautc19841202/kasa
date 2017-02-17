/*
 * Filename : ar0130_pri.h
 *
 * History:
 *    2012/05/23 - [Long Zhao] Create
 *
 * Copyright (C) 2004-2013, Ambarella, Inc.
 *
 * All rights reserved. No Part of this file may be reproduced, stored
 * in a retrieval system, or transmitted, in any form, or by any means,
 * electronic, mechanical, photocopying, recording, or otherwise,
 * without the prior consent of Ambarella, Inc.
 *
 * This file is produced by perl.
 */
#ifndef __AR0130_PRI_H__
#define __AR0130_PRI_H__

#define AR0130_RESET_REGISTER				0x301A
#define AR0130_LINE_LENGTH_PCK				0x300C
#define AR0130_FRAME_LENGTH_LINES			0x300A
#define AR0130_Y_ADDR_START					0x3002
#define AR0130_X_ADDR_START					0x3004
#define AR0130_Y_ADDR_END					0x3006
#define AR0130_X_ADDR_END					0x3008
#define AR0130_Y_ODD_INC					0x30A6

#define AR0130_CHIP_VERSION_REG				0x3000
#define AR0130_COARSE_INTEGRATION_TIME		0x3012
#define AR0130_AE_CTRL_REG					0x3100
#define AR0130_DIGITAL_TEST					0x30B0
#define AR0130_GLOBAL_GAIN					0x305E

#define AR0130_VT_PIX_CLK_DIV				0x302A
#define AR0130_VT_SYS_CLK_DIV				0x302C
#define AR0130_PRE_PLL_CLK_DIV				0x302E
#define AR0130_PLL_MULTIPLIER				0x3030

/* AR0130 mirror mode */
#define AR0130_READ_MODE				0x3040
#define AR0130_H_MIRROR			(0x01 << 14)
#define AR0130_V_FLIP				(0x01 << 15)
#define AR0130_MIRROR_MASK			(AR0130_H_MIRROR + AR0130_V_FLIP)

#define AR0130_COLUMN_CORRECTION		(0x01 << 15)

#endif /* __AR0130_PRI_H__ */
