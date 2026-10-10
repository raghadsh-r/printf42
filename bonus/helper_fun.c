#include "ft_printf.h"

const char  *ft_atio(const char *str, int *num)
{
    int i;

    i = 0;
    *num = 0;
    while (str[i] >= '0' && str[i] <= '9' )
	{
		(*num) = ((*num) * 10) + (str[i] - '0');
		i++;
	}
	return (&str[i]);
}
const char *cheak_the_flag(const char *str,char *flag)
{
    int i = 0;
    while(str[i]==' ' || str[i]=='+' || str[i]=='-' || str[i]=='0' || str[i]=='#')
    {
        if(str[i]==' ')
            flag[0]='1';
        else if(str[i]=='+')
            flag[1]='1';
        else if(str[i]=='-')
            flag[2]='1';
        else if(str[i]=='0')
            flag[3]='1';
        else if(str[i]=='#')
            flag[4]='1';
        i++;
    }
    return (&str[i]);
}

const char  *cheak_the_doit(const char *str,char *flag)
{
    if(*str=='.')
    {   
        flag[5] ='1';
        str++;
    }
    return (str); 
}

void write_char(int len , char ch,int *c)
{
    int i ;

    i = 0;
    while(i< len)
    {  *c +=  write(1,&ch,1);
        i++;
    }
}
