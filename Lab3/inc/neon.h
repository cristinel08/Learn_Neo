#include <arm_neon.h>

#define ARRAY_SIZE 2048

int32_t CreateNeonArrayAndSum(
    void
);
int32_t SumNi(
    int16_t* array,
    int const arraySize   
);
void MultiplyMatVecNi(
    float* aVec,
    float* bVec,
    float* cVec,
    int const matSize      
);

