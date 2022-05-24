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



int	ft_islimit(char	c)
{
	const char	limit[] = "cspdiuxX%";
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

int	ft_isflags(char	c)
{
	char	*ptr;
	const char	flags[] = "0+-# ";
	
	ptr = (char *) &flags[0];
	while(*ptr)
	{
		if (*ptr == c)
			return (1);
		ptr++;
	}
	return(0);
}

void 	ft_print_params(t_params *params)
{
	printf("\nparams->fill [%c]\n", params->fill);
	printf("\nparams->gap  [%d]\n", params->gap);
	printf("\nparams->positive [%d]\n", params->positive);
	printf("\nparams->leftjustify [%d]\n", params->leftjustify);
	printf("\nparams->altformat [%d]\n", params->altformat);
	printf("\nparams->with [%d]\n", params->with);		
	printf("\nparams->precision [%d]\n", params->precision);	
}



char	*ft_load_params(const char *str, t_params *params)
{
	int 	i;
	char	*with;
	int		wd;

	str ++;
	params->fill = ' ';
	params->positive = 0;
	params->leftjustify = 0;
	params->gap = 0;
	params->altformat = 0;
	params->precision = 0;
	params->with = 0;
	i = 0;	
	while (ft_isflags(*(str + i)))
	{
		if (*(str + i) == '0')
			params->fill = '0';
		if (*(str + i) == ' ')
			params->gap = 1;
		if (*(str + i) == '+')
			params->positive = 1;
		if (*(str + i) == '-')
			params->leftjustify = 1;
		if (*(str + i) == '#')
			params->altformat = 1;
		i++;
	}
	wd = i;
	while (ft_isdigit(*(str + i)))
		i++;	
	with = malloc((i - wd + 1) * sizeof(char));
	ft_strlcpy(with,str + wd, i - wd + 1);
	params->with = ft_atoi(with);
	free (with);
	if (*(str + i) == '.')
	{
		i++;
		wd = i;
		while (ft_isdigit(*(str + i)))
			i++;	
		with = malloc((i - wd + 1) * sizeof(char));
		ft_strlcpy(with,str + wd, i - wd + 1);
		params->precision = ft_atoi(with);
		free (with);
	}
	while (!ft_islimit(*(str)))
		str++;
	params->type = *(str); 	
	return ((char *)str);
}

char	*ft_print_arg(const char *str, va_list	arg)
{
	
	t_params	params;
	char	*returnvalue;	

	returnvalue = ft_load_params(str, &params);
	if (params.type == 'c')
		ft_print_c(arg);
	if (params.type == 's')
		ft_print_s(arg);
	if (params.type == 'p')
		ft_print_p(arg);
	if (params.type == 'd')
		ft_print_d(arg);
	if (params.type == 'i')
		ft_print_d(arg);
	if (params.type == 'u')
		ft_print_u(arg);
	if (params.type == 'x')
		ft_print_x(arg);
	if (params.type == 'X')
		ft_print_X(arg);
	if (params.type == '%')
		write(1,"%",1);

	//ft_print_params(&params);		
	return (returnvalue);
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
