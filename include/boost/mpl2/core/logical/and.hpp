// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_CORE_LOGICAL_AND_HPP
#define BOOST_MPL2_CORE_LOGICAL_AND_HPP

#include <type_traits>

namespace boost
{
    namespace mpl2
    {
        template<typename x, typename y, typename... _>
        struct and_ :
                and_<x, and_<y, _...>>
        {};

        template<typename x, typename y>
        struct and_<x, y> :
                and_<typename std::integral_constant<bool, !!x::value>::type, y>
        {};

        template<typename y> struct and_<std::true_type, y> : y {};
        template<typename y> struct and_<std::false_type, y> : std::false_type {};
    }
}

#endif
