#include "../includes/alloc.h"

/*
 * Function: ft_memcpy
 * -------------------
 * Copies n bytes of memory from the sources to the destianation
 * 
 * d: Destination memory
 * 
 * s: Source memory
 * 
 * n: Number of bytes to copy
 * 
 * return: Destination is returned
 */
void	*ft_memcpy (void *d, const void *s, size_t n)
{
   char *source	= (char *)s; 
   char *dest	= (char *)d; 
  
   for (size_t i = 0; i < n; i++) 
       dest[i] = source[i];
	   
	return (d);
}