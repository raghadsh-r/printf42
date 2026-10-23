#include "ft_printf.h"

void	ft_putnbr_unsigned(long nb, int *c)
{
	char	b;
	b = (nb % 10) + '0';
	if (nb >= 10)
	{
		ft_putnbr_unsigned(nb / 10, c);
	}
	(*c)++;
	write(1, &b, 1);
}
void	len_unsigned(long nb, int *len)
{
	if (nb >= 10)
	{
		ft_putnbr_unsigned(nb / 10, len);
	}
	(*len)++;
} 
void print_unsigned_int(va_list ptr, int *c,int *flag,int *num)
{
    unsigned int x;
    int len;

    len = 0;
    x = va_arg(ptr, unsigned int);
    len_unsigned(x, &len);
    num[0] -= len;
    if(flag[2])
    {

    }
    else
    {
 

    }
}
const char  *format(const char *str, va_list ptr, int *c)
{
    int     flag[6];
    int     i;
    int     num[2];

    num[0] = 0;
    num[1] = 0;
    i = 0;
    while(i < 6)
        flag[i++] = '0';
    str = cheak_the_flag(str, flag);
    str = ft_atio(str, num);
    str = cheak_the_doit(str,flag);
    str = ft_atio(str,&num[1]);
    if(*str=='s')
        print_string(str, ptr , c, flag, num);
    else if(*str == 'c')
        print_char(ptr,c,flag,num);
    else if(*str == 'p')
        print_pointer(ptr,c,flag,num);
    else if(*str =='u')
        print_unsigned_int(ptr,c,flag,num);
    str++;
    return(str);
}



int ft_printf(const char *str, ...)
{
    int c;
    va_list	ptr;
    
    c = 0;
    va_start(ptr, str);
    if(!str)
        return (-1);
    while(*str)
    {
        if(*str=='%')
        {
            str++;
            if(*str=='%')
                c += write(1,str,1);
            else
            {
                str = format(str,ptr,&c);
            }
        }
        else
        c += write(1, (str++), 1);
    }
    return(c);
}



// int main()
// {
//     ft_printf("hi");
// }
