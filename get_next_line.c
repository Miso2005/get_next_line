
#include "get_next_line.h"

static void	free_t(char **t)
{
	free(*t);
	*t = NULL;
}

static char	*extract_line(char *t)
{
	int		i;
	char	*line;

	i = 0;
	if (!t || !*t)
		return (NULL);
	while (t[i] && t[i] != '\n')
		i++;
	if (t[i] == '\n')
		i++;
	line = ft_substr(t, 0, i);
	return (line);
}

static char	*update(char **t)
{
	int		i;
	char	*temp;

	i = 0;
	if (!*t || **t == '\0')
	{
		free_t(t);
		return (NULL);
	}
	while ((*t)[i] && (*t)[i] != '\n')
		i++;
	if ((*t)[i] == '\n')
		i++;
	if (!(*t)[i])
	{
		free_t(t);
		return (NULL);
	}
	temp = ft_strdup(*t + i);
	free(*t);
	*t = temp;
	return (*t);
}

static char	*read_buf(char **t, int fd)
{
	char	*tmp;
	int		byte;
	char	*buff;

	byte = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!*t)
		*t = ft_strdup("");
	while (byte > 0 && !ft_strchr(*t, '\n'))
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
			free_t(t);
		if (byte == 0 || byte == -1)
			break ;
		buff[byte] = '\0';
		tmp = ft_strjoin(*t, buff);
		free(*t);
		*t = tmp;
	}
	free(buff);
	return (*t);
}

char	*get_next_line(int fd)
{
	static char	*t;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		free_t(&t);
		return (NULL);
	}
	if (!(read_buf(&t, fd)))
	{
		free_t(&t);
		return (NULL);
	}
	line = extract_line(t);
	if (!line)
	{
		free_t(&t);
		return (NULL);
	}
	update(&t);
	return (line);
}
