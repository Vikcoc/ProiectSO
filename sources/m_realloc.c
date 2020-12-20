#include "../includes/alloc.h"

/*
 * Function: m_realloc
 * -------------------
 * Changes the size of the block pointed to by 'ptr' to 'new_size'.
 * Contents of the old memory block are moved to new block up to 'new_size'.
 * If 'new_size' is less than or equal to 0, NULL is returned.
 *
 * ptr: Pointer to block previously returned by m_malloc, m_calloc, m_realloc
 *      If 'ptr' is NULL, m_malloc is called.
 *
 * new_size: New size for the memory block, in bytes.
 *
 * return: Pointer to the new memory block and NULL if function failed.
 *
 * Implementation: If 'new_size' is smaller than the current size of the block,
 *                 the block's resized (and split) using 'resize_block'.
 *
 *                 Otherwise, if 'new_size' is bigger than the current size of
 *                 the block, we first check for a big enough free block to the
 *                 right of the current block. If it is found, the grow the
 *                 block using 'join_blocks' followed by 'resize_block'.
 *
 *                 If no such free block is found, we create a new block using
 *                 'create_block' and move the contents of the old block to the
 *                 new block.
 */
void *m_realloc (void *ptr, size_t new_size)
{

}
