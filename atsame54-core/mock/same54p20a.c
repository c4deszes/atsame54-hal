#include "device/same54p20a.h"

volatile ac_registers_t AC_REGS_internal;
volatile adc_registers_t ADC0_REGS_internal;
volatile adc_registers_t ADC1_REGS_internal;
volatile aes_registers_t AES_REGS_internal;
volatile can_registers_t CAN0_REGS_internal;
volatile can_registers_t CAN1_REGS_internal;
volatile ccl_registers_t CCL_REGS_internal;
volatile cmcc_registers_t CMCC_REGS_internal;
volatile dac_registers_t DAC_REGS_internal;
volatile dmac_registers_t DMAC_REGS_internal;
volatile dsu_registers_t DSU_REGS_internal;
volatile eic_registers_t EIC_REGS_internal;
volatile evsys_registers_t EVSYS_REGS_internal;
volatile freqm_registers_t FREQM_REGS_internal;
volatile gclk_registers_t GCLK_REGS_internal;
volatile gmac_registers_t GMAC_REGS_internal;
volatile hmatrixb_registers_t HMATRIX_REGS_internal;
volatile icm_registers_t ICM_REGS_internal;
volatile i2s_registers_t I2S_REGS_internal;
volatile mclk_registers_t MCLK_REGS_internal;
volatile nvmctrl_registers_t NVMCTRL_REGS_internal;
volatile oscctrl_registers_t OSCCTRL_REGS_internal;
volatile osc32kctrl_registers_t OSC32KCTRL_REGS_internal;
volatile pac_registers_t PAC_REGS_internal;
volatile pcc_registers_t PCC_REGS_internal;
volatile pdec_registers_t PDEC_REGS_internal;
volatile pm_registers_t PM_REGS_internal;
volatile port_registers_t PORT_REGS_internal;
volatile qspi_registers_t QSPI_REGS_internal;
volatile ramecc_registers_t RAMECC_REGS_internal;
volatile rstc_registers_t RSTC_REGS_internal;
volatile rtc_registers_t RTC_REGS_internal;
volatile sdhc_registers_t SDHC0_REGS_internal;
volatile sdhc_registers_t SDHC1_REGS_internal;
volatile sercom_registers_t SERCOM0_REGS_internal;
volatile sercom_registers_t SERCOM1_REGS_internal;
volatile sercom_registers_t SERCOM2_REGS_internal;
volatile sercom_registers_t SERCOM3_REGS_internal;
volatile sercom_registers_t SERCOM4_REGS_internal;
volatile sercom_registers_t SERCOM5_REGS_internal;
volatile sercom_registers_t SERCOM6_REGS_internal;
volatile sercom_registers_t SERCOM7_REGS_internal;
volatile supc_registers_t SUPC_REGS_internal;
volatile tc_registers_t TC0_REGS_internal;
volatile tc_registers_t TC1_REGS_internal;
volatile tc_registers_t TC2_REGS_internal;
volatile tc_registers_t TC3_REGS_internal;
volatile tc_registers_t TC4_REGS_internal;
volatile tc_registers_t TC5_REGS_internal;
volatile tc_registers_t TC6_REGS_internal;
volatile tc_registers_t TC7_REGS_internal;
volatile tcc_registers_t TCC0_REGS_internal;
volatile tcc_registers_t TCC1_REGS_internal;
volatile tcc_registers_t TCC2_REGS_internal;
volatile tcc_registers_t TCC3_REGS_internal;
volatile tcc_registers_t TCC4_REGS_internal;
volatile trng_registers_t TRNG_REGS_internal;
volatile usb_registers_t USB_REGS_internal;
volatile wdt_registers_t WDT_REGS_internal;

void NVIC_EnableIRQ(IRQn_Type IRQn) {

}

uint32_t NVIC_GetEnableIRQ(IRQn_Type IRQn) {
    return 0;
}

void NVIC_DisableIRQ(IRQn_Type IRQn) {
    
}

uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn) {
    return 0;
}

void NVIC_SetPendingIRQ(IRQn_Type IRQn) {

}
