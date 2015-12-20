// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_NUMBER_LOGICAL_OR_HPP
#define METAL_NUMBER_LOGICAL_OR_HPP

namespace metal
{
    namespace detail
    {
        template<typename... nums>
        struct or_;
    }

    /// \ingroup logical
    /// Computes the logical or of \numbers.
    ///
    /// Usage
    /// -----
    /// For any \values `val1, ..., valn`
    /// \code
    ///     using result = metal::or_<val1, ..., valn>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     If all \values in `[val1, ..., valn]` are \numbers,
    ///     then equivalent to
    ///     \code
    ///         using result = metal::boolean<val1::value || ... || valn::value>;
    ///     \endcode
    ///     otherwise, equivalent to
    ///     \code
    ///         using result = metal::nothing;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet number/logical.cpp or_
    ///
    /// See Also
    /// --------
    /// \see boolean, not_, and_
    template<typename... nums>
    using or_ = detail::or_<nums...>;

    /// \ingroup logical
    /// Eager adaptor for \ref or_.
    template<typename... nums>
    using or_t = typename metal::or_<nums...>::type;
}

#include <metal/number/number.hpp>
#include <metal/number/logical/not.hpp>
#include <metal/lambda/invoke.hpp>
#include <metal/lambda/lift.hpp>
#include <metal/list/list.hpp>
#include <metal/list/same.hpp>

namespace metal
{
    namespace detail
    {
        template<typename... nums>
        using nand = not_<same_t<list<boolean<true>, nums...>>>;

        template<typename... nums>
        struct or_ :
            invoke<lift_t<lambda<nand>>, not_<nums>...>
        {};

        template<typename tx, tx vx, typename ty, ty vy, typename... tail>
        struct or_<number<tx, vx>, number<ty, vy>, number<tail, false>...> :
            boolean<vx || vy>
        {};

        template<typename tx, tx vx>
        struct or_<number<tx, vx>> :
            boolean<vx || false>
        {};

        template<>
        struct or_<> :
            boolean<false>
        {};
    }
}

#endif
