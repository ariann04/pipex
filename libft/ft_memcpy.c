/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:50:48 by tblagoev          #+#    #+#             */
/*   Updated: 2023/11/07 18:32:55 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	while (n--)
		*d++ = *s++;
	return (dst);
}

/*int	main()
{
	char arrayd[] = "hola";
	char arrays[] = "adios";
	void	*ptr;
	const void	*ptr2;

	ptr = &arrayd[0];
	ptr2 = &arrays[0];
	printf ("%s\n", ft_memcpy(ptr, ptr2, 8));
	printf ("%s", memcpy(ptr, ptr2 , 8));
	return (0);
}*/
