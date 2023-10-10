#include <type_traits>
#include "ndarray.h"

using nda::ndarray;

static_assert(std::is_same<ndarray<int>, int>::value);
static_assert(std::is_same<ndarray<int, 1>, std::array<int, 1>>::value);
static_assert(std::is_same<ndarray<int, 1, 2>, std::array<std::array<int, 1>, 2>>::value);
static_assert(std::is_same<ndarray<int, 1, 2, 3>, std::array<std::array<std::array<int, 1>, 2>, 3>>::value);

#if __cplusplus >= 202002L
using nda::ndspan;
static_assert(std::is_same_v<ndspan<int>, int>);
static_assert(std::is_same_v<ndspan<int, 1>, std::span<int, 1>>);
static_assert(std::is_same_v<ndspan<int, 1, 2>, std::span<std::span<int, 1>, 2>>);
static_assert(std::is_same_v<ndspan<int, 1, 2, 3>, std::span<std::span<std::span<int, 1>, 2>, 3>>);
#endif

