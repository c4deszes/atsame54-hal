#ifndef CUSTOM_ASSERT_H_
#define CUSTOM_ASSERT_H_

extern _custom_assert(void* addr);

#define _ASSERT_INTERNAL(expression, file, line)

#define CUSTOM_ASSERT(expression) \
    do {                          \
        if (!expression) {        \
            
        }
    } while(0)

#define CUSTOM_EXPECT(expression) \
    do {

    } while(0)

#endif
