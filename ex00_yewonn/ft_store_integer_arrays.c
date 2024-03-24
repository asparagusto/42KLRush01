/*>>>>> TEAM LEADER HEADER <<<< >>> PUT HERE <<<<<<
 *
 *
 *
 * ^^^^^^^^^^^^!! */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen_only_digits(char *str);

int	*ft_store_integer_arrays(char *str)
{
	int	i;
	int	j;
	int	*integer_array;

	i = 0;
	j = 0;
	integer_array = (int *) malloc(ft_strlen_only_digits(str) * sizeof(int));
	if (integer_array == NULL)
	{
		printf("Memory allocation failed!");
		return (NULL);
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			integer_array[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	return (integer_array);
}
/*
int	main(void)
{
	char a[] = "1 3 4 2 1 4 5 1 2";
	
	int i = 0;
	int *arrays = ft_store_integer_arrays(a);

	printf("integer array: ");
	while (i < ft_strlen_only_digits(a))
	{
		printf("%i, ", arrays[i]); 
		i++;
	}
	free(arrays);
}*/
