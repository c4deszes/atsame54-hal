#ifndef (ATSAME54_HAL_INCLUDE_HAL_SYSTEM_STREAM_H_)
#define ATSAME54_HAL_INCLUDE_HAL_SYSTEM_STREAM_H_

#include <stddef.h>

typedef int (*stream_write)(void* buffer, size_t count);

typedef int (*stream_read)(void* buffer, size_t count);

#endif // ATSAME54_HAL_INCLUDE_HAL_SYSTEM_STREAM_H_
