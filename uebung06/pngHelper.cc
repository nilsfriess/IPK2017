
#include "pngHelper.hh"

#include <png.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>

bool PngHelper::writePng(const std::string &fileName, int** pixels, int width, int height) {
  png_bytep row_ptr;

  FILE *pFile = fopen(fileName.c_str(), "wb");
  if (!pFile)
    return false;

  png_structp png =
      png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if (!png)
    return false;

  png_infop info = png_create_info_struct(png);
  if (!info)
    return false;

  if (setjmp(png_jmpbuf(png)))
    return false;

  png_init_io(png, pFile);

  png_set_IHDR(png, info, width, height, 8, PNG_COLOR_TYPE_RGB,
               PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT,
               PNG_FILTER_TYPE_DEFAULT);
  png_write_info(png, info);

// ##############################################################
// http://www.caam.rice.edu/~timwar/HPC12/HPC12/Wave2D/png_util.c
  int n, m;

  unsigned char *rgb =
      (unsigned char *)calloc(3 * width * height, sizeof(unsigned char));

  for (n = 0; n < height; ++n) {
    for (m = 0; m < width; ++m) {
      int id = m + n * width;

      unsigned char I = (unsigned char)pixels[m][n];

      /* use same intensity in each red-green-blue channel */
      rgb[3 * id + 0] = I;
      rgb[3 * id + 1] = I;
      rgb[3 * id + 2] = I;
    }
  }

  for (int i = 0; i < height; i++) {
    row_ptr = rgb + 3 * i * width;
    png_write_rows(png, &row_ptr, 1);
  }

// http://www.caam.rice.edu/~timwar/HPC12/HPC12/Wave2D/png_util.c end
// ###################################################################

  png_write_end(png, NULL);

  fclose(pFile);

  if (png && info)
    png_destroy_write_struct(&png, &info);

  return true;
}