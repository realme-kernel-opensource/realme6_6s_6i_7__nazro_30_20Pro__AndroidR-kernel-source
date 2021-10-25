/*
 * Copyright (C) 2018 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */

#ifndef _MTK_BATTERY_H
#define _MTK_BATTERY_H

#ifndef _DEA_MODIFY_
#include <linux/list.h>
#include <linux/notifier.h>
#else
#include "simulator_kernel.h"
#endif


/* ============================================================ */
/* typedef */
/* ============================================================ */

/* coulomb service */
struct gauge_consumer {
	char *name;
	struct device *dev;
	long start;
	long end;
	int variable;

	int (*callback)(struct gauge_consumer *gc);
	struct list_head list;
};

extern void gauge_coulomb_service_init(void);
extern void gauge_coulomb_consumer_init(struct gauge_consumer *coulomb,
	struct device *dev, char *name);
extern void gauge_coulomb_start(struct gauge_consumer *coulomb, int car);
extern void gauge_coulomb_stop(struct gauge_consumer *coulomb);
extern void gauge_coulomb_dump_list(void);
extern void gauge_coulomb_before_reset(void);
extern void gauge_coulomb_after_reset(void);
extern void gauge_coulomb_set_log_level(int x);
/* coulomb sub system end */


/* battery notify charger_consumer */
enum {
	EVENT_BATTERY_PLUG_OUT,
};

extern int register_battery_notifier(struct notifier_block *nb);
extern int unregister_battery_notifier(struct notifier_block *nb);
/* battery notify charger_consumer end*/

#ifdef CONFIG_OPLUS_CHARGER_MTK6771
extern bool gauge_get_current(int *bat_current);
extern signed int battery_meter_get_battery_current(void);
extern bool battery_meter_get_battery_current_sign(void);
extern signed int battery_meter_get_charger_voltage(void);
#endif

/* battery common interface */
extern signed int battery_get_bat_voltage(void);
extern signed int battery_get_bat_current(void);
extern signed int battery_get_bat_current_mA(void);
extern signed int battery_get_soc(void);
extern signed int battery_get_uisoc(void);
extern signed int battery_get_bat_temperature(void);
extern signed int battery_get_ibus(void);
extern signed int battery_get_vbus(void);
extern signed int battery_get_bat_avg_current(void);

#ifdef CONFIG_OPLUS_CHARGER_MTK6769
/*Liu.Yong@RM.CM.BSP.CHG 2020/08/22, Add charger code*/
/* legacy API */
extern bool gauge_get_current(int *bat_current);
extern signed int battery_meter_get_battery_current(void);
extern bool battery_meter_get_battery_current_sign(void);
extern signed int battery_meter_get_charger_voltage(void);
#endif /*CONFIG_OPLUS_CHARGER_MTK6769*/

#endif /* End of _FUEL_GAUGE_GM_30_H */
