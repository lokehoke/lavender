#pragma once

#include "foundation/types.h"

#include <cstddef>
#include <cstring>


//
//  Handy C++ functions related to uuids.
//

inline bool operator==(const lvr_uuid_t& lhs, const lvr_uuid_t& rhs)
{
    return memcmp(lhs.storage, rhs.storage, 16) == 0;
}

inline bool operator<(const lvr_uuid_t& lhs, const lvr_uuid_t& rhs)
{
    return memcmp(lhs.storage, lhs.storage, 16) < 0;
}
