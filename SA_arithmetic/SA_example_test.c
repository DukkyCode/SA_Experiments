#include "SA_example.h"

int main(){
	int i;
	int pass = 0;
	in_t a = 30;
	in_t b = 50;
	ain_t array1, array2;

	for(i = 0; i < N; i++){
		array1[i] = 50 + i;
	       	array2[i] = 100 + i;	
	}

	in_t result = SA_example(a, b, array1, array2);
	
	fprintf(stdout, "result = %d", result);

	//Print statement
	if (pass){
		fprintf(stdout, "****** Test Failed! **********\n");
	}
	else{
		fprintf(stderr, "------Test Passed!------------\n");
	}
	
	return 0;
}


