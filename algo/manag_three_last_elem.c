/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manag_three_last_elem.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:57:20 by amandine          #+#    #+#             */
/*   Updated: 2025/10/13 18:05:14 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	is_second_three_last(t_list **list_a)
{
	(*list_a) = pointer_last(*list_a);
	if ((*list_a)->value == ((*list_a)->p_prev->value + 1))
	{
		reverse_rotate_a(list_a, yes_write);
		reverse_rotate_a(list_a, yes_write);
	}
	else
	{
		reverse_rotate_a(list_a, yes_write);
		reverse_rotate_a(list_a, yes_write);
		swap_a(list_a, yes_write);
		rotate_a(list_a, yes_write);
	}
}

void	is_third_three_two_last(t_list **list_a)
{
	(*list_a) = pointer_last(*list_a);
	reverse_rotate_a(list_a, yes_write);
	reverse_rotate_a(list_a, yes_write);
	reverse_rotate_a(list_a, yes_write);
	swap_a(list_a, yes_write);
	rotate_a(list_a, yes_write);
	swap_a(list_a, yes_write);
	reverse_rotate_a(list_a, yes_write);
	swap_a(list_a, yes_write);
	rotate_a(list_a, yes_write);
}

void	is_third_three_last(t_list **list_a)
{
	(*list_a) = pointer_last(*list_a);
	if ((*list_a)->p_prev->value == ((*list_a)->p_prev->p_prev->value + 1))
	{
		if ((*list_a)->value == ((*list_a)->p_prev->value + 1))
		{
			reverse_rotate_a(list_a, yes_write);
			reverse_rotate_a(list_a, yes_write);
			reverse_rotate_a(list_a, yes_write);
		}
		else
			is_third_three_two_last(list_a);
	}
	else
	{
		reverse_rotate_a(list_a, yes_write);
		reverse_rotate_a(list_a, yes_write);
		reverse_rotate_a(list_a, yes_write);
		swap_a(list_a, yes_write);
		rotate_a(list_a, yes_write);
		swap_a(list_a, yes_write);
		rotate_a(list_a, yes_write);
	}
}

void	fill_three_last(t_list **list_a, t_list **list_b)
{
	int	value;

	(*list_b) = pointer_first(*list_b);
	value = (*list_b)->value;
	(*list_a) = pointer_last(*list_a);
	if ((*list_a)->value == (value + 1))
		reverse_rotate_a(list_a, yes_write);
	else if ((*list_a)->p_prev->value == (value + 1))
		is_second_three_last(list_a);
	else if ((*list_a)->p_prev->p_prev->value == (value + 1))
		is_third_three_last(list_a);
	else
		return ;
}

void	sort_three(t_list **list)
{
	(*list) = pointer_first(*list);
	if ((*list)->value < (*list)->p_next->value)
	{
		if ((*list)->p_next->value < (*list)->p_next->p_next->value)
			return ;
		if ((*list)->p_next->value > (*list)->p_next->p_next->value)
			reverse_rotate_a(list, yes_write);
		(*list) = pointer_first(*list);
		if ((*list)->value < (*list)->p_next->value)
			return ;
	}
	if ((*list)->value > (*list)->p_next->value)
	{
		if ((*list)->p_next->value < (*list)->p_next->p_next->value)
		{
			if ((*list)->value < (*list)->p_next->p_next->value)
				return (swap_a(list, yes_write));
			return (rotate_a(list, yes_write));
		}
		if ((*list)->p_next->value > (*list)->p_next->p_next->value)
			return (rotate_a(list, yes_write), swap_a(list, yes_write));
	}
}

// void 	sort_reverse_three(t_list **list)
// {
// 	(*list) = pointer_first(*list);
// 	if ((*list)->value < (*list)->p_next->value)
// 	{
// 		if ((*list)->p_next->value > (*list)->p_next->p_next->value)
// 		{
// 			if ((*list)->value < (*list)->p_next->p_next->value)
// 				return (rotate_a(list, yes_write));
// 			else
// 				return (swap_a(list, yes_write));
// 		}
// 		else
// 			swap_a(list, yes_write);
// 	}
// 	if ((*list)->value > (*list)->p_next->value)
// 	{
// 		if ((*list)->p_next->value < (*list)->p_next->p_next->value)
// 		{
// 			if ((*list)->value < (*list)->p_next->p_next->value)
// 				return (reverse_rotate_a(list, yes_write));
// 			else
// 				return (swap_a(list, yes_write), rotate_a(list, yes_write));
// 		}
// 	}
// }