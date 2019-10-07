#ifndef METAL_NUMBER_MIN_HPP
#define METAL_NUMBER_MIN_HPP

#include "../config.hpp"
#include "../lambda/lambda.hpp"
#include "../number/if.hpp"
#include "../number/less.hpp"
#include "../number/number.hpp"
#include "../value/fold_left.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class x, class y>
        using min = if_<less<x, y>, x, y>;
    }
    /// \endcond

    /// \ingroup number
    ///
    /// ### Description
    /// Computes the minimum of \numbers.
    ///
    /// ### Usage
    /// For any \numbers `num_0, ..., num_n-1`
    /// \code
    ///     using result = metal::min<num_0, ..., num_n-1>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If `m` the minimum between all \numbers in `num_0, ..., num_n-1`,
    ///     then
    ///     \code
    ///         using result = m;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet number.cpp min
    ///
    /// ### See Also
    /// \see number, greater, less, max
    template<class... nums>
    using min = fold_left<lambda<detail::min>, if_<is_number<nums>, nums>...>;
}

#endif
