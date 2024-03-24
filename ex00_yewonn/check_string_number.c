/*>>>>> TEAM LEADER HEADER <<<< >>> PUT HERE <<<<<<
 *
 *
 *
 * ^^^^^^^^^^^^!! */
#include <unistd.h>
void	check_string_number(char *str)
{
	int	i;
	int counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '1' && str[i] <= '4'))
			write(1, "Error: Clues not between 1 & 4", 30);
		counter++;
		i++;
	}
}


int	main(int argc, char **argv)
{

