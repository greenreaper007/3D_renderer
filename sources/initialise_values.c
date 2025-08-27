/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 05:17:21 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/27 17:33:30 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/scop.h"

void reset_key_state(t_render *render)
{
	render->key.is_uparrow = 0;
	render->key.is_downarrow = 0;
	render->key.is_leftarrow = 0;
	render->key.is_rightarrow = 0;
	render->key.is_zoomin = 0;
	render->key.is_zoomout = 0;
}

void initialise_values(t_render *render)
{
	render->glfw = 0;
	render->scale = ZOOM;
	render->window = NULL;
	render->time_before_frame = 0;
	render->time_after_frame = 0;
	render->frame_count = 0;
	render->object.raw = NULL;
	render->object.name = NULL;
	render->object.vertex = NULL;
	render->object.face = NULL;
	reset_key_state(render);
}
