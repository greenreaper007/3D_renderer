/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 05:56:16 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/24 06:53:44 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/scop.h"

int count_lines(t_render *render, char *file_path)
{
	int fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		end_program(ARGUMENT_ERROR, "Object file could not be open/read", render);
	}
	int i = 1;
	char *temp;
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		i++;
		free(temp);
	}
	close(fd);
	if (i == 1)
	{
		end_program(OBJECT_FILE_ERROR, "Object file is empty", render);
	}
	return (i);
}

void copy_file(t_render *render, char *file_path)
{
	int i = count_lines(render, file_path);
	render->object.raw = (char **)malloc(i * sizeof(char *));
	if (!render->object.raw)
	{
		end_program(MALLOC_ERROR, "Malloc error: object.raw", render);
	}
	int fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		end_program(ARGUMENT_ERROR, "Object file could not be open/read", render);
	}
	i = 0;
	while (1)
	{
		render->object.raw[i] = get_next_line(fd);
		if (!render->object.raw[i])
			break ;
		render->object.raw[i + 1] = NULL;
		i++;
	}
	close(fd);
}
