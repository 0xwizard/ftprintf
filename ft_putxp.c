#include "ft_printf.h" 

int ft_putx(unsigned int x, char c)
{
    if (c == 'x')
       return(ft_base(x, "0123456789abcdef"));
    else 
        return (ft_base(x, "0123456789ABCDEF"));
}

int ft_putp(void *p)
{
    if (!p)
        return (ft_putstr("(nil)"));
    return (ft_putstr("0x") + ft_base((unsigned long)p, "0123456789abcdef"));
}