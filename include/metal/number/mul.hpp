#ifndef METAL_NUMBER_MUL_HPP
#define METAL_NUMBER_MUL_HPP

#include "../config.hpp"
#include "../lambda/lambda.hpp"
#include "../number/number.hpp"
#include "../value/fold_left.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class x, class y>
        struct _mul;

        template<class x, class y>
        using mul = typename _mul<x, y>::type;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// Computes the arithmetic multiplication of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `num_0, ..., num_n-1`
    /// \code
    ///     using result = metal::mul<num_0, ..., num_n-1>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::number<num_0{} * ... * num_n-1{}>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp mul
    ///
    /// ### See Also
    /// \see number, abs, inc, dec, neg, add, sub, div, mod, pow
    template<class... nums>
    using mul = fold_left<lambda<detail::mul>, nums..., number<1>>;

    /// \cond
    namespace detail {
        template<class x, class y>
        struct _mul {};

        template<int_ x, int_ y>
        struct _mul<number<x>, number<y>> {
            using type = number<x * y>;
        };
    }
    /// \endcond
}

#endif
