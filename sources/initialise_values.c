/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 05:17:21 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/24 06:31:42 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/scop.h"

void initialise_values(t_render *render)
{
	render->mlx = NULL;
	render->win = NULL;
	render->frame_image = NULL;
	render->object.raw = NULL;
	render->object.name = NULL;
	render->object.vertex = NULL;
	render->object.face = NULL;
}
