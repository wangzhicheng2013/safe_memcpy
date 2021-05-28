#include <iostream>
#include "safe_memcpy.hpp"
int main() {
    char src[64] = "123";
    char dst[64] = "";
    safe_memcpy(dst, src, strlen(src), dst, dst + 64);
    std::cout << dst << std::endl;

    return 0;
}