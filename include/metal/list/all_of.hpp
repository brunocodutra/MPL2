#ifndef METAL_LIST_ALL_OF_HPP
#define METAL_LIST_ALL_OF_HPP

#include "../config.hpp"
#include "../lambda/apply.hpp"
#include "../lambda/lambda.hpp"
#include "../list/transform.hpp"
#include "../number/and.hpp"

namespace metal {
    /// \ingroup list
    ///
    /// ### Description
    /// Checks whether a predicate holds for all elements of a \list.
    ///
    /// ### Usage
    /// For any \list `l` and \lambda `lbd`
    /// \code
    ///     using result = metal::all_of<l, lbd>;
    /// \endcode
    ///
    /// \pre: For any element `l[i]` contained in `l`,
    /// `metal::invoke<lbd, l[i]>` returns a \number
    /// \returns: \number
    /// \semantics:
    ///     If `metal::invoke<lbd, l[i]>{} != false` for all `l[i]` contained in
    ///     `l`, then
    ///     \code
    ///         using result = metal::true_;
    ///     \endcode
    ///     otherwise
    ///     \code
    ///         using result = metal::false_;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp all_of
    ///
    /// ### See Also
    /// \see list, any_of, none_of
    template<class seq, class lbd>
    using all_of =
        metal::apply<metal::lambda<metal::and_>, metal::transform<lbd, seq>>;
}

#endif
