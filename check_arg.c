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
	write(1, "Error\n", 6);
}

void	check_arg(int argc, **argv)
{
	int	i;
	if (argc >= 2)
	{
		i = 0;
		while (argv[i])
		{
			if (!ft_atoi(argv[i]) && !check_double())
			i++;
		}
	}
}

int	check_double(int argc, **argv)
{
	int i = 1;

	while(i < argc )
	{
		
	}
}