// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_OPTIONAL_EVAL_HPP
#define METAL_OPTIONAL_EVAL_HPP

#include <metal/optional/conditional.hpp>
#include <metal/optional/optional.hpp>

#include <metal/detail/nil.hpp>

namespace metal
{
    /// \ingroup optional
    /// Evaluates an \optional.
    ///
    /// A fallback \value may be specified in case the \optional is empty.
    ///
    /// Usage
    /// -----
    /// For any \optional `opt`
    /// \code
    ///     metal::eval<opt>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     Equivalent to
    ///     \code
    ///         typename opt::type
    ///     \endcode
    ///
    /// \danger{Evaluating an empty optional leads to a compile time error.}
    ///
    /// ________________________________________________________________________
    ///
    /// For any \optional `opt` and \value `val`
    /// \code
    ///     metal::eval<opt, val>;
    /// \endcode
    ///
    /// \par Semantics:
    ///     Equivalent to
    ///     \code
    ///         conditional_t<is_just_t<opt>, opt, just<val>>;
    ///     \endcode
    ///
    /// Example
    /// -------
    /// \snippet optional/eval.cpp eval
    ///
    /// See Also
    /// --------
    /// \see conditional, just, is_just
    template<typename opt, typename fallback = detail::nil>
    using eval = metal::conditional_t<
        metal::is_just<opt>, opt, metal::just<fallback>
    >;
}

#endif
