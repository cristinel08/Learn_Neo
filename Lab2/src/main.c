#include <arm_neon.h>
#include <stdio.h>
#include <neon.h>
#include <time.h>


int32_t sum_c(int16_t* array)
{
    int32_t sum = 0;
    for(int16_t i = 0; i < ARRAY_SIZE; i++)
    {
        sum += array[i];
    }
    return sum;
}

int main()
{
    //normal c implementation
    clock_t begin = clock();
    int16_t c_array[ARRAY_SIZE] = {};
    for (int16_t i = 0; i < ARRAY_SIZE; i++)
    {
        c_array[i] = i;
    }
    int32_t sum = sum_c(c_array);
    clock_t end = clock();
    float time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
    printf("C_IMPLEMENTATION:\n");
    printf("The sum of the elements is: %d\n", sum);
    printf("The execution time is: %f ms\n", time_spent * 1000);
    //neon implementation
    begin = clock();
    int32_t neonSum = CreateNeonArrayAndSum();
    end = clock();
    time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
    printf("NEON_IMPLEMENTATION\n");
    printf("The sum of the elements is: %d\n", neonSum);
    printf("The execution time is: %f ms\n", time_spent * 1000);
    return 0;
}