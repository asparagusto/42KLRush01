/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-md- <mbin-md-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 12:18:02 by mbin-md-          #+#    #+#             */
/*   Updated: 2024/03/24 14:58:12 by yewoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	check_string_count(char *str)
{
	int i;
	int char_count;

	i = 0;
	char_count = 0;

	while (str[i] != '\0')
	{
		char_count++;
		i++;
	}

	if (char_count >= 32)
		write(1, "Error: String too long\n", 23);
	if (char_count < 31)
		write(1, "Error: String too short\n", 24);
}	
