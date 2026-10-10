#include "ft_printf.h"
void count_number(long nb,int *c)
{   
    char	b;
    b = (nb % 10) + '0';
    if (nb >= 10)
	{
		count_number(nb / 10, c );
	}
    (*c)++;
}
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

void    print_number(va_list ptr , int *c,char *flag, int *num)
{
    int num;
    int len_num;
    int numofzero;

    len_num = 0;
    numofzero = 0;
    num = va_arg(ptr, int);
    count_number(num, len_num);
    if(num[1] > len_num )
    {
        numofzero = num - len_num;
    }
    if (flag[2] == '1') 
    {  
        if(flag[1])
        ft_putnbr(num , c,'+');
        
    }
    else 
    {

    }

}
const char  *format(const char *str, va_list ptr, int *c)
{
    char flag[6];
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
    else if(*str == 'd' || *str == 'i')
        print_number(ptr,c, flag, num);
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
