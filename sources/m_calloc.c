#include "../includes/alloc.h"

/*
 * Function: m_calloc
 * ------------------
 * Similar to m_malloc, but initializes new block with 0.
 * If either 'num' or 'size' is less than or equal to 0, NULL is returned.
 *
 * num: Number of elements to allocate.
 *
 * size: Size of each element.
 *
 * return: Pointer to new block of memory and NULL if function failed.
 *         If either 'num' or 'size is less than or equal to 0, NULL is
 *         returned.
 *
 * Implementation: m_malloc (num * size) is called. If m_malloc returns a value
 *                 other than NULL, all bytes of the new_block are set to 0.
 */
void *m_calloc (size_t num, size_t size)
{

}
