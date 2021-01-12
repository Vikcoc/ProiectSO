#include "includes/alloc.h"

int main ()
{
    int *mems;

    mems = malloc (1000000 * sizeof (void*));
    int j = 0;

    for (int i = 0; i < 100; i++)
        for (size_t i = 1; i <= 9223372036854775807 / 2; i *= 2)
        {
            mems[j++] = malloc (i);
            realloc (mems[j], i + sizeof(int));
        }

    for (int i = j; i >= 0; i--)
        free (mems[j]);


    // j = 0;
    // for (size_t i = 1; i <= 2500000000; i *= 2)
    // {
    //     mems[j++] = calloc (1, i);
    // }

    // for (int i = j; i >= 0; i--)
    //     free (mems[j]);

    return (0);
}
