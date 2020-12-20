#ifndef ALLOC_H
#define ALLOC_H

#include <unistd.h>

#include <stdio.h>  // DEBUG

#define bool char
#define true 1
#define false 0

#define ALIGNMENT 8

typedef struct
{
    void    *next;
    void    *prev;
    size_t  size;
    bool    free;
}   mem_block;

static mem_block *mem_blocks_head = NULL;
static mem_block *mem_blocks_tail = NULL;

void *m_malloc (size_t size);

void m_free (void *ptr);

void *m_realloc (void *ptr, size_t new_size);

void *m_calloc (size_t num, size_t size);

mem_block *find_free_block (size_t size);

mem_block *create_block (size_t size);

mem_block *resize_block (mem_block *block, size_t new_size);

mem_block *join_blocks (mem_block *left_block);

#endif //ALLOC_H