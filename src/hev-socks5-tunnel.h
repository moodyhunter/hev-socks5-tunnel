/*
 ============================================================================
 Name        : hev-socks5-tunnel.h
 Author      : hev <r@hev.cc>
 Copyright   : Copyright (c) 2019 - 2023 hev
 Description : Socks5 Tunnel
 ============================================================================
 */

#ifndef __HEV_SOCKS5_TUNNEL_H__
#define __HEV_SOCKS5_TUNNEL_H__

#include "hev-task.h"
#include "hev-task-io.h"

#ifdef __cplusplus
extern "C" {
#endif

int hev_socks5_tunnel_init (int tun_fd);
void hev_socks5_tunnel_fini (void);

int hev_socks5_tunnel_run (void);
void hev_socks5_tunnel_stop (void);

static inline ssize_t
hev_tunnel_read (int fd, void *buf, size_t count, HevTaskIOYielder yielder,
                 void *yielder_data)
{
    return hev_task_io_read (fd, buf, count, yielder, yielder_data);
}

static inline ssize_t
hev_tunnel_readv (int fd, struct iovec *iov, int iovcnt,
                  HevTaskIOYielder yielder, void *yielder_data)
{
    return hev_task_io_readv (fd, &iov[1], iovcnt - 1, yielder, yielder_data);
}

static inline ssize_t
hev_tunnel_write (int fd, void *buf, size_t count, HevTaskIOYielder yielder,
                  void *yielder_data)
{
    return hev_task_io_write (fd, buf, count, yielder, yielder_data);
}

static inline ssize_t
hev_tunnel_writev (int fd, struct iovec *iov, int iovcnt,
                   HevTaskIOYielder yielder, void *yielder_data)
{
    return hev_task_io_writev (fd, &iov[1], iovcnt - 1, yielder, yielder_data);
}

#ifdef __cplusplus
}
#endif

#endif /* __HEV_SOCKS5_TUNNEL_H__ */
