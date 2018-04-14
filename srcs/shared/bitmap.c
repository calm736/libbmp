/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bitmap.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ghazette <ghazette@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/12 18:49:53 by ghazette     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/13 11:32:23 by ghazette    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/bitmap.h"

t_bmp			*init_bmp(void)
{
	t_bmp	*bmp;

	if (!(bmp = malloc(sizeof(t_bmp))))
		return (NULL);
	if (!(bmp->file_header = malloc(sizeof(t_bmp_file_header))))
		return (NULL);
	if (!(bmp->info_header = malloc(sizeof(t_bitmap_info_header))))
		return (NULL);
	bmp->data = NULL;
	return (bmp);
}

t_bitmap_data	*new_bitmapdata_node(t_uchar b, t_uchar g, t_uchar r)
{
	t_bitmap_data *bmd;

	if (!(bmd = malloc(sizeof(t_bitmap_data))))
		return (NULL);
	bmd->rgb.color[0] = b;
	bmd->rgb.color[1] = g;
	bmd->rgb.color[2] = r;
	return (bmd);
}

void			destroy_bmp(t_bmp *bmp)
{
	t_bitmap_data	*ptr;
	t_bitmap_data	*nxt;

	ptr = bmp->data;
	while (ptr)
	{
		nxt = ptr->next;
		free(ptr);
		ptr = NULL;
		ptr = nxt;
	}
	bmp->data = NULL;
	//free(bmp->row_ptr);
	free(bmp->file_header);
	free(bmp->info_header);
	bmp->row_ptr = NULL;
	bmp->file_header = NULL;
	bmp->info_header = NULL;
	free(bmp);
	bmp = NULL;
}