// ndarray version 0.1.0
// Licensed under the MIT License <http://opensource.org/licenses/MIT>.
// Copyright (c) 2023 00-KAMIDUKI <kamiduki.0@gmail.com>.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef _NDARRAY_NDARRAY_H
#define _NDARRAY_NDARRAY_H

#include <array>

namespace nda {
template <typename, std::size_t...>
struct basic_ndarray;

template <typename _T, std::size_t __n, std::size_t... __ns>
struct basic_ndarray<_T, __n, __ns...> {
  using type = typename basic_ndarray<std::array<_T, __n>, __ns...>::type;
};

template <typename _T>
struct basic_ndarray<_T> {
  using type = _T;
};

template <typename _T, std::size_t... __ns>
using ndarray = typename basic_ndarray<_T, __ns...>::type;
}

#endif //_NDARRAY_NDARRAY_H

