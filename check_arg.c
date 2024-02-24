/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsiavos <alsiavos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:25:41 by alsiavos          #+#    #+#             */
/*   Updated: 2024/02/24 07:23:56 by alsiavos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	test_valide(void)
{
	write(2, "Correct\n", 8);
	exit(EXIT_FAILURE);
}
int	ft_sign(char c)
{
	return (c == '+' || c == '-');
}
int	mydigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_number(char *v)
{
	int	i;

	i = 0;
	if (ft_sign(v[i]) && v[i + 1] != '\0')
		i++;
	while (v[i] && mydigit(v[i]))
		i++;
	if (v[i] != '\0' && !mydigit(v[i]))
		return (0);
	return (1);
}

int	ft_double(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int	arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (ft_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

void	split_arg(char **argv)
{
	int		i;
	int		j;
	char	**args;

	i = 0;
	while (argv[i])
	{
		args = ft_split(argv[i], ' ');
		j = 0;
		while (args[j])
		{
			if (!ft_number(args[j]))
				check_error();
			j++;
		}
		free(args);
		i++;
	}
	test_valide();
}

void	check_arg(char **argv)
{
	int	i;
	int	n;

	n = 0;
	i = 1;
	while (argv[i])
	{
		if(!ft_double(argv))
			check_error();
		split_arg(&argv[i]);
		if (!ft_number(argv[i]))
			check_error();
		n += arg_is_zero(argv[i]);
		i++;
	}
	if (n > 1)
		check_error();
	test_valide();
}
