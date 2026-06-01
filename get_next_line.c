#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

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

static int	line_len(t_list *list)
{
	int	i;
	int	len;

	len = 0;
	while (list)
	{
		i = 0;
		while (((char *)list->content)[i])
		{
			len++;
			if (((char *)list->content)[i] == '\n')
				return (len);
			i++;
		}
		list = list->next;
	}
	return (len);
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
	t_list	*actualNode;
	char	*rest;
	int		i;
	int		j;

	actualNode = *list;
	while (actualNode && !ft_strchr(actualNode->content, '\n'))
		actualNode = actualNode->next;
	if (!actualNode)
	{
		clean_list(list);
		return ;
	}
	i = 0;
	while (((char *)actualNode->content)[i] != '\n')
		i++;
	i++;
	rest = malloc(ft_strlen(actualNode->content + i) + 1);
	if (!rest)
		return ;
	j = 0;
	while (((char *)actualNode->content)[i])
		rest[j++] = ((char *)actualNode->content)[i++];
	rest[j] = '\0';

	clean_list(list);

	if (!rest[0])
	{
		free(rest);
		*list = NULL;
		return ;
	}
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

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
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
}