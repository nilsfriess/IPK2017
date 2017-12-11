#ifndef PNG_HELPER_HH
#define PNG_HELPER_HH

#include <string>
#include <vector>

class PngHelper {
public:
    static bool writePng(const std::string &fileName, int **pixels, int width, int height);
};

#endif // PNG_HH_HELPER
