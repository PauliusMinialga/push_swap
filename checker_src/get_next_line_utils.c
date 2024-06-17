/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 10:38:00 by pminialg      #+#    #+#                 */
/*   Updated: 2024/02/16 09:51:02 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return (&((char *)str)[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return (&((char *)str)[i]);
	return (NULL);
}

char	*ft_strjoin_checker(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*strjoin;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	strjoin = malloc(((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char)));
	if (!strjoin)
		return (ft_free_gnl(&s1));
	i = -1;
	while (s1[++i])
		strjoin[i] = s1[i];
	j = -1;
	while (s2[++j])
		strjoin[i + j] = s2[j];
	strjoin[i + j] = '\0';
	ft_free_gnl(&s1);
	return (strjoin);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*substr;
	unsigned int	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		len = 0;
	if (len > str_len - start)
		len = str_len - start;
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[i + start])
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
