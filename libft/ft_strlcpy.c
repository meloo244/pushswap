
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (*(src + count))
		count++;
	if (dstsize != 0)
	{
		while ((*(src + i)) && i < (dstsize - 1))
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = 0;
	}
	return (count);
}
