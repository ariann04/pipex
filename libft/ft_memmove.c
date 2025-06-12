/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:37:20 by tblagoev          #+#    #+#             */
/*   Updated: 2023/09/14 20:28:43 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (d < s)
		while (len--)
			*d++ = *s++;
	else if (d > s)
	{
		d += len;
		s += len;
		while (len--)
			*(--d) = *(--s);
	}
	return (dst);
}

/*int	main()
{
	char arrayd[] = "holamundo";
	char arrays[] = "adios";

	void 	*ptr;
	const void *ptr2;

	ptr = &arrayd[0];
	ptr2 = &arrays[0];
	printf ("%s\n", ft_memmove(arrayd, arrays, 100));
	printf ("%s", ptr);
	return (0);
}*/
