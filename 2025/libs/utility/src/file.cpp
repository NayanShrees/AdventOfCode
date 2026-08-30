#include <filesystem>
#include <format>
#include <fstream>
#include <iterator>

#include "utility/errors.hpp"
#include "utility/file.hpp"
#include "utility/logger.hpp"

FileUtilityError utility::file::get_runtime_path(std::filesystem::path& runtime_file_path) {
#if defined(_WIN32)
    LOG_ERROR(std::format("Function not implemented for Windows"));
#elif defined(__APPLE__)
    LOG_ERROR(std::format("Function not implemented for Apple"));
#elif defined(__linux__)
    runtime_file_path = std::filesystem::canonical("/proc/self/exe");
    return FileUtilityError::OK;
#endif
    return FileUtilityError::RUNTIME_DIRECTORY_RESOLVE_ERROR;
}

FileUtilityError utility::file::reader(std::string& out, const std::string_view& file_name,
                                       const std::filesystem::path& relative_file_path,
                                       const std::filesystem::path& absolute_file_path) {
    auto working_file_dir = std::filesystem::path();
    // Prefer absolute -> relative -> default to root of build/install
    if (!absolute_file_path.empty() && std::filesystem::exists(absolute_file_path)) {
        LOG_DEBUG(std::format("Absolute path {}", working_file_dir.string()));
        working_file_dir = absolute_file_path;
    } else if (!relative_file_path.empty()) {
        if (auto result = get_runtime_path(working_file_dir); result != FileUtilityError::OK) {
            LOG_ERROR("Error resolving relative file path to absolute");
            return result;
        }
        LOG_DEBUG(std::format("relative path working dir {}", working_file_dir.string()));
        working_file_dir = working_file_dir.parent_path().parent_path() / relative_file_path;
    }

    // Default to top of build/install folder since app will be in build/bin or install/bin
    if (working_file_dir.empty()) {
        get_runtime_path(working_file_dir);
        working_file_dir = working_file_dir.parent_path().parent_path();
        LOG_INFO(std::format("File path empty defaulting to base file path: {}",
                             working_file_dir.string()));
    }
    LOG_INFO(std::format("Utility File reader called on {}/{}",
                         working_file_dir.relative_path().string(), file_name));

    auto file_path = working_file_dir / file_name;

    if (!std::filesystem::exists(file_path)) {
        LOG_ERROR(std::format("File {} not found", file_name));
        return FileUtilityError::FILE_NOT_FOUND;
    }

    std::ifstream file_stream(file_path, std::ios::in);

    if (!file_stream.is_open()) {
        LOG_ERROR(std::format("Error opening file: {}", file_name));
        return FileUtilityError::FILE_OPEN_ERROR;
    }
    out =
        std::string{std::istreambuf_iterator<char>(file_stream), std::istreambuf_iterator<char>()};

    return FileUtilityError::OK;
}
