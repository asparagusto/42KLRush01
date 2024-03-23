/*>>>>> TEAM LEADER HEADER <<<< >>> PUT HERE <<<<<<
 *
 *
 *
 * ^^^^^^^^^^^^!! */

void	ft_putchar(char c);

void	ft_putstr(char *c)
{
	while (*c != '\0')
	{
		ft_putchar(*c);
		c++;
	}
}
