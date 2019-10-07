#ifndef METAL_LIST_COPY_IF_HPP
#define METAL_LIST_COPY_IF_HPP

#include "../config.hpp"
#include "../lambda/bind.hpp"
#include "../lambda/lambda.hpp"
#include "../list/remove_if.hpp"
#include "../number/not.hpp"

namespace metal {
    /// \ingroup list
    ///
    /// ### Description
    /// Removes all elements from a \list except for those that satisfy a
    /// predicate.
    ///
    /// ### Usage
    /// For any \list `l` and \lambda `lbd`
    /// \code
    ///     using result = metal::copy_if<l, lbd>;
    /// \endcode
    ///
    /// \pre: For any element `l[i]` contained in `l`,
    /// `metal::invoke<lbd, l[i]>` returns a \number
    /// \returns: \list
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::list<...>;
    ///     \endcode
    ///     where `result` contains all and only the elements `l[i]` in `l` for
    ///     which `metal::invoke<lbd, l[i]>{} != false`.
    ///
    /// ### Example
    /// \snippet list.cpp copy_if
    ///
    /// ### See Also
    /// \see list, copy, remove_if, replace_if
    template<class seq, class lbd>
    using copy_if =
        metal::remove_if<seq, metal::bind<metal::lambda<metal::not_>, lbd>>;
}

#endif
