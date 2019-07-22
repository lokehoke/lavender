#pragma once

#include "foundation/types.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct lvr_uuid_gen_i
{
    lvr_uuid_t (*next_uuid)();
} lvr_uuid_gen_i;

#ifdef __cplusplus
}
#endif
