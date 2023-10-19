#include "ggen.h"

std::string m_line(uint16_t X, uint16_t Y, uint16_t Z, uint16_t FEED) {
    using namespace std;
    #define SPACE (char)32
    return "G1 " + ('X' + to_string(X) + SPACE + 'Y' + to_string(Y) + SPACE + 'Z' + to_string(Z) + SPACE + 'F' + to_string(FEED));
}