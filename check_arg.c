/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:25:41 by alsiavos          #+#    #+#             */
/*   Updated: 2024/01/11 14:03:30 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
int	check_double(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				check_error();
			j++;
		}
		i++;
	}
	return (0);
}
void	check_arg(int argc, char **argv)

{
	int i;
	int len;

	i = 1;
	if (argc >= 2)
	{
		while (i < argc)
		{
			len = 0;
			while (argv[i][len] != '\0')
			{
				if (!ft_isdigit(argv[i][len]) && argv[i][len] != '-'
					&& argv[i][len] != '+')
				{
					check_error();
				}
				len++;
			}
			i++;
		}
		if (check_double(argc, argv))
			check_error();
	}
}
