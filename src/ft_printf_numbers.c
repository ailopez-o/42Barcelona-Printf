/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailopez- <ailopez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:36:20 by ailopez-          #+#    #+#             */
/*   Updated: 2022/05/25 19:30:49 by ailopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/ft_printf.h"

int	ft_print_d(va_list	arg, t_params *params)
{
	char	*num;
	char	*fill;
	char	*toprint;
	int		value;
	long	valueabs;

	value = va_arg(arg, int);
	valueabs = value;
	if (valueabs < 0)
		valueabs = -valueabs;
	if (value >= 0)
		params->sign = '+';
	else
		params->sign = '-';
	num = ft_uitoa((unsigned int)valueabs);
	fill = ft_fill_nbr(num, params);
	toprint = ft_strjoin(fill, num);
	free(num);
	free(fill);
	ft_putstr_fd(toprint, 1);
	value = ft_strlen(toprint);
	free(toprint);
	return (value);
}

int	ft_print_u(va_list	arg, t_params *params)
{
	char	*num;
	char	*fill;

	num = ft_uitoa(va_arg(arg, unsigned int));
	params->sign = '+';
	fill = ft_fill_nbr(num, params);
	num = ft_strjoin(fill, num);
	ft_putstr_fd(num, 1);
	free(num);
	free (fill);
	return (1);
}

int	ft_print_x(va_list arg)
{
	char	*num;
	int		len;

	num = ft_itoa_hex(va_arg(arg, int));
	ft_putstr_fd(num, 1);
	len = ft_strlen(num);
	free(num);
	return (len);
}

int	ft_print_xx(va_list arg)
{
	char	*num;
	int		i;
	int		len;

	num = ft_itoa_hex(va_arg(arg, int));
	num = ft_substr(num,8,8);
	i = 0;
	while (*(num + i))
	{
		*(num + i) = ft_toupper(*(num + i));
		i++;
	}
	ft_putstr_fd(num, 1);
	len = ft_strlen(num);
	free(num);
	return (len);
}

int	ft_print_p(va_list arg)
{
	char	*num;
	char	*address;
	char	*ptr;
	int 	len;

	ptr = va_arg(arg, char *);
	num = ft_itoa_hex((unsigned long)ptr);
	address = malloc((ft_strlen(num) + 3) * sizeof(char));
	ft_strlcpy(address, "0x", 3);
	ft_strlcat(address, num, ft_strlen(num) + 3);
	ft_putstr_fd(address, 1);
	len = ft_strlen(address);
	free(address);
	free(num);
	return (len);
}
