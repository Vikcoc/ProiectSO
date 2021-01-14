#include "../includes/alloc.h"

pthread_mutex_t write_mutex = PTHREAD_MUTEX_INITIALIZER;

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
    print_number((unsigned long) mem_blocks_head);
    write (1,"\nTail: ",8);
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
        curr_block = curr_block -> next;
    }
    write (1,"\n",2);
    pthread_mutex_unlock (&write_mutex);
}
