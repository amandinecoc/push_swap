/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sorted_index_tab.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:47:48 by amandine          #+#    #+#             */
/*   Updated: 2025/10/09 11:16:49 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*create_sorted_index_tab(int *tab_input, int *tab_sorted, int len)
{
	int	i;
	int	j;
	int	*tab_index;

	i = 0;
	tab_index = malloc(sizeof(int) * len);
	if (!tab_index)
		return (NULL);
	while (i < len)
	{
		j = 0;
		while (j < len)
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

int	*sort_int_tab(int *tab_sorted, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	temp = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			temp = tab_sorted[i];
			while (j < len && temp > tab_sorted[j])
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

int	*tab_index_handler(int *tab_input, int len)
{
	int	*tab_index;
	int	*tab_sorted;
	int	i;

	i = 0;
	tab_sorted = malloc(sizeof(int) * len);
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

int sorted_tab_index(char **tab_str, int **tab_index, int len)
{
	int	*tab_input;
	
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
	*tab_index = tab_index_handler(tab_input, len);
	if (*tab_index == NULL)
		return (free(tab_input), malloc_failure);
	return(Success);
}
