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

}
