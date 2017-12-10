
#include "pngHelper.hh"

#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <png.h>
#include <vector>

void convert2DVector(std::vector<std::vector<double>> &vals, png_bytepp temp) {
    temp = new double*[vals.size()];

    for (unsigned i=0; i < vals.size(); i++) {
        temp[i] = new double[vals.size()];

        for (unsigned j=0; j < vals[i].size(); j++) {
            temp[i][j] = (char)vals[i][j];
        }
    }
}

bool PngHelper::writePng(std::string fileName, int width, int height, char **pixels) {
    FILE *pFile = fopen(fileName.c_str(), "wb");
    if (!pFile) return false;

    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) return false;

    png_infop info = png_create_info_struct(png);
    if (!info) return false;

    if (setjmp(png_jmpbuf(png))) return false;

    png_init_io(png, pFile);

    png_set_IHDR(
        png,
        info,
        width, height,
        8,
        PNG_COLOR_TYPE_GRAY,
        PNG_INTERLACE_ADAM7,
        PNG_COMPRESSION_TYPE_DEFAULT,
        PNG_FILTER_TYPE_DEFAULT
    );
    png_write_info(png, info);

    png_write_image(png, pixels);
    png_write_end(png, NULL);

    fclose(pFile);
}