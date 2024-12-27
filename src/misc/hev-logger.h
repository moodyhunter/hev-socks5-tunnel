/*
 ============================================================================
 Name        : hev-logger.h
 Author      : hev <r@hev.cc>
 Copyright   : Copyright (c) 2019 - 2023 hev
 Description : Logger
 ============================================================================
 */

#ifndef __HEV_LOGGER_H__
#define __HEV_LOGGER_H__

void my_hev_logger_log (int x, ...);

#define LOG_D(fmt...) my_hev_logger_log (HEV_LOGGER_DEBUG, fmt)
#define LOG_I(fmt...) my_hev_logger_log (HEV_LOGGER_INFO, fmt)
#define LOG_W(fmt...) my_hev_logger_log (HEV_LOGGER_WARN, fmt)
#define LOG_E(fmt...) my_hev_logger_log (HEV_LOGGER_ERROR, fmt)

#define LOG_ON() 1
#define LOG_ON_D() 1
#define LOG_ON_I() 1
#define LOG_ON_W() 1
#define LOG_ON_E() 1

typedef enum
{
    HEV_LOGGER_DEBUG,
    HEV_LOGGER_INFO,
    HEV_LOGGER_WARN,
    HEV_LOGGER_ERROR,
    HEV_LOGGER_UNSET,
} HevLoggerLevel;

int hev_logger_init (HevLoggerLevel level, const char *path);
void hev_logger_fini (void);

int hev_logger_enabled (HevLoggerLevel level);
void hev_logger_log (HevLoggerLevel level, const char *fmt, ...);

#endif /* __HEV_LOGGER_H__ */
