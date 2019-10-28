#ifndef METAL_LIST_PARTITION_HPP
#define METAL_LIST_PARTITION_HPP

#include "../config.hpp"
#include "../detail/sfinae.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class lbd>
        struct _partition;
    }
    /// \endcond

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
    using partition = detail::call<detail::_partition<lbd>::template type, seq>;
}

#include "../lambda/lambda.hpp"
#include "../list/join.hpp"
#include "../list/list.hpp"
#include "../number/if.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<bool>
        struct _partitioner_impl {};

        template<>
        // help memoization; see https://github.com/brunocodutra/metal/pull/100#issuecomment-541343498
        struct _partitioner_impl<true> {
            template<template<class...> class expr, class val>
            using type =
                if_<expr<val>, list<list<val>, list<>>,
                    list<list<>, list<val>>>;
        };

        template<template<class...> class expr>
        struct _partitioner {
            template<class val, class... _>
            using type = typename _partitioner_impl<!sizeof...(
                _)>::template type<expr, val>;
        };

        template<class...>
        struct _partition_joiner;

        template<class... left, class... right>
        struct _partition_joiner<list<left, right>...> {
            using type = list<join<left...>, join<right...>>;
        };

        template<class seq>
        struct _partition_impl {};

        template<class... vals>
        struct _partition_impl<list<vals...>> {
            template<template<class...> class expr>
            using type = typename _partition_joiner<expr<vals>...>::type;
        };

        template<class lbd>
        class _partition {};

        template<template<class...> class expr>
        struct _partition<lambda<expr>> {
            template<class seq>
            using type = forward<
                _partition_impl<seq>::template type,
                _partitioner<expr>::template type>;
        };
    }
    /// \endcond
}

#endif
