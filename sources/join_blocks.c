#include "../includes/alloc.h"

/*
 * Function: join_blocks
 * ---------------------
 * Joins 'left_block' with the block to its right.
 *
 * 'left_block' should be a pointer previously returned by 'create_block'.
 *
 * left_blocks': One of the blocks which will be joined.
 *
 * return: The final block and NULL if the function failed.
 *
 * Implementation: Increases the size of 'left_block' to its current size plus
 *                 the total size of the block to its right and deletes the
 *                 block to its right from the 'mem_blocks' list.
 *
 *                 If 'left_block' is the last block in the list, NULL should be
 *                 returned.
 */
mem_block *join_blocks (mem_block *left_block)
{
    mem_block *right_block;

    if (left_block -> next == NULL)
        return (NULL);

    right_block = left_block -> next;
    if (mem_blocks_tail == right_block)
        mem_blocks_tail = left_block;

    left_block -> next  = right_block -> next;
    left_block -> size  = left_block -> size + right_block -> size + sizeof (mem_block);

    return (left_block);
}
