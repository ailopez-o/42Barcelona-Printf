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

int ft_print_x(va_list arg)
{
	char	*num;

	num  = ft_itoa_hex(va_arg(arg, int));
	ft_putstr_fd(num,1);
	free(num);
	return(1);
}

int ft_print_X(va_list arg)
{
	char	*num;
	int 	i;

	num  = ft_itoa_hex(va_arg(arg, int));
	i = 0;
	while(*(num + i))
	{
		*(num + i) = ft_toupper(*(num + i));
		i++;
	}
	ft_putstr_fd(num,1);
	free(num);
	return(1);
}

int ft_print_p(va_list arg)
{
	char	*num;
	char	*address;
	char	*ptr;

	ptr = va_arg(arg, char *);
	num  = ft_itoa_hex((unsigned long)ptr);
	address = malloc((ft_strlen(num) + 3) * sizeof(char));
	ft_strlcpy(address,"0x",3);
	ft_strlcat(address,num,ft_strlen(num) + 3);
	ft_putstr_fd(address,1);
	free (address);
	free(num);
	return(1);
}
