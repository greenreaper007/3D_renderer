/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 04:42:54 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/27 09:28:27 by flturbou         ###   ########.fr       */
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
	//print_data(render);
	create_window(render);
	display_frame(render);
	
	end_program(SUCCESS, "Main function finished", render);
}
