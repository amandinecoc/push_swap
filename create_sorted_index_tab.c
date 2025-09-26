/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sorted_index_tab.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 11:47:48 by amandine          #+#    #+#             */
/*   Updated: 2025/09/26 11:50:26 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab_str(char **tab_str, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(tab_str[i++]);
	free(tab_str);
}

int	len_tab(char **tab)
{
	int	len;

	len = 0;
	while (tab[len] != NULL)
		len++;
	return (len);
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
