#pragma once

#define LVR_LOGGER_INTERFACE_NAME "lvr_logger_i"
#define LVR_LOGGER_SINK_INTERFACE_NAME "lvr_logger_sink_i"

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum
{
    lvr_severity_panic
} lvr_severity_t;

typedef struct lvr_logger_i
{
    void (*lvr_log)(lvr_severity_t severity, const char* message);
} lvr_logger_i;

typedef struct lvr_logger_sink_i
{
    void (*lvr_log)(lvr_severity_t severity, const char* message);
} lvr_logger_sink_i;

#ifdef __cplusplus
}
#endif
