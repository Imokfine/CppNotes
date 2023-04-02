 /**
 * @file logging.h
 * @brief Header file for logging functions.
 * 		See https://en.cppreference.com/w/cpp/utility/source_location
 * @author R. Morrin
 * @version 1.0
 * @date 2023-03-13
 */
#ifndef LOGGING_H_QYJGNTWO
#define LOGGING_H_QYJGNTWO
#include <source_location>
#include <string>
#include <iostream>

std::string sourceline(const std::source_location location = std::source_location::current());

#endif /* end of include guard: LOGGING_H_QYJGNTWO */

