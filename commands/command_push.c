/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:07:32 by amandine          #+#    #+#             */
/*   Updated: 2025/10/13 18:17:02 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;

	if ((*list_b) == NULL)
		return ;
	(*list_a) = pointer_first(*list_a);
	(*list_b) = pointer_first(*list_b);
	tmp = (*list_b);
	(*list_b) = (*list_b)->p_next;
	if ((*list_b) != NULL)
		(*list_b)->p_prev = NULL;
	if ((*list_a) != NULL)
		(*list_a)->p_prev = tmp;
	tmp->p_next = (*list_a);
	(*list_a) = tmp;
	ft_putendl_fd("pa", 1);
}

void	push_b(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;

	if (*list_a == NULL)
		return ;
	tmp = *list_b;
	*list_b = *list_a;
	*list_a = (*list_a)->p_next;
	(*list_b)->p_next = tmp;
	if (tmp != NULL)
		tmp->p_prev = *list_b;
	if (list_a != NULL)
		(*list_a)->p_prev = NULL;
	ft_putendl_fd("pb", 1);
}
