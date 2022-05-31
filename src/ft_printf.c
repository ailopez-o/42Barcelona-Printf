/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailopez- <ailopez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:54:28 by ailopez-          #+#    #+#             */
/*   Updated: 2022/05/25 19:27:01 by ailopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/ft_printf.h"

int	ft_islimit(char c)
{
	const char	limit[] = "cspdiuxX%";
	char		*ptr;

	ptr = (char *) &limit[0];
	while (*ptr)
	{
		if (*ptr == c)
			return (1);
		ptr++;
	}
	return (0);
}

int	ft_isflags(char c)
{
	char		*ptr;
	const char	flags[] = "0+-# ";

	ptr = (char *) &flags[0];
	while (*ptr)
	{
		if (*ptr == c)
			return (1);
		ptr++;
	}
	return (0);
}

void	ft_struct_ini(t_params *params)
{
	params->fill = ' ';
	params->positive = 0;
	params->leftjustify = 0;
	params->gap = 0;
	params->altformat = 0;
	params->precision = 0;
	params->with = 0;
	params->chrprinted = 0;
}

char	*ft_load_params(const char *str, t_params *params)
{
	int		i;
	char	*with;
	int		wd;

	ft_struct_ini(params);
	str ++;
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
	ft_strlcpy(with, str + wd, i - wd + 1);
	params->with = ft_atoi(with);
	free (with);
	if (*(str + i) == '.')
	{
		i++;
		wd = i;
		while (ft_isdigit(*(str + i)))
			i++;
		with = malloc((i - wd + 1) * sizeof(char));
		ft_strlcpy(with, str + wd, i - wd + 1);
		params->precision = ft_atoi(with);
		free (with);
	}
	if(params->precision > 0)
		params->fill = ' ';
	while (!ft_islimit(*(str)))
		str++;
	params->type = *(str);
	return ((char *)str);
}

char	*ft_print_arg(const char *str, va_list	arg, t_params *params)
{
	char		*returnvalue;

	returnvalue = ft_load_params(str, params);
	if (params->type == 'c')
		params->chrprinted = ft_print_c(arg, params);
	if (params->type == 's')
		params->chrprinted = ft_print_s(arg, params);
	if (params->type == 'p')
		params->chrprinted = ft_print_p(arg, params);
	if (params->type == 'd')
		params->chrprinted = ft_print_d(arg, params);
	if (params->type == 'i')
		params->chrprinted = ft_print_d(arg, params);
	if (params->type == 'u')
		params->chrprinted = ft_print_u(arg, params);
	if (params->type == 'x')
		params->chrprinted = ft_print_x(arg, params);
	if (params->type == 'X')
		params->chrprinted = ft_print_xx(arg, params);
	if (params->type == '%')
	{
		write(1, "%", 1);
		params->chrprinted = 1;
	}
	return (returnvalue);
}

int	ft_printf(const char *toprint, ...)
{
	int			n;
	va_list		argc;
	char		*str;
	t_params	params;

	str = (char *)toprint;
	va_start (argc, toprint);
	n = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str = ft_print_arg(str, argc, &params);
			n = n + params.chrprinted;
		}
		else
		{
			write (1, str, 1);
			n++;
		}
		str++;
	}
	va_end(argc);
	return (n);
}
