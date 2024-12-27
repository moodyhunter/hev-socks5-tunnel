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
#include "hev-config.h"
#include "hev-logger.h"
#include "hev-socks5-logger.h"
#include "hev-socks5-tunnel.h"

#include "hev-main.h"

#define WEAK __attribute__ ((weak))

int
hev_socks5_tunnel_main (int tun_fd)
{
    const char *pid_file;
    const char *log_file;
    int log_level;
    int nofile;
    int res;

    log_file = hev_config_get_misc_log_file ();
    log_level = hev_config_get_misc_log_level ();

    res = hev_logger_init (log_level, log_file);
    if (res < 0)
        return -2;

    res = hev_socks5_logger_init (log_level, log_file);
    if (res < 0)
        return -3;

    nofile = hev_config_get_misc_limit_nofile ();
    res = set_limit_nofile (nofile);
    if (res < 0)
        LOG_W ("set limit nofile");

    pid_file = hev_config_get_misc_pid_file ();
    if (pid_file)
        run_as_daemon (pid_file);

    res = hev_task_system_init ();
    if (res < 0)
        return -4;

    lwip_init ();

    res = hev_socks5_tunnel_init (tun_fd);
    if (res < 0)
        return -5;

    hev_socks5_tunnel_run ();

    hev_socks5_tunnel_fini ();
    hev_socks5_logger_fini ();
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
