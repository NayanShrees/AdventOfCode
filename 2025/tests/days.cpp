#include <gtest/gtest.h>

#include "days.hpp"
#include "days/day_1.hpp"

struct Results {
    int32_t part_1_example;
    int32_t part_1;
    int32_t part_2_example;
    int32_t part_2;
};

template <typename Day>
void expect_day(const Results& expected) {
    Results actual{0, 0, 0, 0};
    Day day;

    day.solve(actual.part_1_example, actual.part_1, actual.part_2_example, actual.part_2);

    EXPECT_EQ(actual.part_1_example, expected.part_1_example);
    EXPECT_EQ(actual.part_1, expected.part_1);
    EXPECT_EQ(actual.part_2_example, expected.part_2_example);
    EXPECT_EQ(actual.part_2, expected.part_2);
}

TEST(Days, Day_1) { expect_day<Day_1>({3, 1048, 0, 0}); }
