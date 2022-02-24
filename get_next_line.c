/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsage <jsage@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:49:00 by jsage             #+#    #+#             */
/*   Updated: 2022/02/24 17:07:33 by jsage            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buf;
	char	*line;
	int		i;

	if (fd < 0)
		return (NULL);
	line = ft_strdup("");
	while (read(fd, &buf, 1) > 0)
	{
		line = ft_strjoin(line, buf);
		if (buf == '\n')
			break ;
	}
	i = 0;
	while (line[i])
		i++;
	if (i == 0)
	{
		free(line);
		line = NULL;
	}
	return (line);
}
