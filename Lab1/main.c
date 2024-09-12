#include <arm_neon.h>
#include <stdio.h>

int main()
{
    int8x8_t data1 = vdup_n_s8(128);
    int8x8_t data2 = vdup_n_s8(2);
    data1 = vdup_lane_s8(data2, 7);

    int8x8_t result8x8 = vadd_s8(data1, data2);
    int result = vget_lane_s8(result8x8, 0);
    // int result = (int) rst8x8;
    printf("Data is: %d\n", result);
    return 0;
}