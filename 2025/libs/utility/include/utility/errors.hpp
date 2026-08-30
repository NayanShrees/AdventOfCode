#ifndef ERRORS_HPP_
#define ERRORS_HPP_

enum class FileUtilityError {
    OK = 0,
    FILE_NOT_FOUND = 1,
    FILE_OPEN_ERROR = 2,

    RUNTIME_DIRECTORY_RESOLVE_ERROR = 1000,
};

#endif  // ERRORS_HPP_
