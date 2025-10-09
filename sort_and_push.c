/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:01:55 by acocoual          #+#    #+#             */
/*   Updated: 2025/10/09 15:25:41 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list *list)
{
	list = pointer_first(list);
	if (list->value < list->p_next->value)
	{
		if (list->p_next->value < list->p_next->p_next->value)
			return ;
		if (list->p_next->value > list->p_next->p_next->value)
			reverse_rotate_a(list, yes_write);
		list = pointer_first(list);
		if (list->value < list->p_next->value)
			return ;
	}
	if (list->value > list->p_next->value)
	{
		if (list->p_next->value < list->p_next->p_next->value)
		{
			if (list->value < list->p_next->p_next->value)
				return (swap_a(list, yes_write));
			return (rotate_a(list, yes_write));
		}
		if (list->p_next->value > list->p_next->p_next->value)
			return (rotate_a(list, yes_write), swap_a(list, yes_write));
	}
}
