/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:07:38 by amandine          #+#    #+#             */
/*   Updated: 2025/10/07 13:26:52 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
// Le premier élément devient le dernier.

// rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
// Le premier élément devient le dernier.

// rr : ra et rb en même temps.

void	rotate_a(t_list *list_a, t_write_status status)
{
	t_list	*tmp;

	list_a = pointer_first(list_a);
	if (list_a == NULL && list_a->p_next == NULL)
		return ;
	tmp = list_a;
	list_a = list_a->p_next;
	list_a->p_prev = NULL;
	list_a = pointer_last(list_a);
	tmp->p_next = NULL;
	list_a->p_next = tmp;
	list_a->p_next->p_prev = list_a;
	if (status == not_write)
		return ;
	ft_putendl_fd("ra", 2);
}

void	rotate_b(t_list *list_b, t_write_status status)
{
	t_list	*tmp;

	list_b = pointer_first(list_b);
	if (list_b == NULL && list_b->p_next == NULL)
		return ;
	tmp = list_b;
	list_b = list_b->p_next;
	list_b->p_prev = NULL;
	list_b = pointer_last(list_b);
	tmp->p_next = NULL;
	list_b->p_next = tmp;
	list_b->p_next->p_prev = list_b;
	if (status == not_write)
		return ;
	ft_putendl_fd("ra", 2);
}

void	rotate_rotate(t_list *list_a, t_list *list_b)
{
	rotate_a(list_a, not_write);
	rotate_b(list_b, not_write);
	ft_putendl_fd("rr", 2);
}
