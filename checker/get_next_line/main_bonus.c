/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acocoual <acocoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:42:33 by acocoual          #+#    #+#             */
/*   Updated: 2025/09/11 20:16:38 by acocoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line;

	fd1 = open("./get_next_line.c", O_RDONLY);
	fd2 = open("./get_next_line.c", O_RDONLY);
	line = get_next_line(fd1);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd2);
		printf("%s", line);
		free(line);
		line = get_next_line(fd1);
	}
	free(line);
	free(line);
	close(fd1);
	close(fd2);
	return (0);
}

// int	main(void)
// {
// 	int	fd1;
// 	int	fd2;

// 	fd1 = open("./get_next_line.c", O_RDONLY);
// 	fd2 = open("./get_next_line_bonus.c", O_RDONLY);
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd2));
// 	printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd2));
// 	printf("%s", get_next_line(fd2));
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }
