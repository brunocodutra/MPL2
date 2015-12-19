// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal.hpp>

#include <type_traits>

#include "example.hpp"

ANONYMOUS(namespace)
{
/// [ex1]
using lbd = void;
/// [ex1]

static_assert(std::is_same<metal::invoke_t<lbd>, void>::value, "");
}

ANONYMOUS(namespace)
{
/// [ex2]
using lbd = metal::_2;
/// [ex2]

static_assert(std::is_same<metal::invoke_t<lbd, int, int>, int>::value, "");
}

ANONYMOUS(namespace)
{
/// [ex3]
using lbd = metal::lambda<std::add_pointer>;
/// [ex3]

static_assert(std::is_same<metal::invoke_t<lbd, void>, void*>::value, "");
}

ANONYMOUS(namespace)
{
/// [ex4]
using lbd = std::add_pointer<void>;
/// [ex4]

static_assert(std::is_same<metal::invoke_t<lbd>, void*>::value, "");
}

ANONYMOUS(namespace)
{
/// [ex5]
using lbd = std::is_convertible<metal::_1, std::add_pointer<metal::_2>>;
/// [ex5]

static_assert(metal::invoke_t<lbd, lbd*, void>::value, "");
}
