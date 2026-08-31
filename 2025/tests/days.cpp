
#include <gtest/gtest.h>

#include "days/day_1.hpp"

TEST(Days, Day_1_part_1_example) {
    auto day = Day_1();
    int out = 10;
    auto result = day.day_part_1_example(out);
    EXPECT_EQ(DaysError::OK, result);
    EXPECT_EQ(out, 10);
}
