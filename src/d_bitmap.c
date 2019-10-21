#include "d_bitmap.h"
#include <stdint.h>

#pragma pack(1)
struct d_bmp_header {
	unsigned short header_field;
	unsigned int size;
	unsigned short reserved_1;
	unsigned short reserved_2;
	unsigned int offset_data;
};

struct d_dib_header {
	unsigned int header_size;
	int width;
	int height;
	unsigned short color_plane;
	unsigned short color_depth;
	unsigned int compression;
	unsigned int raw_size_img;
	unsigned int h_res;
	unsigned int v_res;
	unsigned int number_color;
	unsigned int important_color;
};
#pragma pack()

void d_init_bmp_header(D_BMP_HEADER *hdr, unsigned int size) {
    hdr->header_field = 0x4D42;
    hdr->size = size;					
	hdr->reserved_1 = 0x0;
	hdr->reserved_2 = 0x0;
	hdr->offset_data = 0x36;
}

void d_init_dib_header(D_DIB_HEADER *hdr, int w, int h, unsigned int raw_size) {
    hdr->header_size = 0x28;
	hdr->width = w;
	hdr->height = h;
	hdr->color_plane = 0x1;
	hdr->color_depth = 0x18;
	hdr->compression = 0x0;
	hdr->raw_size_img = raw_size;
	hdr->h_res = 0x130B;
	hdr->v_res = 0x130B;
	hdr->number_color = 0x0;
	hdr->important_color = 0x0;
}

void d_write_bmp_header(FILE *fp, unsigned int size) {
    D_BMP_HEADER hdr;
    d_init_bmp_header(&hdr, size);
    fwrite(&hdr, sizeof(D_BMP_HEADER), 1, fp);
}

void d_write_dib_header(FILE *fp, int w, int h, unsigned int raw_size) {
    D_DIB_HEADER hdr;
    d_init_dib_header(&hdr, w, h, raw_size);
    fwrite(&hdr, sizeof(D_DIB_HEADER), 1, fp);
}

void d_write_pixel(FILE *fp, D_PIXEL p) {
    fwrite(&p.b, sizeof(unsigned char), 1, fp);
	fwrite(&p.g, sizeof(unsigned char), 1, fp);
    fwrite(&p.r, sizeof(unsigned char), 1, fp);
}