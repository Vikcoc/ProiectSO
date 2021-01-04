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

	ptr = (unsigned char *)s;
	while(n--)
		*ptr++ = (unsigned char)c;
	return (s);
}