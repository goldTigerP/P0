#ifndef __ERROR_CODE_H__
#define __ERROR_CODE_H__

#include <stdint.h>

using ErrorT = uint32_t;

inline constexpr ErrorT SUCCESS = 0;

inline constexpr ErrorT FAILURE = 1;

#endif
