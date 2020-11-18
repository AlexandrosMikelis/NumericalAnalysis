#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//###############################################################################################
//# Problem Analysis :                                                                          #
//#        With General Successive Approximation Solve:						#
//#                 -1 Xn+1 = Xn^3 - Xn^2 + Xn + 1                                              #
//#                 -2 Xn+1 = Xn - (Xn^3 - Xn^2 + 1) / Xn^2 + 4                                 #
//#                                                                                             #
//#                                                                                             #
//#                                                                                             #
//###############################################################################################
int main() {
	double x0=0.5,x,error; 							// initial x0 x and error
	int i=0; 								// initial i for looping counting
	printf("   i	    x_old	   x_new	  error\n");		//format
	do{
		i = i + 1;
		x=pow(x0,3)-pow(x0,2) + x0 + 1;					// first case
		error = fabs(x-x0);
		printf("\n %3d  %14.10f  %14.10f  %14.10f",i ,x0 ,x,error); 	//print info with format : <number of loop> <current  approach of root> <error>
		x0 = x;
		if(error > 10000.0){ 						// if error gets bigger stop the method and inform the user that dosen't converge
			printf("\n\nThe method did not converge\n\n");
			break; 							//break if method dosent converge
		}
	}while(error >= 0.5*pow(10.0,-5)); 					// condition so our loop will stop when we have at least 6 decimals of the root
	
	i=0; 									// initial i again for the the second case
	x0=0.5; 								// initial x0 for the second case
	printf("   i	    x_old	   x_new	  error\n");		//format
	do{
		i = i + 1;
		x=x0 - (pow(x0,3)-pow(x0,2) + 1)/(pow(x0,2) + 4); 		// second case
		error = fabs(x-x0);
		printf("\n %3d %14.10f  %14.10f  %14.10f",i ,x0,x,error); 	//print info with format : <number of loop> <current  approach of root> <error>
		x0 = x;
		if(error > 10000.0){ 						// if error gets bigger stop the method and inform the user that dosen't converge
			printf("\n\nThe method did not converge\n\n");
			break; 							//break if method dosent converge
		}
	}while(error >= 0.5*pow(10.0,-5)); 					// condition so our loop will stop when we have at least 6 decimals of the root
	printf("\n\n\n The root is : %14.5f",x); 				//print the root
	return 0;
}
