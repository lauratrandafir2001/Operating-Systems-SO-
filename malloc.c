// // SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *new = (void *)mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	int ret = mem_list_add(new, size);
	return new;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	malloc(nmemb * size);
}

void free(void *ptr)
{
	/* TODO: Implement free(). */

	struct mem_list *st = mem_list_find(ptr);
	int len = st->len;
	mem_list_del(st);
	munmap(st, len);
}

void *realloc(void *ptr, size_t size)
{

	// /* TODO: Implement realloc(). */
	if (size == NULL)
	{
		free(ptr);
		return NULL;
	}

	if (ptr == NULL)
		return malloc(size);

	struct mem_list *st = mem_list_find(ptr);
	size_t copy_size;
	if (st->len > size)
	{
		copy_size = size;
	}
	if (st->len < size)
	{
		copy_size = st->len;
	}
	void *new_ptr = mremap(st, st->len, copy_size, 0);
	mem_list_del(st);
	int ret = mem_list_add(new_ptr, size);
	return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	// return realloc(ptr, nmemb * size);
}
