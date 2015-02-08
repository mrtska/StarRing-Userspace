/*
 * init.c
 *
 *  Created on: 2014/10/27
 *      Author: StarRing
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>
//#include <ft2build.h>
//#include FT_FREETYPE_H

#pragma GCC diagnostic ignored "-Wformat="

/*FT_Library library;
FT_Face face;*/

struct graphics_context {

	unsigned short width;
	unsigned short height;
	unsigned short depth;
	unsigned int size;
	char *buffer;
	char *backbuffer;
};

#define GFX_W(ctx)	((ctx)->width)
#define GFX_H(ctx)	((ctx)->height)
#define GFX_D(ctx)	((ctx)->depth)
#define GFX(ctx, x, y)	*((unsigned int*) &((ctx)->backbuffer)[(GFX_W(ctx) * (y) + (x)) * GFX_D(ctx)])
#define RGB(r, g, b) (r << 16 || g << 8 || b)


struct graphics_context context;
void draw_point(struct graphics_context *ctx, int x, int y, unsigned int color) {

	GFX(ctx, x, y) = color;
}
/*
void draw_string(wchar_t *c, int y) {

	int ret;

	int x = 10;
	int i;
	for(i = 0; i < wcslen(c); i++) {

		int glyph_index = FT_Get_Char_Index(face, c[i]);


		printf("glyph index %X\n", glyph_index);
		ret = FT_Load_Glyph(face, glyph_index, FT_LOAD_DEFAULT);
		if(ret) {

			puts("4");
		}
		ret = FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL);
		if(ret) {

			puts("5");
		}

		FT_GlyphSlot slot = face->glyph;
		FT_Bitmap bitmap = slot->bitmap;

		int i;
		for(i = 0; i < bitmap.width * bitmap.rows; i++) {

			draw_point(&context, (i % bitmap.width) + x, (i / bitmap.width) + y, bitmap.buffer[i]);

		}
		if(y == 200) {

			x += 50;
		} else {

			x += 200;
		}


	}

}

static int free_type_init() {

	int ret = 0;

	ret = FT_Init_FreeType(&library);
	if(ret) {

		return ret;
	}

	FILE *p = fopen("/font/fui.ttf", "rb");
	unsigned char buf[0x600000];

	unsigned int size;
	fseek(p, 0, SEEK_END);
	size = ftell(p);
	fseek(p, 0, SEEK_SET);

	printf("size %u\n", size);
	fread(buf, 0x600000, 1, p);

	ret = FT_New_Memory_Face(library, buf, 0x600000, 0, &face);
	if(ret) {

		puts("1");
		return ret;
	}
	ret = FT_Set_Char_Size(face, 0, 16 * 64, 480, 854);
	if(ret) {

		puts("2");
		return ret;
	}
	ret = FT_Set_Pixel_Sizes(face, 0, 200);
	if(ret) {

		puts("3");
		return ret;
	}

	short str[4];
	str[0] = 0x81EA;
	str[1] = 0x4F5C;
	str[2] = 'O';
	str[3] = 'S';

	draw_string(L"自作OS", 10);
	FT_Set_Pixel_Sizes(face, 0, 100);
	draw_string(L"StarRing", 200);
	return ret;
}*/

/*
 #define asmv __asm__ __volatile__

 static __inline__ __attribute__((always_inline)) void enable_single_step(void) {

 asmv("pushf");
 asmv("pop %rax");
 asmv("bts $8, %rax");
 asmv("push %rax");
 asmv("popf");
 }*/



int main(int argc, char *argv[]) {
/*

	context.width = 854;
	context.height = 480;
	context.backbuffer = (char*) syscall(7);
	context.depth = 4;
	context.size = context.width * context.height * context.depth;
*/

	exit(0);

	puts("User Space");
	FILE *fp = fopen("/font/ipaexg.ttf", "rb");

	fseek(fp, 0, SEEK_END);
	printf("file size %u\n", ftell(fp));


	fclose(fp);

/*

	int ret = free_type_init();
	printf("ret = %d\n", ret);
*/

	//mmap();
	errno = 0;

	printf("errno %d, %s\n", errno, strerror(errno));
	errno = 0xDEAD;
	//enable_single_step();
	return 0;
}

