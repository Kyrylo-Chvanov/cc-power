#include "complex.hpp"

#include "basic.hpp"

uint64_t sum(uint64_t x, uint64_t y) {
  if (y == 0) {
    return p<1>(1, {x});
  }
  return s(p<3>(3, {x, y - 1, sum(x, y - 1)}));
}

uint64_t mul(uint64_t x, uint64_t y) {
  if (y == 0) {
    return p<1>(1, {z(x)});
  }
  return sum(x, p<3>(3, {x, y - 1, mul(x, y - 1)}));
}

uint64_t pow(uint64_t x, uint64_t y) {
  if (y == 0) {
    return p<1>(1, {s(z(x))});
  }
  return mul(x, p<3>(3, {x, y - 1, pow(x, y - 1)}));
}
