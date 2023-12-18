// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <errno.h>
#include <internal/syscall.h>
#include <stdio.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */

	int ret = syscall(__NR_fstat, fd, st);
	if (ret < -1)
	{
		// error occurred
		errno = -ret;
		return -1;
	}
	return ret;
}
