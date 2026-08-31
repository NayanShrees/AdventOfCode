#ifndef DAYS_HPP_
#define DAYS_HPP_

#include <cstdint>
#include <filesystem>
#include <string>
#include <string_view>

#include "utility/errors.hpp"
#include "utility/file.hpp"
#include "utility/logger.hpp"

enum class DaysError { OK = 0, VIRTUAL_FUNCTION_NOT_IMPLEMENTED = 1 };

class Days {
   public:
    Days(uint8_t day) : day{day}, assets_path{std::format("assets/day_{}", day)} {
        auto day_file_name = std::format("day_{}.txt", day);
        auto example_file_name = std::format("day_{}_example.txt", day);
        if (auto result = utility::file::reader(day_buffer, day_file_name, assets_path);
            result != FileUtilityError::OK) {
            LOG_ERROR(std::format("Error reading day {} data", day));
        }
        if (auto result = utility::file::reader(example_buffer, example_file_name, assets_path);
            result != FileUtilityError::OK) {
            LOG_ERROR("Error reading day example data");
        }
    }

    virtual ~Days() = default;

    virtual DaysError day_part_1_example(int32_t&) {
        LOG_ERROR("Day Part 1 Example not implemented");
        return DaysError::VIRTUAL_FUNCTION_NOT_IMPLEMENTED;
    };
    virtual DaysError day_part_1(int32_t&) {
        LOG_ERROR("Day Part 1 not implemented");
        return DaysError::VIRTUAL_FUNCTION_NOT_IMPLEMENTED;
    };
    virtual DaysError day_part_2_example(int32_t&) {
        LOG_ERROR("Day Part 2 Example not implemented");
        return DaysError::VIRTUAL_FUNCTION_NOT_IMPLEMENTED;
    };
    virtual DaysError day_part_2(int32_t&) {
        LOG_ERROR("Day Part 2 not implemented");
        return DaysError::VIRTUAL_FUNCTION_NOT_IMPLEMENTED;
    };

    DaysError solve() {
        int32_t out = 0;
        if (auto result = day_part_1_example(out); result != DaysError::OK) {
            return result;
        }
        LOG_INFO(std::format("Day {} Part 1 example result: {}", day, out));
        out = 0;
        if (auto result = day_part_1(out); result != DaysError::OK) {
            return result;
        }

        LOG_INFO(std::format("Day {} Part 1 result: {}", day, out));
        out = 0;
        if (auto result = day_part_2_example(out); result != DaysError::OK) {
            return result;
        }

        LOG_INFO(std::format("Day {} Part 2 example result: {}", day, out));
        out = 0;
        if (auto result = day_part_2(out); result != DaysError::OK) {
            return result;
        }
        LOG_INFO(std::format("Day {} Part 2 result: {}", day, out));
        return DaysError::OK;
    };

   protected:
    std::string example_buffer;
    std::string day_buffer;
    uint8_t day;

   private:
    std::string assets_path;
};

#endif  // DAYS_HPP_
