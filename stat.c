// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <internal/syscall.h>
#include <stdio.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */

	int ret = syscall(__NR_stat, path, buf);
	if (ret < -1)
	{
		// error occurred
		errno = -ret;
		return -1;
	}
	return ret;
}
