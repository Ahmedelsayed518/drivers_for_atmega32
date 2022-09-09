#ifndef SSD_H_
#define SSD_H_

#include "../../MCAL/DIO/Dio.h"
#include "util/delay.h"


#define SSD_A_PIN PA4
#define SSD_B_PIN PA5
#define SSD_C_PIN PA6
#define SSD_D_PIN PA7
#define SSD_EN_1_PIN PB2
#define SSD_EN_2_PIN PB1
#define RIGHT_SSD 0
#define LEFT_SSD 1

void Ssd_init(void);
void Ssd_write(Uint8);


#endif