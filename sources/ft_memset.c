#include "../includes/alloc.h"

/*
 * Function: ft_memset
 * -------------------
 * Set a number of bytes to a value in a memory location
 * 
 * s: Memory location to modify
 * 
 * c: Value of new memory
 * 
 * n: Number of bytes to modify
 * 
 * return: 's' is returned
 */ 
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *ptr;
	
	// write(1,"memset\n",7);
	ptr = (unsigned char *)s;
	while(n--)
	{
		// print_number (n);
    	// write(1,"   ayyyy\n",9);
		*ptr++ = (unsigned char)c;
	}
	return (s);
}