/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef __TIME_H__
#define __TIME_H__
#define time_t long
struct timespec
{
    time_t tv_sec;
    long tv_nsec;
};

#ifdef __cplusplus
extern "C"
{
#endif

    unsigned int nanosleep(const struct timespec *__requested_time,
                           struct timespec *__remaining);
    unsigned int sleep(unsigned int seconds);
#ifdef __cplusplus
}
#endif

#endif