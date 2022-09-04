#include "Logger.h"
#include <string>
#include <iostream>
#include <ctime>
#include <sstream>

std::vector<LogEntry> Logger::logEntries;

std::string getCurrentDateInString(){
  std::time_t now = std::time(0);
  char* dt = std::ctime(&now);
  std::tm* ltm = std::localtime(&now);
  int year = ltm->tm_year + 1900;
  int month = ltm->tm_mon + 1;
  int day = ltm->tm_mday;
  int hour = ltm->tm_hour;
  int minutes = ltm->tm_min;
  int seconds = ltm->tm_sec;
  std::ostringstream oss;
  oss << year << "/" << month << "/"<< day << " - " << hour << ":" << minutes << ":" << seconds;
  std::string date = oss.str();
  return date;
}

void Logger::Log(const std::string& message){
  LogEntry logEntry;
  logEntry.type = LOG_INFO;
  logEntry.message = std::string("LOG | ") + std::string("[ ") + getCurrentDateInString() + std::string(" ] - ") + message ;
  std::cout << "\x1B[32m" << logEntry.message << "\033[0m" << std::endl;
  logEntries.push_back(logEntry);
}

void Logger::Err(const std::string& message){
  LogEntry logEntry;
  logEntry.type = LOG_ERROR;
  logEntry.message = std::string("ERR | ") + std::string("[ ") + getCurrentDateInString() + std::string(" ]") + std::string(" - ") + message;
  std::cerr << "\x1B[31m" << logEntry.message << "\033[0m" << std::endl;
  logEntries.push_back(logEntry);
}