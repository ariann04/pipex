/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:58:02 by tblagoev          #+#    #+#             */
/*   Updated: 2023/10/23 14:50:25 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char) c == 0)
		return ((char *)s);
	return (NULL);
}
/*int	main()
{
	char  array[] = "Tsvetelina";
	int	a = 'v';

	printf("%s\n", ft_strchr(array, a));
	printf("%s", strchr(array, a));
	return (0);
}*/
