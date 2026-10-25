#pragma once

#include <cstdint>
#include <stdexcept>
#include <string>

struct Arguments {
  uint64_t x, y;
};

class ArgumentParser {
 public:
  ArgumentParser(const int argc, const char* const* argv)
      : argc_{argc}, argv_{argv} {}
  Arguments parse() const;

 private:
  void expect_arg_(const std::string_view opt, const int index) const;
  int64_t parse_int64_(const std::string& arg) const;
  const int argc_;
  const char* const* argv_;
};

class ParserException : public std::runtime_error {
 public:
  ParserException(const std::string& message) noexcept
      : std::runtime_error{message} {}
};

class HelpRequested : public std::runtime_error {
 public:
  HelpRequested() noexcept : std::runtime_error{""} {}
};
