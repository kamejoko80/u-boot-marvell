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

#ifndef _MVEBU_COMMON_H_
#define _MVEBU_COMMON_H_

#include <asm/arch/regs-base.h>

/* Temp */
#define CONFIG_ADEC

/* Usefull Debug */
/* #define DEBUG */
#define CONFIG_BOOTSTAGE
#define CONFIG_BOOTSTAGE_REPORT
/* #define CONFIG_MVEBU_DEBUG_FUNC_IN_OUT */
/* #define CONFIG_MV_DEBUG_PUTS */

#define CONFIG_SYS_GENERIC_BOARD
#define CONFIG_ARMADA_8K_SOC_ID		8022

/* Global definitions */
#ifndef CONFIG_SYS_TEXT_BASE
#define CONFIG_SYS_TEXT_BASE            0x00000000
#endif
#define CONFIG_SYS_SDRAM_BASE           0x00000000
#define CONFIG_SYS_RESET_ADDRESS        0xffff0000
#define CONFIG_SYS_MALLOC_BASE          (CONFIG_SYS_TEXT_BASE + (3 << 20))  /* TEXT_BASE + 3M */
#define CONFIG_SYS_MALLOC_LEN           (1 << 20)    /* Reserve 1MB for malloc*/
#define CONFIG_NR_DRAM_BANKS		(4)
/* maybe need to set back to 0x7fff0 */
#define CONFIG_SYS_INIT_SP_ADDR         (CONFIG_SYS_TEXT_BASE + 0xFF0000)   /* End of 16M scrubbed by training in bootrom */
#define CONFIG_SYS_GBL_DATA_SIZE        128	/* Size in bytes reserved for init data */
#define CONFIG_SYS_MAXARGS		32	/* Max number of command argg */
#define CONFIG_UBOOT_SIZE		0x100000 /* 1MB */
#undef  CONFIG_USE_IRQ

/* Memory reserve */
#define CONFIG_UBOOT_MAX_MEM_SIZE	(3ll << 30)	/* Limit u-boot to 3GB */
#define MVEBU_IO_RESERVE_BASE		0xC0000000ll

/* memtest definition */
#define CONFIG_SYS_MEMTEST_START        (CONFIG_SYS_SDRAM_BASE)
#define CONFIG_SYS_MEMTEST_END          (CONFIG_SYS_SDRAM_BASE + 0x10000000)

/* Board init functions */
#define CONFIG_BOARD_EARLY_INIT_F	/* pre relloc board init */
#define CONFIG_MISC_INIT_R              /* post relloc board init */
#define CONFIG_BOARD_LATE_INIT		/* late  board init */
#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_ENV_OVERWRITE            /* allow to change env parameters */
#undef  CONFIG_WATCHDOG                 /* watchdog disabled */

/* SPL */
/* Common defines for SPL */
#define CONFIG_SPL_FRAMEWORK
#define CONFIG_SPL_LIBCOMMON_SUPPORT
#define CONFIG_SPL_LIBGENERIC_SUPPORT
#define CONFIG_SPL_SERIAL_SUPPORT

/* Cache */
#define CONFIG_SYS_DCACHE_OFF
#define CONFIG_SYS_CACHELINE_SIZE       32

/*
 * For booting Linux, the board info and command line data
 * have to be in the first 8 MB of memory, since this is
 * the maximum mapped by the Linux kernel during initialization.
 */
#define CONFIG_SYS_BOOTMAPSZ	(16 << 20)	/* Initial Memory map for Linux */
#define CONFIG_CMDLINE_TAG              1	/* enable passing of ATAGs  */
#define CONFIG_CMDLINE_EDITING          1
#define CONFIG_INITRD_TAG               1       /* enable INITRD tag for ramdisk data */
#define CONFIG_SETUP_MEMORY_TAGS        1
#define CONFIG_MARVELL_TAG
#define ATAG_MARVELL                    0x41000403
#define CONFIG_ZERO_BOOTDELAY_CHECK
#define CONFIG_SYS_LOAD_ADDR		0x02000000      /* default load address	*/
#define CONFIG_SYS_MIN_HDR_DEL_SIZE	0x100

/* Recovery */
#ifdef MV_INCLUDE_RCVR
#define CONFIG_CMD_RCVR
#define RCVR_IP_ADDR			"169.254.100.100"
#define RCVR_LOAD_ADDR			"0x02000000"
#endif /* MV_INCLUDE_RCVR */

/* Parser */
#define CONFIG_SILENT_CONSOLE
#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_AUTO_COMPLETE
#define CONFIG_SYS_PROMPT_HUSH_PS2      "> "
#define CONFIG_SYS_LONGHELP             /* undef to save memory	*/
#define CONFIG_SYS_PROMPT               "Marvell>> "  /* Command Prompt	*/
#define CONFIG_SYS_CBSIZE               1024          /* Console I/O Buffer Size */
#define CONFIG_SYS_PBSIZE               (CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)  /* Print Buffer Size */
#define CONFIG_LOADS_ECHO		0       /* Echo off for serial download */
#define CONFIG_SYS_CONSOLE_INFO_QUIET		/* Don't print In/Out/Err console assignment. */


/* Default Env vars */
#define CONFIG_SYS_BARGSIZE             CONFIG_SYS_CBSIZE       /* Boot Argument Buffer Size */
#define CONFIG_BOOTDELAY                3
#define CONFIG_ROOTPATH                 "/srv/nfs/"             /* Default Dir for NFS */
#define CONFIG_EXTRA_ENV_SETTINGS	"kernel_addr=0x200000\0"	\
					"initrd_addr=0xa00000\0"	\
					"initrd_size=0x2000000\0"	\
					"fdt_addr=0x100000\0"		\
					"fdt_high=0xa0000000\0"

#define CONFIG_BOOTARGS			"console=ttyS0,115200 earlyprintk root=/dev/ram0"
#define CONFIG_BOOTCOMMAND		"bootm $kernel_addr - $fdt_addr"

/* Marvell specific env*/
#define MV_BOOTARGS_END			":10.4.50.254:255.255.255.0:Marvell:eth0:none"
#define MV_BOOTARGS_END_SWITCH		":::Marvell:eth0:none"

/* U-Boot Commands */
/* #define CONFIG_BOOTP_MASK       (CONFIG_BOOTP_DEFAULT | CONFIG_BOOTP_BOOTFILESIZE) */
#define CONFIG_CMD_BSP		/* Enable board specfic commands */
#define CONFIG_CMD_ELF
#define CONFIG_CMD_STAGE_BOOT
#ifdef CONFIG_ARM64
#define CONFIG_CMD_BOOTI
#endif

/* Memory commands / tests. */
#ifdef CONFIG_CMD_MEMTEST
#define CONFIG_SYS_ALT_MEMTEST	/* More comprehensive mtest algorithm */
#endif


#if defined(CONFIG_ENV_IS_IN_BOOTDEV)
	#define CONFIG_ENV_IS_IN_SPI_FLASH
	#define CONFIG_ENV_IS_IN_NAND
	#define DEFAULT_BUBT_DST "spi"
	#define CONFIG_DOIMAGE_TYPE     "flash"
	#define CONFIG_DOIMAGE_SUFFIX   "dynamic"
#endif  /* CONIFG_ENV_IS_IN_BOOTDEV */


/* Flash env setup */
#if !defined(MV_INCLUDE_NOR) && !defined(CONFIG_MVEBU_NAND_BOOT) &&		\
	!defined(CONFIG_MVEBU_SPI_BOOT) && !defined(CONFIG_ENV_IS_IN_BOOTDEV)
	#undef CONFIG_CMD_FLASH
	#undef CONFIG_CMD_IMLS
	#define CONFIG_ENV_IS_NOWHERE
	#define CONFIG_ENV_SIZE		0x10000  /* environment takes one erase block */
	#define CONFIG_SYS_NO_FLASH
#else
	#define CONFIG_ENV_SECT_SIZE	0x10000
	#define CONFIG_ENV_SIZE		CONFIG_ENV_SECT_SIZE    /* environment takes one sector */
	#define CONFIG_ENV_OFFSET	CONFIG_UBOOT_SIZE
	#define CONFIG_ENV_ADDR		CONFIG_ENV_OFFSET

	/* TODO - Do we really need this */
	#define CONFIG_SYS_MONITOR_BASE	0
	#define CONFIG_SYS_MONITOR_LEN	0x80000  /* Reserve 512 kB for Monitor */

	#define CONFIG_MVEBU_DOIMAGE
#endif


/* Boot from NAND settings */
#if defined(CONFIG_MVEBU_NAND_BOOT) && !defined(CONFIG_ENV_IS_IN_BOOTDEV)
	#define CONFIG_ENV_IS_IN_NAND
	#define CONFIG_DOIMAGE_TYPE	"nand"
	#define CONFIG_DOIMAGE_SUFFIX	"nand"
#endif /* CONFIG_MVEBU_NAND_BOOT */

/* Boot from SPI settings */
#if defined(CONFIG_MVEBU_SPI_BOOT) && !defined(CONFIG_ENV_IS_IN_BOOTDEV)
	#define CONFIG_ENV_IS_IN_SPI_FLASH
	#define CONFIG_DOIMAGE_TYPE	"flash"
	#define CONFIG_DOIMAGE_SUFFIX	"spi"
#endif /* CONFIG_MVEBU_SPI_BOOT */


/* Generic Interrupt Controller Definitions */
#define GICD_BASE                       MVEBU_GICD_BASE
#define GICC_BASE                       MVEBU_GICC_BASE
#define GICR_BASE                       MVEBU_GICR_BASE

/* Flat Device Tree Definitions */
#define CONFIG_OF_LIBFDT

/* SMP Spin Table Definitions */
#define CPU_RELEASE_ADDR               (CONFIG_SYS_SDRAM_BASE + 0x2000000)

/* Exception level */
/* define CONFIG_ARMV8_SWITCH_TO_EL1 */

/*********  IO Definitions **********/

/* UART */
#ifdef CONFIG_SYS_NS16550
/* We keep the UART configuration in .h file, because the UART driver is basic driver for loading
 * U-Boot, if there any issue in the driver or in FDT getting values or maybe in the values
 * the U-Boot will stuck while loading it. For now we'll keep this defines here,
 * and we can later move them to Kconfig.
 */
	#define CONFIG_SYS_NS16550_SERIAL
	#define CONFIG_SYS_NS16550_MEM32
	#define CONFIG_SYS_NS16550_REG_SIZE	(-4)
	#define CONFIG_SYS_NS16550_COM1		MVEBU_UART_BASE(0)
	#define CONFIG_SYS_NS16550_CLK		200000000
	#define CONFIG_CONS_INDEX		1
	#define CONFIG_BAUDRATE			115200
	#define CONFIG_SYS_LOADS_BAUD_CHANGE	/* allow baudrate changes */
	/*#define CONFIG_SYS_DUART_CHAN		0*/
#endif /* CONFIG_SYS_NS16550 */


/* GPIO */
#ifdef MV_INCLUDE_GPIO
	#define CONFIG_KIRKWOOD_GPIO
#endif /* MV_INCLUDE_GPIO */

/* I2C */
#ifdef CONFIG_MVEBU_I2C
	#define CONFIG_SYS_I2C
	#define CONFIG_I2C_MULTI_BUS
	#define CONFIG_SYS_I2C_SPEED            100000  /* I2C speed default */
/*	#define CONFIG_CMD_EEPROM
	#define CONFIG_SYS_I2C_EEPROM_ADDR_LEN  1
	#define CONFIG_SYS_I2C_MULTI_EEPROMS
	#define CONFIG_SYS_I2C_SLAVE		0x0*/
#endif

/* RTC */
#if defined(MV_INCLUDE_RTC)
	#define CONFIG_CMD_DATE
	#define CONFIG_RTC_MVEBU
	#define CONFIG_SYS_NVRAM_SIZE  0x00                     /* dummy */
	#define CONFIG_SYS_NVRAM_BASE_ADDR DEVICE_CS1_BASE      /* dummy */
#endif

/* USB */
#ifdef MV_INCLUDE_USB
	#define CONFIG_CMD_USB
	#define CONFIG_USB_STORAGE
	#define CONFIG_USB_EHCI
	#define CONFIG_USB_EHCI_MARVELL
	#define CONFIG_EHCI_IS_TDI
	#define CONFIG_DOS_PARTITION
	#define CONFIG_ISO_PARTITION
	#define ENV_USB0_MODE   "host"
	#define ENV_USB1_MODE   "host"
	#define ENV_USB2_MODE   "device"
	#define ENV_USB_ACTIVE  "0"
#endif

/* MMC-SD */
#if MV_INCLUDE_SDIO
	#define  CONFIG_MMC
	#define  CONFIG_CMD_MMC
	#define  CONFIG_GENERIC_MMC
	#define  CONFIG_MRVL_MMC
	#define  CONFIG_SYS_MMC_BASE
	#define  CONFIG_SYS_MMC_MAX_DEVICE
#endif

/* PCI-E */
#if defined(CONFIG_MVEBU_PCI) || defined(CONFIG_MVEBU_DW_PCIE)
	#define CONFIG_PCI
	#define CONFIG_PCI_PNP  /* Enable plug-and-play */
	/*#define CONFIG_MVEBU_PCI_EP*/ /* Set PCI host as end point */

	/* Enable PCIE NIC for devel boards */
	#ifdef CONFIG_DEVEL_BOARD
		#define CONFIG_EEPRO100
		#define CONFIG_E1000
		#define CONFIG_MVEBU_NET
	#endif

#endif /* CONFIG_MVEBU_PCI */

/* Neta */
#ifdef CONFIG_MV_ETH_NETA
	#define CONFIG_MVEBU_NET
	#define MV_INCLUDE_GIG_ETH
	#define CONFIG_MV_INCLUDE_GIG_ETH
	#define MV_ETH_NETA
#endif /* CONFIG_MV_ETH_NETA */

/* General Networking */
#ifdef CONFIG_MVEBU_NET

	/* Environment */
	#define CONFIG_IPADDR           10.4.50.154
	#define CONFIG_SERVERIP         10.4.50.3
	#define CONFIG_NETMASK          255.255.255.0
	#define ETHADDR                 "00:00:00:00:51:81"
	#define ENV_ETH_PRIME           "e1000#0"

#endif /* CONFIG_MVEBU_NET */

/* SATA AHCI over PCIe */
#if defined(CONFIG_DEVEL_BOARD) && (defined(CONFIG_MVEBU_PCI) || defined(CONFIG_MVEBU_DW_PCIE))

	#define CONFIG_CMD_SCSI
	#define CONFIG_CMD_EXT2
	#define CONFIG_CMD_EXT4
	#define CONFIG_CMD_EXT4_WRITE
	#define CONFIG_CMD_JFFS2
	#define CONFIG_CMD_FAT

	#define CONFIG_EXT4_WRITE
	#define CONFIG_FS_FAT
	#define CONFIG_FS_EXT4
	#define CONFIG_SUPPORT_VFAT

	#undef CONFIG_MAC_PARTITION
	#define CONFIG_DOS_PARTITION
	#define CONFIG_EFI_PARTITION

	#define CONFIG_SYS_64BIT_LBA	/* Support disk over 2TB */
	#define CONFIG_LBA48

	#define __io
	#define CONFIG_LIBATA
	#define CONFIG_SCSI_AHCI
	#define CONFIG_SCSI_MAX_CONTROLLERS	2
	#define CONFIG_SYS_SCSI_MAX_SCSI_ID	(4 * CONFIG_SCSI_MAX_CONTROLLERS)
	#define CONFIG_SYS_SCSI_MAX_LUN		1
	#define CONFIG_SYS_SCSI_MAX_DEVICE	(CONFIG_SYS_SCSI_MAX_SCSI_ID * CONFIG_SYS_SCSI_MAX_LUN)

	/* Add support for Magni 9215 and Magni 9235 */
	#define CONFIG_SCSI_DEV_LIST		{ 0x1B4B, 0x9215 }, { 0x1B4B, 0x9235 }, { 0, 0 }
#endif

/* NAND */
#ifdef CONFIG_MVEBU_NAND
	#define CONFIG_NAND_PXA3XX
	#define CONFIG_SYS_MAX_NAND_DEVICE 1
	#define CONFIG_SYS_NAND_MAX_CHIPS 1
	#define CONFIG_SYS_NAND_SELF_INIT
	#define CONFIG_NAND_ECC_STRENGTH 4
	#define CONFIG_NAND_ECC_STEP_SIZE 512
#endif

/* SPI Flash */
#ifdef CONFIG_MVEBU_SPI
	#define CONFIG_SPI_FLASH
	#define CONFIG_SPI_FLASH_WINBOND
	#define CONFIG_SPI_FLASH_STMICRO
	#define CONFIG_SPI_FLASH_MACRONIX
	#define CONFIG_ENV_SPI_MAX_HZ           10000000        /*Max 50Mhz- will sattle on SPI bus max 41.5Mhz */
	#define CONFIG_ENV_SPI_CS               0
	#define CONFIG_ENV_SPI_BUS              0
	#define CONFIG_SPI_FLASH_BAR

	#ifndef CONFIG_SF_DEFAULT_SPEED
	#define CONFIG_SF_DEFAULT_SPEED        1000000
	#endif

	#ifndef CONFIG_SF_DEFAULT_MODE
	#define CONFIG_SF_DEFAULT_MODE         SPI_MODE_3
	#endif


#endif  /* MV_INCLUDE_SPI */


/* NOR Flash */
#ifdef MV_INCLUDE_NOR

	#define DEVICE_CS0_BASE NOR_CS_BASE
	#define DEVICE_CS0_SIZE NOR_CS_SIZE

	#define CONFIG_SYS_MAX_FLASH_BANKS              1

	#define CONFIG_SYS_FLASH_CFI
	#define CONFIG_SYS_FLASH_PROTECTION
	#define CONFIG_FLASH_CFI_DRIVER

	#define CONFIG_SYS_MAX_FLASH_SECT               128
	#define CONFIG_SYS_FLASH_BASE                   NOR_CS_BASE
	#define CONFIG_SYS_FLASH_CFI_WIDTH              FLASH_CFI_8BIT

	#define CONFIG_FLASH_SHOW_PROGRESS              1
	#define CONFIG_SYS_FLASH_EMPTY_INFO
	#define CONFIG_SYS_FLASH_USE_BUFFER_WRITE

	#define CONFIG_CMD_FLASH
	#undef  CONFIG_CMD_IMLS

	#if defined(MV_NOR_BOOT)
	#define CONFIG_ENV_IS_IN_FLASH
	#define CONFIG_ENV_SIZE                 0x10000
	#define CONFIG_ENV_SECT_SIZE            0x10000
	#define CONFIG_ENV_OFFSET               0x60000
	#define CONFIG_ENV_RANGE                CONFIG_ENV_SIZE * 8
	#define CONFIG_ENV_ADDR                 (NOR_CS_BASE + CONFIG_ENV_OFFSET)
	#define MONITOR_HEADER_LEN              0x200
	#define CONFIG_SYS_MONITOR_LEN          0x70000 /* 448 K */
	#define CONFIG_SYS_MONITOR_BASE		(0 + CONFIG_ENV_SECT_SIZE)
	#define CONFIG_SYS_MONITOR_END		(CONFIG_SYS_MONITOR_BASE + CONFIG_SYS_MONITOR_LEN)
	#endif /* MV_NOR_BOOT */
#else /* MV_INCLUDE_NOR */
	#define CONFIG_SYS_NO_FLASH
	#undef CONFIG_CMD_FLASH
	#undef CONFIG_CMD_IMLS
#endif


#endif /* _MVEBU_COMMON_H_ */