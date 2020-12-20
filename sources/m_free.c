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
void m_free (void *ptr)
{

}
