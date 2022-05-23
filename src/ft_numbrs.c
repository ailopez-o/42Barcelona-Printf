/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailopez- <ailopez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:36:20 by ailopez-          #+#    #+#             */
/*   Updated: 2022/05/24 00:34:12 by aitorlope        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "inc/ft_printf.h"

int	ft_print_d(va_list	arg)
{
	char	*num;

	num = ft_itoa(va_arg(arg, int));
	ft_putstr_fd(num,1);
	free(num);
	return(1);
}


int	ft_print_u(va_list	arg)
{
	char	*num;
	
	num  = ft_uitoa(va_arg(arg, unsigned int));
	ft_putstr_fd(num,1);
	free(num);
	return(1);
}
