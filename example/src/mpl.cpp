#include <metal.hpp>

#include "example.hpp"

#if 0
/// [lazy_expression]
struct na {};

template<class arg_1 = na, class arg_2 = na, /*...*/ class arg_n = na>
struct metafunction
{
    typedef /*...*/ type;
};

template<class arg_1, class arg_2, /*...*/ class arg_n>
struct compound_metafunction
{
    typedef typename metafunction<
        typename metafunction<arg_1>::type,
        typename metafunction<arg_2>::type,
        /*...*/
        typename metafunction<arg_n>::type
    >::type type;
};
/// [lazy_expression]

/// [eager_expression]
template<class... args>
using metafunction = /*...*/;

template<class... args>
using compound_metafunction = metafunction<metafunction<args>...>;
/// [eager_expression]

/// [lazy_lambda]
struct first_class_metafunction
{
    template<class arg_1, class arg_2, /*...*/ class arg_n>
    struct apply {
        typedef /*...*/ type;
    };
};
/// [lazy_lambda]

/// [eager_lambda]
template<class... args>
using metafunction = /*...*/;

using first_class_metafunction = metal::lambda<metafunction>;
/// [eager_lambda]
#endif

/// [lazy_evaluation]
IS_SAME(metal::invoke<metal::lambda<std::add_pointer>, void>, std::add_pointer<void>);
IS_SAME(metal::invoke<metal::lambda<std::common_type>, void*, char[]>, std::common_type<void*, char[]>);
/// [lazy_evaluation]

/// [lazy_adaptor]
IS_SAME(metal::invoke<metal::lazy<std::add_pointer>, void>, void*);
IS_SAME(metal::invoke<metal::lazy<std::common_type>, void*, char[]>, void*);
/// [lazy_adaptor]

/// [eval]
IS_SAME(metal::eval<std::add_pointer<void>>, void*);
IS_SAME(metal::eval<std::common_type<void*, char[]>>, void*);
/// [eval]

/// [trait_adaptor]
IS_SAME(metal::invoke<metal::trait<std::is_pointer>, void*>, metal::true_);
IS_SAME(metal::invoke<metal::trait<std::is_pointer>, void()>, metal::false_);

IS_SAME(metal::invoke<metal::trait<std::is_convertible>, char[], void*>, metal::true_);
IS_SAME(metal::invoke<metal::trait<std::is_convertible>, void*, char[]>, metal::false_);
/// [trait_adaptor]

/// [as_number]
IS_SAME(metal::as_number<std::is_pointer<void*>>, metal::true_);
IS_SAME(metal::as_number<std::is_pointer<void()>>, metal::false_);

IS_SAME(metal::as_number<std::is_convertible<char[], void*>>, metal::true_);
IS_SAME(metal::as_number<std::is_convertible<void*, char[]>>, metal::false_);
/// [as_number]
