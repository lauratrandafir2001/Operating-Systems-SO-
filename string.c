// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	if ((const char *)source == NULL)
	{
		return NULL;
	}
	int i = 0;
	while (source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	// Terminate destination string with '\0'
	destination[i] = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	if ((const char *)source == NULL)
	{
		return NULL;
	}
	if (len == 0)
	{
		return NULL;
	}
	size_t i;
	for (i = 0; i < len && source[i] != '\0'; i++)
	{
		destination[i] = source[i];
	}
	for (; i < len; i++)
	{
		destination[i] = '\0';
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	if ((const char *)source == NULL)
	{
		return NULL;
	}
	int dest_len = strlen(destination);
	int i;
	for (i = 0; source[i] != '\0'; i++)
	{
		destination[dest_len + i] = source[i];
	}
	destination[dest_len + i] = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	if ((const char *)source == NULL)
	{
		return NULL;
	}
	if (len == 0)
	{
		return NULL;
	}
	int dest_len = strlen(destination);
	int i;
	for (i = 0; i < len && source[i] != '\0'; i++)
	{
		destination[dest_len + i] = source[i];
	}
	destination[dest_len + i] = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	if (str1 == NULL || str2 == NULL)
	{
		return NULL;
	}
	int i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return str1[i] - str2[i];
		}
		i++;
	}
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	if (str1 == NULL || str2 == NULL)
	{
		return NULL;
	}
	int i = 0;
	while (i < len && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
		{
			return str1[i] - str2[i];
		}
		i++;
	}
	return 0;
}

size_t strlen(const char *str)
{
	int i = 0;
	size_t len = 0;
	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	return len;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */

	while (*str != '\0')
	{
		if (*str == c)
		{
			return (char *)str;
		}
		str++;
	}
	if (c == '\0')
	{
		return (char *)str;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */

	const char *last = NULL;
	while (*str != '\0')
	{
		if (*str == c)
		{
			last = str;
		}
		str++;
	}
	if (c == '\0')
	{
		return (char *)str;
	}
	return (char *)last;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */

	if (strlen(needle) == 0)
	{
		return (char *)haystack;
	}
	// look until you can't possibly find it
	for (size_t i = 0; i < strlen(haystack) - strlen(needle) + 1; i++)
	{
		if (strncmp(&haystack[i], needle, strlen(needle)) == 0)
		{
			return (char *)&haystack[i];
		}
	}

	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */

	if (strlen(needle) > strlen(haystack))
	{
		return NULL;
	}
	if (strlen(haystack) == 0)
	{
		return NULL;
	}

	const char *haystack_end = haystack + strlen(haystack) - strlen(needle);

	while (haystack_end >= haystack)
	{
		if (strncmp(haystack_end, needle, strlen(needle)) == 0)
		{
			return (char *)haystack_end;
		}
		haystack_end--;
	}

	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	if (source == NULL)
	{
		return NULL;
	}
	const char *src = (const char *)source;
	char *dest = (char *)destination;
	if ((const char *)source == NULL)
	{
		return NULL;
	}
	for (size_t i = 0; i < num; i++)
	{
		dest[i] = src[i];
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */

	const unsigned char *src = source;
	unsigned char *dest = destination;
	if ((const char *)source == NULL)
	{
		return NULL;
	}

	if (dest == src)
	{
		return dest;
	}

	if (dest < src)
	{
		for (size_t i = 0; i < num; i++)
		{
			dest[i] = src[i];
		}
	}
	else
	{
		for (size_t i = num; i > 0; i--)
		{
			dest[i - 1] = src[i - 1];
		}
	}

	return dest;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	char *src = (char *)ptr1;
	char *dest = (char *)ptr2;

	if (ptr1 == NULL || ptr2 == NULL)
	{
		return NULL;
	}

	// Copy content of src[] to dest[]
	for (size_t i = 0; i < num; i++)
		dest[i] = src[i];
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *src = (char *)source;
	for (size_t i = 0; i < num; i++)
		src[i] = (char)value;
	return source;
}
