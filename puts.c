#include <stdio.h>
#include <internal/syscall.h>

int puts(const char *str)
{

    int ret = write(__NR_write, str, strlen(str));
    ret = write(__NR_write, "\n", 1);

    if (ret < 0)
    {
        return -1;
    }
    return ret;
}