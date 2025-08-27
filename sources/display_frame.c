/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_frame.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:08:54 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/27 17:39:29 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/scop.h"

void draw_face(t_face *face, float z)
{
	int i = 1;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(face->vertex[0]->x * z, face->vertex[0]->y * z, face->vertex[0]->z * z);
	while (1)
	{
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(face->vertex[i]->x * z, face->vertex[i]->y * z, face->vertex[i]->z * z);
		i++;
		if (i >= face->vertex_count)
			break ;
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(face->vertex[i]->x * z, face->vertex[i]->y * z, face->vertex[i]->z * z);
		i++;
		if (i >= face->vertex_count)
			break ;
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(face->vertex[i]->x * z, face->vertex[i]->y * z, face->vertex[i]->z * z);
		i++;
		if (i >= face->vertex_count)
			break ;
	}
	glEnd();
}

void display_render(t_render *render)
{
	glClear(GL_COLOR_BUFFER_BIT);

	int i = 0;
	while (i < render->object.face_count)
	{
		draw_face(&render->object.face[i], render->scale);
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
		do_keyboard_input(render);
		render->frame_count++;
		printf("Frame %d took %ld\n", render->frame_count, render->time_after_frame - render->time_before_frame);
	}
}
