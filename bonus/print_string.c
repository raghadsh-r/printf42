

#include "ft_printf.h"

int ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


void hindel_print_string(char *strr, int *c,int *flag, int *num)
{
    int len;
    int to_print;
    int padding;

    len = ft_strlen(strr);
    to_print = len;
    if (flag[5] == 1)
    {
        if (num[1] < len)
            to_print = num[1];
    }
    padding = num[0] - to_print;
    if (padding < 0)
        padding = 0;
    if (flag[2] == 1) 
    {
        *c += write(1, strr, to_print);
        write_char(padding, ' ', c);
    }
    else 
    {
        write_char(padding, ' ', c);
        *c += write(1, strr, to_print);
    }
}

void    print_string(const char *str, va_list ptr , int *c,int *flag, int *num)
{
    char    *strr;
    (void)str;

    strr = va_arg(ptr, char *);
    if(!strr)
    {
        (*c) += write(1,"(null)",6);
        return ;
    }
    hindel_print_string(strr,c,flag,num);
}