/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 04:52:27 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/24 09:21:28 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/scop.h"

void free_tab(char **tab)
{
	size_t i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void free_face(t_render *render)
{
	int i = 0;
	while (render->object.face[i].vertex)
	{
		free(render->object.face[i].vertex);
		i++;
	}
	free(render->object.face);
}

void free_all(t_render *render)
{
	if (!render)
		return ;
	if (render->frame_image)
	{
		mlx_destroy_image(render->mlx, render->frame_image);
	}
	if (render->win)
	{
		mlx_destroy_window(render->mlx, render->win);
	}
	if (render->mlx)
	{
		mlx_destroy_display(render->mlx);
		free(render->mlx);
	}
	if (render->object.raw)
	{
		free_tab(render->object.raw);
	}
	if (render->object.name)
	{
		free(render->object.name);
	}
	if (render->object.vertex)
	{
		free(render->object.vertex);
	}
	if (render->object.face)
	{
		free_face(render);
	}


	free(render);
}

void end_program(int error_code, char *message, t_render *render)
{
	if (error_code == SUCCESS)
	{
		printf("%s\n", message);
	}
	else
	{
		if (message[0])
			write(2, message, ft_strlen(message));
		write(2, "\n", 1);
	}
	free_all(render);
	exit(error_code);
}
