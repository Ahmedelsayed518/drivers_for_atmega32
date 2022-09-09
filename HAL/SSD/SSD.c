#include "SSD.h"

static void DigitDisplay(Uint8 num, Uint8 ssd_num);


void Ssd_init(void)
{
    PinMode(SSD_A_PIN, OUTPUT);
    PinMode(SSD_B_PIN, OUTPUT);
    PinMode(SSD_C_PIN, OUTPUT);
    PinMode(SSD_D_PIN, OUTPUT);
    PinMode(SSD_EN_1_PIN, OUTPUT);
    PinMode(SSD_EN_2_PIN, OUTPUT);
}
/*
void Ssd_write(Uint8 num)
{
    Uint8 num_arr[4] = {num % 10, num /10};
    Uint8 binary_int[4],i, j;
    int k= 0; 
    for (k; k<1; k++)
    {
        for (j=0;j<2;j++)
        {
            if (j==0)
            {
                PinWrite(SSD_EN_1_PIN, LOW);
                PinWrite(SSD_EN_2_PIN, HIGH);
            }
            else if(j==1)
            {
                PinWrite(SSD_EN_1_PIN, HIGH);
                PinWrite(SSD_EN_2_PIN, LOW);
            }
            if (num_arr[j] == 0)
            {
                binary_int[0] = 0;
                binary_int[1] = 0;
                binary_int[2] = 0;
                binary_int[3] = 0;
            }
            for(i=0;num_arr[j]>0;i++)    
            {
                binary_int[i]=num_arr[j]%2;
                num_arr[j]=num_arr[j]/2;
            }
            PinWrite(SSD_A_PIN, binary_int[0]);
            PinWrite(SSD_B_PIN, binary_int[1]);
            PinWrite(SSD_C_PIN, binary_int[2]);
            PinWrite(SSD_D_PIN, binary_int[3]);
            _delay_ms(5);
        }
    }
    PinWrite(SSD_EN_1_PIN, LOW);
    PinWrite(SSD_EN_2_PIN, LOW);
}
 
*/
static void DigitDisplay(Uint8 num, Uint8 ssd_num)
{
    Uint8 binary_int[4],i;
    if (ssd_num==RIGHT_SSD)
    {
        PinWrite(SSD_EN_1_PIN, LOW);
        PinWrite(SSD_EN_2_PIN, HIGH);
    }
    else if(ssd_num==LEFT_SSD)
    {
        PinWrite(SSD_EN_1_PIN, HIGH);
        PinWrite(SSD_EN_2_PIN, LOW);
    }
    if (num == 0)
    {
        binary_int[0] = 0;
        binary_int[1] = 0;
        binary_int[2] = 0;
        binary_int[3] = 0;
    }
    for(i=0;num>0;i++)    
    {
        binary_int[i]=num%2;
        num=num/2;
    }
    PinWrite(SSD_A_PIN, binary_int[0]);
    PinWrite(SSD_B_PIN, binary_int[1]);
    PinWrite(SSD_C_PIN, binary_int[2]);
    PinWrite(SSD_D_PIN, binary_int[3]);
    _delay_ms(1);
    PinWrite(SSD_EN_1_PIN, LOW);
    PinWrite(SSD_EN_2_PIN, LOW);
}

void Ssd_write(Uint8 num)
{
    for (int i=0; i<50; i++)
    {
        DigitDisplay(num%10, 0);
        _delay_ms(5);
        DigitDisplay(num/10, 1);
        _delay_ms(5);
    }
    
}


void SSD_CountUp(Uint8 target)
{
    Uint8 num = 0;
    for (num = 0; num<=target; target++)
    {
        Ssd_write(num);
    }
}