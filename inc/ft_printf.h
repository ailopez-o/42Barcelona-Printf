/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailopez- <ailopez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:56:02 by ailopez-          #+#    #+#             */
/*   Updated: 2022/05/23 19:58:27 by ailopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef	struct{
	int		parameter;
	char	flags;
	int 	with;
	int 	precision;
	char	lenght[2];
	char	type;
} t_params;



# include "libft.h"
# include <stdarg.h>
# include <string.h>
# include <stdio.h> 
# include <stdlib.h>
# include <unistd.h>

int ft_printf(const char *params, ...);
int	ft_print_c (va_list	arg);
int ft_print_s(va_list arg);
int	ft_print_d(va_list arg);
#endif
