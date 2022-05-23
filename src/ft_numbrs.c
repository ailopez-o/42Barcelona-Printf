/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailopez- <ailopez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:36:20 by ailopez-          #+#    #+#             */
/*   Updated: 2022/05/23 20:06:15 by ailopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "inc/ft_printf.h"

int	ft_print_d(va_list	arg)
{
	char	*num;
	num = ft_itoa(va_arg(arg, int));
	write (1,num,ft_strlen(num));
	return(1);
}
