//Liberar espacio de memoria de los nodos impresos
//funcion que se desplace por la lista y me imprima hasta que encuentre un salto de linea
//funcion que me cree y rellene una lista enlazada en el que cada nodo este el numero de bytes que se puede leer 
void	create_list(t_list **list, int fd)
{
	int		numChar;
	char	*buf;

	while(!funciondehacerlista)
	{
		buf = malloc(BUFFERSIZE + 1);
		if (!buf)
			return ;
		numChar = read(fd, buf, BUFFERSIZE);
		if(!numChar)
		{
			free(buf);
			return ;
		}
		buf[numChar] = '\0';
		//addNewNode
	}
}
//get_next_line
char *get_next_line(int fd)
{
	static t_list	*list;
	char			*currentLine;

	if (fd < 0 || BUFFERSIZE <= 0 || read(fd, &currentLine) < 0)
		return (NULL);
	create_list(&list, fd);
	//find a line
	//upload the list
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