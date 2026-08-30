#include <iostream>

#include "cxxopts.hpp"
#include "days/day_1.hpp"
#include "utility/logger.hpp"

bool parse_opts(int argc, char* argv[], std::string& log_file_path) {
    try {
        cxxopts::Options options("Advent of Code", "Advent of Code 2025 done in C++");

        options.add_options()("h,help", "Print this help menu")(
            "l,log-file", "Output logs to a file", cxxopts::value<std::string>());

        auto result = options.parse(argc, argv);

        if (result.count("help")) {
            std::cout << options.help() << std::endl;
            exit(0);
        }

        if (result.count("log-file")) {
            log_file_path = result["log-file"].as<std::string>();
        }
    } catch (const cxxopts::exceptions::exception& e) {
        LOG_ERROR(std::format("Error parsing options: {}", e.what()));
        return false;
    };
    return true;
}

int main(int argc, char* argv[]) {
    std::string log_file_path = "";

    if (!parse_opts(argc, argv, log_file_path)) {
        return 1;
    }

    if (!log_file_path.empty()) {
        Logger::initializeFileLogging(log_file_path);
    }

    Day_1 day = Day_1();
    day.solve();

    return 0;
}
