/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_and_print_error.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:45:36 by amandine          #+#    #+#             */
/*   Updated: 2025/10/19 12:42:43 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_digit_and_handle_error(char **tab_str)
{
	int	i;
	int	j;

	i = 0;
	while (tab_str[i] != NULL)
	{
		j = 0;
		if (tab_str[i][j] == '+' || tab_str[i][j] == '-')
			j++;
		while (tab_str[i][j] != '\0')
		{
			if (ft_isdigit(tab_str[i][j]) == 1)
				j++;
			else
				return (digit_failure);
		}
		i++;
	}
	return (Success);
}

int	check_sorted_tab(int *tab, int len)
{
	int	i;

	i = 0;
	while (i < (len - 1))
	{
		if (tab[i] > tab[i + 1])
			return (Success);
		i++;
	}
	return (already_sorted);
}

int	check_duplicata_value(int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i != len)
	{
		j = i + 1;
		while (j != len)
		{
			if (tab[i] == tab[j])
				return (double_failure);
			j++;
		}
		i++;
	}
	return (Success);
}

int	check_is_not_int_min_max_and_str_to_int(char **tab_str, int len,
		int *tab_input)
{
	int			i;
	long long	check;

	i = 0;
	while (i < len)
	{
		check = ft_atoll(tab_str[i]);
		if (check < -2147483648 || check > 2147483647)
			return (limit_failure);
		tab_input[i] = check;
		i++;
	}
	return (Success);
}

void	ft_printerror(int status)
{
	if (status == digit_failure)
		ft_putendl_fd("Error : not a digit input", 2);
	if (status == double_failure)
		ft_putendl_fd("Error : number duplicata", 2);
	if (status == malloc_failure)
		ft_putendl_fd("Error : memory allocation", 2);
	if (status == already_sorted)
		ft_putendl_fd("list already sorted", 2);
	if (status == limit_failure)
		ft_putendl_fd("Error : int min or int max", 2);
}
