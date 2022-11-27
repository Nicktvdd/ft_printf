#include "ft_printf.h"

// take the argument from '%'
va_list	params(va_list ap) 
{
	if ap ==

}

// loop through the string until '%'
int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, str);

	while (str[i - 1] != '%' && str[i])
		ft_putchar(i++)

	va_end(ap);


}