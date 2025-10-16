/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:31:50 by amandine          #+#    #+#             */
/*   Updated: 2025/10/16 17:25:07 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(char **tab_str, int status)
{
	int		len;
	int		i;
	int		*tab_index;
	t_list	*list_a;

	i = 0;
	len = len_tab(tab_str);
	status = sorted_tab_index(tab_str, &tab_index, len);
	if (status != Success)
		return (status);
	while (i < len)
	{
		if (i == 0)
		{
			list_a = list_new(tab_index[i++]);
			if (list_a == NULL)
				return (malloc_failure);
		}
		else
			list_add_back(list_a, tab_index[i++]);
	}
	algo_sort(&list_a);
	free(tab_index);
	free_list_a(&list_a);
	return (Success);
}

int	main(int argc, char **argv)
{
	char	**tab_str;
	int		status;

	if (argc <= 1)
		return (EXIT_FAILURE);
	status = create_tab_str(argc, argv, &tab_str);
	if (status != Success)
		return (ft_printerror(status), status);
	status = push_swap(tab_str, status);
	ft_printerror(status);
	return (status);
}
