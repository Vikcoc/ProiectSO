#include "../includes/alloc.h"

mem_block       *mem_blocks_head    = NULL;
mem_block       *mem_blocks_tail    = NULL;
pthread_mutex_t mem_mutex           = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t write_mutex         = PTHREAD_MUTEX_INITIALIZER;

void print_number(unsigned long v)
{
    unsigned long a;
    a = 1;
    char b;
    while (v / a > 9)
        a = a * 10;
    b = v/a + '0';
    write(1,&b,1);
    while (a > 9)
    {
        b = (v%a)/(a/10)+'0';
        write(1,&b,1);
        a = a/10;
    }
}

void debug_print_blocks ()
{
    pthread_mutex_lock (&write_mutex);
    mem_block *curr_block = mem_blocks_head;

    write (1,"\nHead: ",8);
    // write (1,mem_blocks_head,4);
    print_number((unsigned long) mem_blocks_head);
    write (1,"\nTail: ",8);
    // write (1,mem_blocks_tail,4);
    print_number((unsigned long) mem_blocks_tail);
    write (1,"\n",2);
    while (curr_block != NULL)
    {
        write (1,"Block: status(",15);
        write(1,curr_block -> free ? "free" : "used",5);
        write(1,")\t",3);

        write(1,"size(",6);
        print_number(curr_block -> size);
        write(1,")\t",3);
        
        write(1,"location(",10);
        print_number((unsigned long) curr_block);
        write(1,")\t",3);

        write(1,"prev(",6);
        print_number((unsigned long) curr_block -> prev);
        write(1,")\t",3);

        write(1,"next(",6);
        print_number((unsigned long) curr_block -> next);
        write(1,")\n",3);
        // printf ("prev(%p)\t", curr_block -> prev);
        // printf ("next(%p)\n", curr_block -> next);
        // write (1,"\n",2);
        curr_block = curr_block -> next;
    }
    write (1,"\n",2);
    pthread_mutex_unlock (&write_mutex);
}


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

void *malloc (size_t size)
{
    pthread_mutex_lock (&mem_mutex);
    mem_block *ret_block;

    if (size <= 0)
    {
        pthread_mutex_unlock (&mem_mutex);
        return (NULL);
    }

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
        {
            pthread_mutex_unlock (&mem_mutex);
            return (NULL);
        }
    }

    pthread_mutex_unlock (&mem_mutex);
    return (ret_block + 1);
}
