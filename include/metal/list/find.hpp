#ifndef METAL_LIST_FIND_HPP
#define METAL_LIST_FIND_HPP

#include "../config.hpp"
#include "../lambda/lambda.hpp"
#include "../lambda/partial.hpp"
#include "../list/find_if.hpp"
#include "../value/same.hpp"

namespace metal {
    /// \ingroup list
    ///
    /// ### Description
    /// Returns the index of the first occurrence of a \value in a \list.
    ///
    /// ### Usage
    /// For any \list `l` and \value `val`
    /// \code
    ///     using result = metal::find<l, val>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::number<i>;
    ///     \endcode
    ///     where `i` is index of the first occurrence of `val` in `l`,
    ///     otherwise
    ///     \code
    ///         using result = metal::size<l>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp find
    ///
    /// ### See Also
    /// \see list, find_if, count, contains
    template<class seq, class val>
    using find =
        metal::find_if<seq, metal::partial<metal::lambda<metal::same>, val>>;
}

#endif
