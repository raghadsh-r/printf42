/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralshraw <ralshraw@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:00:14 by ralshraw          #+#    #+#             */
/*   Updated: 2026/11/04 09:58:39 by ralshraw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(va_list ptr, int *c, int *flag, int *num)
{
	char	ch;

	ch = va_arg(ptr, int);
	if (num[0] - 1 > 0 && flag[2])
	{
		write_char(1, ch, c);
		write_char(num[0] - 1, ' ', c);
	}
	else
	{
		write_char(num[0] - 1, ' ', c);
		write_char(1, ch, c);
	}
}
