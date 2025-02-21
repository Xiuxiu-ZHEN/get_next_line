/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhen <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 19:50:19 by xzhen             #+#    #+#             */
/*   Updated: 2025/01/31 20:25:59 by xzhen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buf(int fd, char *buff, char *left)
{
	int		i;
	char	*tempp;

	i = read(fd, buff, BUFFER_SIZE);
	while (i > 0)
	{
		buff[i] = '\0';
		if (left)
			tempp = ft_strjoin(left, buff);
		else
			tempp = ft_strdup(buff);
		free(left);
		left = tempp;
		if (ft_strchr(left, '\n'))
			break ;
		i = read(fd, buff, BUFFER_SIZE);
	}
	if ((i == 0 && left && *left == '\0') || i < 0)
	{
		free(left);
		left = NULL;
	}
	free(buff);
	return (left);
}

char	*extract_line(char *left)
{
	char	*a;
	char	*b;

	a = ft_strchr(left, '\n');
	if (a)
		b = ft_substr(left, 0, (a - left + 1));
	else
		b = ft_strdup(left);
	return (b);
}

char	*leftover(char *left)
{
	char	*a;
	char	*b;

	a = ft_strchr(left, '\n');
	if (a)
		b = ft_strdup(a + 1);
	else
		b = NULL;
	return (b);
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		*buffer;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	left = read_buf(fd, buffer, left);
	if (!left)
		return (NULL);
	line = extract_line(left);
	temp = leftover(left);
	free(left);
	left = temp;
	return (line);
}
