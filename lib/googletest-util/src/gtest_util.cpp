#include "gtest/gtest.h"
#include "gtest_util/gtest_util.h"

namespace testing {
namespace internal {
    ::testing::AssertionResult BitEquals(
        const char* expr1,
        const char* expr2,
        const char* expr3,
        uint32_t value,
        uint32_t position,
        uint32_t expected) {
        if (((value >> position) & 1) != expected) {
            return ::testing::AssertionFailure() << "Expected " << expected
                                                 << " in " << expr1
                                                 << " (=" << value << ")"
                                                 << " at bit " << position;
        }
        return ::testing::AssertionSuccess();
    }

    ::testing::AssertionResult BitMaskSet(
        const char* expr1,
        const char* expr2,
        const char* expr3,
        uint32_t value,
        uint32_t mask) {

        if ((value & mask) == 0) {
            return ::testing::AssertionFailure() << "Expected non zero in "
                                                 << expr1 << " (=" << value << ")"
                                                 << " at mask " << mask;
        }
        return ::testing::AssertionSuccess();
    }

    ::testing::AssertionResult BitMaskClear(
        const char* expr1,
        const char* expr2,
        const char* expr3,
        uint32_t value,
        uint32_t mask) {
        
        if ((value & mask) != 0) {
            return ::testing::AssertionFailure() << "Expected zero in "
                                                 << expr1 << " (=" << value << ")"
                                                 << " at mask " << mask;;
        }
        return ::testing::AssertionSuccess();
    }
}
}