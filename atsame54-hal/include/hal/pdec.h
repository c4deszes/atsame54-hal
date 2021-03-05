#ifndef CONTROL_HAL_HAL_PDEC_H_
#define CONTROL_HAL_HAL_PDEC_H_

#include <stdint.h>
#include "device/system_same54.h"
#include "device/same54p20a.h"
#include "component/pdec.h"

typedef enum {
    X4 = PDEC_CTRLA_CONF_X4,
    X4S = PDEC_CTRLA_CONF_X4S
} pdec_qdec_conf;

typedef struct {
    uint8_t gclk_source;
    pdec_qdec_conf conf;
} pdec_qdec_configuration;

typedef struct {
    uint8_t gclk_source;
} pdec_hall_configuration;

typedef struct {
    uint8_t gclk_source;

} pdec_counter_configuration;

extern void PDEC_QdecInitialize(pdec_qdec_configuration*);
extern void PDEC_HallInitialize(pdec_hall_configuration*);
extern void PDEC_CounterInitialize(pdec_counter_configuration*);

extern void PDEC_Start(void);
extern void PDEC_Stop(void);

extern uint16_t PDEC_GetPosition(void);
extern uint16_t PDEC_GetRevolutions(void);

#endif