#include <type_traits>
#include "ndarray.h"

using nda::ndarray;

static_assert(std::is_same<ndarray<int>, int>::value);
static_assert(std::is_same<ndarray<int, 1>, std::array<int, 1>>::value);
static_assert(std::is_same<ndarray<int, 1, 2>, std::array<std::array<int, 1>, 2>>::value);
static_assert(std::is_same<ndarray<int, 1, 2, 3>, std::array<std::array<std::array<int, 1>, 2>, 3>>::value);

