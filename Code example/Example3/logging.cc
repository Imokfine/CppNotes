/**
 * @file logging.h
 * @brief Logging functions.
 * @author Xueni Fu
 * @version 1.0
 * @date 2023-03-20
 */

#include "logging.h"

std::string sourceline(const std::source_location location) {
    std::string inf;
    inf += std::string("file: ") + location.file_name() + std::string(" (");
    inf += std::to_string(location.line()) + ":" + std::to_string(location.column());
    inf += ") ";
    inf += location.function_name();
    inf += "\n";

    return inf;
}
