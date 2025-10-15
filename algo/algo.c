/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:01:19 by amandine          #+#    #+#             */
/*   Updated: 2025/10/16 00:14:19 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	fill_max_value_list_b_in_list_a(t_list **list_a, t_list **list_b)
{
	int	len;
	int	pos;

	len = lenght_list(*list_b);
	pos = pos_of_max_value(*list_b);
	if (pos > (len / 2))
	{
		while (pos < len)
		{
			reverse_rotate_b(list_b, yes_write);
			pos++;
		}
		fill_three_last(list_a, list_b);
		push_a(list_a, list_b);
	}
	else
	{
		while (pos > 0)
		{
			rotate_b(list_b, yes_write);
			pos--;
		}
		fill_three_last(list_a, list_b);
		push_a(list_a, list_b);
	}
}

void	fill_list_b_in_list_a_and_sort(t_list **list_a, t_list **list_b)
{
	int	len;

	len = lenght_list(*list_b);
	while (len > 0)
	{
		fill_max_value_list_b_in_list_a(list_a, list_b);
		len--;
	}
}

void	create_and_fill_list_b(t_list **list_a, t_list **list_b, int min_w,
		int max_w)
{
	int	len;

	len = lenght_list(*list_a);
	while (len > 3)
	{
		(*list_a) = pointer_first(*list_a);
		if ((*list_a)->value < min_w)
		{
			push_b(list_a, list_b);
			min_w++;
			max_w++;
			rotate_b(list_b, yes_write);
		}
		else if ((*list_a)->value >= min_w && (*list_a)->value <= max_w)
		{
			push_b(list_a, list_b);
			min_w++;
			max_w++;
		}
		else
			rotate_a(list_a, yes_write);
		len = lenght_list(*list_a);
	}
	*list_b = pointer_first(*list_b);
}

void	algo_sort(t_list **list_a)
{
	int		min_w;
	int		max_w;
	t_list	*list_b;

	min_w = 0;
	list_b = NULL;
	if (lenght_list(*list_a) == 5)
		sort_five(list_a, &list_b);
	else
	{
		if (lenght_list(*list_a) <= 110)
			max_w = lenght_list(*list_a) * 0.13;
		else
			max_w = lenght_list(*list_a) * 0.06;
		create_and_fill_list_b(list_a, &list_b, min_w, max_w);
		if (lenght_list(*list_a) >= 3)
		{
			sort_three(list_a);
			fill_list_b_in_list_a_and_sort(list_a, &list_b);
		}
		else
			swap_a(list_a, yes_write);
	}
	free(list_b);
}
