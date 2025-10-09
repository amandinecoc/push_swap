/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:31:50 by amandine          #+#    #+#             */
/*   Updated: 2025/10/09 22:25:34 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_three_last(t_list *list_a)
{
	int	value;

	list_a = pointer_first(list_a);
	value = list_a->value;
	list_a = pointer_last(list_a);
	if (list_a->value > value)
	{
		reverse_rotate_a(list_a, yes_write);
		swap_a(list_a, yes_write);
	}
	if (list_a->value == (value + 1))
		reverse_rotate_a(list_a, yes_write);
}

int	pos_of_max_value(t_list *list_b)
{
	int	i;
	int	pos;
	int	value;

	i = 0;
	list_b = pointer_first(list_b);
	value = list_b->value;
	pos = i;
	while (list_b->p_next != NULL)
	{
		list_b = list_b->p_next;
		i++;
		if (list_b->value > value)
		{
			value = list_b->value;
			pos = i;
		}
	}
	return (pos);
}

void	fill_max_value_list_b_in_list_a(t_list *list_a, t_list *list_b)
{
	int	len;
	int	pos;

	len = lenght_list(list_b);
	pos = pos_of_max_value(list_b);
	if (pos > (len / 2))
	{
		while (pos <= len)
		{
			reverse_rotate_b(list_b, yes_write);
			pos++;
		}
		list_a = push_b(list_a, list_b);
	}
	// else
	if (pos <= (len / 2))
	{
		while (pos < 0)
		{
			rotate_b(list_b, yes_write);
			pos--;
		}
		list_a = push_b(list_a, list_b);
	}
}

void	fill_list_b_in_list_a_and_sort(t_list *list_a, t_list *list_b)
{
	int	len;

	len = lenght_list(list_b);
	while (len > 0)
	{
		list_b = pointer_first(list_b);
		fill_max_value_list_b_in_list_a(list_a, list_b);
		fill_three_last(list_a);
		len = lenght_list(list_b);
	}
}

void	create_and_fill_list_b(t_list **list_a, t_list **list_b, int min_w,
		int max_w)
{
	int	len;

	len = lenght_list(*list_a);
	while (len > 3)
	{
		*list_a = pointer_first(*list_a);
		if ((*list_a)->value < min_w)
		{
			*list_a = push_b(*list_a, *list_b);
			reverse_rotate_b(*list_b, yes_write);
		}
		else if ((*list_a)->value >= min_w && (*list_a)->value <= max_w)
		{
			*list_a = push_b(*list_a, *list_b);
			min_w++;
			max_w++;
		}
		else
			rotate_a(*list_a, yes_write);
		len = lenght_list(*list_a);
	}
	print_list(*list_a);
	*list_b = pointer_first(*list_b);
	printf("autre \n");
}

void	code(t_list *list_a)
{
	int		min_w;
	int		max_w;
	t_list	*list_b;

	min_w = 0;
	max_w = 3;
	// gerer creation *list_b ---fonction
	// gerer attribution window ---fonction
	list_b = NULL;
	create_and_fill_list_b(&list_a, &list_b, min_w, max_w);
	print_list(list_a);
	sort_three(list_a);
	fill_list_b_in_list_a_and_sort(list_a, list_b);
}

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
			list_a = list_new(tab_index[i++]);
		else
			list_add_back(list_a, tab_index[i++]);
	}
	print_list(list_a);
	// reverse_rotate_a(list_a, yes_write);
	// sort_three(list_a);
	// reverse_rotate_a(list_a, yes_write);
	// swap_a(list_a, yes_write);
	code(list_a);
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
