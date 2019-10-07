#ifndef METAL_MAP_VALUES_HPP
#define METAL_MAP_VALUES_HPP

#include "../config.hpp"
#include "../lambda/lambda.hpp"
#include "../list/transform.hpp"
#include "../map/map.hpp"
#include "../number/if.hpp"
#include "../pair/second.hpp"

namespace metal {
    /// \ingroup map
    ///
    /// ### Description
    /// Returns a \list of values contained in a \map.
    ///
    /// ### Usage
    /// For any \map `m`
    /// \code
    ///     using result = metal::values<m>;
    /// \endcode
    ///
    /// \returns: \list
    /// \semantics:
    ///     If `m` associates keys `k_1, ..., k_n` to values `v_1, ..., v_n`,
    ///     then
    ///     \code
    ///         using result = metal::list<v_1, ..., v_n>;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet map.cpp values
    ///
    /// ### See Also
    /// \see map, keys
    template<class seq>
    using values = metal::if_<
        metal::is_map<seq>,
        metal::transform<metal::lambda<metal::second>, seq>>;
}

#endif
