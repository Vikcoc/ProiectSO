#include "../includes/alloc.h"

/*
 * Function: m_free
 * ----------------
 * Deallocates a block of memory previously returned by m_malloc, m_calloc or
 * m_realloc. If 'ptr' is NULL, nothing is done.
 *
 * ptr: Pointer to block previously returned by m_malloc, m_calloc or m_realloc
 *
 * return: No return value.
 *
 * Implementation: marks the block pointed to by 'ptr' as free and joins all
 *                 the adjacent free blocks into one free block with
 *                 'join_blocks'.
 */
void free (void *ptr)
{
    pthread_mutex_lock (&mem_mutex);
    mem_block *curr_block = mem_blocks_head;

    if (ptr == NULL)
    {
        pthread_mutex_unlock (&mem_mutex);
        return;
    }

    while (curr_block != NULL && ptr - sizeof (mem_block) != curr_block)
        curr_block = curr_block -> next;

    if (curr_block == NULL)
    {  
        pthread_mutex_unlock (&mem_mutex);
        return;
    }

    if (curr_block -> free == true)
    {
        pthread_mutex_unlock (&mem_mutex);
        return;
    }
    curr_block -> free = true;

    if (curr_block -> prev != NULL && curr_block -> prev -> free == true)
        curr_block = join_blocks (curr_block -> prev);

    if (curr_block -> next != NULL && curr_block -> next -> free == true)
        join_blocks (curr_block);

    pthread_mutex_unlock (&mem_mutex);
    return;
}
