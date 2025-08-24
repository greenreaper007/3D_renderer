/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 04:42:54 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/24 07:58:04 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/scop.h"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(2, "Include the .obj file to render on the command line\n", 52);
		return (ARGUMENT_ERROR);
	}
	if (argc > 2)
	{
		write(2, "Include only the .obj file to render on the command line\n", 57);
		return (ARGUMENT_ERROR);
	}
	t_render *render = (t_render *)malloc(sizeof(t_render));
	if (!render)
	{
		end_program(MALLOC_ERROR, "Malloc error: t_render", render);
	}
	initialise_values(render);
	parse_object(render, argv[1]);
	
	int i = 0;
	while (i < render->object.vertex_count)
	{
		printf("x = %f y = %f z = %f\n", render->object.vertex[i].x, render->object.vertex[i].y, render->object.vertex[i].z);
		i++;
	}
	printf("%s has vertex count: %d\n", render->object.name, render->object.vertex_count);

	i = 0;
	while (i < render->object.face_count)
	{
		printf("{ x = %f y = %f z = %f , x = %f y = %f z = %f , x = %f y = %f z = %f }\n", render->object.face[i].first->x, render->object.face[i].first->y, render->object.face[i].first->z, render->object.face[i].second->x, render->object.face[i].second->y, render->object.face[i].second->z, render->object.face[i].second->x, render->object.face[i].second->y, render->object.face[i].second->z);
		i++;
	}
	printf("%s has vertex count: %d\n", render->object.name, render->object.face_count);

	end_program(SUCCESS, "Main function finished", render);
}
