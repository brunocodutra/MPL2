// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_DEFER_HPP
#define METAL_LAMBDA_DEFER_HPP

namespace metal
{
    namespace detail
    {
        template<typename lbd>
        struct defer;
    }

    /// \ingroup lambda
    /// ...
    template<typename lbd>
    using defer = detail::defer<lbd>;

    /// \ingroup lambda
    /// Eager adaptor for \ref defer.
    template<typename lbd>
    using defer_t = typename metal::defer<lbd>::type;
}

#include <metal/lambda/bind.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/quote.hpp>
#include <metal/optional/optional.hpp>

#include <metal/detail/declptr.hpp>

namespace metal
{
    namespace detail
    {
        template<
            template<typename...> class expr, typename... args,
            typename ret = just<expr<args...>>
        >
        ret defer_impl(list<args...>*);

        template<template<typename...> class>
        nothing defer_impl(...);

        template<typename lbd>
        struct defer :
            quote<lbd>
        {};

        template<template<typename...> class expr>
        struct defer<lambda<expr>>
        {
            template<typename... args>
            using _ = decltype(defer_impl<expr>(declptr<list<args...>>()));

            using type = lambda<_>;
        };

        template<template<typename...> class expr, typename... params>
        struct defer<expr<params...>> :
            bind<defer_t<lambda<expr>>, params...>
        {};
    }
}

#endif

