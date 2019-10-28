#pragma once
#ifndef LOG_H
#define LOG_H "LOG_H"

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
static class Log
{
public:
	const enum Level {INFO, DEBUG, WARNING, ERROR};
	static inline void info(string message) { cout << "INFO: " << message << endl; }
	static inline void debug(string message) { cout << "DEBUG: " << message << endl; }
	static inline void warn(string message) { cout << "WARNING: " << message << endl; }
	static inline void error(string message) { cout << "ERROR: " << message << endl; }
};

#endif //!LOG_H