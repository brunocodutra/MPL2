// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LIST_PUSH_FRONT_HPP
#define METAL_LIST_PUSH_FRONT_HPP

namespace metal
{
    namespace detail
    {
        template<typename list, typename val>
        struct push_front;
    }

    /// \ingroup list
    /// ...
    template<typename list, typename val>
    using push_front = detail::push_front<list, val>;

    /// \ingroup list
    /// Eager adaptor for \ref push_front.
    template<typename list, typename val>
    using push_front_t = typename metal::push_front<list, val>::type;
}

#include <metal/list/copy.hpp>
#include <metal/list/list.hpp>

namespace metal
{
    namespace detail
    {
        template<typename list, typename val>
        struct push_front
        {};

        template<
            template<typename...> class list, typename... vals,
            typename val
        >
        struct push_front<list<vals...>, val> :
            copy<list<vals...>, metal::list<val, vals...>>
        {};
    }
}

#endif
