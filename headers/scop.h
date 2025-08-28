/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flturbou <flturbou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 04:42:40 by flturbou          #+#    #+#             */
/*   Updated: 2025/08/28 18:12:04 by flturbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <fcntl.h>
#include <time.h>
#include <sys/time.h>
#include <GLFW/glfw3.h>
#include "../MyLibft/libft.h"

/* Graphic Data */
#define WINDOW_LENGTH 750
#define WINDOW_HEIGHT 750
#define ZOOM 0.1f

#define FPS 60
#define SECOND 1000000

/* Error code Data */
#define SUCCESS 0
#define ARGUMENT_ERROR 1
#define MALLOC_ERROR 2
#define GLFW_ERROR 3
#define OBJECT_FILE_ERROR 4
#define RENDER_ERROR 5

typedef struct s_key_state
{
	char is_uparrow;
	char is_downarrow;
	char is_leftarrow;
	char is_rightarrow;
	char is_zoomin;
	char is_zoomout;

	char is_angleyup;
	char is_angleydown;
	char is_anglexup;
	char is_anglexdown;
	char is_anglezup;
	char is_anglezdown;
	
} t_key_state;

typedef struct s_vertex
{
	float x;
	float y;
	float z;
	
} t_vertex;

typedef struct s_face
{
	t_vertex	**vertex;
	int			vertex_count;
	
} t_face;

typedef struct s_object
{
	char		**raw;
	char		*name;
	t_vertex	*vertex;
	int			vertex_count;
	t_face		*face;
	int			face_count;

} t_object;

typedef struct s_render
{
	GLFWwindow* window;
	int			glfw;
	float		scale;
	t_vertex	angle;
	long		time_before_frame;
	long		time_after_frame;
	int			frame_count;
	t_key_state key;
	t_object	object;

} t_render;

/* end_program.c */
void end_program(int error_code, char *message, t_render *render);

/* create_window.c */
void create_window(t_render * render);

/* display_frame.c */
void display_frame(t_render *render);

/* keyboard_input.c */
void do_keyboard_input(t_render *render);
void keyboard_input(GLFWwindow* window, int key, int scancode, int action, int mods);

/* initialise_values.c */
void initialise_values(t_render *render);

/* parse_object.c */
void parse_object(t_render *render, char *file_path);

/* parse_vertex.c */
void get_object_vertex(t_render *render);

/* parse_face.c */
void get_object_face(t_render *render);

/* copy_file.c */
void copy_file(t_render *render, char *file_path);

/* print_data.c */
void print_data(t_render *render);

/* get_time.c */
long get_time(void);

/* atof_fast.c */
float atof_fast(const char *s);

#endif