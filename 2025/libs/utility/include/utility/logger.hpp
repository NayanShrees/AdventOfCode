#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include <format>
#include <fstream>
#include <iostream>
#include <string_view>

#ifdef DEVELOPMENT_MODE
#define LOG_DEBUG(msg) Logger::log(LogLevel::Debug, __func__, msg)
#define LOG_INFO(msg) Logger::log(LogLevel::Info, __func__, msg)
#else
#define LOG_DEBUG(msg) \
    do {               \
        (void)(msg);   \
    } while (0)
#define LOG_INFO(msg) \
    do {              \
        (void)(msg);  \
    } while (0)
#endif
#define LOG_WARN(msg) Logger::log(LogLevel::Warn, __func__, msg)
#define LOG_ERROR(msg) Logger::log(LogLevel::Error, __func__, msg)

enum class LogLevel {
    Debug,
    Info,
    Warn,
    Error,
};

class Logger {
   private:
    inline static std::ofstream fileStream;
    inline static bool logToFile = false;

    static constexpr std::string_view levelToString(LogLevel level) {
        switch (level) {
            case LogLevel::Debug:
                return "[DEBUG]";
            case LogLevel::Info:
                return "[INFO]";
            case LogLevel::Warn:
                return "[WARN]";
            case LogLevel::Error:
                return "[ERROR]";
        }
        return "[UNKNOWN]";
    }

   public:
    static void initializeFileLogging(const std::string& filepath) {
        fileStream.open(filepath, std::ios::out | std::ios::app);
        if (fileStream.is_open()) {
            logToFile = true;
            LOG_INFO(std::format("Logging to file: {}", filepath));
        } else {
            std::cerr << "[LOGGER ERROR] Failed to open log file: " << filepath << '\n';
        }
    }

    static void log(LogLevel level, std::string_view func, std::string_view message) {
        std::string_view prefix = levelToString(level);
        std::string log_message = std::format("{} [{}] {}\n", prefix, func, message);
        if (level == LogLevel::Error) {
            std::cerr << log_message;
        } else {
            std::cout << log_message;
            ;
        }

        if (logToFile && fileStream.is_open()) {
            fileStream << log_message;
            fileStream.flush();
        }
    }
};

#endif  // LOGGER_HPP_
