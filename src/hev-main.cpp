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

#include "hev-main.h"

extern "C" {

int
hev_socks5_tunnel_main (int tun_fd)
{
    int nofile;
    int res;

    res = hev_logger_init (HEV_LOGGER_DEBUG);
    if (res < 0)
        return -2;

    LOG_D ("socks5 tunnel start");

    nofile = hev_config.limit_nofile;
    res = set_limit_nofile (nofile);
    if (res < 0)
        LOG_W ("set limit nofile");

    res = hev_task_system_init ();
    if (res < 0)
        return -3;

    lwip_init ();

    res = hev_socks5_tunnel_init (tun_fd);
    if (res < 0)
        return -4;

    hev_socks5_tunnel_run ();

    hev_socks5_tunnel_fini ();
    hev_logger_fini ();
    hev_task_system_fini ();

    return 0;
}

void
hev_socks5_tunnel_quit (void)
{
    hev_socks5_tunnel_stop ();
}

int
main ()
{
    hev_socks5_tunnel_main (1);

    hev_socks5_tunnel_quit ();
}
}
