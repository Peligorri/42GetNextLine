#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&str[i]);
	return (NULL);
}

void	ft_lstadd_back(t_list **lst, t_list *newNode)
{
	t_list	*actualNode;

	if (!*lst)
	{
		*lst = newNode;
		return ;
	}
	actualNode = *lst;
	while (actualNode->next)
		actualNode = actualNode->next;
	actualNode->next = newNode;
}

static void	add_new_node(t_list **list, char *buf)
{
	t_list	*newNode;

	newNode = malloc(sizeof(t_list));
	if (!newNode)
		return ;
	newNode->content = buf;
	newNode->next = NULL;
	ft_lstadd_back(list, newNode);
}

static int	has_newline(t_list *list)
{
	while (list)
	{
		if (ft_strchr(list->content, '\n'))
			return (1);
		list = list->next;
	}
	return (0);
}
