#include "../includes/alloc.h"

/*
 * Function: create_block
 * ----------------------
 * Creates a new block of 'size' bytes at the end of the mem_blocks list.
 *
 * size: Number of bytes in the new block.
 *
 * return: Pointer to the allocated block and NULL if block couldn't be created
 *
 * Implementation: Call sbrk to allocate new memory and append a new block at
 *                 the end of the list using 'mem_blocks_tail'.
 *
 *                 If memory sbrk failed, return NULL.
 */
mem_block *create_block (size_t size)
{
    mem_block   *new_block;
    mem_block   *old_tail = mem_blocks_tail;

    new_block = sbrk (size + sizeof (mem_block));
    if (new_block == (void*) - 1)
        return (NULL);

    if (mem_blocks_head == NULL)
        mem_blocks_head = new_block;
    else
        mem_blocks_tail -> next = new_block;

    mem_blocks_tail     = (mem_block*) new_block;
    new_block -> free   = false;
    new_block -> next   = NULL;
    new_block -> prev   = old_tail;
    new_block -> size   = size;

    return (new_block);
}
