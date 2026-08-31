#include <functional>
#include <map>
#include <memory>

#include "days.hpp"
#include "days/day_1.hpp"

using DayFactory = std::function<std::unique_ptr<Days>()>;

const std::map<int, DayFactory> day_factories{{1, [] { return std::make_unique<Day_1>(); }}};
