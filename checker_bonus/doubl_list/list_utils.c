/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:41:14 by amandine          #+#    #+#             */
/*   Updated: 2025/10/16 17:26:04 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_list	*pointer_first(t_list *list)
{
	if (list == NULL)
		return (list);
	while (list->p_prev != NULL)
		list = list->p_prev;
	return (list);
}

t_list	*pointer_last(t_list *list)
{
	if (list == NULL)
		return (list);
	while (list->p_next != NULL)
		list = list->p_next;
	return (list);
}

int	lenght_list(t_list *list)
{
	int	len;

	len = 0;
	list = pointer_first(list);
	if (list == NULL)
		return (len);
	while (list->p_next != NULL)
	{
		list = list->p_next;
		len++;
	}
	return (++len);
}

void	free_list_a(t_list **list_a)
{
	t_list	*tmp;
	t_list	*del;

	(*list_a) = pointer_first(*list_a);
	if (*list_a != NULL)
	{
		tmp = (*list_a);
		while (tmp != NULL)
		{
			del = tmp;
			tmp = tmp->p_next;
			free(del);
		}
	}
}
