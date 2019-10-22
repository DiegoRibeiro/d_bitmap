cmake_minimum_required (VERSION 2.6)

project (d_bitmap)

add_library(d_bitmap src/d_bitmap.c src/d_bitmap_v4.c)

install (TARGETS d_bitmap DESTINATION bin)
install (FILES src/d_bitmap.h src/d_bitmap_v4.h DESTINATION include)
