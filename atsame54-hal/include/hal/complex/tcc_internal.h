#ifndef ATSAME54_HAL_INCLUDE_HAL_COMPLEX_TCC_INTERNAL_H_
#define ATSAME54_HAL_INCLUDE_HAL_COMPLEX_TCC_INTERNAL_H_

#define TCC_INSTANCE_COUNT 5

struct tcc_instance {
    tcc_registers_t* peripheral;
};

extern uint8_t tcc_instance_cntr;
extern struct tcc_instance tcc_instances[TCC_INSTANCE_COUNT];

#endif