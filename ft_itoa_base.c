
#include "fillit.h"

static size_t	len_number(int value, int base)
{
	size_t len;

	len = 0;
	if (value == 0)
		len = 1;
	if (base == 10 && value < 0)
		len += 1;
	while (value != 0)
	{
		value = value / base;
		len += 1;
	}
	return (len);
}

char	*ft_itoa_base (int value, int base)
{
	char *str;
	size_t len;
	unsigned int number;
	char *base_value;
	
	base_value = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (0);
	len = len_number(value, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (value < 0 && base == 10)
		str[0] = '-';
	number = (value < 0) ? (unsigned int)-value : value;
	while (number >= (unsigned int) base)
	{
		str[len - 1] = base_value[number % base];
		number = number / base;
		len -= 1;
	}
	str[len - 1] = base_value[number];
	return (str);
}
