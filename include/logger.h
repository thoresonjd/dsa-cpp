#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string_view>

class Logger {
private:
	enum class LogType {
		SUCCESS,
		INFO,
		WARNING,
		ERROR,
		NORMAL
	};
 
	static constexpr std::string_view SUCCESS_PREFIX = "[SUCCESS] ";
	static constexpr std::string_view INFO_PREFIX    = "[INFO   ] ";
	static constexpr std::string_view WARNING_PREFIX = "[WARNING] ";
	static constexpr std::string_view ERROR_PREFIX   = "[ERROR  ] ";
	static constexpr std::string_view NORMAL_PREFIX  = "";

	static constexpr std::string_view RED    = "\033[31m"; 
	static constexpr std::string_view YELLOW = "\033[33m";
	static constexpr std::string_view GREEN  = "\033[32m";
	static constexpr std::string_view BLUE   = "\033[94m";
	static constexpr std::string_view RESET  = "\033[0m";	

	std::ostream* console;
	std::ostream* file;

	Logger();
	~Logger();
	Logger(const Logger& other) = delete;
	Logger(Logger&& other) = delete;
	Logger& operator=(const Logger& other) = delete;
	Logger& operator=(Logger&& other) = delete;
	void log(const LogType& logType, const std::string_view message) const;
	static const std::string_view logTypeToAnsiColor(const LogType& logType);
	static const std::string_view logTypeToPrefix(const LogType& logType);
public:
	static Logger& getInstance();
	void success(const std::string_view message) const noexcept;
	void info(const std::string_view message) const noexcept;
	void warning(const std::string_view message) const noexcept;
	void error(const std::string_view message) const noexcept;
	void log(const std::string_view message) const noexcept;
};

#endif

