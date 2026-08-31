#ifndef DAY_1_HPP_
#define DAY_1_HPP_

#include "days.hpp"

class Day_1 : public Days {
   public:
    Day_1() : Days(day) {};
    DaysError day_part_1_example(int& out) override;
    DaysError day_part_1(int& out) override;
    DaysError day_part_2_example(int& out) override;
    DaysError day_part_2(int& out) override;

   private:
    static constexpr uint8_t day = 1;
};

#endif  // DAY_1_HPP_
