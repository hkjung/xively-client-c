/* Copyright (c) 2003-2016, LogMeIn, Inc. All rights reserved.
 *
 * This is part of the Xively C Client library,
 * it is licensed under the BSD 3-Clause license.
 */

#include <xi_bsp_time.h>
#include "xi_bsp_time_stm32f4_nucleo_wifi_sntp.h"
#include "xi_debug.h"

extern uint32_t HAL_GetTick(void);

void xi_bsp_time_init()
{
    uint8_t sock_id = -1;
    sntp_sock_id_ptr = &sock_id;
    while( xi_bsp_time_sntp_init(&sock_id) < 0 )
    {
        xi_debug_printf("\r\n>>SNTP Failed. Retrying...");
    }
}

xi_time_t xi_bsp_time_getcurrenttime_seconds()
{
    return xi_bsp_time_sntp_getseconds_posix() + HAL_GetTick() / 1000;
}

xi_time_t xi_bsp_time_getcurrenttime_milliseconds()
{
    return xi_bsp_time_sntp_getseconds_posix() + HAL_GetTick() / 1000;
}
