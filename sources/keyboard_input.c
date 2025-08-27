/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 08:30:10 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/27 17:38:40 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/scop.h"

void do_keyboard_input(t_render *render)
{
	if (render->key.is_uparrow)
		glTranslatef(0.0f, -0.1f, 0.0f);
	if (render->key.is_downarrow)
		glTranslatef(0.0f, 0.1f, 0.0f);
	if (render->key.is_leftarrow)
		glTranslatef(0.1f, 0.0f, 0.0f);
	if (render->key.is_rightarrow)
		glTranslatef(-0.1f, 0.0f, 0.0f);
	if (render->key.is_zoomin)
		render->scale *= 1.1f;
	if (render->key.is_zoomout)
		render->scale *= 0.9f;
}

void keyboard_input(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	t_render *render = glfwGetWindowUserPointer(window);
	if (action == GLFW_REPEAT)
		return ;
	
	switch (key)
	{
		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(window, GL_TRUE);
			return ;
		case GLFW_KEY_UP:
			render->key.is_uparrow = !render->key.is_uparrow;
			return ;
		case GLFW_KEY_DOWN:
			render->key.is_downarrow = !render->key.is_downarrow;
			return ;
		case GLFW_KEY_LEFT:
			render->key.is_leftarrow = !render->key.is_leftarrow;
			return ;
		case GLFW_KEY_RIGHT:
			render->key.is_rightarrow = !render->key.is_rightarrow;
			return ;
		case GLFW_KEY_KP_ADD:
			render->key.is_zoomin = !render->key.is_zoomin;
			return ;
		case GLFW_KEY_KP_SUBTRACT:
			render->key.is_zoomout = !render->key.is_zoomout;
			return ;
		
		default:
			break;
	}
	(void)scancode;
	(void)mods;
}
