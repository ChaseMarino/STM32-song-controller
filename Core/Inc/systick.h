/*
 * systick.h
 *
 */

#ifndef INC_SYSTICK_H_
#define INC_SYSTICK_H_

typedef struct {
	uint32_t SYST_CSR;
	uint32_t SYST_RVR;
	uint32_t SYST_CVR;
	uint32_t SYST_CALIB;
} systick_t ;

#endif /* INC_SYSTICK_H_ */
