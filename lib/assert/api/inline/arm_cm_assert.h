#ifndef ARM_CM_ASSERT_H_
#define ARM_CM_ASSERT_H_

#define CUSTOM_ASSERT(expression) \
    do {                          \
        if (!expression) {        \
            while(1);             \
        }                         \
    } while(0)

#define CUSTOM_EXPECT(expression) \
    do {                          \
        if (!expression) {        \
            while(1);             \
        }                         \
    } while(0)

#endif // ARM_CM_ASSERT_H_
