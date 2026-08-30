#ifndef FILE_HPP_
#define FILE_HPP_

#include <filesystem>
#include <string>

#include "errors.hpp"

namespace utility {
namespace file {
FileUtilityError get_runtime_path(std::filesystem::path& runtime_file_path);

FileUtilityError reader(std::string& out, const std::string_view& file_name,
                        const std::filesystem::path& relative_file_path = std::filesystem::path(),
                        const std::filesystem::path& absolute_file_path = std::filesystem::path());
}  // namespace file
}  // namespace utility

#endif  // FILE_HPP_
