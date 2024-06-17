/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/14 10:37:02 by pminialg      #+#    #+#                 */
/*   Updated: 2024/02/16 09:50:33 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_free_gnl(char **string)
{
	free(*string);
	*string = NULL;
	return (NULL);
}

char	*next_line_data(char *buffer, char **line_data)
{
	char	*line_next;
	char	*temp_ptr;
	int		length;

	temp_ptr = ft_strchr(buffer, '\n');
	if (!temp_ptr)
	{
		line_next = NULL;
		return (ft_free_gnl(&buffer));
	}
	else
		length = (temp_ptr - buffer) + 1;
	if (!buffer[length])
		return (ft_free_gnl(&buffer));
	line_next = ft_substr(buffer, length, ft_strlen(buffer) - length);
	ft_free_gnl(&buffer);
	if (!line_next)
		return (ft_free_gnl(line_data));
	return (line_next);
}

char	*get_line_from_buffer(char *buffer)
{
	char	*line_data;
	char	*temp_ptr;	
	int		line_length;

	temp_ptr = ft_strchr(buffer, '\n');
	line_length = (temp_ptr - buffer) + 1;
	line_data = ft_substr(buffer, 0, line_length);
	if (!line_data)
		return (NULL);
	return (line_data);
}

char	*read_data_from_file(char *result, int fd)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ft_free_gnl(&result));
	buffer[0] = '\0';
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			result = ft_strjoin_checker(result, buffer);
			if (!result)
				return (ft_free_gnl(&buffer));
		}
	}
	free(buffer);
	if (bytes_read == -1)
		return (ft_free_gnl(&result));
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line_data;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if ((buffer && !ft_strchr(buffer, '\n')) || !buffer)
		buffer = read_data_from_file(buffer, fd);
	if (!buffer)
		return (NULL);
	line_data = get_line_from_buffer(buffer);
	if (!line_data)
		return (ft_free_gnl(&buffer));
	buffer = next_line_data(buffer, &line_data);
	return (line_data);
}
