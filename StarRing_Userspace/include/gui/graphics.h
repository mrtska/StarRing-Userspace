/*
 * graphics.h
 *
 *  Created on: 2014/09/28
 *      Author: StarRing
 */

#pragma once


#define GFX_W(ctx)	((ctx)->width)
#define GFX_H(ctx)	((ctx)->height)
#define GFX_D(ctx)	((ctx)->depth)


#define GFX(ctx, x, y)	*((unsigned int*) &((ctx)->backbuffer)[(GFX_W(ctx) * (y) + (x)) * GFX_D(ctx)])




struct graphics_context {

	unsigned short width;
	unsigned short height;
	unsigned short depth;
	unsigned int size;
	char *buffer;
	char *backbuffer;
};




void draw_line(struct graphics_context *ctx, int x1, int y1, int x2, int y2, unsigned int color);

void draw_point(struct graphics_context *ctx, int x, int y, unsigned int color);

void flip(struct graphics_context *ctx);


















