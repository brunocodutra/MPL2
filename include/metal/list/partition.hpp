#ifndef METAL_LIST_PARTITION_HPP
#define METAL_LIST_PARTITION_HPP

#include "../config.hpp"
#include "../list/copy_if.hpp"
#include "../list/remove_if.hpp"
#include "../pair/pair.hpp"

namespace metal {
    /// \ingroup list
    ///
    /// ### Description
    /// Splits a \list in two according to a predicate.
    ///
    /// ### Usage
    /// For any \list `l` and \lambda `lbd`
    /// \code
    ///     using result = metal::partition<l, lbd>;
    /// \endcode
    ///
    /// \pre: For any element `l[i]` contained in `l`,
    /// `metal::invoke<lbd, l[i]>` returns a \number
    /// \returns: \pair
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::pair<l_1, l_2>;
    ///     \endcode
    ///     where `l_1` contains all and only the elements `l[i]` in `l` for
    ///     which `metal::invoke<lbd, l[i]>{} != false` and `l_2` contains the
    ///     remaining elements.
    ///
    /// ### Example
    /// \snippet list.cpp partition
    ///
    /// ### See Also
    /// \see list, copy_if, remove_if
    template<class seq, class lbd>
    using partition =
        metal::pair<metal::copy_if<seq, lbd>, metal::remove_if<seq, lbd>>;
}

#endif
