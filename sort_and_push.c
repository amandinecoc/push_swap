/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:01:55 by acocoual          #+#    #+#             */
/*   Updated: 2025/10/10 17:13:45 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort_three(t_list *list)
{
	list = pointer_first(list);
	if (list->value < list->p_next->value)
	{
		if (list->p_next->value < list->p_next->p_next->value)
			return (list);
		if (list->p_next->value > list->p_next->p_next->value)
			reverse_rotate_a(list, yes_write);
		list = pointer_first(list);
		if (list->value < list->p_next->value)
			return (list);
	}
	if (list->value > list->p_next->value)
	{
		if (list->p_next->value < list->p_next->p_next->value)
		{
			if (list->value < list->p_next->p_next->value)
				return (swap_a(list, yes_write), list);
			return (rotate_a(list, yes_write), list);
		}
		if (list->p_next->value > list->p_next->p_next->value)
			return (rotate_a(list, yes_write), swap_a(list, yes_write), list);
	}
	return (list);
}
