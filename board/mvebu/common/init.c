/*
 * ***************************************************************************
 * Copyright (C) 2015 Marvell International Ltd.
 * ***************************************************************************
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 2 of the License, or any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * ***************************************************************************
 */

/* #define DEBUG */

#include <common.h>
#include <malloc.h>
#include <errno.h>
#include <asm/io.h>
#include <linux/compiler.h>
#include <asm/arch-mvebu/soc.h>
#include <asm/arch-mvebu/pinctl.h>
#include <asm/arch-mvebu/mpp.h>
#include "board.h"
#ifdef CONFIG_DEVEL_BOARD
#include "devel-board.h"
#endif

DECLARE_GLOBAL_DATA_PTR;

struct mvebu_brd_fam *brd_fam;

#ifdef CONFIG_BOARD_LATE_INIT
int board_late_init(void)
{
	return 0;
}
#endif

int __soc_early_init_f(void)
{
	return 0;
}
int soc_early_init_f(void)
		__attribute__((weak, alias("__soc_early_init_f")));

#ifdef CONFIG_BOARD_EARLY_INIT_F
/* Do very basic stuff like board and soc detection */
int board_early_init_f(void)
{
	soc_early_init_f();
	return 0;
}
#endif

#ifdef CONFIG_MISC_INIT_R
int misc_init_r(void)
{
	/* Boot progress. */
#if 0
	/* Initialize special environment variables. */
	misc_init_r_env();

	/* CPU Init (part of it depends on env varisables. */
	mv_cpu_init();

	/* USB init (according to usbMode).
	** XOR init
	*/
	// ACS-TODO: Why do we need this?

	/* Boot Progress. */

	/* Print of MPP configuration and modules. */
	mvBoardMppModuleTypePrint();
	mvBoardOtherModuleTypePrint();

	/* Boot Progress. */

	/* Phy Initialization. */
	/* Init the PHY or Switch of the board */
	mvebu_board_phy_switch_init();
#endif
	return 0;
}
#endif


int mvebu_io_init(void)
{
	return 0;
}

int mvebu_print_info(char *board_name)
{
	printf("Board: %s\n", board_name);
	mvebu_print_soc_info();

	return 0;
}

int mvebu_board_init(void)
{
	int board_id;
	struct mvebu_board_family *brd_fam;
	struct mvebu_board_info *brd;

	debug("Initializing board\n");

#ifdef CONFIG_MVEBU_PINCTL
	mvebu_pinctl_probe();
#endif

	brd_fam = board_init_family();
	if (!brd_fam) {
		error("Failed to get board family structure");
		return 0;
	}

	set_board_family(board_init_family());

	/* Identify the specific board */
	board_id = board_get_id();
	if ((board_id < 0) || (board_id > brd_fam->board_cnt)) {
		error("Unidentified board id %d. Using default %d",
		      board_id, brd_fam->default_id);
		board_id = brd_fam->default_id;
	}

	brd_fam->curr_board = brd_fam->boards_info[board_id];
	brd = brd_fam->curr_board;

	mvebu_print_info(brd->name);

#ifdef CONFIG_MVEBU_MPP_BUS
	mpp_bus_probe();
#endif

#ifdef CONFIG_DEVEL_BOARD
	mvebu_devel_board_init(brd_fam);
#endif

	return 0;
}


int board_init(void)
{
	mvebu_soc_init();

	mvebu_board_init();

	mvebu_io_init();
	
	return 0;
}
