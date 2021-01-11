#ifndef ALLOC_H
#define ALLOC_H

#include <unistd.h>
#include <pthread.h>

#define bool char
#define true 1
#define false 0

#define ALIGNMENT 8

typedef struct mem_block
{
    struct mem_block    *next;
    struct mem_block    *prev;
    size_t              size;
    bool                free;
}   mem_block;

extern mem_block *mem_blocks_head;
extern mem_block *mem_blocks_tail;

extern pthread_mutex_t mem_mutex;

void *malloc (size_t size);

void free (void *ptr);

void *realloc (void *ptr, size_t new_size);

void *calloc (size_t num, size_t size);

mem_block *find_free_block (size_t size);

mem_block *create_block (size_t size);

mem_block *resize_block (mem_block *block, size_t new_size);

mem_block *join_blocks (mem_block *left_block);

mem_block *extend_block (mem_block *block, size_t size);

void *ft_memcpy(void *d, const void *s, size_t n);

void *ft_memset(void *s, int c, size_t n);

#endif //ALLOC_H
