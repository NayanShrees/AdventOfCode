#include "utils/file_reader.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

namespace utils {
namespace file_reader {
std::string ReadFile(std::string path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Could not read file" << std::endl;
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
}  // namespace file_reader
}  // namespace utils
