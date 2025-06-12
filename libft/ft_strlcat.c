/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:54:25 by tblagoev          #+#    #+#             */
/*   Updated: 2023/09/27 18:35:00 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ret;
	size_t	i;

	i = 0;
	if (dstsize <= (size_t)ft_strlen(dst))
		return ((dstsize + ft_strlen(src)));
	while (*dst && i < dstsize)
	{
		dst++;
		i++;
	}
	ret = ft_strlcpy(dst, src, dstsize - i);
	return (ret + i);
}
/*int main()
{
    char destino[20] = "Hola, ";
    const char *origen = "mundo!";
    size_t copiados;

    printf("Contenido inicial de destino: %s\n", destino);

    copiados = ft_strlcat(destino, origen, 11);

    printf("Cadena copiada: %s\n", destino);
    printf("Longitud de la cadena copiada: %zu\n", copiados);

    return 0;
}*/
/*int	main()
{
		size_t	size = 14;
		char dst1[500] = "pqrs";
		char *src1 = strdup("abcdefghi");
		char dst2[500] = "pqrs";
		char *src2 = strdup("abcdefghi");

		size_t paco1 = ft_strlcat(dst1, src1, size);
		size_t paco2 = strlcat(dst2, src2, size);
		printf("paco 1: %zu\n", paco1);
		printf("paco 2: %zu\n", paco2);
		printf("dst1: %s\n", dst1);
		printf("dst2: %s\n", dst2);
		printf("len1 = %zu\n", ft_strlen(dst1));
		printf("len2 = %zu\n", ft_strlen(dst2));
}*/
