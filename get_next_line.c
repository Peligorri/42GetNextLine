/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 11:05:14 by jangonza          #+#    #+#             */
/*   Updated: 2026/06/01 16:43:48 by jangonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	create_list(t_list **list, int fd)
{
	int		bytes;
	char	*buf;

	while (!has_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
		{
			free(buf);
			return ;
		}
		buf[bytes] = '\0';
		add_new_node(list, buf);
	}
}

static char	*get_one_line(t_list *list)
{
	char	*line;
	int		i;
	int		k;

	line = malloc(line_len(list) + 1);
	if (!line)
		return (NULL);
	k = 0;
	while (list)
	{
		i = 0;
		while (((char *)list->content)[i])
		{
			line[k++] = ((char *)list->content)[i];
			if (((char *)list->content)[i++] == '\n')
			{
				line[k] = '\0';
				return (line);
			}
		}
		list = list->next;
	}
	line[k] = '\0';
	return (line);
}

static void	clean_list(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = tmp;
	}
}

static void	cut_list(t_list **list)
{
	t_list	*actual_node;
	char	*rest;
	int		i;
	int		j;

	actual_node = *list;
	while (actual_node && !ft_strchr(actual_node->content, '\n'))
		actual_node = actual_node->next;
	if (!actual_node)
		return (clean_list(list));
	i = 0;
	while (((char *)actual_node->content)[i] != '\n')
		i++;
	rest = malloc(ft_strlen(actual_node->content + ++i) + 1);
	if (!rest)
		return (free(rest));
	j = 0;
	while (((char *)actual_node->content)[i])
		rest[j++] = ((char *)actual_node->content)[i++];
	rest[j] = '\0';
	clean_list(list);
	if (!rest[0])
		return (free(rest));
	add_new_node(list, rest);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (!list)
		return (NULL);
	line = get_one_line(list);
	cut_list(&list);
	return (line);
}

/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("bla", O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}*/
