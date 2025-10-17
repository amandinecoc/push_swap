/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:13:48 by amandine          #+#    #+#             */
/*   Updated: 2025/10/17 14:47:39 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_sort_list(t_list *list_a, int len)
{
	int	newlen;

	newlen = lenght_list(list_a);
	if (len != newlen)
		return (is_KO);
	list_a = pointer_first(list_a);
	while (list_a != NULL)
	{
		if (list_a->value > list_a->p_next->value)
			return (is_KO);
		else
			list_a = list_a->p_next;
	}
	return (is_OK);
}

void	fill_list_a(t_list **list_a, int len, int *tab_index)
{
	int	i;

	i = 1;
	while (i < len)
		list_add_back((*list_a), tab_index[i++]);
}

int	create_list_a(char **tab_str, int status)
{
	int		len;
	int		*tab_index;
	t_list	*list_a;

	len = len_tab(tab_str);
	status = sorted_tab_index(tab_str, &tab_index, len);
	if (status != is_OK)
		return (status);
	if (len > 0)
	{
		list_a = list_new(tab_index[0]);
		if (list_a == NULL)
			return (is_ERROR);
	}
	fill_list_a(&list_a, len, tab_index);
	len = lenght_list(list_a);
	if (create_and_sort_list_b_and_a(&list_a) != is_OK)
		return (free(tab_index), free_list_a(&list_a), is_ERROR);
	if (check_sort_list(list_a, len) != is_OK)
		return (free(tab_index), free_list_a(&list_a), is_KO);
	free(tab_index);
	free_list_a(&list_a);
	return (is_OK);
}

void	print_status(int status)
{
	if (status == is_ERROR)
		ft_putendl_fd("Error", 2);
	if (status == is_KO)
		ft_putendl_fd("KO", 2);
	if (status == is_OK)
		ft_putendl_fd("OK", 2);
}

int	main(int argc, char **argv)
{
	char	**tab_str;
	int		status;

	if (argc <= 1)
		return (ft_putendl_fd("Error", 2), is_ERROR);
	status = create_tab_str(argc, argv, &tab_str);
	if (status != is_OK)
		return (print_status(status), status);
	status = create_list_a(tab_str, status);
	return (print_status(status), status);
}
