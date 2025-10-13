/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:07:41 by amandine          #+#    #+#             */
/*   Updated: 2025/10/13 18:15:38 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_list **list_a, t_write_status status)
{
	t_list	*tmp;

	(*list_a) = pointer_first(*list_a);
	if ((*list_a) == NULL && (*list_a)->p_next == NULL)
		return ;
	tmp = (*list_a);
	(*list_a) = (*list_a)->p_next;
	(*list_a)->p_prev = NULL;
	tmp->p_next = (*list_a)->p_next;
	if (tmp->p_next != NULL)
		tmp->p_next->p_prev = tmp;
	(*list_a)->p_next = tmp;
	tmp->p_prev = (*list_a);
	if (status == not_write)
		return ;
	ft_putendl_fd("sa", 1);
}

void	swap_b(t_list **list_b, t_write_status status)
{
	t_list	*tmp;

	(*list_b) = pointer_first(*list_b);
	if ((*list_b) == NULL && (*list_b)->p_next == NULL)
		return ;
	tmp = (*list_b);
	(*list_b) = (*list_b)->p_next;
	(*list_b)->p_prev = NULL;
	tmp->p_next = (*list_b)->p_next;
	if (tmp->p_next != NULL)
		tmp->p_next->p_prev = tmp;
	(*list_b)->p_next = tmp;
	tmp->p_prev = (*list_b);
	if (status == not_write)
		return ;
	ft_putendl_fd("sa", 1);
}

void	swap_swap(t_list **list_a, t_list **list_b)
{
	swap_a(list_a, not_write);
	swap_b(list_b, not_write);
	ft_putendl_fd("ss", 1);
}
