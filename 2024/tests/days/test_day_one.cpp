#include <gtest/gtest.h>

#include "days/day_one.hpp"

TEST(DayOne, PartOneExample) { EXPECT_EQ(day::one::PartOne(true), 11); }

TEST(DayOne, PartOne) { EXPECT_EQ(day::one::PartOne(false), 2285373); }

TEST(DayOne, PartTwoExample) { EXPECT_EQ(day::one::PartTwo(true), 31); }

TEST(DayOne, PartTwo) { EXPECT_EQ(day::one::PartTwo(false), 21142653); }
