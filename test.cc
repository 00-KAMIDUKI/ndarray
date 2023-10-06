#include <type_traits>
#include "ndarray.h"

using ndarray::ndarray_t;

static_assert(std::is_same<ndarray_t<int>, int>::value);
static_assert(std::is_same<ndarray_t<int, 1>, std::array<int, 1>>::value);
static_assert(std::is_same<ndarray_t<int, 1, 2>, std::array<std::array<int, 1>, 2>>::value);
static_assert(std::is_same<ndarray_t<int, 1, 2, 3>, std::array<std::array<std::array<int, 1>, 2>, 3>>::value);

