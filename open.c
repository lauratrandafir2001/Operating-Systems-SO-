// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	va_list valist;
	int a;
	if ((flags & O_CREAT) == O_CREAT)
	{
		va_start(valist, flags);
		a = va_arg(valist, int);
		va_end(valist);
	}

	int ret = syscall(__NR_open, filename, flags, a);
	if (ret < 0)
	{
		errno = -ret;
		return -1;
	}
	return ret;
}
