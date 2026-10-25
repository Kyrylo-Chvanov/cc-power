#include "args.hpp"

#include <cctype>
#include <exception>
#include <format>
#include <string>
#include <string_view>

constexpr std::string_view XFlag{"-x"};
constexpr std::string_view YFlag{"-y"};

Arguments ArgumentParser::parse() const {
  Arguments args{};
  int flags_collected{0};
  for (int i{1}; i < argc_; ++i) {
    const std::string arg{argv_[i]};
    if (arg == XFlag) {
      expect_arg_(XFlag, i + 1);
      args.x = parse_int64_(argv_[++i]);
      flags_collected++;
    } else if (arg == YFlag) {
      expect_arg_(YFlag, i + 1);
      args.y = parse_int64_(argv_[++i]);
      flags_collected++;
    } else {
      throw ParserException("unknown flag " + arg);
    }
  }
  if (flags_collected != 2) {
    throw ParserException(
        "not enough arguments provided: expected -x <uint> and -y <uint>");
  }
  return args;
}

void ArgumentParser::expect_arg_(const std::string_view opt,
                                 const int index) const {
  if (index >= argc_) {
    throw ParserException(std::format("{} expects an argument", opt));
  }
}

int64_t ArgumentParser::parse_int64_(const std::string& arg) const {
  try {
    for (const char c : arg) {
      if (!std::isdigit(c)) throw ParserException("");
    }
    return std::stoull(arg);
  } catch (const std::exception& e) {
    throw ParserException(
        std::format("{} is not a valid unsigned integer", arg));
  }
}
