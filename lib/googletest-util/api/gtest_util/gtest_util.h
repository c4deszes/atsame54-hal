#ifndef GTEST_UTIL_LIB_H_
#define GTEST_UTIL_LIB_H_

#include "gtest/gtest.h"

namespace testing {
namespace internal {
    ::testing::AssertionResult BitEquals(
        const char* expr1,
        const char* expr2,
        const char* expr3,
        uint32_t value,
        uint32_t position,
        uint32_t expected);

    ::testing::AssertionResult BitMaskSet(
        const char* expr1,
        const char* expr2,
        const char* expr3,
        uint32_t value,
        uint32_t mask);

    ::testing::AssertionResult BitMaskClear(
        const char* expr1,
        const char* expr2,
        const char* expr3,
        uint32_t value,
        uint32_t mask);
}
}

#define EXPECT_BITSET(value, position) \
    EXPECT_PRED_FORMAT3(::testing::internal::BitEquals, value, position, 1)
#define EXPECT_BITCLR(value, position) \
    EXPECT_PRED_FORMAT3(::testing::internal::BitEquals, value, position, 0)

#define EXPECT_BITSET_MASK(value, mask) \
    EXPECT_PRED_FORMAT3(::testing::internal::BitMaskSet, value, mask)
#define EXPECT_BITCLR_MASK(value, mask) \
    EXPECT_PRED_FORMAT3(::testing::internal::BitMaskClear, value, mask)

#define EXPECT_BITFIELD_MASK(value, mask, expected)

#endif
