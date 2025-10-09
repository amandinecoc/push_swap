/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:07:37 by amandine          #+#    #+#             */
/*   Updated: 2025/10/09 22:19:17 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de la pile a.
// Le dernier élément devient le premier.

// rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de la pile b.
// Le dernier élément devient le premier.

// rrr : rra et rrb en même temps.

void	reverse_rotate_a(t_list *list_a, t_write_status status)
{
	t_list	*tmp;

	list_a = pointer_last(list_a);
	if (list_a == NULL || list_a->p_prev == NULL)
		return ;
	tmp = list_a;
	list_a = list_a->p_prev;
	list_a->p_next = NULL;
	list_a = pointer_first(list_a);
	tmp->p_prev = NULL;
	list_a->p_prev = tmp;
	list_a->p_prev->p_next = list_a;
	// list_a = pointer_first(list_a);
	if (status == not_write)
		return ;
	// list = pointer_first(list);
	ft_putendl_fd("rra", 2);
}

void	reverse_rotate_b(t_list *list_b, t_write_status status)
{
	t_list	*tmp;

	list_b = pointer_last(list_b);
	if (list_b == NULL || list_b->p_prev == NULL)
		return ;
	tmp = list_b;
	list_b = list_b->p_prev;
	list_b->p_next = NULL;
	list_b = pointer_first(list_b);
	tmp->p_prev = NULL;
	list_b->p_prev = tmp;
	list_b->p_prev->p_next = list_b;
	if (status == not_write)
		return ;
	ft_putendl_fd("rrb", 2);
}

void	reverse_rotate_rotate(t_list *list_a, t_list *list_b)
{
	reverse_rotate_a(list_a, not_write);
	reverse_rotate_b(list_b, not_write);
	ft_putendl_fd("rrr", 2);
}
