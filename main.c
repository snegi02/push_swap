/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snegi <snegi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:52:09 by snegi             #+#    #+#             */
/*   Updated: 2024/02/14 10:52:12 by snegi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_sort.h"

int	convettodigit(char *s)
{
	long	result;
	long	sign;
	int		i;

	i = 0;
	sign = 1;
	result = 0;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (s[i] >= '0' && s[i] <= '9' && s[i] != '\0')
	{
		while (s[i] >= '0' && s[i] <= '9' && s[i] != '\0')
		{
			result = result * 10 + s[i] - '0';
			i++;
		}
		if ((result * sign > INT_MAX) || (result * sign < INT_MIN))
			return (0);
		if (s[i] == '\0')
			return (sign * result);
	}
	return (0);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	*make_arg(int len, char **str, int *array, int ac)
{
	int	i;
	int	num;
	int	j;

	i = 0;
	array = malloc (len * sizeof(int));
	while (i < len)
	{
		num = (int)convettodigit(str[ac++]);
		if (num == 0 && str[ac - 1][0] != '0')
		{
			free(array);
			return (NULL);
		}
		j = 0;
		while (j < i)
		{
			if (same_num(array[j++], num, array) == 0)
				return (NULL);
		}
		array[i++] = num;
	}
	return (array);
}

void	arg_check(int *array, int len)
{
	if (array == NULL)
		write(1, "Error\n", 6);
	else if (!checksorted(array, len))
	{
		write(1, "sorted!\n", 8);
		free (array);
	}
	else
		stack_build(array, len);
}

int	main(int argc, char **argv)
{
	int	*array;
	int	len;

	array = NULL;
	if (argc <= 1)
		return (-1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		len = lenght(argv);
		array = make_arg(len, argv, array, 0);
		free_str(argv);
	}
	else
	{
		len = argc - 1;
		array = make_arg(len, argv++, array, 1);
	}
	arg_check(array, len);
	return (0);
}
