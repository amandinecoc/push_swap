/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:31:50 by amandine          #+#    #+#             */
/*   Updated: 2025/10/09 11:16:11 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(char **tab_str, int *status)
{
	int	len;
	int i;
	int	*tab_index;
	// t_list *list_a;

	i = 0;
	len = len_tab(tab_str);
	*status = sorted_tab_index(tab_str, &tab_index, len);
	// while (i < len)
	// {
	// 	if (i == 0)
	// 		list_a = list_new(tab_index[i++]);
	// 	else
	// 		list_add_back(list_a, tab_index[i++]);
	// }
	// print_list(list_a);
	// reverse_rotate_a(list_a, yes_write);
	// print_list(list_a);
	while (i < len)
		printf("%d\n", tab_index[i++]);
	free(tab_index);
	return ((*status = Success), Success);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*str;
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
			if ((status = create_input_str(&str, argv[i++])) == malloc_failure)
				return (free(str), ft_printerror(status), malloc_failure);
		}
	}
	tab_str = ft_split(str, ' ');
	free(str);
	if (tab_str == NULL)
		return ((status = malloc_failure), ft_printerror(status), malloc_failure);
	push_swap(tab_str, &status);
	ft_printerror(status);
	return (status);
}
