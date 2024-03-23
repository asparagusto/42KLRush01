/*>>>>> TEAM LEADER HEADER <<<< >>> PUT HERE <<<<<<
 *
 *
 *
 * ^^^^^^^^^^^^!! */

int	ft_strlen_only_digits(char *str)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			count++;
		i++;
	}
	return count;
}
/*
int	main(void)
{
	char a[] = "a b c d e f 1 2 3 ";

	printf("number of digits: %i", ft_strlen_only_digits(a));
}
*/
