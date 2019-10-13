#ifndef METAL_LIST_INSERT_HPP
#define METAL_LIST_INSERT_HPP

#include "../config.hpp"
#include "../list/list.hpp"
#include "../list/splice.hpp"

namespace metal {
    /// \ingroup list
    ///
    /// ### Description
    /// Inserts a \value in a \list at an arbitrary position.
    ///
    /// ### Usage
    /// For any \list `l`, \number `num` and \values `val_0, ..., val_n-1`
    /// \code
    ///     using result = metal::insert<l, num, val_0, ..., val_n-1>;
    /// \endcode
    ///
    /// \pre: `metal::number<0>{} &le; num{} &le; metal::size<l>{}`
    /// \returns: \list
    /// \semantics:
    ///     If `l` contains elements `l[0], ..., l[i], ..., l[m-1]` and
    ///     `num{} == i`, then
    ///     \code
    ///         using result = metal::list<
    ///             l[0], ..., val_0, ..., val_n-1, l[i], ..., l[m-1]
    ///         >;
    ///     \endcode
    ///
    /// ### Example
    /// \snippet list.cpp insert
    ///
    /// ### See Also
    /// \see list, prepend, append, splice
    template<class seq, class num, class... vals>
    using insert = metal::splice<seq, num, metal::list<vals...>>;
}

#endif
