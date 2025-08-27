/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_perspective.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:33:00 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/27 09:33:56 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/scop.h"

void perspective(float fov, float aspect, float near, float far, mat4 out)
{
    float f = 1.0f / tanf(fov * 0.5f * (3.14159265f / 180.0f));
    out[0] = f / aspect;
    out[1] = 0.0f;
    out[2] = 0.0f;
    out[3] = 0.0f;

    out[4] = 0.0f;
    out[5] = f;
    out[6] = 0.0f;
    out[7] = 0.0f;

    out[8] = 0.0f;
    out[9] = 0.0f;
    out[10] = (far + near) / (near - far);
    out[11] = -1.0f;

    out[12] = 0.0f;
    out[13] = 0.0f;
    out[14] = (2 * far * near) / (near - far);
    out[15] = 0.0f;
}
