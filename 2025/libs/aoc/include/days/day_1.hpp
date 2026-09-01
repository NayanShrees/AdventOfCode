#ifndef DAY_1_HPP_
#define DAY_1_HPP_

#include "days.hpp"

class Day_1 : public Days {
   public:
    Day_1() : Days(day) {};
    ~Day_1() = default;

   private:
    DaysError part_1(int32_t& out, bool example = false) override;
    DaysError part_2(int32_t& out, bool example = false) override;
    static constexpr uint8_t day = 1;
};

#endif  // DAY_1_HPP_
