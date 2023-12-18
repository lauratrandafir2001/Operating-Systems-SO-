
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <internal/syscall.h>
#include <time.h>

unsigned int nanosleep(const struct timespec *__requested_time,
                       struct timespec *__remaining)
{

    /* TODO: Implement nano_sleep(). */

    int ret = syscall(__NR_nanosleep, __requested_time, __remaining);
    if (ret <= -1)
    {
        // error occurred
        errno = -ret;
        return -1;
    }
    return ret;
}