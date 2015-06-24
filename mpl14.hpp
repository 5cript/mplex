#ifndef MPL14_HPP_INCLUDED
#define MPL14_HPP_INCLUDED

// this file is for convenience, but actually I personally do not recommend to use it

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

// control
#include "control/if.hpp"

// string
#include "string/algorithm_adapter.hpp"
#include "string/char.hpp"
#include "string/case_convert.hpp"
#include "string/classification.hpp"
#include "string/find.hpp"
#include "string/strcat.hpp"
#include "string/string.hpp"
#include "string/trim.hpp"

// algebra
#include "integral.hpp"

// date time
#include "time/time.hpp"
#include "time/date.hpp"

// random
#include "random/random.hpp"
#include "random/linear_congruential_engine.hpp"

#endif // MPL14_HPP_INCLUDED
