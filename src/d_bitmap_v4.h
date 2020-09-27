#ifndef D_BITMAP_V4_H
    #define D_BITMAP_V4_H
    
    #include <stdio.h>
    #include <stdint.h>

    #define HEADER_V4_SIZE 122
    #define PIXEL_V4_SIZE 4

    // private structs
    typedef struct d_bmp_header_v4 D_BMP_HEADER_V4;
    typedef struct d_dib_header_v4 D_DIB_HEADER_V4;

    // public struct
    #pragma pack(1)
    struct d_pixel_a {
	    uint8_t r; // red
	    uint8_t g; // green
	    uint8_t b; // blue
        uint8_t a; // alpha
    };
    #pragma pack()
    typedef struct d_pixel_a D_PIXEL_A;

    void d_write_bmp_header_v4(FILE *fp, uint32_t size);
    void d_write_dib_header_v4(FILE *fp, int32_t w, int32_t h, uint32_t raw_size);
    void d_write_pixel_v4(FILE *fp, D_PIXEL_A p);
	void d_write_pixel_v4_n(FILE *fp, D_PIXEL_A p);
#endif

