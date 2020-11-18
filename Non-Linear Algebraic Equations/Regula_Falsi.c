#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double f(double x){ // f 
	return cos(x) - x;
}
int main() {
	double x0=-0.75,x1=0.75,error,x; // initialize x0 x1 error x and i (num of loops)
	int i = 0;
	printf("   i	    x 	          f(x)		error \n"); // format 
	do{
		i = i + 1; //count loops
		x=x1 - ((x1 - x0)/(f(x1)-f(x0)))*f(x1); // method equation
		error = fabs(x-x1); //error calculation
		printf("\n %3d %14.10f %14.10f %14.10f",i ,x,f(x),error); // printing in specific format
		if(f(x)*f(x1) < 0 ){ //checking if for xn xn-1 everytime bolzano is true
			x0 = x1;
			x1 = x;	
		}
		else{ // if bolzano isn't true x0 isnt changing 
			x0=x0;
			x1=x;
		}
	}while(error >= 0.5*pow(10.0,-8)); //8 decimals calculation
	
	printf("\n\nThe root is : %14.8f",x);
	
	return 0;
}
