/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:31:50 by amandine          #+#    #+#             */
/*   Updated: 2025/09/26 11:33:58 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_digit_and_handle_error(char **tab_str)
{
	int	i;
	int j;

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

int	len_tab(char **tab)
{
	int	len;

	len = 0;
	while (tab[len] != NULL)
		len++;
	return (len);
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

int	*sort_int_tab(int *tab_sorted, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	temp = 0;
	while (i <= (len - 1))
	{
		j = i + 1;
		while (j <= (len - 1))
		{
			temp = tab_sorted[i];
			while (temp > tab_sorted[j] && j <= (len - 1))
			{
				temp = tab_sorted[j];
				tab_sorted[j] = tab_sorted[i];
				tab_sorted[i] = temp;
				j++;
			}
			j++;
		}
		i++;
	}
	return (tab_sorted);
}

int	*create_sorted_index_tab(int *tab_input, int *tab_sorted, int len)
{
	int	i;
	int	j;
	int	*tab_index;

	i = 0;
	tab_index = malloc(sizeof(int) * len);
	if (!tab_index)
		return (NULL);
	while (i <= (len - 1))
	{
		j = 0;
		while (j <= (len - 1))
		{
			if (tab_input[i] == tab_sorted[j])
			{
				tab_index[i] = j;
			}
			j++;
		}
		i++;
	}
	return (tab_index);
}

int	*tab_index_handler(int *tab_input, int len)
{
	int	*tab_index;
	int	*tab_sorted;
	int	i;

	i = 0;
	tab_sorted = malloc(sizeof(char) * len);
	if (!tab_sorted)
		return (NULL);
	while (i < len)
	{
		tab_sorted[i] = tab_input[i];
		i++;
	}
	sort_int_tab(tab_sorted, len);
	tab_index = create_sorted_index_tab(tab_input, tab_sorted, len);
	free(tab_sorted);
	free(tab_input);
	return (tab_index);
}

void	free_tab_str(char **tab_str, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(tab_str[i++]);
	free(tab_str);
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

int	push_swap(char **tab_str)
{
	int	len;
	int	*tab_input;
	int	*tab_index;

	len = len_tab(tab_str);
	tab_input = malloc(sizeof(int) * len);
	if (!tab_input)
		return (free_tab_str(tab_str, len), malloc_failure);
	if (check_digit_and_handle_error(tab_str) == digit_failure)
		return (free_tab_str(tab_str, len), free(tab_input), digit_failure);
	if (check_is_not_int_min_max_and_str_to_int(tab_str, len,
			tab_input) == limit_failure)
		return (free_tab_str(tab_str, len), free(tab_input), limit_failure);
	free_tab_str(tab_str, len);
	if (check_duplicata_value(tab_input, len) == double_failure)
		return (free(tab_input), double_failure);
	if (check_sorted_tab(tab_input, len) == already_sorted)
		return (free(tab_input), already_sorted);
	tab_index = tab_index_handler(tab_input, len);
	if (tab_index == NULL)
		return (free(tab_input), malloc_failure);
	free(tab_index);
	return (Success);
}

void	ft_printerror(int status)
{
	if (status == digit_failure)
		ft_putendl_fd("ERROR : not a digit input\n", 2);
	if (status == double_failure)
		ft_putendl_fd("ERROR : number duplicata\n", 2);
	if (status == malloc_failure)
		ft_putendl_fd("ERROR : memory allocation\n", 2);
	if (status == already_sorted)
		ft_putendl_fd("ERROR : liste already sorted\n", 2);
	if (status == limit_failure)
		ft_putendl_fd("ERROR : int min or int max\n", 2);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*str;
	char	*temp;
	char	**tab_str;
	int		status;

	i = 2;
	if (argc <= 1)
		return (EXIT_FAILURE);
	str = ft_strdup(argv[1]);
	if (argc > 2)
	{
		while (i != argc)
		{
			temp = ft_strjoin(str, " ");
			if (temp == NULL)
				return (malloc_failure);
			free(str);
			str = ft_strjoin(temp, argv[i++]);
			if (str == NULL)
				return (malloc_failure);
			free(temp);
		}
	}
	tab_str = ft_split(str, ' ');
	free(str);
	if (tab_str == NULL)
		return (malloc_failure);
	status = push_swap(tab_str);
	ft_printerror(status);
	return (status);
}
