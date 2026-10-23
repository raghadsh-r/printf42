#include "ft_printf.h"
void	ft_printf_hexa(unsigned long nb, char *str, int *c, char postive)
{
	int	b;

	b = (nb % 16);
	if (postive && nb)
	{
		if (str[15] == 'f')
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
		(*c) += 2;
		postive = 0;
	}
	if (nb >= 16)
	{
		ft_printf_hexa(nb / 16, str, c, postive);
	}
	(*c)++;
	write(1, &str[b], 1);
}
void len_hexa(unsigned long nb,int *len)
{
	if (nb >= 16)
	{
		len_hexa(nb / 16,len);
	}
	(*len)++;
}
void    print_pointer(va_list ptr , int *c,int *flag, int *num)
{
    void	*pt;
	int		len;

	len = 0;
	pt = va_arg(ptr, void *);
	len_hexa((unsigned long)pt,&len);
	len +=2;
	if (!pt)
	{
		write(1, "(nil)", 5);
    	(*c) += 5;
	}
	else if(num[0] - len > 0 && flag[2])
	{
		write(1, "0x", 2);
		(*c) += 2;
		ft_printf_hexa((unsigned long)pt, "0123456789abcdef", c, 0);
        write_char(num[0] - len,' ',c);
    }
    else
    {
        write_char(num[0] - len ,' ',c);
        write(1, "0x", 2);
		(*c) += 2;
		ft_printf_hexa((unsigned long)pt, "0123456789abcdef", c, 0);
    }
}