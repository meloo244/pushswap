

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	char			*dest_val;
	char			*src_val;

	dest_val = (char *)dest;
	src_val = (char *)src;
	if (len == 0)
		return (dest);
	if (src < dest)
	{
		while (len-- > 0)
		{
			dest_val[len] = src_val[len];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dest_val[i] = src_val[i];
			i++;
		}
	}
	return (dest);
}
