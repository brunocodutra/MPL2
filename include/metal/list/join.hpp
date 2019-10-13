#ifndef METAL_LIST_JOIN_HPP
#define METAL_LIST_JOIN_HPP

#include "../config.hpp"
#include "../detail/sfinae.hpp"

#include <cstddef>

namespace metal {
    /// \cond
    namespace detail {
        template<std::size_t n>
        struct joiner;
    }
    /// \endcond

    /// \ingroup list
    ///
    /// ### Description
    /// Concatenates \lists.
    ///
    /// ### Usage
    /// For any \lists `l_0, ..., l_n-1`
    /// \code
    ///     using result = metal::join<l_0, ..., l_n-1>;
    /// \endcode
    ///
    /// \returns: \list
    /// \semantics:
    ///     Equivalent to
    ///     \code
    ///         using result = metal::list<l_0[:], ...[:], l_n-1[:]>;
    ///     \endcode
    ///     where `l[:]` stands for the expansion of all elements contained in
    ///     `l`.
    ///
    /// ### Example
    /// \snippet list.cpp join
    ///
    /// ### See Also
    /// \see list, flatten
    template<class... seqs>
    using join =
        detail::call<detail::joiner<sizeof...(seqs)>::template type, seqs...>;
}

#include "../list/list.hpp"

namespace metal {
    /// \cond
    namespace detail {
        template<
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,
            class = list<>, class = list<>, class = list<>, class = list<>,

            class = list<>>
        struct _join_impl {};

        template<
            class... _00, class... _01, class... _02, class... _03,
            class... _04, class... _05, class... _06, class... _07,
            class... _08, class... _09, class... _10, class... _11,
            class... _12, class... _13, class... _14, class... _15,
            class... _16, class... _17, class... _18, class... _19,
            class... _20, class... _21, class... _22, class... _23,
            class... _24, class... _25, class... _26, class... _27,
            class... _28, class... _29, class... _30, class... _31,
            class... _32, class... _33, class... _34, class... _35,
            class... _36, class... _37, class... _38, class... _39,
            class... _40, class... _41, class... _42, class... _43,
            class... _44, class... _45, class... _46, class... _47,
            class... _48, class... _49, class... _50, class... _51,
            class... _52, class... _53, class... _54, class... _55,
            class... _56, class... _57, class... _58, class... _59,
            class... _60, class... _61, class... _62, class... _63,
            class... _64, class... _65, class... _66, class... _67,
            class... _68, class... _69, class... _70, class... _71,
            class... _72, class... _73, class... _74, class... _75,
            class... _76, class... _77, class... _78, class... _79,
            class... _80, class... _81, class... _82, class... _83,
            class... _84, class... _85, class... _86, class... _87,
            class... _88, class... _89, class... _90, class... _91,
            class... _92, class... _93, class... _94, class... _95,
            class... _96, class... _97, class... _98, class... _99,

            class... _>
        struct _join_impl<
            list<_00...>, list<_01...>, list<_02...>, list<_03...>,
            list<_04...>, list<_05...>, list<_06...>, list<_07...>,
            list<_08...>, list<_09...>, list<_10...>, list<_11...>,
            list<_12...>, list<_13...>, list<_14...>, list<_15...>,
            list<_16...>, list<_17...>, list<_18...>, list<_19...>,
            list<_20...>, list<_21...>, list<_22...>, list<_23...>,
            list<_24...>, list<_25...>, list<_26...>, list<_27...>,
            list<_28...>, list<_29...>, list<_30...>, list<_31...>,
            list<_32...>, list<_33...>, list<_34...>, list<_35...>,
            list<_36...>, list<_37...>, list<_38...>, list<_39...>,
            list<_40...>, list<_41...>, list<_42...>, list<_43...>,
            list<_44...>, list<_45...>, list<_46...>, list<_47...>,
            list<_48...>, list<_49...>, list<_50...>, list<_51...>,
            list<_52...>, list<_53...>, list<_54...>, list<_55...>,
            list<_56...>, list<_57...>, list<_58...>, list<_59...>,
            list<_60...>, list<_61...>, list<_62...>, list<_63...>,
            list<_64...>, list<_65...>, list<_66...>, list<_67...>,
            list<_68...>, list<_69...>, list<_70...>, list<_71...>,
            list<_72...>, list<_73...>, list<_74...>, list<_75...>,
            list<_76...>, list<_77...>, list<_78...>, list<_79...>,
            list<_80...>, list<_81...>, list<_82...>, list<_83...>,
            list<_84...>, list<_85...>, list<_86...>, list<_87...>,
            list<_88...>, list<_89...>, list<_90...>, list<_91...>,
            list<_92...>, list<_93...>, list<_94...>, list<_95...>,
            list<_96...>, list<_97...>, list<_98...>, list<_99...>,

            list<_...>> {
            using type = list<
                _00..., _01..., _02..., _03..., _04..., _05..., _06..., _07...,
                _08..., _09..., _10..., _11..., _12..., _13..., _14..., _15...,
                _16..., _17..., _18..., _19..., _20..., _21..., _22..., _23...,
                _24..., _25..., _26..., _27..., _28..., _29..., _30..., _31...,
                _32..., _33..., _34..., _35..., _36..., _37..., _38..., _39...,
                _40..., _41..., _42..., _43..., _44..., _45..., _46..., _47...,
                _48..., _49..., _50..., _51..., _52..., _53..., _54..., _55...,
                _56..., _57..., _58..., _59..., _60..., _61..., _62..., _63...,
                _64..., _65..., _66..., _67..., _68..., _69..., _70..., _71...,
                _72..., _73..., _74..., _75..., _76..., _77..., _78..., _79...,
                _80..., _81..., _82..., _83..., _84..., _85..., _86..., _87...,
                _88..., _89..., _90..., _91..., _92..., _93..., _94..., _95...,
                _96..., _97..., _98..., _99...,

                _...>;
        };

        template<class... seqs>
        using join_impl = typename _join_impl<seqs...>::type;

        template<std::size_t n>
        struct joiner : joiner<(n > 100) ? 100 : 0> {};

        template<>
        struct joiner<100> {
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
            using type = join_impl<
                _00, _01, _02, _03, _04, _05, _06, _07, _08, _09, _10, _11, _12,
                _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25,
                _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38,
                _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51,
                _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64,
                _65, _66, _67, _68, _69, _70, _71, _72, _73, _74, _75, _76, _77,
                _78, _79, _80, _81, _82, _83, _84, _85, _86, _87, _88, _89, _90,
                _91, _92, _93, _94, _95, _96, _97, _98, _99,

                typename joiner<sizeof...(tail)>::template type<tail...>>;
        };

        template<>
        struct joiner<0> {
            template<class... seqs>
            using type = join_impl<seqs...>;
        };
    }
    /// \endcond
}

#endif
