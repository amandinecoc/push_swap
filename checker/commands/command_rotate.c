/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:07:38 by amandine          #+#    #+#             */
/*   Updated: 2025/10/16 17:18:49 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	rotate_a(t_list **list_a, t_write_status status)
{
	t_list	*tmp;

	(*list_a) = pointer_first(*list_a);
	if ((*list_a) == NULL && (*list_a)->p_next == NULL)
		return ;
	tmp = (*list_a);
	(*list_a) = (*list_a)->p_next;
	(*list_a)->p_prev = NULL;
	(*list_a) = pointer_last(*list_a);
	tmp->p_next = NULL;
	(*list_a)->p_next = tmp;
	(*list_a)->p_next->p_prev = (*list_a);
	(*list_a) = pointer_first((*list_a));
	if (status == not_write)
		return ;
	ft_putendl_fd("ra", 1);
}

void	rotate_b(t_list **list_b, t_write_status status)
{
	t_list	*tmp;

	(*list_b) = pointer_first(*list_b);
	if ((*list_b) == NULL && (*list_b)->p_next == NULL)
		return ;
	tmp = (*list_b);
	(*list_b) = (*list_b)->p_next;
	(*list_b)->p_prev = NULL;
	(*list_b) = pointer_last(*list_b);
	tmp->p_next = NULL;
	(*list_b)->p_next = tmp;
	tmp->p_prev = (*list_b);
	(*list_b) = pointer_first(*list_b);
	if (status == not_write)
		return ;
	ft_putendl_fd("rb", 1);
}

void	rotate_rotate(t_list **list_a, t_list **list_b)
{
	rotate_a(list_a, not_write);
	rotate_b(list_b, not_write);
	ft_putendl_fd("rr", 1);
}
