// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_FIND_HPP
#define METAL_LIST_FIND_HPP

namespace metal
{
    namespace detail
    {
        template<typename list, typename val>
        struct find;
    }

    /// \ingroup list
    /// ...
    template<typename list, typename val>
    using find = detail::find<list, val>;

    /// \ingroup list
    /// Eager adaptor for \ref find.
    template<typename list, typename val>
    using find_t = typename metal::find<list, val>::type;
}

#include <metal/list/find_if.hpp>
#include <metal/lambda/arg.hpp>
#include <metal/lambda/quote.hpp>

#include <type_traits>

namespace metal
{
    namespace detail
    {
        template<typename list, typename val>
        struct find :
            find_if<list, std::is_same<_1, quote_t<val>>>
        {};
    }
}

#endif
