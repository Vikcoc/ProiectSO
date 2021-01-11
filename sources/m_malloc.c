#include "../includes/alloc.h"

mem_block *mem_blocks_head = NULL;
mem_block *mem_blocks_tail = NULL;

/*
 * Function: m_malloc
 * ------------------
 * Allocates a new block of memory of 'size' bytes.
 *
 * size: Size of the memory block, in bytes
 *       NULL is returned if size <= 0.
 *
 * return: On success, a pointer to the block allocated by the function
 *         If the function failed, NULL is returned.
 *
 * Implementation: Should first look if a free, big enough block already exists
 *                 with 'find_free_block'. If no such block is found,
 *                 'create_block' should be called.
 *                 The size should be aligned to ALIGNMENT.
 *
 * Tip: Use 'size = (size + ALIGNMENT - 1) & (~(ALIGNMENT - 1))' to align size
 *      to ALIGNMENT.
 */

void *m_malloc (size_t size)
{
    mem_block *ret_block;

    if (size <= 0)
        return (NULL);

    size = (size + ALIGNMENT - 1) & (~(ALIGNMENT - 1));

    ret_block = find_free_block (size);
    if (ret_block != NULL)
    {
        ret_block -> free = false;
        ret_block = resize_block (ret_block, size);
    }
    else
    {
        ret_block = create_block (size);

        if (ret_block == NULL)
            return (NULL);
    }
    
    return (ret_block + 1);
}
