/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailopez- <ailopez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:54:28 by ailopez-          #+#    #+#             */
/*   Updated: 2022/05/23 23:24:30 by aitorlope        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/ft_printf.h"

const char	limit[] = "cspdiuxX%";

int	ft_islimit(char	c)
{
	char	*ptr;

	ptr = (char *) &limit[0];
	while(*ptr)
	{
		if (*ptr == c)
			return (1);
		ptr++;
	}
	return(0);
}


char	*ft_print_arg(const char *str, va_list	arg)
{
	
	t_params	params;
	int i;

	str ++;
	i = 0;
	while (!ft_islimit(*(str + i)))
		i++;
	params.type = *(str + i); 
	if (params.type == 'c')
		ft_print_c(arg);
	if (params.type == 's')
		ft_print_s(arg);
	if (params.type == 'p')
		printf("Tipo p");
	if (params.type == 'd')
		ft_print_d(arg);
	if (params.type == 'i')
		ft_print_d(arg);
	if (params.type == 'u')
		ft_print_u(arg);
	if (params.type == 'x')
		printf("Tipo x");
	if (params.type == 'X')
		printf("Tipo X");
	if (params.type == '%')
		write(1,"%",1);
	return ((char *)str + i);
}




int ft_printf(const char *toprint, ...)
{
	int	n;
	va_list argc;
	char	*str;
	
	str = (char *)toprint;


	va_start (argc, toprint);
	n = 0;
	while(*str)
	{
		if (*str == '%')
			str = ft_print_arg(str, argc);
		else
			write (1,str,1);
		str++;
	}
	va_end(argc);
	return (1);
}
