#ifndef D_BITMAP_H
    #define D_BITMAP_H
    
    #include <stdio.h>

    #define HEADER_SIZE 54

    // private structs
    typedef struct d_bmp_header D_BMP_HEADER;
    typedef struct d_dib_header D_DIB_HEADER;

    // public struct
    #pragma pack(1)
    struct d_pixel {
	    unsigned char r;
	    unsigned char g;
	    unsigned char b;
    };
    #pragma pack()
    typedef struct d_pixel D_PIXEL;

    void d_write_bmp_header(FILE*, unsigned int);
    void d_write_dib_header(FILE*, int, int, unsigned int);
    void d_write_pixel(FILE *, D_PIXEL);
#endif

