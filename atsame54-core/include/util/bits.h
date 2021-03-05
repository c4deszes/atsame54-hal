#ifndef BASE_INCLUDE_UTIL_BITS_H_
#define BASE_INCLUDE_UTIL_BITS_H_

#define MAKE_BYTE(h, l) \
            (uint8_t)((h & 0x0F << 4) | (l & 0x0F))
#define MAKE_WORD(h, l) \
            (uint16_t)(((uint16_t)h & 0xFF << 8) | ((uint16_t)l & 0xFF))

#endif  // BASE_INCLUDE_UTIL_BITS_H_
