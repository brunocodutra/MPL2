// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/optional/maybe.hpp>
#include <metal/optional/just.hpp>

#include "test.hpp"

#define _boilerplate(_, N) \
    _assert((metal::is_just_t<metal::maybe<_val(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::maybe<_num(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::maybe<_lbd(N)>>), (_true)); \
    _assert((metal::is_just_t<metal::maybe<_lambda(N)>>), (_false)); \
    _assert((metal::is_just_t<metal::maybe<_expr()<_val(N)>>>), (_true)); \
    _assert((metal::maybe<_num(N)>::type), (_num(N))); \
    _assert((metal::maybe<_lbd(N)>::type), (_lbd(N)::type)); \
    _assert((metal::maybe<_expr()<_val(N)>>::type), (_expr()<_val(N)>::type)); \
/**/

_gen(_boilerplate)
