#include "../includes/alloc.h"
// #include <string.h>

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
void *calloc (size_t num, size_t size)
{
    pthread_mutex_lock (&mem_mutex);

    // write(1,"calloc\n",7);
    if(num < 1 || size < 1)
        return NULL;
    
    // write (1, "calling malloc: ", 16);
    pthread_mutex_unlock (&mem_mutex);
    mem_block *ret_block = (mem_block*) malloc(num * size);
    pthread_mutex_lock (&mem_mutex);
    if (ret_block == NULL)
    {
        pthread_mutex_unlock (&mem_mutex);
        return NULL;
    }
    
    // write(1,"starting memset\n",16);
    ft_memset(ret_block, 0, (ret_block - 1) -> size);
    pthread_mutex_unlock (&mem_mutex);
    return ret_block;
}
