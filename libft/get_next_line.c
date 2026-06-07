/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:08:20 by aforcada          #+#    #+#             */
/*   Updated: 2026/03/13 20:06:20 by aforcada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_clean(char *stash, ssize_t *pt_size);
static char		*ft_extract(char *stash, ssize_t size);
static ssize_t	ft_accumulate(int fd, char **pt_stash);
static ssize_t	ft_fill(int fd, char **pt_stash, ssize_t size);
char			*get_next_line(int fd);

static char	*ft_clean(char *stash, ssize_t *pt_size)
{
	ssize_t	total;
	char	*endl;
	char	*clean;

	if (stash == NULL)
		return (NULL);
	if (*pt_size < 1)
		return (free(stash), NULL);
	endl = gnl_strlchr(stash, '\n', *pt_size);
	if (endl)
		total = endl - stash + 1;
	else
		total = *pt_size;
	if (total < *pt_size)
	{
		clean = gnl_strlcpy(stash + total, (*pt_size) - total);
		*pt_size = *pt_size - total;
		return (free(stash), stash = NULL, clean);
	}
	*pt_size = 0;
	return (free(stash), stash = NULL, NULL);
}

static char	*ft_extract(char *stash, ssize_t size)
{
	char	*line;
	char	*endl;
	ssize_t	total;

	if (!stash || size < 1)
		return (NULL);
	endl = gnl_strlchr(stash, '\n', size);
	if (endl)
		total = endl - stash + 1;
	else
		total = size;
	if (total < 1)
		return (NULL);
	line = gnl_strlcpy(stash, total);
	return (line);
}

static ssize_t	ft_accumulate(int fd, char **pt_stash)
{
	ssize_t	len;
	ssize_t	size;

	size = 0;
	if (*pt_stash != NULL)
		size = gnl_strchr(*pt_stash, '\0') - (*pt_stash);
	if (*pt_stash != NULL && gnl_strlchr(*pt_stash, '\n', size))
		return (size);
	len = ft_fill(fd, pt_stash, size);
	if (len < 0)
		return (free(*pt_stash), *pt_stash = NULL, -1);
	size += len;
	while (len > 0 && !gnl_strlchr(*pt_stash, '\n', size))
	{
		len = ft_fill(fd, pt_stash, size);
		if (len < 0)
			return (free(*pt_stash), *pt_stash = NULL, -1);
		size += len;
	}
	return (size);
}

static ssize_t	ft_fill(int fd, char **pt_stash, ssize_t size)
{
	char	*buf;
	ssize_t	len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (-1);
	len = read(fd, buf, BUFFER_SIZE);
	if (len < 1)
		return (free(buf), buf = NULL, len);
	buf[len] = '\0';
	if (size == 0)
		*pt_stash = gnl_strlcpy(buf, len);
	if (size > 0)
		*pt_stash = gnl_strlcat(*pt_stash, size, buf, len);
	return (free(buf), buf = NULL, len);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	ssize_t		size;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	size = ft_accumulate(fd, &stash);
	line = ft_extract(stash, size);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	stash = ft_clean(stash, &size);
	return (line);
}
