/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralshraw <ralshraw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:00:26 by ralshraw          #+#    #+#             */
/*   Updated: 2026/11/04 10:13:01 by ralshraw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	hindel_print_string(char *strr, int *c, int *flag)
{
	int		len;

	(void)flag;
	len = ft_strlen(strr);
	*c += write(1, strr, len);
}

void	print_string(const char *str, va_list ptr, int *c, int *flag)
{
	char	*strr;

	(void)str;
	strr = va_arg(ptr, char *);
	if (!strr)
	{
		(*c) += write(1, "(null)", 6);
		return ;
	}
	hindel_print_string(strr, c, flag);
}
