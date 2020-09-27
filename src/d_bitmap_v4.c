#include "d_bitmap_v4.h"

#pragma pack(1)
struct d_bmp_header_v4 {
	uint16_t header_field;
	uint32_t size;
	uint16_t reserved_1;
	uint16_t reserved_2;
	uint32_t offset_data;
};

struct d_dib_header_v4 {
	uint32_t header_size;
	int32_t width;
	int32_t height;
	uint16_t color_plane;
	uint16_t bpp;
	uint32_t compression;
	uint32_t raw_size;
	uint32_t h_res;
	uint32_t v_res;
	uint32_t colors_pallete;
	uint32_t important_colors;
	uint32_t red_channel;
	uint32_t green_channel;
	uint32_t blue_channel;
	uint32_t alpha_channel;
	uint32_t lcs;
	uint8_t CIEXYZTRIPLE[36];
	uint32_t red_gamma;
	uint32_t green_gamma;
	uint32_t blue_gamma;
    //uint32_t unknown[4];
};
#pragma pack()

void d_init_bmp_header_v4(D_BMP_HEADER_V4 *hdr, uint32_t size) {
    //printf("bmp size: %d\n", sizeof(D_BMP_HEADER_V4));

    hdr->header_field = 0x4D42;
    hdr->size = size;
    hdr->reserved_1 = 0x0;
    hdr->reserved_2 = 0x0;
    hdr->offset_data = sizeof(D_BMP_HEADER_V4) + sizeof(D_DIB_HEADER_V4);
}

void d_init_dib_header_v4(D_DIB_HEADER_V4 *hdr, int32_t w, int32_t h, uint32_t raw_size) {
    //printf("dib size: %d\n", sizeof(D_DIB_HEADER_V4));

    hdr->header_size = sizeof(D_DIB_HEADER_V4);
    hdr->width = w;
    hdr->height = h;
    hdr->color_plane = 0x1;
    hdr->bpp = 0x20;
    hdr->compression = 0x03;
    hdr->raw_size = raw_size;
    hdr->h_res = 0x0B13;
    hdr->v_res = 0x0B13;
    hdr->colors_pallete = 0x0;
    hdr->important_colors = 0x0;
    hdr->red_channel    =   0x00FF0000;
    hdr->green_channel  =   0x0000FF00;
    hdr->blue_channel   =   0x000000FF;
    hdr->alpha_channel  =   0xFF000000;
    hdr->lcs = 0x42475273;

    for(int i = 0; i < 36; i++) {
        hdr->CIEXYZTRIPLE[i] = 0x0;
    }

    hdr->red_gamma = 0x0;
    hdr->green_gamma = 0x0;
    hdr->blue_gamma = 0x0;

    /*for(int i = 0; i < 4; i++) {
        hdr->unknown[i] = 0x00;
    }*/
}

void d_write_bmp_header_v4(FILE *fp, uint32_t size) {
    D_BMP_HEADER_V4 hdr;
    d_init_bmp_header_v4(&hdr, size);
    fwrite(&hdr, sizeof(D_BMP_HEADER_V4), 1, fp);
}

void d_write_dib_header_v4(FILE *fp, int32_t w, int32_t h, uint32_t raw_size) {
    D_DIB_HEADER_V4 hdr;
    d_init_dib_header_v4(&hdr, w, h, raw_size);
    fwrite(&hdr, sizeof(D_DIB_HEADER_V4), 1, fp);
}

void d_write_pixel_v4(FILE *fp, D_PIXEL_A p) {
    fwrite(&p.b, sizeof(uint8_t), 1, fp);
	fwrite(&p.g, sizeof(uint8_t), 1, fp);
    fwrite(&p.r, sizeof(uint8_t), 1, fp);
    fwrite(&p.a, sizeof(uint8_t), 1, fp);
}

void d_write_pixel_v4_n(FILE *fp, D_PIXEL_A p) {
    fwrite(&p.r, sizeof(uint8_t), 1, fp);
	fwrite(&p.g, sizeof(uint8_t), 1, fp);
    fwrite(&p.b, sizeof(uint8_t), 1, fp);
    fwrite(&p.a, sizeof(uint8_t), 1, fp);
}
