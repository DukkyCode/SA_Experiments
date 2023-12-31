// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
/*******************************************************************************
Vendor: Xilinx 
Associated Filename: types_global_test.c
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
#include "types_global.h"
 
int main () {
	din1_t idx;
	int i, retval=0;
	FILE        *fp;
	char buffer[100];
	int out_t[N/2];

	// Create Input Data
	for(i=0; i<N;++i) {
		Ain[i] = i;
	}

	// Save the results to a file
	fp=fopen("result.golden.dat","r");

	// Call the function
	idx=45;
	types_global(idx);
	
	i = 0;
	//Store the data in result.golden.dat in an array
	while(fgets(buffer, sizeof(buffer), fp) != NULL &&  i < (N/2)){
		out_t[i] = atoi(buffer);
		//fprintf(stdout, "%d \n", out_t[i]);
		i++;
	}
	fclose(fp);
	
	dout_t total = 0;
	//Get the MAE test
	for(i=0; i<(N/2); ++i){
		//fprintf(stdout, "Aout = %.2f, out_t = %d \n", Aout[i], out_t[i]);
		dout_t temp = fabs((float) out_t[i] - Aout[i]);
		//fprintf(stdout, "temp = %.2f \n", temp);
	        total = total + temp;
		//fprintf(stdout, "total = %.2f \n", total);	
	}

	dout_t mae = total / ((float) (N/2));
	
	fprintf(stdout, "mae = %.2f \n",mae);

	if(mae < 1){
		printf("Test passed \n");
	}
	else{
		retval = 1;
		printf("Test failed \n");
	}

	//fclose(fp);

	//for(i=0; i<(N/2);++i) {
		//fprintf(fp, "%d \n", Aout[i]);
	//}
	//fclose(fp);

	// Compare the results file with the golden results
	//retval = system("diff --brief -w result.dat result.golden.dat");
	//if (retval != 0) {
		//printf("Test failed  !!!\n"); 
		//retval=1;
	//} else {
		//printf("Test passed !\n");
  //}

	// Return 0 if the test passed
  return retval;
}

