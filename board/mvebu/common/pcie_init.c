/*
 * ***************************************************************************
 * Copyright (C) Marvell International Ltd. and its affiliates
 * ***************************************************************************
 * Marvell GPL License Option
 * If you received this File from Marvell, you may opt to use, redistribute
 * and/or modify this File in accordance with the terms and conditions of the
 * General Public License Version 2, June 1991 (the "GPL License"), a copy of
 * which is available along with the File in the license.txt file or by writing
 * to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 or on the worldwide web at http://www.gnu.org/licenses/gpl.txt.
 *
 * THE FILE IS DISTRIBUTED AS-IS, WITHOUT WARRANTY OF ANY KIND, AND THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE ARE
 * EXPRESSLY DISCLAIMED. The GPL License provides additional details about this
 * warranty disclaimer.
 * ***************************************************************************
 */

#include <common.h>
#include <errno.h>
#include <pci.h>
#include <asm/arch-mvebu/unit-info.h>
#include <asm/arch-mvebu/driver_interface.h>

void pci_init_board(void)
{
	int host_cnt = unit_info_get_count(PCIE_UNIT_ID);
	u16 active_mask = unit_info_get_mask(PCIE_UNIT_ID);
	int ep_mask = 0;

#ifdef CONFIG_MVEBU_PCI_EP
	/*
	 * Currently set all hosts as EP. In case we want to support
	 * mixed mode (RC & EP hosts) we need to define a way to
	 * select it per port
	 */
	ep_mask = active_mask;
#endif

	mvebu_pcie_init_board(host_cnt, active_mask, ep_mask);
}