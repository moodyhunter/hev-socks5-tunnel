/*
 ============================================================================
 Name        : hev-main.c
 Author      : hev <r@hev.cc>
 Copyright   : Copyright (c) 2019 - 2023 hev
 Description : Main
 ============================================================================
 */

#include <lwip/init.h>

#include <hev-task.h>
#include <hev-task-system.h>

#include "hev-utils.h"

#include "hev-logger.h"
#include "hev-socks5-tunnel.h"
#include <stdarg.h>

#include "hev-main.h"

extern "C" {

int
hev_socks5_tunnel_main (int tun_fd)
{
    LOG_D ("socks5 tunnel start");

    const auto nfiles = hev_config.limit_nofile;

    if (set_limit_nofile (nfiles) < 0)
        LOG_W ("set limit no.file");

    if (hev_task_system_init () < 0)
        return __COUNTER__;

    lwip_init ();

    if (hev_socks5_tunnel_init (tun_fd) < 0)
        return __COUNTER__;

    hev_socks5_tunnel_run ();

    hev_socks5_tunnel_fini ();
    hev_task_system_fini ();

    return 0;
}

void
hev_socks5_tunnel_quit (void)
{
    hev_socks5_tunnel_stop ();
}

void
hev_logger_log (HevLoggerLevel level, const char *fmt, ...)
{
    va_list list;
    va_start (list, fmt);
    hev_config.logging (level, fmt, list);
    va_end (list);
}
}
