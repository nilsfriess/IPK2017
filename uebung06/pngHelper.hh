#ifndef PNG_HELPER_HH
#define PNG_HELPER_HH

#include <string>

class PngHelper {
public:
    static bool writePng(std::string fileName, int width, int height, char **pixels);
}

#endif // PNG_HH_HELPER
