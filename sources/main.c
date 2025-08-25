/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 04:42:54 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/25 01:35:40 by flturbou         ###   ########.fr       */
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
	int j;
	while (i < render->object.face_count)
	{
		j = 0;
		printf("{ ");
		while (j < render->object.face[i].vertex_count)
		{
			printf("%f %f %f", render->object.face[i].vertex[j]->x, render->object.face[i].vertex[j]->y, render->object.face[i].vertex[j]->z);
			j++;
			if (j < render->object.face[i].vertex_count)
				printf(" , ");
		}
		printf(" }\n");
		i++;
	}
	printf("%s has face count: %d\n", render->object.name, render->object.face_count);

	end_program(SUCCESS, "Main function finished", render);
}
