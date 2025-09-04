/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_faces_distance.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:44:55 by flturbou          #+#    #+#             */
/*   Updated: 2025/09/04 18:25:01 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/scop.h"

void compute_camera_forward(t_render *render, float out_forward[3])
{
	float yaw = render->angle.x * M_PI / 180.0f;
	float pitch = render->angle.y / 180.0f;
	float roll = render->angle.z * M_PI / 180.0f;

	// Rotation matrices
	float cy = cosf(yaw);
	float sy = sinf(yaw);
	float cp = cosf(pitch);
	float sp = sinf(pitch);
	float cr = cosf(roll);
	float sr = sinf(roll);

	// Composite rotation matrix: R = Yaw * Pitch * Roll
	float R[3][3];

	R[0][0] = cy * cr + sy * sp * sr;
	R[0][1] = sr * cp;
	R[0][2] = -sy * cr + cy * sp * sr;

	R[1][0] = -cy * sr + sy * sp * cr;
	R[1][1] = cr * cp;
	R[1][2] = sr * sy + cy * sp * cr;

	R[2][0] = sy * cp;
	R[2][1] = -sp;
	R[2][2] = cy * cp;

	// Default forward vector in OpenGL: (0, 0, -1)
	out_forward[0] = -R[0][2];
	out_forward[1] = -R[1][2];
	out_forward[2] = -R[2][2];

	// Normalize (optional but recommended)
	float len;
	len = sqrtf(out_forward[0]*out_forward[0] + out_forward[1]*out_forward[1] + out_forward[2]*out_forward[2]);

    if (len > 0.0001f)
	{
		out_forward[0] /= len;
		out_forward[1] /= len;
		out_forward[2] /= len;
	}
}

float dot_to_camera(const float* point, const float* camera_pos, const float* view_dir)
{
    float dx = point[0] - camera_pos[0];
    float dy = point[1] - camera_pos[1];
    float dz = point[2] - camera_pos[2];
    return (dx * view_dir[0] + dy * view_dir[1] + dz * view_dir[2]);
}

int compare_faces(const void* a, const void* b)
{
    const face_t* fa = (const face_t*)a;
    const face_t* fb = (const face_t*)b;

    float da = dot_to_camera(fa->center, camera_pos, cam_forward);
    float db = dot_to_camera(fb->center, camera_pos, cam_forward);

    return (da < db) ? 1 : (da > db) ? -1 : 0;
}

void sort_faces_distance(t_render *render)
{
	float out_forward[3];
	compute_camera_forward(render, out_forward);
}
