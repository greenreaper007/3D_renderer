/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 05:35:56 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/26 08:01:49 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/scop.h"

void get_object_name(t_render *render)
{
	int i = 0;
	int j;
	while (render->object.raw[i])
	{
		if (render->object.raw[i][0] == 'o')
		{
			j = 1;
			while (render->object.raw[i][j] == ' ')
				j++;
			if (render->object.raw[i][j])
			{
				render->object.name = ft_strdup(&render->object.raw[i][j]);
				if (!render->object.name)
					end_program(MALLOC_ERROR, "Malloc error: Object.name", render);
				if (render->object.name[ft_strlen(render->object.name) - 1] == '\n')
					render->object.name[ft_strlen(render->object.name) - 1] = 0;
				return ;
			}
		}
		i++;
	}
	render->object.name = ft_strdup("Unamed object");
	if (!render->object.name)
		end_program(MALLOC_ERROR, "Malloc error: Object.name", render);
}

void parse_object(t_render *render, char *file_path)
{
	copy_file(render, file_path);
	get_object_name(render);
	printf("Getting %s file vertexes\n", render->object.name);
	get_object_vertex(render);
	printf("Getting %s file faces\n", render->object.name);
	get_object_face(render);
	printf("Parsing for %s file completed\n", render->object.name);
}
