/*
 * graphics.h
 *
 *  Created on: 2014/09/28
 *      Author: StarRing
 */

#include <gui/graphics.h>
#include <string.h>

#define abs __builtin_abs




void flip(struct graphics_context *ctx) {

	memcpy(ctx->buffer, ctx->backbuffer, ctx->size);
}


void draw_line(struct graphics_context *ctx, int x1, int y1, int x2, int y2, unsigned int color) {

	int delta_x = abs(x2 - x1);
	int delta_y = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int error = delta_x - delta_y;

	while(1) {

		if(x1 >= 0 && y1 >= 0 && x1 < GFX_W(ctx) && y1 < GFX_H(ctx)) {

			GFX(ctx, x1, y1) = color;
		}

		if(x1 == x2 && y1 == y2) {

			break;
		}

		int e2 = 2 * error;
		if(e2 > -delta_y) {

			error -= delta_y;
			x1 += sx;
		}
		if(e2 < -delta_x) {

			error += delta_x;
			y1 += sy;
		}
	}

}

void draw_point(struct graphics_context *ctx, int x, int y, unsigned int color) {

	GFX(ctx, x, y) = color;
}













