/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_and_print_error.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:45:36 by amandine          #+#    #+#             */
/*   Updated: 2025/10/18 17:31:43 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

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
				return (is_ERROR);
		}
		i++;
	}
	return (is_OK);
}

int	check_sorted_tab(int *tab, int len)
{
	int	i;

	i = 0;
	while (i < (len - 1))
	{
		if (tab[i] > tab[i + 1])
			return (is_OK);
		i++;
	}
	return (is_SORTED);
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
				return (is_ERROR);
			j++;
		}
		i++;
	}
	return (is_OK);
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
			return (is_ERROR);
		tab_input[i] = check;
		i++;
	}
	return (is_OK);
}
