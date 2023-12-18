#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <internal/syscall.h>
#include <time.h>
#include <stdio.h>

unsigned int sleep(unsigned int seconds)
{
    /* TODO: Implement sleep(). */
    struct timespec tv;
    tv.tv_sec = seconds;
    tv.tv_nsec = 0;
    if (nanosleep(&tv, &tv))
        return tv.tv_sec;
    return 0;
}
