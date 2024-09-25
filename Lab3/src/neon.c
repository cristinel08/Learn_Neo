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

int32_t SumNi(
    int16_t *array, 
    int const arraySize
)
{
    int32_t sum = 0;
    for(int i = 0; i < arraySize; i = i + 8)
    {
        sum += vaddvq_s16(vld1q_s16(&array[i]));
    }
    return sum;
}

void MultiplyMatVecNi(
    float* aVec,
    float* bVec,
    float* cVec,
    int const matSize   
)
{
    float bTranspose[matSize];
    float32x4_t aNeon = vld1q_f32(aVec);
    float32x4_t bNeon;
    float32x4_t result = vdupq_n_f32(0.0);
    for(int i = 0; i < matSize; i++)
    {
        bTranspose[i] = bVec[((i * 4) + i / 4) % matSize];
    }
    int8_t bIndex = 0;
    for(int i = 0; i < matSize; i++)
    {
        if(i % 4 == 0)
        {
            aNeon = vld1q_f32(&aVec[i]);
        }
        bNeon = vld1q_f32(&bTranspose[bIndex]);
        result = vmulq_f32(aNeon, bNeon);
        cVec[i] = vaddvq_f32(result);
        bIndex = (i * 4) % 16;
    }
}