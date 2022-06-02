/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorlopezdeaudicana <marvin@42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:11:14 by aitorlope         #+#    #+#             */
/*   Updated: 2022/06/01 10:11:15 by aitorlope        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/ft_printf.h"

int	ft_print_nbr_x(char *num, t_params *params)
{
	if (params->precision == 0 && ft_atoi(num) == 0)
	{
		ft_putstr_fd("", 1);
		return (0);
	}
	else
		return (ft_putstr(num));
}

int	ft_print_x(va_list arg, t_params *params)
{
	char	*num;
	int		valor;	
	int		len;
	int		gap;

	valor = va_arg(arg, int);
	num = ft_itoa_hex_4bytes(valor);
	if (valor == 0)
		params->altformat = 0;
	if (params->precision >= 0 && params->precision < (int)ft_strlen(num) && \
		valor != 0)
		params->precision = (int)ft_strlen(num);
	len = 0;
	if (params->leftjustify)
	{
		gap = params->precision - ft_strlen(num);
		if (params->precision < 0)
			gap++;
		if (params->altformat)
			len += ft_putstr("0x");
		len += ft_print_fill('0', gap);
		len += ft_print_nbr_x(num, params);
		len += ft_print_fill(' ', params->with - len);
	}
	else
	{
		if (params->precision >= 0)
		{
			len += ft_print_fill(' ', params->with - params->precision - \
				2 * params->altformat);
			if (params->altformat)
				len += ft_putstr("0x");
			len += ft_print_fill('0', params->precision - ft_strlen(num));
		}
		else
		{
			if (params->altformat && params->fill == '0')
				len += ft_putstr("0x");
			len += ft_print_fill(params->fill, params->with - \
				(int)ft_strlen(num) - 2 * params->altformat);
			if (params->altformat && params->fill == ' ')
				len += ft_putstr("0x");
		}
		len += ft_print_nbr_x(num, params);
	}
	free(num);
	return (len);
}

int	ft_print_xx(va_list arg, t_params *params)
{
	char	*num;
	int		valor;	
	int		len;		
	int		i;
	int		gap;

	valor = va_arg(arg, int);
	num = ft_itoa_hex_4bytes(valor);
	i = 0;
	while (*(num + i))
	{
		*(num + i) = ft_toupper(*(num + i));
		i++;
	}	
	if (valor == 0)
		params->altformat = 0;
	if (params->precision >= 0 && params->precision < (int)ft_strlen(num) && \
		valor != 0)
		params->precision = (int)ft_strlen(num);
	len = 0;
	if (params->leftjustify)
	{
		gap = params->precision - ft_strlen(num);
		if (params->precision < 0)
			gap++;
		if (params->altformat)
			len += ft_putstr("0X");
		len += ft_print_fill('0', gap);
		len += ft_print_nbr_x(num, params);
		len += ft_print_fill(' ', params->with - len);
	}
	else
	{
		if (params->precision >= 0)
		{
			len += ft_print_fill(' ', params->with - params->precision - \
				2 * params->altformat);
			if (params->altformat)
				len += ft_putstr("0X");
			len += ft_print_fill('0', params->precision - ft_strlen(num));
		}
		else
		{
			if (params->altformat && params->fill == '0')
				len += ft_putstr("0X");
			len += ft_print_fill(params->fill, params->with - \
				(int)ft_strlen(num) - 2 * params->altformat);
			if (params->altformat && params->fill == ' ')
				len += ft_putstr("0X");
		}
		len += ft_print_nbr_x(num, params);
	}
	free(num);
	return (len);
}

int	ft_print_p(va_list arg, t_params *params)
{
	char	*num;
	char	*ptr;
	int		len;

	ptr = va_arg(arg, char *);
	num = ft_itoa_hex((unsigned long)ptr);
	if (params->leftjustify)
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(num, 1);
		ft_print_fill(' ', params->with - ft_strlen(num) - 2);
	}
	else
	{
		ft_print_fill(' ', params->with - ft_strlen(num) - 2);
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(num, 1);
	}
	len = (int)ft_strlen(num) + 2;
	free(num);
	if (params->with > len)
		return (params->with);
	return (len);
}
