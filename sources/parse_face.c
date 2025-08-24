/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_face.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 07:41:13 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/24 09:31:49 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/scop.h"

int verify_face(char *face)
{
	int i = 0;
	while (face[i] == ' ')
		i++;
	if (!face[i])
		return (0);
	return (1);
}

int count_face(t_render *render)
{
	int i = 0;
	int count = 0;
	while (render->object.raw[i])
	{
		if (render->object.raw[i][0] == 'f' && render->object.raw[i][1] == ' ')
		{
			if (verify_face(&render->object.raw[i][2]) == 0)
			{
				write(2, "face is invalid at line ", 24);
				ft_putnbr_fd(i + 1, 2);
				end_program(OBJECT_FILE_ERROR, "", render);
			}
			count++;
		}
		i++;
	}
	return (count);
}

void add_face_data(t_face *face, char *line, t_render *render)
{
	int i = 0;

	face->vertex_count = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (!line[i])
			break ;
		while (line[i] && line[i] != ' ')
			i++;
		face->vertex_count++;
	}
	if (face->vertex_count < 3)
	{
		write(2, line, ft_strlen(line));
		end_program(OBJECT_FILE_ERROR, "Error face doesnt have atleast 3 vextexes", render);
	}
	face->vertex = (t_vertex **)malloc(face->vertex_count * sizeof(t_vertex *));
	if (!face->vertex)
		end_program(MALLOC_ERROR, "Malloc error: face vertex", render);
	i = 0;
	int temp;
	int j = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (!line[i])
			break ;
		temp = atoi(&line[i]) - 1;
		if (temp >= render->object.vertex_count)
		{
			write(2, line, ft_strlen(line));
			end_program(OBJECT_FILE_ERROR, "Error index outside of vertex", render);
		}
		face->vertex[j] = &render->object.vertex[temp];
		while (line[i] && line[i] != ' ')
			i++;
		j++;
	}
}

void add_face(t_render *render)
{
	int i = 0;
	int count = 0;
	while (render->object.raw[i])
	{
		if (render->object.raw[i][0] == 'f' && render->object.raw[i][1] == ' ')
		{
			render->object.face[count + 1].vertex = NULL;
			add_face_data(&render->object.face[count], &render->object.raw[i][2], render);
			count++;
		}
		i++;
	}
}

void get_object_face(t_render *render)
{
	render->object.face_count = count_face(render);
	render->object.face = (t_face *)malloc((render->object.face_count + 1) * sizeof(t_face));
	if (!render->object.face)
		end_program(MALLOC_ERROR, "Malloc error: face", render);
	render->object.face[0].vertex = NULL;
	add_face(render);
}