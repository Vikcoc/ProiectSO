#include "../includes/alloc.h"

mem_block *add_in_flist (mem_block *curr_block)
{
    if(mem_blocks_fhead > curr_block)
    {
        curr_block -> fnext = mem_blocks_fhead;
        mem_blocks_fhead -> fprev = curr_block;
        mem_blocks_fhead = curr_block;
    }
    else
    {
    
        if(mem_blocks_fhead == NULL)
        {
            mem_blocks_fhead = curr_block;
            mem_blocks_ftail = curr_block;
        }
        else
        {
            mem_block* lib = mem_blocks_fhead;
            while (lib != NULL && lib -> fnext < curr_block)
                lib = lib -> fnext;
            if(lib == NULL)
            {
                curr_block -> fprev = mem_blocks_ftail;
                mem_blocks_ftail = curr_block;
                mem_blocks_ftail = curr_block;
            }
            else
            {
                curr_block -> fnext = lib -> fnext;
                curr_block -> fprev = lib;
                lib -> fnext = curr_block;
                curr_block -> fnext -> fprev = curr_block;
            }
        }
    }
    return (curr_block);
}

/*
 * Function: m_free
 * ----------------
 * Deallocates a block of memory previously returned by m_malloc, m_calloc or
 * m_realloc. If 'ptr' is NULL, nothing is done.
 *
 * ptr: Pointer to block previously returned by m_malloc, m_calloc or m_realloc
 *
 * return: No return value.
 *
 * Implementation: marks the block pointed to by 'ptr' as free and joins all
 *                 the adjacent free blocks into one free block with
 *                 'join_blocks'.
 */
void free (void *ptr)
{
    pthread_mutex_lock (&mem_mutex);

    mem_block *curr_block = mem_blocks_head;

    if (ptr == NULL)
    {
        pthread_mutex_unlock (&mem_mutex);
        return;
    }

    while (curr_block != NULL && ptr - sizeof (mem_block) != curr_block)
        curr_block = curr_block -> next;

    if (curr_block == NULL)
    {  
        pthread_mutex_unlock (&mem_mutex);
        return;
    }

    if (curr_block -> free == true)
    {
        pthread_mutex_unlock (&mem_mutex);
        return;
    }
    curr_block -> free = true;
    
    add_in_flist(curr_block);

    if (curr_block -> prev != NULL && curr_block -> prev -> free == true)
        curr_block = join_blocks (curr_block -> prev);

    if (curr_block -> next != NULL && curr_block -> next -> free == true)
        join_blocks (curr_block);

    pthread_mutex_unlock (&mem_mutex);
    return;
}
