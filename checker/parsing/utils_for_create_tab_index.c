/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_create_tab_index.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandine <amandine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 11:15:20 by acocoual          #+#    #+#             */
/*   Updated: 2025/10/17 01:50:02 by amandine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	free_tab_str(char **tab_str, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(tab_str[i++]);
	free(tab_str);
}

int	len_tab(char **tab)
{
	int	len;

	len = 0;
	while (tab[len] != NULL)
		len++;
	return (len);
}

int	create_input_str(char **str, char *argv)
{
	char	*tmp;

	tmp = ft_strjoin(*str, " ");
	if (tmp == NULL)
		return (free(*str), EXIT_FAILURE);
	free(*str);
	*str = ft_strjoin(tmp, argv);
	if (*str == NULL)
		return (free(tmp), EXIT_FAILURE);
	free(tmp);
	return (EXIT_SUCCESS);
}

int	create_tab_str(int argc, char **argv, char ***tab_str)
{
	int		i;
	int		status;
	char	*str;

	i = 2;
	str = ft_strdup(argv[1]);
	if (str == NULL)
		return (EXIT_FAILURE);
	if (argc > 2)
	{
		while (i != argc)
		{
			status = create_input_str(&str, argv[i++]);
			if (status == EXIT_FAILURE)
				return (status);
		}
	}
	*tab_str = ft_split(str, ' ');
	free(str);
	if (*tab_str == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
