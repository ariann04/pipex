/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:21:06 by tblagoev          #+#    #+#             */
/*   Updated: 2023/10/11 03:47:34 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (unsigned char)c)
			return ((char *)s + len);
		len--;
	}
	if ((char)c == 0)
		return ((char *)s);
	return (NULL);
}

/*int	main()
{
	printf ("%s\n", ft_strrchr("caracola", 'c'));
	printf ("%s\n", strrchr("caracola", 'c'));
	return (0);
}*/
