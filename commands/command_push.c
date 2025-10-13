/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:07:32 by amandine          #+#    #+#             */
/*   Updated: 2025/10/13 14:19:06 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// pa (push a) : Prend le premier élément au sommet de b et le met sur a.
// Ne fait rien si b est vide.

// pb (push b) : Prend le premier élément au sommet de a et le met sur b.
// Ne fait rien si a est vide.

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
	// list_a = pointer_first(list_a);
	ft_putendl_fd("pa", 1);
}

// void	push_b(t_list **list_a, t_list **list_b)
// {
// 	t_list	*tmp;

// 	if (*list_a == NULL)
// 		return ;
// 	*list_a = pointer_first(*list_a);
// 	tmp = (*list_a);
// 	(*list_a) = (*list_a)->p_next;
// 	if ((*list_a) != NULL)
// 		(*list_a)->p_prev = NULL;
// 	if (*list_b == NULL)
// 	{
// 		tmp->p_next = NULL;
// 		// list_b->p_prev = NULL;
// 	}
// 	else 
// 	{
// 		// list_b = pointer_first(*list_b);
// 		(*list_b)->p_prev = tmp;
// 		tmp->p_next = (*list_b);
// 	}
// 	(*list_b) = tmp;
// 	// list_b = pointer_first(*list_b);
// 	ft_putendl_fd("pb", 2);
// 	// return (list_a);
// }

void	push_b(t_list **list_a, t_list **list_b)
{
	t_list *tmp;
	if(*list_a == NULL)
		return;
		
	tmp = *list_b;
	*list_b = *list_a;
	*list_a = (*list_a)->p_next;
	(*list_b)->p_next = tmp;
	if(tmp != NULL)
		tmp->p_prev = *list_b;
	if(list_a != NULL)
		(*list_a)->p_prev = NULL;
	ft_putendl_fd("pb", 1);
}

//   t_list *p_new = malloc(sizeof(t_list));
//     if (p_new != NULL)
//     {
//         p_new->value = content;
//         p_new->p_next = NULL;
//         p_new->p_prev = NULL;
//     }
//     return p_new;