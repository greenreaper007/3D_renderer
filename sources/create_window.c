/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 08:09:43 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/27 17:01:18 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/scop.h"

void create_window(t_render *render)
{
	render->glfw = glfwInit();
	if (!render->glfw)
		end_program(GLFW_ERROR, "GLFW error: cannot initialise GLFW", render);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	render->window = glfwCreateWindow(WINDOW_LENGTH, WINDOW_HEIGHT, render->object.name, NULL, NULL);
	if (!render->window)
		end_program(GLFW_ERROR, "GLFW error: cannot create window", render);
	glfwMakeContextCurrent(render->window);
	glfwSetKeyCallback(render->window, keyboard_input);
	glfwSetWindowUserPointer(render->window, render);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	//glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glClearColor(0.0, 0.0, 0.0, 1.0);
}
