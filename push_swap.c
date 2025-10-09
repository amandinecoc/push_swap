/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:31:50 by amandine          #+#    #+#             */
/*   Updated: 2025/10/09 15:55:14 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(char **tab_str, int status)
{
	int	len;
	int i;
	int	*tab_index;
	t_list *list_a;

	i = 0;
	len = len_tab(tab_str);
	status = sorted_tab_index(tab_str, &tab_index, len);
	if (status != Success)
		return (status);
	while (i < len)
	{
		if (i == 0)
			list_a = list_new(tab_index[i++]);
		else
			list_add_back(list_a, tab_index[i++]);
	}
	print_list(list_a);
	// reverse_rotate_a(list_a, yes_write);
	sort_three(list_a);
	// reverse_rotate_a(list_a, yes_write);
	// swap_a(list_a, yes_write);
	print_list(list_a);
	free(tab_index);
	return ((status = Success), status);
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
