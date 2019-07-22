#pragma once

#ifdef __cplusplus
#include <cstdint>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct lvr_uuid_t
{
    uint8_t storage[16];
} lvr_uuid_t;

#ifdef __cplusplus
} // extern "C"
#endif
