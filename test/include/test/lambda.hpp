// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_TEST_LAMBDA_HPP
#define METAL_TEST_LAMBDA_HPP

#include "test/expressions.hpp"
#include "test/preprocessor.hpp"

#define ARG(N) metal::arg<INC(N)>
#define ARGS(N) ENUM(N, LIFT(ARG))

#define LBD(N) EXPR(N)<ARGS(N)>
#define LBDS(N) ENUM(N, LIFT(LBD))

#define FUN(...) metal::lambda<EXPR(__VA_ARGS__)>
#define FUNS(N) ENUM(N, LIFT(FUN))

#endif
