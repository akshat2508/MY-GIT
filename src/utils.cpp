// utils.cpp
#include "../include/utils.h"
#include <ctime>
#include <string>

std::string getCurrentTimestamp() {
    std::time_t now = std::time(0);
    char buf[80];
    std::strftime(buf, sizeof(buf), "[%Y-%m-%d %H:%M:%S]", std::localtime(&now));
    return std::string(buf);
}
