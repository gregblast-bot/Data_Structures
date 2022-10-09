/*This program was created to show a recursive algorithm for an ancient
 *method of multiplication.
 * @author Gregory Wagonblast
 * @version 1.0
 * @since 25May2020
 */ 

//Include all necessary preprocessor drives
#include <cstdlib>
#include <iostream>

//Function prototype, two integers
int EgyptianPowers(int, int);

//The main function is a simple example of the code in action
int main(){
	//Declare integer variable to hold the result of the Egyptian Powers function
	int result;
	
	//Set result equal to the Egyptian Powers function
	result = EgyptianPowers(2,0);
	
	//Print to user
	std::cout << "Egyptian Powers: " << result << std::endl;
	
	//Let's do another, awesome
	//Set result equal to the Egyptian Powers function
	result = EgyptianPowers(2,1);
	
	//Print to user
	std::cout << "Egyptian Powers: " << result << std::endl;
	
	//Let's do another, very awesome
	//Set result equal to the Egyptian Powers function
	result = EgyptianPowers(2,2);
	
	//Print to user
	std::cout << "Egyptian Powers: " << result << std::endl;
	
	//Let's do another, very very awesome
	//Set result equal to the Egyptian Powers function
	result = EgyptianPowers(2,3);
	
	//Print to user
	std::cout << "Egyptian Powers: " << result << std::endl;
	
	//Let's do another, awesomer
	//Set result equal to the Egyptian Powers function
	result = EgyptianPowers(2,4);
	
	//Print to user
	std::cout << "Egyptian Powers: " << result << std::endl;
	
	//Let's do another, much more awesome
	//Set result equal to the Egyptian Powers function
	result = EgyptianPowers(2,5);
	
	//Print to user
	std::cout << "Egyptian Powers: " << result << std::endl;
	
	//Let's do another, holy awesomeness
	//Set result equal to the Egyptian Powers function
	result = EgyptianPowers(2,6);
	
	//Print to user
	std::cout << "Egyptian Powers: " << result << std::endl;
	
	//Let's do another, omg awesome
	//Set result equal to the Egyptian Powers function
	result = EgyptianPowers(2,7);
	
	//Print to user
	std::cout << "Egyptian Powers: " << result << std::endl;
	
	//Let's do another, awesomest
	//Set result equal to the Egyptian Powers function
	result = EgyptianPowers(2,8);
	
	//Print to user
	std::cout << "Egyptian Powers: " << result << std::endl;
}

/*Input variable x and power n
 * @pre Take in the base and power from programmer for desired numbers.
 * @post Output the desired result taking advantage of this beautiful recursive function.
 * @param int x is the base of the power
 * @param int n is the exponent of the base
 * @return return the power based off the recursive function
 */
int EgyptianPowers(int x,int n){
	int pow;
	
	if(n == 0){
		pow = 1;
	}
	
	else if(n == 1){
		pow = x;
	}
	
	else if(n % 2 == 0){
		pow = EgyptianPowers(x*x,n/2);
	}
	
	else{
		pow = x*EgyptianPowers(x*x,(n-1)/2);
	}
	return pow;
}
