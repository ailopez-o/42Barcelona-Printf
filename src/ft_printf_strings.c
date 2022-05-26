/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailopez- <ailopez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:36:03 by ailopez-          #+#    #+#             */
/*   Updated: 2022/05/25 19:16:23 by ailopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/ft_printf.h"

int	ft_print_c(va_list	arg)
{
	int	c;

	c = va_arg(arg, int);
	write(1, &c, 1);	
	return (1);
}

int	ft_print_s(va_list arg, t_params *params)
{
	char	*toprint;

	toprint = va_arg(arg, char *);
	if (toprint == NULL)
	{
		write(1,"(null)", 6);
		return (6);
	}
	else if (params->precision > 0)
	{	
		toprint = ft_substr(toprint, 0, params->precision);
		ft_putstr_fd(toprint, 1);
		free (toprint);
	}	
	else
		ft_putstr_fd(toprint, 1);
	return (ft_strlen(toprint));
}
