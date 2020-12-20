#include "../includes/alloc.h"

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
 *                 The final size (not the one provided by the user) should
 *                 include the size of a mem_block and be aligned to ALIGNMENT.
 *
 * Tip: Use 'size = (size + sizeof (mem_block) + ALIGNMENT - 1) & (~(ALIGNMENT -
 *      1))' to make size include the size of a block meta data and align it to
 *      ALIGNMENT.
 */

void *m_malloc (size_t size)
{

}
