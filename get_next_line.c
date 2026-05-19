//Liberar espacio de memoria de los nodos impresos
static void	upload_list(t_list **list)
{
	
}
//funcion que se desplace por la lista y me imprima hasta que encuentre un salto de linea
static int	line_len(t_list *list)
{
	int	i;
	int	len;

	len = 0;
	while (list)
	{
		i = 0;
		while(list->((char *)content)[i])
		{
			if(list->((char *)content)[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

static char	*get_one_line(t_list *list)
{
	char	*next_line;

	next_line = malloc((line_len(list)) + 1);
	if (next_line == NULL)
		return (NULL);
	return (next_line);
}
//funcion que me cree y rellene una lista enlazada en el que cada nodo este el numero de bytes que se puede leer 
static void	addNewNode(t_list **list)
{
	t_list	*newNode;

	newNode = malloc(sizeof(t_list));
	if (NULL == newNode)
		return ;
	ft_lstadd_back(list, newNode);
}

static void	create_list(t_list **list, int fd)
{
	int		numChar;
	char	*buf;

	while(!funciondehacerlista)
	{
		buf = malloc(BUFFERSIZE + 1);
		if (!buf)
			return ;
		numChar = read(fd, buf, BUFFERSIZE);
		if(numChar == -1)
		{
			free(buf);
			return ;
		}
		buf[numChar] = '\0';
		addNewNode(list);
	}
}
//get_next_line
char *get_next_line(int fd)
{
	static t_list	*list;
	char			*currentLine;

	//If para asegurarnos de que el archivo al menos se puede leer
	if (fd < 0 || BUFFERSIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	//find a line
	currentLine = get_one_line(list);
	//upload the list
	upload_list(&list);
	return (currentLine);
}
//un main que me abra el archivo
int	main()
{
	int	fd;

	fd = open("archivo.txt", O_RDONLY, 0644);
	if (fd == -1)
		return(1);
	get_next_line(fd);
	return (0);
}