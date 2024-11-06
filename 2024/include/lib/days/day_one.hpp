#ifndef DAY_ONE_HPP
#define DAY_ONE_HPP

#include <sstream>
#include <string>
#include <vector>

namespace day {
namespace one {
const std::string EXAMPLE_FILE_PATH = "day_1_example.txt";
const std::string FILE_PATH = "day_1.txt";
int PartOne(bool example);
int PartTwo(bool example);
void SplitInput(std::istringstream *input, std::vector<int> *first, std::vector<int> *second);
}  // namespace one
}  // namespace day

#endif  // DAY_ONE_HPP
