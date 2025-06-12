/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:15:15 by tblagoev          #+#    #+#             */
/*   Updated: 2023/09/25 20:13:58 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*int	main()
{
	char array[142];

	ft_bzero(array, sizeof(array));

	for (size_t i = 0; i < sizeof(array); i++){
		printf("%d", (int)array[i]);
	}
	return (0);
}*/
