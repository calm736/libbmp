/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bitmap.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/12 18:40:33 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/13 11:46:19 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "bmp.h"

/*
** DECODE
*/

int							get_imagedata(t_bmp *bmp);
void						decode_bitmap_info_header(t_bmp *bmp);
void						decode_bmp_file_header(t_bmp *bmp);
t_bmp						*decode(const char *path);

/*
** ENCODE
*/

void						fill_headers(t_bmp *bmp, int width, int height);
t_bitmap_data				*fill_imagedata(char *img, int width, int height);
t_bmp						*encode(char *img, int width, int height);
void						write_rgb(t_bmp *bmp);
void						write_headers(t_bmp *bmp);
int							export_as_bmp(char *path, char *img, int width,
							int height);
/*
** SHARED
*/

t_bmp						*init_bmp(void);
t_bitmap_data				*new_bitmapdata_node(t_uchar b, t_uchar g,
							t_uchar r);
int							check_header(t_bmp *bmp);
t_uint						bytes_to_number(t_uchar *str, t_uint len);
void						number_to_bytes(t_uint nb, unsigned char *buffer,
							t_uint len);
void						destroy_bmp(t_bmp *bmp);

#endif