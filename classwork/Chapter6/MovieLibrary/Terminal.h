/*
 * COSC 1436
 * Fall 2024
 *
 * Terminal helper functions.
 */
#pragma once

/// @brief Reads an integer value
/// @param message Message to display
/// @param minValue Minimum required value
/// @param maxValue Maximum required value
/// @return Input from user
int ReadInt(std::string message, int minValue, int maxValue);

/// @brief Reads a string from input
/// @param message Message to display
/// @return Input from user
std::string ReadString(std::string message);

/// @brief Reads a string from input
/// @param message Message to display
/// @param isRequired True if the value is required
/// @return Input from user
std::string ReadString(std::string message, bool isRequired);