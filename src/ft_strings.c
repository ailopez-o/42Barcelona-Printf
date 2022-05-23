/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailopez- <ailopez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:36:03 by ailopez-          #+#    #+#             */
/*   Updated: 2022/05/23 19:56:50 by ailopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/ft_printf.h"

int	ft_print_c (va_list	arg)
{
	int	c;

	c =  va_arg(arg, int);
	write(1, &c, 1);
	return (1);
}

int ft_print_s(va_list arg)
{
	ft_putstr_fd(va_arg(arg, char *), 1);
	return (1);
}
