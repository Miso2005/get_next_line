
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s)
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	length;
	size_t	i;
	size_t	j;
	char	*str_join;
	size_t	len_s1;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	length = ft_strlen(s1) + ft_strlen(s2);
	str_join = malloc(length + 1);
	if (!str_join)
		return (NULL);
	while (i < len_s1)
	{
		str_join[i++] = s1[j++];
	}
	j = 0;
	while (i < length)
		str_join[i++] = s2[j++];
	str_join[i] = 0;
	return (str_join);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strdup(const char *s)
{
	size_t	length;
	char	*str;
	size_t	i;
	char	*src;

	src = (char *)s;
	length = ft_strlen(src) + 1;
	str = (char *)malloc((length) * sizeof(char));
	i = 0;
	if (str == NULL)
		return (0);
	while (s[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s || start >= (int)ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (len > (size_t)ft_strlen(s + start))
		len = (size_t)ft_strlen(s + start);
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
