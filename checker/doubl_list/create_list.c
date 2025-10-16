/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:33:04 by amandine          #+#    #+#             */
/*   Updated: 2025/10/16 17:18:29 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_list	*list_new(int content)
{
	t_list	*p_new;

	p_new = malloc(sizeof(t_list));
	if (p_new == NULL)
		return (NULL);
	else
	{
		p_new->value = content;
		p_new->p_next = NULL;
		p_new->p_prev = NULL;
	}
	return (p_new);
}

void	list_add_back(t_list *list, int value)
{
	t_list	*elem;

	if (list == NULL)
		return ;
	elem = list_new(value);
	if (elem == NULL)
		return ;
	list = pointer_last(list);
	list->p_next = elem;
	elem->p_prev = list;
}

// void print_list(t_list *list)
// {
//     list = pointer_first(list);
//     while(list->p_next != NULL)
//     {
//         printf("elem %d\n",list->value);
//         list = list->p_next;
//     }
//     printf("elem %d\n",list->value);
// }
