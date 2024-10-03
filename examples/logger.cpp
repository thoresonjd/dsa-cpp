#include <logger.h>

int main(void) {
	Logger& logger = Logger::getInstance();
	logger.log("Normal");
	logger.info("Info");
	logger.success("Success");
	logger.warning("Warning");
	logger.error("Error");
	return 0;
}
