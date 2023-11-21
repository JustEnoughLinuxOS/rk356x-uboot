/*
 * (C) Copyright 2020 Hardkernel Co., Ltd
 * (C) Copyright 2023 David Barbion for Recalbox
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <command.h>
#include <adc.h>

#define check_range(min,max,val) (val > 0 && val > min && val < max ? 1 : 0)

int do_hwrev(cmd_tbl_t *cmdtp, int flag, int argc, char * const argv[])
{
	unsigned int hwrev_adc;

	if (adc_channel_single_shot("saradc", 1, &hwrev_adc)) {
		printf("board hw rev failed\n");
		return CMD_RET_FAILURE;
	}

	/* RG353P */
	if (check_range(822, 882, hwrev_adc)) {
		env_set("hwrev", "rg353p");
		env_set("fdtfile", "rk3566-rg353p-linux.dtb");
	}
        /* RG353M */
        else if (check_range(482, 542, hwrev_adc)) {
                env_set("hwrev", "rg353m");
                env_set("fdtfile", "rk3566-rg353m-linux.dtb");
        }
	/* RG353V */
	else if (check_range(670, 701, hwrev_adc)) {
		env_set("hwrev", "rg353v");
		env_set("fdtfile", "rk3566-rg353v-linux.dtb");
	}
        /* RG503 */
        else if (check_range(992, 1053, hwrev_adc)) {
                env_set("hwrev", "rg503");
                env_set("fdtfile", "rk3566-rg503-linux.dtb");
        }
	/* RK2023 */
        else if (check_range(630, 669, hwrev_adc)) {
                env_set("hwrev", "rk2023");
                env_set("fdtfile", "rk3566-rk2023-linux.dtb");
        }
        /* RGB30 */
        else if (check_range(371, 394, hwrev_adc)) {
                env_set("hwrev", "rgb30");
                env_set("fdtfile", "rk3566-rgb30-linux.dtb");
        }
	else { 
		env_set("hwrev", "unknown");
		env_set("fdtfile", "rk3566-rk2023-linux.dtb");
	}

	printf("adc0 (hw rev) %d\n", hwrev_adc);

	return CMD_RET_SUCCESS;
}

U_BOOT_CMD(
	hwrev, 1, 1, do_hwrev,
	"check hw revision of Rockchip device",
	""
);
