#include "../includes/alloc.h"

/*
 * Function: extend_block
 * -------------------------
 * Extends the size of the given block by number of bytes
 *
 * size: The size to be extended by
 *
 * return: Pointer to the block if function succedes and NULL otherwise.
 *
 * Implementation: Check if the given block is the last block
 *                 Use sbrk to get more memory from system
 *                 Change the size of the block to the new size
 */
mem_block *extend_block (mem_block *block, size_t size)
{
    if(block != mem_blocks_tail || size < 1)
        return (NULL);
    
    if(sbrk(size) == (void*) - 1)
        return (NULL);
    
    block -> size = block -> size + size;
    return (block);
}