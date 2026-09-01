#include <cstdint>
#include <ranges>
#include <utility>

#include "days.hpp"
#include "days/day_1.hpp"
#include "utility/logger.hpp"

DaysError Day_1::part_1(int32_t& out, bool example) {
    int32_t start_position = 50;
    uint32_t count = 0;
    auto data = example ? example_buffer : day_buffer;
    constexpr std::string_view delimiter = "\n";

    auto split = data | std::views::split(delimiter);
    std::cout << " Start " << std::endl;

    for (auto token : split) {
        if (token.empty()) {
            continue;
        }
        if (example) {
            std::string_view line{token.begin(), token.end()};
            std::cout << line << std::endl;
            char direction = token.front();
        }
    }

    std::cout << " END " << std::endl;

    if (!std::in_range<int32_t>(count)) {
        LOG_ERROR("Total count can't be represented as an int32_t, count: {}", count);
        return DaysError::TYPE_CONVERSION_ERROR;
    }
    out = static_cast<int32_t>(count);
    return DaysError::OK;
}

DaysError Day_1::part_2(int32_t& out, bool example) { return DaysError::OK; }
