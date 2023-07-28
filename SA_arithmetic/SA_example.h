#ifndef _SA_EXAMPLE_H
#define _SA_EXAMPLE_H

#include <stdio.h>
#include <math.h>

#define N 10

//Declare types for the inputs
typedef int in_t;
typedef int ain_t[N];


in_t arith_func(in_t a, in_t b, in_t c);

//Shared Accelerators
in_t func_1(in_t a, in_t b, ain_t array1, ain_t array2);
in_t func_2(in_t a, in_t b, ain_t array1, ain_t array2);

//Top Function
in_t SA_example(in_t a, in_t b, ain_t array1, ain_t array2);
#endif

