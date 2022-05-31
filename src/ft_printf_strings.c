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

int	ft_print_c(va_list	arg, t_params *params)
{
	int	c;

	c = va_arg(arg, int);
	if (params->with < 2)
	{
		write(1, &c, 1);	
		return (1);
	}
	if (params->leftjustify)
	{	
		write(1, &c, 1);	
		ft_print_fill(' ',params->with - 1);
		return (params->with);
	}
	else
	{
		ft_print_fill(' ',params->with - 1);
		write(1, &c, 1);
		return (params->with);	
	}	
}

void ft_print_str(char *str, int leftjustify, int size)
{
	if(leftjustify)
	{
		ft_putstr_fd(str, 1);
		ft_print_fill(' ', size);
	}
	else
	{
		ft_print_fill(' ', size);
		ft_putstr_fd(str, 1);
	}
}

int	ft_print_s(va_list arg, t_params *params)
{
	char	*toprint;
	int 	len;

	toprint = va_arg(arg, char *);
	if (toprint == NULL)
	{
		write(1,"(null)", 6);
		return (6);
	}
	if (params->precision > 0)
		toprint = ft_substr(toprint, 0, params->precision);
	else
		toprint = ft_substr(toprint, 0, ft_strlen(toprint));
	len = ft_strlen(toprint);
	if (params->with > len)
		ft_print_str (toprint, params->leftjustify, params->with - len);
	else
		ft_putstr_fd(toprint, 1);
	free (toprint);		
	if (params->with > len)
		return (params->with);
	else
		return(len);
}
