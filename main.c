#include "includes/alloc.h"

void debug_print_blocks ()
{
    mem_block *curr_block = mem_blocks_head;

    printf ("\nHead: %p\nTail: %p\n", mem_blocks_head, mem_blocks_tail);
    while (curr_block != NULL)
    {
        printf ("Block: status(%s)\t",  curr_block -> free ? "free" : "used");
        printf ("size(%zu)\t", curr_block -> size);
        printf ("location(%p)\t", curr_block);
        printf ("prev(%p)\t", curr_block -> prev);
        printf ("next(%p)\n", curr_block -> next);
        curr_block = curr_block -> next;
    }
    printf ("\n");
}

int main ()
{
    return (0);
}
