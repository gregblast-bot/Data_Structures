#ifndef FANCYPOWER_HPP
#define FANCYPOWER_HPP

/*This program was created to show a recursive algorithm for an ancient
 *method of multiplication.
 * @author Gregory Wagonblast
 * @version 1.0
 * @since 25May2020
 */ 

//Include all necessary preprocessor drives
#include <cstdlib>
#include <iostream>

int fancyPower(int x, int n)
{
	// your code should go here.
/*Input variable x and power n
 * @pre Take in the base and power from programmer for desired numbers.
 * @post Output the desired result taking advantage of this beautiful recursive function.
 * @param int x is the base of the power
 * @param int n is the exponent of the base
 * @return return the power based off the recursive function
 */
	int pow;
	
	if(n == 0){
		pow = 1;
	}
	
	else if(n == 1){
		pow = x;
	}
	
	else if(n % 2 == 0){
		pow = fancyPower(x*x,n/2);
	}
	
	else{
		pow = x*fancyPower(x*x,(n-1)/2);
	}
	return pow;
	
	return 0;
}

#endif
