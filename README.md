# Ndarray C++
Header-only C++11 multidimensional array library
## Examples
```cpp
#include <type_traits>
#include "ndarray.h"

using ndarray::ndarray_t;

// ndarray<T> -> T
static_assert(std::is_same<ndarray_t<int>, int>::value);

// ndarray<T, ...> -> nested std::array<T, n>
static_assert(std::is_same<ndarray_t<int, 1>, std::array<int, 1>>::value);
static_assert(std::is_same<ndarray_t<int, 1, 2>, std::array<std::array<int, 1>, 2>>::value);
static_assert(std::is_same<ndarray_t<int, 1, 2, 3>, std::array<std::array<std::array<int, 1>, 2>, 3>>::value);

#include <iostream>
template<typename T, std::size_t... ns>
void print(ndarray_t<T, ns...> arr) {
  for (
    auto it = reinterpret_cast<T*>(arr.data());
    it != reinterpret_cast<T*>(arr.data()) + (1 * ... * ns);
    ++it
  ) {
    std::cout << *it << ' ';
  }
  std::cout << std::endl;
}

int main() {
  auto arr1 = ndarray_t<int, 2, 2>{{
    {1, 2},
    {3, 4},
  }};

  auto arr2 = ndarray_t<int, 2, 2>{1, 2, 3, 4};

  auto arr3 = ndarray_t<int, 2, 3, 4>{{
    {1, 3, 2, 5, 1, 3},
    {1, 3, 3, 4, 5, 3}, 
    {1, 2, 2, 34, 0, 3}, 
    {2, 3, 3, 5, 6, 7},
  }};
  
  auto arr4 = ndarray_t<int, 2, 3, 4>{{
    {{{1, 3}, {2, 5}, {1, 3}}},
    {{{1, 3}, {3, 4}, {5, 3}}},
    {{{1, 2}, {2, 34}, {0, 3}}},
    {{{2, 3}, {3, 5}, {6, 7}}},
  }};

  print<int, 2, 2>(arr1); // 1 2 3 4
  print<int, 2, 2>(arr2); // 1 2 3 4
  print<int, 2, 3, 4>(arr3); // 1 3 2 5 1 3 1 3 3 4 5 3 1 2 2 34 0 3 2 3 3 5 6 7
  print<int, 2, 3, 4>(arr4); // 1 3 2 5 1 3 1 3 3 4 5 3 1 2 2 34 0 3 2 3 3 5 6 7
}

```
