//Include bitset.hpp for member functions, member variables and library
#include "bitset.hpp"

    /*This default constructor sets the bitset size to 8 and initializes
    the bitset to zero. Sets validity equal to true.*/
	Bitset::Bitset(){
		bitsize = 8;
		bitset = new uint8_t[bitsize];
		
		for(int i = 0; i < 8; i++){
			bitset[i] = 0;
		}
		
		validity = true;
	}

	/*This copy constructor sets the bitset size to size and initializes
    the bitset to zero. Sets validity equal to true if size is greater than zero.*/
	Bitset::Bitset(intmax_t size){
		bitsize = size;
		bitset = new uint8_t[bitsize];
		
		if(bitsize <= 0){
			validity = false;
		}
		
		for(int i = 0; i < bitsize; i++){
			bitset[i] = 0;
		}
		
		validity = true;
	}
	
	/*This copy constructor sets the bitset size to the length of the string 
	value and initializes the bitset to the string vlue. If the index of the 
	bitset is not equal to zero and one it is not valid. Sets validity equal
	to true otherwise */
	Bitset::Bitset(const std::string & value){
		bitsize = value.length();
		bitset = new uint8_t[bitsize];
		
		for(int i = 0; i < bitsize; i++){
			
			if(value[i] != '0' && value[i] != '1'){
				validity = false;
			}
			
			if(value[i] == '0'){
				bitset[i] = 0;
			}
			
			else if(value[i] == '1'){
				bitset[i] = 1;
			}
			
			else{
				validity = false;
				exit(EXIT_FAILURE);
			}
			
			//Tried this but did not work for me
			//bitset[i] = value[i] - '0';
		}
	}
	
	//This destructor deallocated the bitsets memory if it has allocated memory
	Bitset::~Bitset(){
	  if(bitset != NULL){
		delete [] bitset;
	  }
	}
	
	//This member function returns the size of the bitset
	intmax_t  Bitset::size() const{
		return bitsize;
	}
	
	/*This member function checks to see if the bitset is valid or not.
	the bitset is valid if the index of the bitset is equal to zero or one
	(account for characters and integers) and if the bit set size is greater 
	than zero.*/
	bool Bitset::good() const{
			
			if(bitsize <= 0){
				return false;
			}
			
			else if(bitsize > 0){
				
				for(int i = 0; i < bitsize; i++){
					
					if((bitset[i] == 0 || bitset[i] == 1) || (bitset[i] == '0' || bitset[i] == '1')){
						return true;
					} 
					
					else{
						return false;
					}
				}
			}	
	//I don't know how to fix the warning: control reaches end of non-void function that this gives
	}
	
	/*This member function sets the chosen index of the bitset, given by the 
	argument, equal to one and the validity equal to true.*/
	void Bitset::set(intmax_t index){
		
			if(bitset[index] == 1 || bitset[index] == 0){
				bitset[index] = 1;
				validity = true;
			}
			
			else if(bitset[index] == '1' || bitset[index] == '0'){
				bitset[index] = '1';
				validity = true;
			}
			
			else{
				validity = false;
				exit(EXIT_FAILURE);
			}
	}
	
	/*This member function sets the chosen index of the bitset, given by the 
	argument, equal to zero and the validity equal to true.*/
	void Bitset::reset(intmax_t index){
		
			if(bitset[index] == 1 || bitset[index] == 0){
				bitset[index] = 0;
				validity = true;
			}
			
			else if(bitset[index] == '1' || bitset[index] == '0'){
				bitset[index] = '0';
				validity = true;
			}
			
			else{
				validity = false;
				exit(EXIT_FAILURE);
			}
	}
	
	/*This member function sets the chosen index of the bitset, given by the 
	argument, equal to one if it is zero and equal to zero if it is one. In 
	other words, it toggles. The validity equal to true if conditions are met.*/
	void Bitset::toggle(intmax_t index){
		
			if(bitset[index] == 0){
				bitset[index] = 1;
				validity = true;
			}
			
			else if(bitset[index] == 1){
				bitset[index] = 0;
				validity = true;
			}
			
			else if(bitset[index] == '0'){
				bitset[index] = '1';
				validity = true;
			}
			
			else if(bitset[index] == '1'){
				bitset[index] = '0';
				validity = true;
			}
			
			else{
				validity = false;
				exit(EXIT_FAILURE);
			}
	}
	
	/*This member function tests to see if the index inputted by the user
	is set (equal to one), if so return true. Else, return false.*/
	bool Bitset::test(intmax_t index){
		
			if(bitset[index] == 0){
				return false;
			}

			else if(bitset[index] == 1){
				return true;
			}
			
			else if(bitset[index] == '0'){
				return false;
			}

			else if(bitset[index] == '1'){
				return true;
			}
			
			else{
				return false;
				exit(EXIT_FAILURE);
			}
	}
	
	//This member function represents the bitset as a string
	std::string Bitset::asString() const{
		std::string bitstring = "";
		
		for(int i = 0; i < bitsize; i++){
				bitstring += std::to_string(bitset[i]);
				std::cout << bitset[i] << std::endl;
		}
		
			return bitstring;
	}
