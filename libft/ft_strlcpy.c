/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarie <mmarie@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:47:55 by mmarie            #+#    #+#             */
/*   Updated: 2023/10/14 14:10:04 by mmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = ft_strlen(src);
	if (!dstsize)
		return (len);
	if (dstsize <= len)
		len = dstsize - 1;
	ft_memcpy(dst, src, len);
	dst[len] = '\0';
	return ((size_t)ft_strlen(src));
}
