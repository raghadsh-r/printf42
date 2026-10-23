
#include "ft_printf.h"
void    print_char(va_list ptr , int *c,int *flag, int *num)
{
    char ch;

    ch = va_arg(ptr, int);
    if(num[0] - 1 > 0 && flag[2])
    {
        write_char(1,ch,c);
        write_char(num[0] - 1 ,' ',c);
    }
    else
    {
        write_char(num[0] - 1,' ',c);
        write_char(1,ch,c);
       
    }
}