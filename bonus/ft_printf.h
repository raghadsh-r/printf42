/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralshraw <ralshraw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 09:41:53 by ralshraw          #+#    #+#             */
/*   Updated: 2026/10/08 11:05:15 by ralshraw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

const char  *ft_atio(const char *str, int *num);
const char *cheak_the_flag(const char *str,int*flag);
const char  *cheak_the_doit(const char *str,int *flag);
void write_char(int len , char ch,int *c);
int ft_strlen(const char *s);
void hindel_print_string(char *strr, int *c,int *flag, int *num);
void    print_string(const char *str, va_list ptr , int *c,int *flag, int *num);
const char  *format(const char *str, va_list ptr, int *c);
int ft_printf(const char *str, ...);
void    print_char(va_list ptr , int *c,int *flag, int *num);
void	ft_printf_hexa(unsigned long nb, char *str, int *c, char postive);
void    print_pointer(va_list ptr , int *c,int *flag, int *num);

#endif
