#pragma once

#include <array>
#include <cstdint>

uint64_t z(uint64_t x);
uint64_t s(uint64_t x);

template <int N>
uint64_t p(uint64_t i, const std::array<uint64_t, N>& args) {
  return args[i - 1];
}
