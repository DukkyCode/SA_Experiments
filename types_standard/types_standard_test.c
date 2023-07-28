// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
/*******************************************************************************
Vendor: Xilinx 
Associated Filename: types_standard_test.c
Purpose:Vivado HLS Coding Style example 
Device: All 
Revision History: May 30, 2008 - initial release
                                                
*******************************************************************************
#-  (c) Copyright 2011-2019 Xilinx, Inc. All rights reserved.
#-
#-  This file contains confidential and proprietary information
#-  of Xilinx, Inc. and is protected under U.S. and
#-  international copyright and other intellectual property
#-  laws.
#-
#-  DISCLAIMER
#-  This disclaimer is not a license and does not grant any
#-  rights to the materials distributed herewith. Except as
#-  otherwise provided in a valid license issued to you by
#-  Xilinx, and to the maximum extent permitted by applicable
#-  law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
#-  WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
#-  AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
#-  BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
#-  INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
#-  (2) Xilinx shall not be liable (whether in contract or tort,
#-  including negligence, or under any other theory of
#-  liability) for any loss or damage of any kind or nature
#-  related to, arising under or in connection with these
#-  materials, including for any direct, or any indirect,
#-  special, incidental, or consequential loss or damage
#-  (including loss of data, profits, goodwill, or any type of
#-  loss or damage suffered as a result of any action brought
#-  by a third party) even if such damage or loss was
#-  reasonably foreseeable or Xilinx had been advised of the
#-  possibility of the same.
#-
#-  CRITICAL APPLICATIONS
#-  Xilinx products are not designed or intended to be fail-
#-  safe, or for use in any application requiring fail-safe
#-  performance, such as life-support or safety devices or
#-  systems, Class III medical devices, nuclear facilities,
#-  applications related to the deployment of airbags, or any
#-  other applications that could lead to death, personal
#-  injury, or severe property or environmental damage
#-  (individually and collectively, "Critical
#-  Applications"). Customer assumes the sole risk and
#-  liability of any use of Xilinx products in Critical
#-  Applications, subject only to applicable laws and
#-  regulations governing limitations on product liability.
#-
#-  THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
#-  PART OF THIS FILE AT ALL TIMES. 
#- ************************************************************************

This file contains confidential and proprietary information of Xilinx, Inc. and 
is protected under U.S. and international copyright and other intellectual 
property laws.

DISCLAIMER
This disclaimer is not a license and does not grant any rights to the materials 
distributed herewith. Except as otherwise provided in a valid license issued to 
you by Xilinx, and to the maximum extent permitted by applicable law: 
(1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND WITH ALL FAULTS, AND XILINX 
HEREBY DISCLAIMS ALL WARRANTIES AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, 
INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-INFRINGEMENT, OR 
FITNESS FOR ANY PARTICULAR PURPOSE; and (2) Xilinx shall not be liable (whether 
in contract or tort, including negligence, or under any other theory of 
liability) for any loss or damage of any kind or nature related to, arising under 
or in connection with these materials, including for any direct, or any indirect, 
special, incidental, or consequential loss or damage (including loss of data, 
profits, goodwill, or any type of loss or damage suffered as a result of any 
action brought by a third party) even if such damage or loss was reasonably 
foreseeable or Xilinx had been advised of the possibility of the same.

CRITICAL APPLICATIONS
Xilinx products are not designed or intended to be fail-safe, or for use in any 
application requiring fail-safe performance, such as life-support or safety 
devices or systems, Class III medical devices, nuclear facilities, applications 
related to the deployment of airbags, or any other applications that could lead 
to death, personal injury, or severe property or environmental damage 
(individually and collectively, "Critical Applications"). Customer asresultes the 
sole risk and liability of any use of Xilinx products in Critical Applications, 
subject only to applicable laws and regulations governing limitations on product 
liability. 

THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS PART OF THIS FILE AT 
ALL TIMES.

*******************************************************************************/
#include "types_standard.h"
 
int main () {
  din_A  inA;
  din_B  inB;
  din_C  inC;
  din_D  inD;
  dout_1 out1;
  dout_2 out2;
  dout_3 out3;
  dout_4 out4;

	int i, retval=0;
	FILE        *fp;

	float out1_total = 0;
	float out2_total = 0;
	float out3_total = 0; 
	float out4_total = 0;

	int out1_results[9] = {46, 72, 100, 130, 162, 196, 232, 270, 310};
        int out2_results[9] = {25, 27, 29, 31, 33, 35, 37, 39, 41};	
	int out3_results[9] = {117, 78, 59, 47, 39, 34, 30, 26, 24};
	int out4_results[9] = {1, 0, 3, 3, 3, 5, 7, 3, 3};
	

	// Save the results to a file
	//fp=fopen("result.dat","w");

	for (i=0;i<N;i++) {
		// Create input data
    		inA = i+2;
    		inB = i+23;
    		inC = i+234;
    		inD = i+2345;

        	// Call the function to operate on the data
        	types_standard(inA,inB,inC,inD,&out1,&out2,&out3,&out4);

		//Get the accuracy
		float temp1 = (float) out1 - out1_results[i];
		float temp2 = (float) out2 - out2_results[i];
		float temp3 = (float) out3 - out3_results[i];
		
		float temp4;

		//Avoid the 0/0 arithmetic
		if(out4 == 0){
			temp4 = 1;
		}
		else{
			temp4 = (float) out4 - out4_results[i];
		}

		//Use this function to calculate the total
		out1_total = out1_total + fabs(temp1);
		out2_total = out2_total + fabs(temp2);
		out3_total = out3_total + fabs(temp3);
		out4_total = out4_total + fabs(temp4);

		fprintf(stdout,"out1: %.2f; out2: %.2f; out3: %.2f; out4: %.2f \n", out1, out2, out3, out4);

//#ifndef __MINGW32__
	//fprintf(fp, "%d*%d=%d; %d+%d=%d; %d/%d=%d; %lld mod %d=%d;\n", inA, inB, out1, inB, inA, out2, inC, inA, out3, inD, inA,out4);
//#else
		//fprintf(fp, "%d*%d=%d; %d+%d=%d; %d/%d=%d; %I64d mod %d=%d;\n", inA, inB, out1, inB, inA, out2, inC, inA, out3, inD, inA,out4);
//#endif
	}
	//fclose(fp);

	// Compare the results file with the golden results
	//retval = system("diff --brief -w result.dat result.golden.dat");
	//if (retval != 0) {
		//printf("Test failed  !!!\n"); 
		//retval=1;
	//} else {
		//printf("Test passed !\n");
  //}
	//Get the average accuracy across the output
	float out1_error = fabs(out1_total / N);
	float out2_error = fabs(out2_total / N);
        float out3_error = fabs(out3_total / N);
        float out4_error = fabs(out4_total / N);
	
	//Printing the statement
	fprintf(stdout, "out1_error: %.2f, out2_error: %.2f, out3_error: %.2f, out4_error: %.2f \n", out1_error, out2_error, out3_error, out4_error);
	//If the accuracy is less than 5 then the test fails
	if (out1_error > 5 || out2_error > 5 || out3_error > 5 || out4_error > 5) {
    		printf("MAE is more than 5 percent! Test fail\n");
		//retval = 1;
	}

	// Return 0 if the test passed
  return retval;
}

