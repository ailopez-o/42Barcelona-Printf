/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorlopezdeaudicana <marvin@42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 00:17:14 by aitorlope         #+#    #+#             */
/*   Updated: 2022/05/25 19:39:26 by ailopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "inc/ft_printf.h"

char	*ft_fill_reverse(char *str, char c, int size)
{
	while (size > 0)
	{
		*str = c;
		str--;
		size--;
	}
	return (str);
}

int	ft_is_sign(t_params *params)
{
	return ((params->sign == '+' && params->positive) || \
		params->sign == '-' || params->gap);
}

void	ft_sign_print(char *str, t_params *params)
{
	if (ft_is_sign(params))
		*str = params->sign;
}

char	*ft_fill_str(int numsize, t_params *params)
{
	int		gap;
	char	*fill;
	char	*ptraux;

	if (params->precision > params->with)
		gap = params->precision + ft_is_sign(params) - numsize;
	else
		gap = params->with - numsize;
	fill = malloc((gap + 1) * sizeof(char));
	if (fill == NULL)
		return (NULL);
	if (params->precision > 0)
	{
		ft_memset(fill, ' ', gap);
		ptraux = ft_fill_reverse(fill + gap - 1, '0', \
				params->precision - numsize);
		ft_sign_print(ptraux, params);
	}
	else if (params->with > numsize)
	{
		ft_memset(fill, params->fill, gap);
		ft_sign_print(fill, params);
	}
	fill[gap + 1] = '\0';
	return (fill);
}

char	*ft_fill_nbr(char *num, t_params *params)
{
	char	*fill;

	if (params->gap && params->positive)
		params->gap = 0;
	if (params->gap && params->sign == '+')
		params->sign = ' ';
	fill = ft_strdup("");
	if ((params->precision > (int)ft_strlen(num)) || \
			params->with > (int)ft_strlen(num))
		fill = ft_fill_str(ft_strlen(num), params);
	else if (ft_is_sign(params))
		fill = ft_substr(&params->sign, 0, 1);
	return (fill);
}
/*
void	ft_print_params(t_params *params)
{
	printf("\nparams->fill [%c]\n", params->fill);
	printf("\nparams->gap  [%d]\n", params->gap);
	printf("\nparams->positive [%d]\n", params->positive);
	printf("\nparams->leftjustify [%d]\n", params->leftjustify);
	printf("\nparams->altformat [%d]\n", params->altformat);
	printf("\nparams->with [%d]\n", params->with);
	printf("\nparams->precision [%d]\n", params->precision);
}
*/
