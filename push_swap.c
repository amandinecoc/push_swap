/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:31:50 by amandine          #+#    #+#             */
/*   Updated: 2025/10/03 02:44:41 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(char **tab_str)
{
	int	len;
	int i;
	int	*tab_input;
	int	*tab_index;
	t_list *list_a;

	i = 0;
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
	while (i < len)
	{
		if (i == 0)
			list_a = list_new(tab_index[i++]);
		else
			list_add_back(&list_a, tab_index[i++]);
	}
	print_list(list_a);
	free(tab_index);
	return (Success);
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
