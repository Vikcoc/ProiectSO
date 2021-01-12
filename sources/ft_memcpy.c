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
void	*ft_memcpy(void *d, const void *s, size_t n)
{
	// void	*ptrd;

	// ptrd = d;
	// while(n--)
	// 	*(unsigned char *)ptrd = *(unsigned char *)s;
	// return (ptrd);

   char *csrc = (char *)s; 
   char *cdest = (char *)d; 
  
   // Copy contents of src[] to dest[] 
   for (size_t i = 0; i < n; i++) 
       cdest[i] = csrc[i];
	return (d);
}