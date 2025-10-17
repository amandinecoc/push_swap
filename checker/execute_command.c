/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 01:33:15 by amandine          #+#    #+#             */
/*   Updated: 2025/10/17 01:59:03 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int execute_rotate(char *line, t_list **list_a, t_list **list_b)
{
	if (line[1] == 'r')
	{
		if (line[2] == '\0')
			return (rotate_rotate(list_a, list_b), EXIT_SUCCESS);
		else if (line[2] == 'a')
			return (reverse_rotate_a(list_a, yes_write), EXIT_SUCCESS);
		else if (line[2] == 'b')
			return (reverse_rotate_b(list_b, yes_write), EXIT_SUCCESS);
		else
			return (EXIT_FAILURE);
	}
	else if (line[1] == 'a')
		return (rotate_a(list_a, yes_write), EXIT_SUCCESS);
	else if (line[1] == 'b')
		return (rotate_b(list_b, yes_write), EXIT_SUCCESS);
	else 
		return (EXIT_FAILURE);
}

int execute_swap(char *line, t_list **list_a, t_list **list_b)
{
	if (line[1] == 'a')
		return (swap_a(list_a, yes_write), EXIT_SUCCESS);
	else if (line[1] == 'b')
		return (swap_b(list_b, yes_write), EXIT_SUCCESS);
	else if (line[1] == 's')
		return (swap_swap(list_a, list_b), EXIT_SUCCESS);
	else 
		return (EXIT_FAILURE);
}

int execute_push(char *line, t_list **list_a, t_list **list_b)
{
	if (line[1] == 'a')
		return (push_a(list_a, list_b), EXIT_SUCCESS);
	else if (line[1] == 'b')
		return (push_b(list_a, list_b), EXIT_SUCCESS);
	else 
		return (EXIT_FAILURE);
}

int	execute_command(char *line, t_list **list_a, t_list **list_b)
{
	if (line[0] == 'r')
		return (execute_rotate(line, list_a, list_b));
	else if (line[0] == 's')
		return (execute_swap(line, list_a, list_b));
	else if (line[0] == 'p')
		return (execute_push(line, list_a, list_b));
	else
		return (EXIT_FAILURE);
}

int create_and_sort_list_b_and_a(t_list **list_a)
{
	char *line;
	char *tmp;
	t_list	*list_b;
	
	list_b = NULL;
	line = get_next_line(STDOUT_FILENO);
	while (line != NULL)
	{
		if (execute_command(line, list_a, &list_b) != EXIT_SUCCESS)
			return (free(line), EXIT_FAILURE);
		free(line);
		line = get_next_line(STDOUT_FILENO);
	}
	return (EXIT_SUCCESS);
}
