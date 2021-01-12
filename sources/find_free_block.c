#include "../includes/alloc.h"

/*
 * Function: find_free_block
 * -------------------------
 * Finds a free block of at least the given 'size'
 *
 * size: Minimum size of the block being searched for.
 *
 * return: Pointer to a block if one such block exists and NULL otherwise.
 *
 * Implementation: Start from the head of the list and search for a free block
 *                 of size at least 'size'. If end of the list is reached
 *                 without finding such a block, return NULL. If a free block is
 *                 found, return it.
 *
 *                 Found block shouldn't be changed in the process, that is, we
 *                 shouldn't change its 'free' flag to false.
 */
mem_block *find_free_block (size_t size)
{
    mem_block *src = mem_blocks_fhead;

    while (src != NULL)
    {
        
        if (src -> free == true && src -> size >= size)
            return (src);

        src = src -> fnext;
    }

    // mem_block *src = mem_blocks_head;

    // while (src != NULL)
    // {
        
    //     if (src -> free == true && src -> size >= size)
    //         return (src);

    //     src = src -> next;
    // }

    return (NULL);
}
