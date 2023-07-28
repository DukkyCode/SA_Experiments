#include "SA_example.h"

in_t arith_func(in_t a, in_t b, in_t c){
	#pragma HLS inline self off
	in_t result = (a * b) + (c / (a - b));
	return result;
}

//Shared Accelerators
in_t func_1(in_t a, in_t b, ain_t array1, ain_t array2){
	#pragma HLS inline
	int i, j, k;
	in_t result = 0;
	
	//Shared Function and loop
	for(i = 0; i < N; i++){
		array2[i] += arith_func(a, b, array1[i]);
		for(j = 0; j < N; j++){
			array2[j] += arith_func(a, b, array1[j]);
			for(k = 0; k < N; k++){
				array2[k] = arith_func(a, b, array1[k]);
			}

		}
	}

	//Not-shared function and loop
	for(i = 0; i < N; i++){
		result += array2[i] * 3;	
	}

	return result;

}

in_t func_2(in_t a, in_t b, ain_t array1, ain_t array2){
	#pragma HLS inline
        int i, j, k;
        in_t result = 0;

        //Shared Function and loop
        for(i = 0; i < N; i++){
                array2[i] = arith_func(a, b, array1[i]);
                for(j = 0; j < N; j++){
                        array2[j] += arith_func(a, b, array1[j]);
                        for(k = 0; k < N; k++){
                                array2[k] = arith_func(a, b, array1[k]);
                        }

                }
	}

	//Not-shared function and loop
	for(i = 0; i < N; i++){
                result = result + array2[i] + array1[i];
        }


}

//Top Function
in_t SA_example(in_t a, in_t b, ain_t array1, ain_t array2){
	#pragma HLS allocation instances=arith_func limit = 2 function
	in_t sum = 0;
	sum += func_1(a, b, array1, array2);
	sum += func_2(a, b, array1, array2);
	
	return sum;


}




