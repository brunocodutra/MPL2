// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_PAIR_FIRST_HPP
#define METAL_PAIR_FIRST_HPP

namespace metal
{
    namespace detail
    {
        template<typename pair>
        struct first;
    }

    /// \ingroup pair
    /// ...
    template<typename pair>
    using first = detail::first<pair>;

    /// \ingroup pair
    /// Eager adaptor for \ref first.
    template<typename pair>
    using first_t = typename metal::first<pair>::type;
}

#include <metal/pair/pair.hpp>
#include <metal/optional/conditional.hpp>

namespace metal
{
    namespace detail
    {
        template<typename pair>
        struct first_impl
        {};

        template<template<typename...> class pair, typename x, typename y>
        struct first_impl<pair<x, y>>
        {
            using type = x;
        };

        template<typename pair>
        struct first :
            conditional<is_pair_t<pair>, first_impl<pair>>
        {};
    }
}

#endif
