#ifndef METAL_VALUE_FOLD_RIGHT_HPP
#define METAL_VALUE_FOLD_RIGHT_HPP

#include "../config.hpp"
#include "../detail/sfinae.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<class lbd>
        struct _fold_right;
    }
    /// \endcond

    /// \ingroup value
    ///
    /// ### Description
    /// Computes the recursive invocation of a binary \lambda with the result of
    /// the previous invocation and each \value, from the last to the first.
    ///
    /// ### Usage
    /// For any \lambda `lbd`, and \values `val_0, ..., val_n-1`
    /// \code
    ///     using result = metal::fold_right<lbd, val_0, ..., val_n-1>;
    /// \endcode
    ///
    /// \returns: \value
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result =
    ///             lbd(val_0, ..., lbd(val_n-3, lbd(val_n-2, val_n-1)), ...)
    ///     \endcode
    ///     where `lbd(x, y)` stands for `metal::invoke<lbd, x, y>`.
    ///
    /// ### Example
    /// \snippet value.cpp fold_right
    ///
    /// ### See Also
    /// \see fold_right
    template<class lbd, class... vals>
    using fold_right =
        detail::call<detail::_fold_right<lbd>::template type, vals...>;
}

#include "../lambda/lambda.hpp"
#include "../value/identity.hpp"

#include <cstddef>

namespace metal {
    /// \cond
    namespace detail {
        template<
            class state,

            class _00, class _01, class _02, class _03, class _04, class _05,
            class _06, class _07, class _08, class _09, class _10, class _11,
            class _12, class _13, class _14, class _15, class _16, class _17,
            class _18, class _19, class _20, class _21, class _22, class _23,
            class _24, class _25, class _26, class _27, class _28, class _29,
            class _30, class _31, class _32, class _33, class _34, class _35,
            class _36, class _37, class _38, class _39, class _40, class _41,
            class _42, class _43, class _44, class _45, class _46, class _47,
            class _48, class _49, class _50, class _51, class _52, class _53,
            class _54, class _55, class _56, class _57, class _58, class _59,
            class _60, class _61, class _62, class _63, class _64, class _65,
            class _66, class _67, class _68, class _69, class _70, class _71,
            class _72, class _73, class _74, class _75, class _76, class _77,
            class _78, class _79, class _80, class _81, class _82, class _83,
            class _84, class _85, class _86, class _87, class _88, class _89,
            class _90, class _91, class _92, class _93, class _94, class _95,
            class _96, class _97, class _98, class _99>
        struct right_folder_100 {
            template<template<class...> class expr>
            using type =
                expr<_00, expr<_01, expr<_02, expr<_03, expr<_04,
                expr<_05, expr<_06, expr<_07, expr<_08, expr<_09,
                expr<_10, expr<_11, expr<_12, expr<_13, expr<_14,
                expr<_15, expr<_16, expr<_17, expr<_18, expr<_19,
                expr<_20, expr<_21, expr<_22, expr<_23, expr<_24,
                expr<_25, expr<_26, expr<_27, expr<_28, expr<_29,
                expr<_30, expr<_31, expr<_32, expr<_33, expr<_34,
                expr<_35, expr<_36, expr<_37, expr<_38, expr<_39,
                expr<_40, expr<_41, expr<_42, expr<_43, expr<_44,
                expr<_45, expr<_46, expr<_47, expr<_48, expr<_49,
                expr<_50, expr<_51, expr<_52, expr<_53, expr<_54,
                expr<_55, expr<_56, expr<_57, expr<_58, expr<_59,
                expr<_60, expr<_61, expr<_62, expr<_63, expr<_64,
                expr<_65, expr<_66, expr<_67, expr<_68, expr<_69,
                expr<_70, expr<_71, expr<_72, expr<_73, expr<_74,
                expr<_75, expr<_76, expr<_77, expr<_78, expr<_79,
                expr<_80, expr<_81, expr<_82, expr<_83, expr<_84,
                expr<_85, expr<_86, expr<_87, expr<_88, expr<_89,
                expr<_90, expr<_91, expr<_92, expr<_93, expr<_94,
                expr<_95, expr<_96, expr<_97, expr<_98, expr<_99,
                    forward<state::template type, expr>
                >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
                >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>;
        };

        template<
            class state,

            class _00, class _01, class _02, class _03, class _04, class _05,
            class _06, class _07, class _08, class _09>
        struct right_folder_10 {
            template<template<class...> class expr>
            /* clang-format off */
            using type =
                expr<_00, expr<_01, expr<_02, expr<_03, expr<_04,
                expr<_05, expr<_06, expr<_07, expr<_08, expr<_09,
                    forward<state::template type, expr>
                >>>>>>>>>>;
            /* clang-format on */
        };

        template<class state, class _00>
        struct right_folder_1 {
            template<template<class...> class expr>
            using type = expr<_00, forward<state::template type, expr>>;
        };

        template<class state>
        struct right_folder_0 {
            template<template<class...> class>
            using type = identity<state>;
        };

        template<std::size_t n>
        struct _fold_right_impl
            : _fold_right_impl<(n > 100) ? 100 : (n > 10) ? 10 : (n > 1)> {};

        template<>
        struct _fold_right_impl<100> {
            template<
                class _00, class _01, class _02, class _03, class _04,
                class _05, class _06, class _07, class _08, class _09,
                class _10, class _11, class _12, class _13, class _14,
                class _15, class _16, class _17, class _18, class _19,
                class _20, class _21, class _22, class _23, class _24,
                class _25, class _26, class _27, class _28, class _29,
                class _30, class _31, class _32, class _33, class _34,
                class _35, class _36, class _37, class _38, class _39,
                class _40, class _41, class _42, class _43, class _44,
                class _45, class _46, class _47, class _48, class _49,
                class _50, class _51, class _52, class _53, class _54,
                class _55, class _56, class _57, class _58, class _59,
                class _60, class _61, class _62, class _63, class _64,
                class _65, class _66, class _67, class _68, class _69,
                class _70, class _71, class _72, class _73, class _74,
                class _75, class _76, class _77, class _78, class _79,
                class _80, class _81, class _82, class _83, class _84,
                class _85, class _86, class _87, class _88, class _89,
                class _90, class _91, class _92, class _93, class _94,
                class _95, class _96, class _97, class _98, class _99,

                class... tail>
            using type = right_folder_100<
                typename _fold_right_impl<sizeof...(tail) - 1>::template type<
                    tail...>,

                _00, _01, _02, _03, _04, _05, _06, _07, _08, _09, _10, _11, _12,
                _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25,
                _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38,
                _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51,
                _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64,
                _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77,
                _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90,
                _91, _92, _93, _94, _95, _96, _97, _98, _99>;
        };

        template<>
        struct _fold_right_impl<10> {
            template<
                class _00, class _01, class _02, class _03, class _04,
                class _05, class _06, class _07, class _08, class _09,

                class... tail>
            using type = right_folder_10<
                typename _fold_right_impl<sizeof...(tail) - 1>::template type<
                    tail...>,

                _00, _01, _02, _03, _04, _05, _06, _07, _08, _09>;
        };

        template<>
        struct _fold_right_impl<1> {
            template<class _00, class... tail>
            using type = right_folder_1<
                typename _fold_right_impl<sizeof...(tail) - 1>::template type<
                    tail...>,
                _00>;
        };

        template<>
        struct _fold_right_impl<0> {
            template<class _00>
            using type = right_folder_0<_00>;
        };

        template<class state, class... vals>
        struct right_folder
            : _fold_right_impl<sizeof...(vals)>::template type<state, vals...> {
        };

        template<class lbd>
        struct _fold_right {};

        template<template<class...> class expr>
        struct _fold_right<lambda<expr>> {
            template<class... vals>
            using type = forward<right_folder<vals...>::template type, expr>;
        };
    }
    /// \endcond
}

#endif
