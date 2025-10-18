/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 01:33:15 by amandine          #+#    #+#             */
/*   Updated: 2025/10/18 16:50:28 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	execute_rotate(char *line, t_list **list_a, t_list **list_b)
{
	if (line[1] == 'r')
	{
		if (line[2] == '\n' && line[3] == '\0')
			return (rotate_rotate(list_a, list_b), is_OK);
		else if (line[2] == 'a' && line[3] == '\n' && line[4] == '\0')
			return (reverse_rotate_a(list_a), is_OK);
		else if (line[2] == 'b' && line[3] == '\n' && line[4] == '\0')
			return (reverse_rotate_b(list_b), is_OK);
		else
			return (is_ERROR);
	}
	else if (line[1] == 'a' && line[2] == '\n' && line[3] == '\0')
		return (rotate_a(list_a), is_OK);
	else if (line[1] == 'b' && line[2] == '\n' && line[3] == '\0')
		return (rotate_b(list_b), is_OK);
	else
		return (is_ERROR);
}

int	execute_swap(char *line, t_list **list_a, t_list **list_b)
{
	if (line[1] == 'a' && line[2] == '\n' && line[3] == '\0')
		return (swap_a(list_a), is_OK);
	else if (line[1] == 'b' && line[2] == '\n' && line[3] == '\0')
		return (swap_b(list_b), is_OK);
	else if (line[1] == 's' && line[2] == '\n' && line[3] == '\0')
		return (swap_swap(list_a, list_b), is_OK);
	else
		return (is_ERROR);
}

int	execute_push(char *line, t_list **list_a, t_list **list_b)
{
	if (line[1] == 'a' && line[2] == '\n' && line[3] == '\0')
		return (push_a(list_a, list_b), is_OK);
	else if (line[1] == 'b' && line[2] == '\n' && line[3] == '\0')
		return (push_b(list_a, list_b), is_OK);
	else
		return (is_ERROR);
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
		return (is_ERROR);
}

int	create_and_sort_list_b_and_a(t_list **list_a)
{
	char	*line;
	t_list	*list_b;

	list_b = NULL;
	line = get_next_line(STDOUT_FILENO);
	if (line == NULL)
		return (is_ERROR);
	printf("line = %s\n", line);
	while (line != NULL)
	{
		if (execute_command(line, list_a, &list_b) != is_OK)
			return (free(line), is_ERROR);
		free(line);
		// line = get_next_line(STDOUT_FILENO);
		line = NULL;
		printf("line = %s\n", line);
	}
	return (is_OK);
}
