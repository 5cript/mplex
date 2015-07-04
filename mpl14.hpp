#ifndef MPL14_HPP_INCLUDED
#define MPL14_HPP_INCLUDED

// this file is for convenience, but actually I personally do not recommend to use it

// fundamental
#include "fundamental/eval_if.hpp"
#include "fundamental/integral.hpp"
#include "fundamental/for_each_exec.hpp"
#include "fundamental/identity.hpp"
#include "fundamental/is_same.hpp"

// functional
#include "functional/functor.hpp"
#include "functional/bind.hpp"
#include "functional/compose.hpp"
#include "functional/bitwise.hpp"
#include "functional/arithmetic.hpp"
#include "functional/logic.hpp"

// sequences / tuples
#include "tuple/apply.hpp"
#include "tuple/front.hpp"
#include "tuple/back.hpp"
#include "tuple/push_back.hpp"
#include "tuple/push_front.hpp"
#include "tuple/pop_back.hpp"
#include "tuple/pop_front.hpp"
#include "tuple/split.hpp"
#include "tuple/remove_if.hpp"
#include "tuple/all_of.hpp"
#include "tuple/one_of.hpp"
#include "tuple/element_swap.hpp"
#include "tuple/trim.hpp"
#include "tuple/erase.hpp"
#include "tuple/copy.hpp"
#include "tuple/erase.hpp"
#include "tuple/replace.hpp"
#include "tuple/find.hpp"
#include "tuple/find_if.hpp"
#include "tuple/make_tuple.hpp"

// control
#include "control/if.hpp"
#include "control/switch.hpp"

// string
#include "string/algorithm_adapter.hpp"
#include "string/char.hpp"
#include "string/case_convert.hpp"
#include "string/classification.hpp"
#include "string/compare.hpp"
#include "string/erase.hpp"
#include "string/find.hpp"
#include "string/strcat.hpp"
#include "string/string.hpp"
#include "string/trim.hpp"
#include "string/inline_string.hpp"
#include "string/split.hpp"
#include "string/remove_if.hpp"

// date time
#include "time/time.hpp"
#include "time/date.hpp"

// random
#include "random/random.hpp"
#include "random/linear_congruential_engine.hpp"

// advanced
#include "advanced/tokenizer.hpp"
#include "advanced/type_mapper.hpp"

// type_print
#include "type_print/type_print.hpp"

#endif // MPL14_HPP_INCLUDED
