#ifndef METAL_VALUE_IDENTITY_HPP
#define METAL_VALUE_IDENTITY_HPP

#include "../config.hpp"
#include "../value/eval.hpp"
#include "../value/value.hpp"

namespace metal {
    /// \ingroup value
    ///
    /// ### Description
    /// The identity \expression.
    ///
    /// ### Usage
    /// For any \value `val`
    /// \code
    ///     using result = metal::identity<val>;
    /// \endcode
    ///
    /// \returns: \value
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = val;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet value.cpp identity
    ///
    /// ### See Also
    /// \see value, eval
    template<class val>
    using identity =
#if defined(METAL_WORKAROUND)
        eval<value<val>>;
#else
        val;
#endif
}

#endif
