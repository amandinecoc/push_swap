/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:07:32 by amandine          #+#    #+#             */
/*   Updated: 2025/10/07 14:24:01 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// pa (push a) : Prend le premier élément au sommet de b et le met sur a.
// Ne fait rien si b est vide.

// pb (push b) : Prend le premier élément au sommet de a et le met sur b.
// Ne fait rien si a est vide.

void	push_a(t_list *list_a, t_list *list_b)
{
	t_list	*tmp;

    if (list_b == NULL)
		return ;
	list_a = pointer_first(list_a);
	list_b = pointer_first(list_b);
	tmp = list_b;
	list_b = list_b->p_next;
	if (list_b != NULL)
		list_b->p_prev = NULL;
    if (list_a != NULL)
	    list_a->p_prev = tmp;
	tmp->p_next = list_a;
    list_a = tmp;
	ft_putendl_fd("pa", 2);
}

void	push_b(t_list *list_a, t_list *list_b)
{
	t_list	*tmp;

    if (list_a == NULL)
		return ;
	list_a = pointer_first(list_a);
	list_b = pointer_first(list_b);
	tmp = list_a;
	list_a = list_a->p_next;
	if (list_a != NULL)
		list_a->p_prev = NULL;
    if (list_b != NULL)
	    list_b->p_prev = tmp;
	tmp->p_next = list_b;
    list_b = tmp;
	ft_putendl_fd("pb", 2);
}
