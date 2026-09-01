#ifndef DAYS_HPP_
#define DAYS_HPP_

#include <cstdint>
#include <filesystem>
#include <print>
#include <string>

#include "utility/file.hpp"
#include "utility/logger.hpp"

enum class DaysError {
    OK = 0,
    TYPE_CONVERSION_ERROR = 1000,
    DATA_ERROR = 2000,
};

class Days {
   public:
    Days(uint8_t day) : day{day} {
        auto assets_path = std::format("assets/day_{}", day);
        auto day_file_name = std::format("day_{}.txt", day);
        auto example_file_name = std::format("day_{}_example.txt", day);

        if (auto result = utility::file::read(day_file_name, assets_path)) {
            day_buffer = *result;
        } else {
            LOG_ERROR("Error reading day {} data", day);
        }
        if (auto result = utility::file::read(example_file_name, assets_path)) {
            example_buffer = *result;
        } else {
            LOG_ERROR("Error reading day example data");
        }
    }

    virtual ~Days() = default;

    DaysError solve(int32_t& part_1_example, int32_t& part_1, int32_t& part_2_example,
                    int32_t& part_2) {
        if (auto result = this->part_1(part_1_example, true); result != DaysError::OK) {
            return result;
        }
        LOG_DEBUG("Day {} Part 1 example result: {}", day, part_1_example);

        if (auto result = this->part_1(part_1); result != DaysError::OK) {
            return result;
        }
        LOG_DEBUG("Day {} Part 1 result: {}", day, part_1);

        if (auto result = this->part_2(part_2_example, true); result != DaysError::OK) {
            return result;
        }
        LOG_DEBUG("Day {} Part 2 example result: {}", day, part_2_example);

        if (auto result = this->part_2(part_2); result != DaysError::OK) {
            return result;
        }
        LOG_DEBUG("Day {} Part 2 result: {}", day, part_2);

        std::println("Day {} part 1 example: {}", day, part_1_example);
        std::println("Day {} part 1: {}", day, part_1);
        std::println("Day {} part 2 example: {}", day, part_2_example);
        std::println("Day {} part 2: {}", day, part_2);
        return DaysError::OK;
    };

    DaysError solve() {
        int32_t part_1_example = 0, part_1 = 0, part_2_example = 0, part_2 = 0;
        return solve(part_1_example, part_1, part_2_example, part_2);
    };

   protected:
    virtual DaysError part_1(int32_t& out, bool example = false) = 0;
    virtual DaysError part_2(int32_t& out, bool example = false) = 0;

    std::string example_buffer;
    std::string day_buffer;
    uint8_t day;
};

#endif  // DAYS_HPP_
