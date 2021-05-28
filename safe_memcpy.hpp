#pragma once
#include <stdint.h>
#include <string.h>
static inline bool between(const uint8_t *start, const uint8_t *end, const uint8_t *p) {
    return (p < end) && (p >= start);
}
static inline bool safe_check(void *dst, size_t len, const void *start, const void *end) {
    if (len < 1) {
        return false;
    }
    if (!dst || !start || !end) {
        return false;
    }
    void *last_pos = ((uint8_t *)dst) + len - 1;
    if (last_pos < dst) {
        return false;
    }
    return between((uint8_t *)start, (uint8_t *)end, (uint8_t *)dst) &&
           between((uint8_t *)start, (uint8_t *)end, (uint8_t *)last_pos);
}
static inline bool safe_memcpy(void *dst, const void *src, size_t len, const void *start, const void *end) {
    if (!safe_check(dst, len, start, end)) {
        return false;
    }
    if (!src) {
        return false;
    }
    memcpy(dst, src, len);
    return true;
}