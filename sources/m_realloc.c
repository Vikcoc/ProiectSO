#include "../includes/alloc.h"

/*
 * Function: m_realloc
 * -------------------
 * Changes the size of the block pointed to by 'ptr' to 'new_size'.
 * Contents of the old memory block are moved to new block up to 'new_size'.
 * If 'new_size' is less than or equal to 0, NULL is returned.
 *
 * ptr: Pointer to block previously returned by m_malloc, m_calloc, m_realloc
 *      If 'ptr' is NULL, m_malloc is called.
 *
 * new_size: New size for the memory block, in bytes.
 *
 * return: Pointer to the new memory block and NULL if function failed.
 *
 * Implementation: If 'new_size' is smaller than the current size of the block,
 *                 the block's resized (and split) using 'resize_block'.
 *
 *                 Otherwise, if 'new_size' is bigger than the current size of
 *                 the block, we first check for a big enough free block to the
 *                 right of the current block. If it is found, the grow the
 *                 block using 'join_blocks' followed by 'resize_block'.
 *
 *                 If no such free block is found, we create a new block using
 *                 'create_block' and move the contents of the old block to the
 *                 new block.
 */
void *realloc (void *ptr, size_t new_size)
{
    pthread_mutex_lock (&mem_mutex);

    // write(1,"realloc\n",8);
    if (new_size < 1)
    {
        pthread_mutex_unlock (&mem_mutex);
        return (NULL);
    }
    
    if (ptr == NULL)
    {
        pthread_mutex_unlock (&mem_mutex);
        return (malloc (new_size));
    }

    new_size = (new_size + ALIGNMENT - 1) & (~(ALIGNMENT - 1));
    mem_block *ret_block = ((mem_block*) ptr) -1;

    mem_block *curr_block = mem_blocks_head;

    while (curr_block != NULL && ptr - sizeof (mem_block) != curr_block)
        curr_block = curr_block -> next;

    if (curr_block == NULL)
    {   
        pthread_mutex_unlock (&mem_mutex);
        return (NULL);
    }

    if(ret_block -> size == new_size)
    {
        pthread_mutex_unlock (&mem_mutex);
        return (ptr);
    }
    if(ret_block -> size > new_size)
    {
        ret_block = resize_block(ret_block, new_size);
        if(ret_block == NULL)
        {
            pthread_mutex_unlock (&mem_mutex);
            return (NULL);
        }

        pthread_mutex_unlock (&mem_mutex);
        return (ret_block + 1);
    }
    
    if(ret_block == mem_blocks_tail)
    {
        size_t temp = new_size - ret_block -> size;
        if(extend_block(ret_block,temp) == NULL)
        {
            pthread_mutex_unlock (&mem_mutex);
            return (NULL);
        }
        
        pthread_mutex_unlock (&mem_mutex);
        return (ret_block + 1);
    }

    if(ret_block -> next -> free && ret_block -> next -> size
        >= new_size - ret_block -> size)
    {
        ret_block = join_blocks (ret_block);
        if(ret_block == NULL)
        {
            pthread_mutex_unlock (&mem_mutex);
            return (NULL);
        }
        
        if(ret_block -> size == new_size)
        {
            pthread_mutex_unlock (&mem_mutex);
            return (ret_block);
        }

        ret_block = resize_block(ret_block,new_size);
        if(ret_block == NULL)
        {
            pthread_mutex_unlock (&mem_mutex);
            return (NULL);
        }
        
        pthread_mutex_unlock (&mem_mutex);
        return (ret_block);
    }

    pthread_mutex_unlock (&mem_mutex);
    void *ret2 = malloc(new_size);
    pthread_mutex_lock (&mem_mutex);
    if(ret2 == NULL)
    {
        pthread_mutex_unlock (&mem_mutex);
        return (NULL);
    }

    ft_memcpy(ret2, ptr, ret_block -> size);
    pthread_mutex_unlock (&mem_mutex);
    free (ptr);
    pthread_mutex_lock (&mem_mutex);
    pthread_mutex_unlock (&mem_mutex);
    return (ret2);
}
