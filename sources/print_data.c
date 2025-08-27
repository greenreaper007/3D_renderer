/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 07:56:51 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/26 07:57:41 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/scop.h"

void print_data(t_render *render)
{
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
}
