/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vertex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 06:38:21 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/25 01:34:16 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/scop.h"

int verify_vertex(char *vertex)
{
	int i = 0;
	int j = 0;
	while (j < 3)
	{
		while (vertex[i] == ' ')
			i++;
		if (!vertex[i])
			return (0);
		while (vertex[i] && vertex[i] != ' ')
			i++;
		if (j != 2 && !vertex[i])
			return (0);
		j++;
	}
	if (vertex[i])
		return (0);
	return (1);
}

int count_vertex(t_render *render)
{
	int i = 0;
	int count = 0;
	while (render->object.raw[i])
	{
		if (render->object.raw[i][0] == 'v' && render->object.raw[i][1] == ' ')
		{
			if (verify_vertex(&render->object.raw[i][2]) == 0)
			{
				write(2, "Vertex is invalid at line ", 26);
				ft_putnbr_fd(i + 1, 2);
				end_program(OBJECT_FILE_ERROR, "", render);
			}
			count++;
		}
		i++;
	}
	return (count);
}

void add_vertex_data(t_vertex *vertex, char *line)
{
	int i = 0;
	while (line[i] == ' ')
		i++;
	vertex->x = atof_fast(&line[i]);
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	vertex->y = atof_fast(&line[i]);
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	vertex->z = atof_fast(&line[i]);
}

void add_vertex(t_render *render)
{
	int i = 0;
	int count = 0;
	while (render->object.raw[i])
	{
		if (render->object.raw[i][0] == 'v' && render->object.raw[i][1] == ' ')
		{
			add_vertex_data(&render->object.vertex[count], &render->object.raw[i][2]);
			count++;
		}
		i++;
	}
}

void get_object_vertex(t_render *render)
{
	render->object.vertex_count = count_vertex(render);
	render->object.vertex = (t_vertex *)malloc(render->object.vertex_count * sizeof(t_vertex));
	if (!render->object.vertex)
		end_program(MALLOC_ERROR, "Malloc error: vertex", render);
	add_vertex(render);
}
