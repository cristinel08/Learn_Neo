#include "neon.h"
#include <stdlib.h>

int32_t CreateNeonArrayAndSum(
    void
)
{
    int32_t sum = {0};
    int16_t cArray[8] = {};
    for(int8_t i = 0; i < 8; i++)
    {
        cArray[i] = i;
    }
    const int16x8_t neonConstArr = vld1q_s16(cArray);
    for(int  i = 0; i < ARRAY_SIZE; i = i + 8)
    {
        sum += vaddvq_s16(
            vaddq_s16(
                vdupq_n_s16(i),
                neonConstArr
            )
        ); 
    }
    return sum;
}

int32_t sum_ni(
    int16_t *array, 
    int const arraySize
)
{
    int32_t sum = 0;
    // int16_t* pointerArray = array;
    // for(int i = 0; i < arraySize / 8; i++)
    // {
    //     sum += vaddvq_u16(vld1q_s16(pointerArray));
    //     pointerArray = pointerArray + 8;
    // }
    for(int i = 0; i < arraySize; i = i + 8)
    {
        sum += vaddvq_s16(vld1q_s16(&array[i]));
    }

    return sum;
}