#include "days/day_one.hpp"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "utils/file_reader.hpp"

namespace day {
namespace one {
int PartOne(bool example) {
    std::istringstream input(utils::file_reader::ReadFile(example ? EXAMPLE_FILE_PATH : FILE_PATH));
    std::vector<int> first, second;

    SplitInput(&input, &first, &second);

    std::sort(first.begin(), first.end());
    std::sort(second.begin(), second.end());

    int total = 0;
    for (int i = 0; i < first.size() && i < second.size(); i++) {
        total += std::abs(first.at(i) - second.at(i));
    }
    return total;
}

int PartTwo(bool example) {
    std::istringstream input(utils::file_reader::ReadFile(example ? EXAMPLE_FILE_PATH : FILE_PATH));
    std::vector<int> first, second;

    SplitInput(&input, &first, &second);

    std::unordered_map<int, int> frequency;

    for (auto& number : second) {
        if (auto search = frequency.find(number); search != frequency.end()) {
            search->second += 1;
        } else {
            frequency.insert({number, 1});
        }
    }

    int total = 0;

    for (auto& number : first) {
        if (auto search = frequency.find(number); search != frequency.end()) {
            total += number * search->second;
        }
    }

    return total;
}

void SplitInput(std::istringstream* input, std::vector<int>* first, std::vector<int>* second) {
    for (std::string line; std::getline(*input, line);) {
        std::string delimiter = "   ";
        size_t first_pos = line.find(delimiter);
        first->push_back(std::stoi(line.substr(0, first_pos)));
        line.erase(0, first_pos + delimiter.length());
        second->push_back(std::stoi(line));
    }
}
}  // namespace one
}  // namespace day
