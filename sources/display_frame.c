/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_frame.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:08:54 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/27 10:38:53 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/scop.h"

void draw_quad(t_face *face)
{
	glBegin(GL_QUADS);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(face->vertex[0]->x, face->vertex[0]->y, face->vertex[0]->z);

		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(face->vertex[1]->x, face->vertex[1]->y, face->vertex[1]->z);

		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(face->vertex[2]->x, face->vertex[2]->y, face->vertex[2]->z);

		glColor3f(0.0, 1, 1);
		glVertex3f(face->vertex[3]->x, face->vertex[3]->y, face->vertex[3]->z);
	glEnd();
}

void draw_triangle(t_vertex *v1, t_vertex *v2, t_vertex *v3)
{
	glBegin(GL_TRIANGLES);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(v1->x, v1->y, v1->z);

		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(v2->x, v2->y, v2->z);

		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(v3->x, v3->y, v3->z);
	glEnd();
}

void display_render(t_render *render)
{
	glClear(GL_COLOR_BUFFER_BIT);

	int i = 0;
	int j;
	t_face *face;
	while (i < render->object.face_count)
	{
		j = 0;
		face = &render->object.face[i];
		while (face->vertex_count - j >= 3)
		{
			draw_triangle(face->vertex[0], face->vertex[j + 1], face->vertex[j + 2]);
			j++;
		}
		i++;
	}

	glFlush();
}

void display_frame(t_render *render)
{
	while (!glfwWindowShouldClose(render->window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		render->time_before_frame = get_time();
		display_render(render);
		glfwSwapBuffers(render->window);
		render->time_after_frame = get_time();
		glfwPollEvents();
		render->frame_count++;
		printf("Frame %d took %ld\n", render->frame_count, render->time_after_frame - render->time_before_frame);
	}
}
