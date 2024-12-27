/*
 ============================================================================
 Name        : hev-config.c
 Author      : hev <r@hev.cc>
 Copyright   : Copyright (c) 2019 - 2024 hev
 Description : Config
 ============================================================================
 */

#include <stdio.h>
#include <arpa/inet.h>
#include <lwip/tcp.h>

#include "hev-logger.h"
#include "hev-config.h"

static unsigned int tun_mtu = 8500;

static HevConfigServer srv;

static char log_file[1024];
static char pid_file[1024];
static int task_stack_size = 86016;
static int tcp_buffer_size = 65536;
static int connect_timeout = 5000;
static int read_write_timeout = 60000;
static int limit_nofile = 65535;
static int log_level = HEV_LOGGER_WARN;

unsigned int
hev_config_get_tunnel_mtu (void)
{
    return tun_mtu;
}

HevConfigServer *
hev_config_get_socks5_server (void)
{
    return &srv;
}

int
hev_config_get_misc_task_stack_size (void)
{
    return task_stack_size;
}

int
hev_config_get_misc_tcp_buffer_size (void)
{
    return tcp_buffer_size;
}

int
hev_config_get_misc_connect_timeout (void)
{
    return connect_timeout;
}

int
hev_config_get_misc_read_write_timeout (void)
{
    return read_write_timeout;
}

int
hev_config_get_misc_limit_nofile (void)
{
    return limit_nofile;
}

const char *
hev_config_get_misc_pid_file (void)
{
    if (!pid_file[0])
        return NULL;

    return pid_file;
}

const char *
hev_config_get_misc_log_file (void)
{
    if (!log_file[0])
        return "stderr";

    return log_file;
}

int
hev_config_get_misc_log_level (void)
{
    return log_level;
}
