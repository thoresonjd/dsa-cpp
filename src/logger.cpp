#include <logger.h>
#include <iostream>

Logger::Logger():
	console(&std::cout), file(new std::ofstream("./log", std::ios::trunc)) {}

Logger::~Logger() { 
	delete file;
	file = nullptr;
}

Logger& Logger::getInstance() {
	static Logger instance;
	return instance;
}

void Logger::success(const std::string_view message) const noexcept {
	log(LogType::SUCCESS, message);
}

void Logger::info(const std::string_view message) const noexcept {
	log(LogType::INFO, message);
}

void Logger::warning(const std::string_view message) const noexcept {
	log(LogType::WARNING, message);
}

void Logger::error(const std::string_view message) const noexcept {
	log(LogType::ERROR, message);
}

void Logger::log(const std::string_view message) const noexcept {
	log(LogType::NORMAL, message);
}

void Logger::log(const LogType& logType, const std::string_view message) const {
	const std::string_view color = logTypeToAnsiColor(logType);
	const std::string_view name = logTypeToPrefix(logType);
	*console << color << name << RESET << message << std::endl;
	*file << message << std::endl;
}

const std::string_view Logger::logTypeToAnsiColor(const LogType& logType) {
	switch (logType) {
		case LogType::SUCCESS:
			return GREEN;
		case LogType::INFO:
			return BLUE;
		case LogType::WARNING:
			return YELLOW;
		case LogType::ERROR:
			return RED;
		case LogType::NORMAL:
		default:
			return RESET;
	}
}

const std::string_view Logger::logTypeToPrefix(const LogType& logType) {
	switch (logType) {
		case LogType::SUCCESS:
			return SUCCESS_PREFIX;
		case LogType::INFO:
			return INFO_PREFIX;
		case LogType::WARNING:
			return WARNING_PREFIX;
		case LogType::ERROR:
			return ERROR_PREFIX;
		case LogType::NORMAL:
		default:
			return NORMAL_PREFIX;
	}
}

