#include "ft_printf.h"
void	ft_putnbr(long nb, int *c, char postive)
{
	char	b;

	if (nb < 0)
	{
		nb *= -1;
		(*c)++;
		write(1, "-", 1);
		postive = 0;
	}
	if (postive)
	{
		write(1, &postive, 1);
		(*c)++;
		postive = 0;
	}
	b = (nb % 10) + '0';
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, c, postive);
	}
	(*c)++;
	write(1, &b, 1);
}
void print_number(va_list ptr , int *flag,int *c)
{
    int x = va_arg(ptr, int);
    if(flag[1])
    ft_putnbr(x,c,'+');
    else if(flag[0])
    ft_putnbr(x,c,' ');
    else
    ft_putnbr(x,c,'\0');
}
void print_unsigned_int(va_list ptr,int *c)
{
    ft_putnbr(va_arg(ptr, unsigned int), c, 0);
}
void ft_printf_hex(va_list ptr, char *str, int *c, int *flag)
{
    if(flag[4])
    ft_printf_hexa(va_arg(ptr, unsigned int), str, c,'#');
    else
    ft_printf_hexa(va_arg(ptr, unsigned int), str, c,'\0');
}