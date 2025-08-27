/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 08:30:10 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/27 16:32:00 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/scop.h"

void keyboard_input(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	t_render *render = glfwGetWindowUserPointer(window);
	if (action == GLFW_RELEASE)
		return ;
	
	switch (key)
	{
		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(window, GL_TRUE);
			return ;
		case GLFW_KEY_UP:
			glTranslatef(0.0f, -0.1f, 0.0f);
			return ;
		case GLFW_KEY_DOWN:
			glTranslatef(0.0f, 0.1f, 0.0f);
			return ;
		case GLFW_KEY_LEFT:
			glTranslatef(0.1f, 0.0f, 0.0f);
			return ;
		case GLFW_KEY_RIGHT:
			glTranslatef(-0.1f, 0.0f, 0.0f);
			return ;
		case GLFW_KEY_KP_ADD:
			render->scale *= 1.1f;
			return ;
		case GLFW_KEY_KP_SUBTRACT:
			render->scale *= 0.9f;
			return ;
		
		default:
			break;
	}
	(void)scancode;
	(void)mods;
}
