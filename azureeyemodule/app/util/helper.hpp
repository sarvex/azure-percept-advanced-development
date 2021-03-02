// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.
#pragma once

// Standard library includes
#include <cstdlib>
#include <string>
#include <vector>

// Third party includes
#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>

namespace util {

// Use template magic to determine the size of an array
template <typename T, std::size_t N>
constexpr std::size_t array_size(const T (&)[N]) noexcept {
    return N;
}

/** Returns true if the given file path exists. */
bool file_exists(const std::string &filename);

/** Log an error */
void log_error(std::string str);

/** Log an info */
void log_info(std::string str);

/** Log a debug */
void log_debug(std::string str);

/** Get a class label from the given vector or return the string representation of the ID. */
std::string get_label(int index, const std::vector<std::string> &class_list);

/** Overlay the given text onto the given image */
void put_text(const cv::Mat &rgb, std::string text);

/** Set verbose logging on or off. */
void set_logging(bool data);

/** Convert the given integer into a hex string */
std::string to_hex_string(int i);

/** Convert the string to lower case */
std::string to_lower(std::string str);

/** Turn the given Mat's dimensions into a string */
std::string to_size_string(cv::Mat &mat);

/** Convert the given float into a string with a particular amount of precision. */
std::string to_string_with_precision(float f, int precision);

/** Run the given shell command. */
int run_command(std::string command);

/** Search for the given word in the given file. */
bool search_keyword_in_file(std::string keyword, std::string filename);

/** Print the version. */
void version();

/** Splices a comma-separated list into a list of strings. */
std::vector<std::string> splice_comma_separated_list(const std::string &list_string);

} // namespace util
