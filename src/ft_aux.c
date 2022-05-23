/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorlopezdeaudicana <marvin@42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 00:17:14 by aitorlope         #+#    #+#             */
/*   Updated: 2022/05/24 00:29:45 by aitorlope        ###   ########.fr       */
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
