/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 03:48:08 by tblagoev          #+#    #+#             */
/*   Updated: 2023/10/11 00:08:44 by ls               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;

	result = malloc((ft_strlen(s) + 1) * sizeof(char));
	i = 0;
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*int main()
{
	char array[] = "Hola";
	char *solution = ft_strmapi(array, toggle_case);
	
	if (solution)
	{
		while (*solution)
		{
			printf("%c", *solution);
			solution++;
																			    
		}
		free(solution);
	}
	return (0);
}*/
