/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fatoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailopez- <ailopez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:20:02 by ailopez-          #+#    #+#             */
/*   Updated: 2022/05/25 19:34:54 by ailopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "inc/ft_printf.h"

int	ft_uitoalen(char **s, unsigned int n)
{
	int		len;

	len = 0;
	if (n == 0)
		len = 2;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	len++;
	*s = malloc(len * sizeof(char));
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*chrnum;

	chrnum = NULL;
	len = ft_uitoalen(&chrnum, n);
	if (chrnum == NULL)
		return (NULL);
	if (n == 0)
		chrnum[0] = '0';
	chrnum[len - 1] = '\0';
	while (n)
	{
		chrnum[len - 2] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (chrnum);
}

int	ft_itoa_hex_len(char **s, unsigned long n)
{
	int		len;

	len = 0;
	if (n == 0)
		len = 2;
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	len++;
	*s = malloc(len * sizeof(char));
	return (len);
}

char	*ft_itoa_hex(unsigned long n)
{
	int			len;
	char		*chrnum;
	const char	hex[] = "123456789abcdef";

	chrnum = NULL;
	len = ft_itoa_hex_len(&chrnum, n);
	if (chrnum == NULL)
		return (NULL);
	if (n == 0)
		chrnum[0] = '0';
	chrnum[len - 1] = '\0';
	while (n)
	{
		chrnum[len - 2] = hex[(n % 16) - 1];
		n = n / 16;
		len--;
	}
	return (chrnum);
}
