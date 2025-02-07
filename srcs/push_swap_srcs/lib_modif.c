#include "push_swap.h"

int	ft_atoi_modif(const char *str, int *max)
{
	int			i;
	int			neg;
	long int	res;

	i = 0;
	res = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		if ((neg == 1 && res > INT_MAX) || (neg == -1 && res * neg < INT_MIN))
		{
			*max = 1;
			return (-1);
		}
	}
	return (res * neg);
}
