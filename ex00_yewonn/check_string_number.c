/*>>>>> TEAM LEADER HEADER <<<< >>> PUT HERE <<<<<<
 *
 *
 *
 * ^^^^^^^^^^^^!! */
#include <unistd.h>
void	check_string_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
			if (i % 2 == 0 && !(str[i] >= '1' && str[i] <= '4'))
			{
				write(1, "Error: Clues not between 1 & 4\n", 31);
				return;
			}
			if (i % 2 == 1 && str[i] != ' ')
			{
				write(1, "Error: Missing space\n", 21);
				return;
			}
		i++;
	}
}
/*

int	main(int argc, char **argv)
{
	check_string_number(argv[1]);
}
*/
