/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 23:32:25 by amandine          #+#    #+#             */
/*   Updated: 2025/10/16 00:14:27 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_five(t_list **list_a, t_list **list_b)
{
	int	min;
	int	max;

	min = 0;
	max = (lenght_list(*list_a) - 1);
	while ((lenght_list(*list_a)) > 3)
	{
		(*list_a) = pointer_first(*list_a);
		if ((*list_a)->value == min || (*list_a)->value == max)
			push_b(list_a, list_b);
		else
			rotate_a(list_a, yes_write);
	}
	sort_three(list_a);
	(*list_b) = pointer_first(*list_b);
	while ((lenght_list(*list_a)) < 5)
	{
		if ((*list_b)->value == min)
			push_a(list_a, list_b);
		else
		{
			push_a(list_a, list_b);
			rotate_a(list_a, yes_write);
		}
	}
}
