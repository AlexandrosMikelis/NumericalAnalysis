#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double f(double x){
	return pow(x,4) + 2*pow(x,3) + pow(x,2) + 12*x + 20; 			//F
}
double df(double x){
	return 4*pow(x,3) + 6*pow(x,2) + 2*x + 12; 				// first derivative of F
}
double ddf(double x){
	return 12*pow(x,2) + 12*pow(x,1) + 2 ; 					// second derivative of F
}
double g(double x){ 								// G
	return f(x)/df(x);
}
double dg(double x){ 								// first derivative of F
	return (df(x)*df(x) - f(x)*ddf(x))/pow(df(x),2);
}

int main() {
	double x,error; 							// Initialize xn xn+1 error and number of loops
	double x0=1;
	int i=0;
	printf("  i    	     x     	  f(x)    	  error\n");
	do{
		i = i + 1;
		x=x0 - f(x0)/df(x0); 						// Newton Ramson Method 
		error = fabs(x-x0); 						// Error calculation 
		printf("\n %3d %14.10f %14.10f %14.10f",i ,x,f(x),error); 	// printing in specific format <Num loops > <xn> <f(x)> <error>
		x0 = x; 
	}while(error >= 0.5*pow(10.0,-8) && fabs(f(x))> 0.5*pow(10.0,-8)); 	// 8 decimals calculation for x and f(x)
	
	printf("\n\n root = %14.10f \n\n",x); // printing the result 
	
	x0=1; 									//initial for the second case
	i=0; //----------------------------------Equal WorK---------------------------------------------------------
	printf("  i    	     x     	  g(x)    	  error\n");
	do{
		i = i + 1;
		x=x0 - g(x0)/dg(x0);
		error = fabs(x-x0);
		printf("\n %3d %14.10f %14.10f %14.10f",i ,x,g(x),error);
		x0 = x;
	}while(error >= 0.5*pow(10.0,-8) && fabs(g(x))> 0.5*pow(10.0,-8));
	
	printf("\n\n root = %14.10f \n\n",x);
	return 0;
}
