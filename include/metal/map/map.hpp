#ifndef METAL_MAP_MAP_HPP
#define METAL_MAP_MAP_HPP

#include "../config.hpp"
#include "../lambda/apply.hpp"
#include "../lambda/lambda.hpp"
#include "../list/list.hpp"
#include "../list/transform.hpp"
#include "../number/if.hpp"
#include "../pair/pair.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class val>
        struct _is_map;
    }
    /// \endcond

    /// \ingroup map
    ///
    /// ### Description
    /// Checks whether some \value is a \map.
    ///
    /// ### Usage
    /// For any \value `val`
    /// \code
    ///     using result = metal::is_map<val>;
    /// \endcode
    ///
    /// \returns: \number
    /// \semantics:
    ///     If `val` is a \map, then
    ///     \code
    ///         using result = metal::true_;
    ///     \endcode
    ///     otherwise
    ///     \code
    ///         using result = metal::false_;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet map.cpp is_map
    ///
    /// ### See Also
    /// \see map, is_value, is_number, is_lambda, is_pair, is_list
    template<class val>
    using is_map = typename detail::_is_map<val>::type;

    /// \ingroup map
    ///
    /// ### Description
    /// Constructs a \map out of a sequence of \pairs.
    ///
    /// ### Usage
    /// For any \pairs `pair_0, ..., pair_n-1`
    /// \code
    ///     using result = metal::map<pair_0, ..., pair_n-1>;
    /// \endcode
    ///
    /// \pre: No two \pairs have the same key
    /// \returns: \map
    ///
    /// ### See Also
    /// \see is_map
    template<class... pairs>
    using map =
        metal::if_<metal::is_map<metal::list<pairs...>>, metal::list<pairs...>>;

    /// \ingroup map
    ///
    /// ### Description
    /// Constructs a \map out of any \value that is a specialization of a
    /// template class or union whose template parameters are all themselves
    /// specializations of template classes or unions that take exactly two
    /// template parameters, the first \values of which are all distinct.
    ///
    /// ### Usage
    /// For any \value `val`
    /// \code
    ///     using result = metal::as_map<val>;
    /// \endcode
    ///
    /// \returns: \map
    ///
    /// ### Example
    /// \snippet map.cpp as_map
    ///
    /// ### See Also
    /// \see map
    template<class val>
    using as_map = metal::apply<
        metal::lambda<metal::map>,
        metal::transform<metal::lambda<metal::as_pair>, metal::as_list<val>>>;
}

#include "../number/number.hpp"
#include "../value/distinct.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class val>
        struct _is_map : false_ {};

        template<>
        struct _is_map<list<>> : true_ {};

        template<class... keys, class... vals>
        struct _is_map<list<list<keys, vals>...>> : distinct<keys...> {};
    }
    /// \endcond
}

#endif
