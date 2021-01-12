#include "../includes/alloc.h"

/*
 * Function: resize_block
 * Resizes the 'block' to 'new_size'. Content of the block are left untouched
 * up to 'new_size'. If 'new_size' is bigger than or equal to the current size
 * of the block, block will be left untouched and NULL will be returned.
 *
 * 'block' should be a pointer previously returned by 'create_block'.
 *
 * block: Pointer to the block which was resized.
 *
 * new_size: New size of the block in bytes.
 *
 * return: Pointer to the block if 'new_size' is equal to or less than the size
 *         of the block. NULL will be returned if 'new_size' is greater than the
 *         size of the block.
 *
 * Implementation: Shrinks the 'block' to 'new_size'. A new free block should be
 *                 created to the right of 'block'.
 *
 *                 If old_size - new_size isn't enough to create a new block of
 *                 at least sizeof(mem_block) + ALIGNMENT, 'block' will be left
 *                 untouched.
 *
 *                 If block is split successfully, the free block generated in
 *                 the process should be joined with the block to its right if
 *                 that block is free.
 */
mem_block *resize_block (mem_block *block, size_t new_size)
{
    size_t free_block_size = (block -> size - new_size + ALIGNMENT - 1) & 
                                (~(ALIGNMENT - 1));

    if (block -> size == new_size || block -> size - new_size <= 
        free_block_size + sizeof(mem_block))
        return (block);

    if(block -> size < new_size)
        return (NULL);
    
    if (block -> size - new_size - sizeof(mem_block) <= 
        ((sizeof (mem_block) + ALIGNMENT - 1) & (~(ALIGNMENT - 1))))
        return (block);
    
    mem_block *blk  = (mem_block*) (((char*) block) + sizeof(mem_block)
                        + new_size);
    blk -> free     = false;
    blk -> prev     = block;
    blk -> next     = block -> next;
    block -> size   = new_size;
    blk -> size     = block -> size - new_size - sizeof(mem_block);
    // write (1, "\n\nBlock size: ", 14);
    // print_number (block -> size);
    // write (1, "\nNew size: ", 11);
    // print_number (new_size);
    // write (1, "\nFree block size: ", 18);
    // print_number (block -> size - new_size - sizeof(mem_block));
    block -> next   = blk;
    blk -> free = true;
    add_in_flist(blk);
    if(blk -> next != NULL)
    {
        blk -> next -> prev = blk;
        if(blk -> next -> free)
            join_blocks(blk);
    }
    else
        mem_blocks_tail = blk;
    
    return (block);
}
