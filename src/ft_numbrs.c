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

char *ft_fill_reverse(char *str, char c, int size)
{

	//printf("\nSize [%d] - Relleno [%c] - Puntero [%p]\n",size, c, str);
	while (size > 0)
	{
		//printf("\nSize [%d] - Relleno [%c] - Puntero [%p]\n",size, c, str);
		*str = c;
		str--;
		size--;
	}
	return(str);
}


int ft_sign_print(t_params *params)
{
	// Verificamos si corresponde imprimir signo o no
	return ((params->sign == '+' && params->positive) || params->sign == '-' || params->gap);
}

char *ft_fill_str(int numsize, t_params *params)
{
	int 	gap;
	char 	*fill;
	char	*ptraux;

	// el hueco que tendremos será la precisión o el ancho, la que sea mayor
	if (params->precision > params->with)
		gap = params->precision + ft_sign_print(params) -  numsize;
	else
		gap = params->with - numsize;
	fill = malloc((gap + 1) * sizeof(char));
	if (fill == NULL)
		return (NULL);
	// Incializamos la cadena con caracter vacio
	ft_memset(fill, '.', gap);
	//printf("\nFILL [%s] - GAP[%d]\n", fill, gap);
	//printf("\nGAP [%d] - PUNTERO INCIO [%p]\n", gap, fill);
	// Si la preecisión es mayoe que el tamaño del numero, tendremos que rellenar con ceros hata precisión
	// Imprimir el signo (si es necesario) y rellenar con caracter vacio hasta el principio
	if (params->precision > numsize)
	{
		// Si la precisión es mayor que el numero, rellenamos hacia atrás de 0 y ponemos signo
		ptraux = ft_fill_reverse(fill + gap - 1, '0', params->precision - numsize);
		//printf("\nRELLENO [%d] - PUNTERO PTRAUX [%p]\n", params->precision - numsize, ptraux);
		//ptraux = fill + (gap - params->precision);
		//ft_memset(ptraux,'0',params->precision - numsize);
		if (ft_sign_print(params))
			ptraux = ft_fill_reverse(ptraux, params->sign, 1);
		//{
		//	ptraux--;
		//	*(ptraux)= params->sign;
		//}
		// Ahora rellenaremos hasta el final (principio) de caracter vacio
		
		ptraux = ft_fill_reverse(ptraux, ' ', gap - params->precision);
		//ft_memset(fill,' ', ptraux - fill);
	}
	// Ahora es momento de rellenar hasta alcanzar with
	if (params->with > numsize)
	{
/*
		if (params->fill == 0)
			ft_memset(fill,'0',params->with - numsize);
		else
			ft_memset(fill,' ',params->with - numsize);
		if (ft_sign_print(params))
			*(fill - 1)= params->sign;
*/
	}
	// Ponemos el caracter NULL y devolvemos
	fill[gap + 1] = '\0';  
	//printf("\nFILL [%s]\n", fill);
	//printf("\nFill[%s] - Precicision [%d] - With [%d]\n", fill, params->precision, params->with);
	return (fill);
}

char *ft_fill_nbr(char *num, t_params *params)
{
	char	*fill;

	// Si tenemos que alinear el hueco pero tambén escribir el signo. No tiene sentido
	if (params->gap && params->positive)
		params->gap = 0;
	// Si tenemos que alinear el hueco, y el sigo es positivo, imprimiremos un hueco
	if (params->gap && params->sign == '+')
		params->sign = ' ';
	// Incializamos con una cadena vacia
	fill = ft_strdup("");
	// Si la precisión o el ancho es mayor que el numero, generamos la cadena de relleno
	if ((params->precision > (int)ft_strlen(num)) || params->with > (int)ft_strlen(num))
		fill = ft_fill_str(ft_strlen(num), params);
	// Si no la cadena será el signo en caso de que haya que imprimirlo
	else if (ft_sign_print(params))
		fill = ft_substr(&params->sign,0,1);
	//Devolvemos la cadena resultante
	return (fill);
}

int	ft_print_d(va_list	arg,  t_params *params)
{
	char	*num;
	char	*fill;
	int		value;
	long	valueabs;

	value = va_arg(arg, int);
	valueabs = value;
	if (valueabs < 0)
		valueabs = -valueabs;
	//Obtenemos la cadena del número en positico
	num = ft_itoa(valueabs);
	//Calculamos el signo que habrá que imprimir
	if (value >= 0)
		params->sign ='+';
	else
		params->sign ='-';
	//Generamos la cadena de relleno
	fill = ft_fill_nbr(num, params);
	//Unimos la cadena de relleno, con la del numero
	num = ft_strjoin(fill, num);
	//La escribimos
	ft_putstr_fd(num,1);
	free(num);
	free(fill);
	return(1);
}

int	ft_print_u(va_list	arg, t_params *params)
{
	char	*num;
	char	*fill;
	
	num  = ft_uitoa(va_arg(arg, unsigned int));
	params->sign = '+';
	fill = ft_fill_nbr(num, params);
	num = ft_strjoin(fill, num);
	ft_putstr_fd(num,1);
	free(num);
	free (fill);
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
