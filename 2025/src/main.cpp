#include <cstdint>
#include <iostream>

#include "cxxopts.hpp"
#include "day_factory.hpp"
#include "utility/logger.hpp"

bool parse_opts(int argc, char* argv[], std::string& log_file_path, uint8_t& day_choice) {
    try {
        cxxopts::Options options("Advent of Code", "Advent of Code 2025 done in C++");

        options.add_options()("h,help", "Print this help menu")(
            "l,log-file", "Output logs to a file", cxxopts::value<std::string>())(
            "d,day", "Select which day to solve", cxxopts::value<int32_t>());

        auto result = options.parse(argc, argv);

        if (result.count("help")) {
            std::cout << options.help() << std::endl;
            exit(0);
        }

        if (result.count("log-file")) {
            log_file_path = result["log-file"].as<std::string>();
        }

        if (result.count("day")) {
            int32_t user_day_choice = result["day"].as<int32_t>();
            if (user_day_choice >= 1 && user_day_choice <= 25) {
                LOG_ERROR(std::format("Day should be 1 <= Day <= 25, not {}", user_day_choice));
                return false;
            }
            day_choice = static_cast<uint8_t>(user_day_choice);
        }
    } catch (const cxxopts::exceptions::exception& e) {
        LOG_ERROR(std::format("Error parsing options: {}", e.what()));
        return false;
    };
    return true;
}

int main(int argc, char* argv[]) {
    std::string log_file_path = "";
    uint8_t day_num = 0;

    if (!parse_opts(argc, argv, log_file_path, day_num)) {
        return 1;
    }

    if (!log_file_path.empty()) {
        Logger::initializeFileLogging(log_file_path);
    }

    if (day_num != 0) {
        const auto day = day_factories.find(day_num);
        if (day == day_factories.end()) {
            LOG_ERROR(std::format("Day {} not found or not yet implemented", day_num));
            return 1;
        }
        day->second()->solve();
    }

    for (const auto& day : day_factories) {
        day.second()->solve();
    }

    return 0;
}
