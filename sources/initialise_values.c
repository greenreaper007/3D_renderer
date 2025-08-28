/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_values.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 05:17:21 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/28 18:13:36 by flturbou         ###   ########.fr       */
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

	render->key.is_angleyup = 0;
	render->key.is_angleydown = 0;
	render->key.is_anglexup = 0;
	render->key.is_anglexdown = 0;
	render->key.is_anglezup = 0;
	render->key.is_anglezdown = 0;

}

void initialise_values(t_render *render)
{
	render->glfw = 0;
	render->scale = ZOOM;
	render->angle.x = 0.0f;
	render->angle.y = 0.0f;
	render->angle.z = 0.0f;
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
