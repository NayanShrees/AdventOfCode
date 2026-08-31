#include <cstdint>

#include "days.hpp"
#include "days/day_1.hpp"
#include "utility/logger.hpp"

DaysError Day_1::day_part_1_example(int32_t&) {
    LOG_INFO(example_buffer);
    return DaysError::OK;
}

DaysError Day_1::day_part_1(int32_t&) { return DaysError::OK; }

DaysError Day_1::day_part_2_example(int32_t& out) { return Days::day_part_2_example(out); }

DaysError Day_1::day_part_2(int32_t& out) { return Days::day_part_2(out); }
