#include "ft_printf.h"
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = s;
	while (n > 0)
	{
		temp[i] = (unsigned char )c;
		i++;
		n--;
	}
	return (s);
}

const char  *format(const char *str, va_list ptr, int *c,int *num)
{
    int     flag[6];

    num[0] = 0;
    num[1] = 0;
    ft_memset(flag,0,sizeof(int) * 6);
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
        print_unsigned_int(ptr,c);
    else if(*str=='i' || *str=='d')
        print_number(ptr,flag,c);
    else if (*str == 'x')
		ft_printf_hex(ptr, "0123456789abcdef", c,flag);
	else if (*str == 'X')
        ft_printf_hex(ptr, "0123456789ABCDEF", c,flag);
    str++;
    return(str);
}



int ft_printf(const char *str, ...)
{
    int c;
    int num[2];
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
                c += write(1,str++,1);
            else
            {
                str = format(str,ptr,&c,num);
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
