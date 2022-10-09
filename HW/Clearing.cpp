//Make include guard and define CLEARING_HPP
#ifdef CLEARING_HPP
#DEFINE CLEARING_HPP

/*This program was created as a clearing class for a Pokemon Go game.
 * The clearing classes main functionality is to make clearings when a
 * pokemon is found and when two pathways intersect. The would be pathway
 * class member functions are implemented in the Clearing class.
 * @author Gregory Wagonblast
 * @version 1.0
 * @since 25May2020
 */ 
 
//Include all preprocessor drives
#include <cstdlib>
#include <iostream>
#include <vector>
#include <random>

//Create a class header file for Clearing
class Clearing{
	
	//Private member variables declared here
	private:
	
	//x and y variables holds the x and y coordinates
	double x = 0, y = 0;
	//Vector c holds the coordinates in a 2D vector
	vector<coordinate> co1,co2;
	//Pathway is a pointer to some "path"
	double *pathway;
	//Count keeps track of the number of pathways and weight for how 
	//many times a pokeman was found at a spot
	int count, weight;
	
		
	//Public member variables declared here	
	public:
	
	//Here are my empty Clearing default constructor and destructor
	Clearing();
	
	~Clearing();
	
	//Coordinate gets x and y, these have to be set unless they will stay
	//initialized to zero
	void coordinate(){
		x1 = getx():
		y1 = gety():
	}
	
	/*Distance calculates the distances between coordinates c1 and c2
	 *@param c1 is a coordinate passed by reference
	 *@param c1 is a coordinate passed by reference
	 *@return This function returns the distance between two points as a double  
	 */
	double distance(const coordinate & c1, const coordinate & c2){
		return  sqrt((c1.x1 * c2.x1) + (c1.y1 * c2.y1));
	}
	
	//This member function deletes a pathway, this is useful because only two pathways can intersect
	void deletePath(){
		delete [] pathway;
	}
	
	//This member function adds a pathway
	void addPath(){
		pathway++;
	}
	
	//This member function utilizes a pseudorandom algorithm to determine where a character will be found
	void characterFound(){
		// Fixed seed of 0 for pseudorandom engine that utilizes the Mersenne Twister Algorithm
		std::mt19937 engine(0); 
		
		//Do some distribution thing
		std::uniform_real_distribution<> dist;
		
		//Create a nested loop to get pseudorandom coordinates for x and y
		for (int i = 0; i < 100; i++) {
			std::cout << dist(engine) << std::endl;
			x1 = dist(engine);
			for (int j = 0; j < 100; j++) {
				std::cout << dist(engine) << std::endl;
				y1 = dist(engine);
		}
		
		//If there are not two pathways intersecting at a point make a 
		//clearing where a pokemon is found
		if(count % 2 == 1){
			clearing = true;
		}
	}
	
	//Setter for x coordinate
	//@param a sets x
	void setx(a){
		x = a;
	}
	
	//Setter for y coordinate
	//@param b sets y
	void sety(b){
		y = b;
	}
	
	/*This member function sets the coordinates for a path
	 *@param x2 takes an x coordinate as one parameter
	 *@param y2 takes a y coordinate as another parameter
	 */
	double setPath(x2,y2){
		x1 = x2;
		y1 = y2;
		double pathway = new double[x1,y1];
		//If this member function is called add to the count of paths
		count++;
		
		//If there are two paths intersecting, set a clearing
		if(count % 2 == 0 ){
			setClearing();
		}
		
		else{
			//Else don't set a clearing
			clearing = false;
		}
	}
	
	//This member function sets a clearing
	double setClearing(){
		clearing = true;
	}
	
	//This member function sets the weight of how many times a pokeman has been found there
	//@param w sets the weight
	double setWeight(w){
		weight = w;
	}
	
	//Getter for x coordinate
	//@return x
	double getx() const{
		return x;
	}
	
	//Getter for y coordinate
	//@return y
	double gety() const{
		return y;
	}
	
	//Getter for pathway
	//@return pathway
	double* getPath() const{
		return pathway;
	}
	
	//Getter for clearing
	//@return clearing
	bool getClearing() const{
		return clearing;
	}
	
	//Getter for weight
	//@return weight
	int getWeight() const{
		return weight;
	}
	
	//Member function to check if a path exists
	//@return true if path exists
	bool hasPath(){
		if(getPath() != NULL){
			return true;
		}
	}

	//This member function will connect paths based on whether the x or y
	//coordinates of two paths have less distance between each other
	//@return boolean values to test functionality
	bool connectPath(){
		if(distance(x1,x2) < distance(y1,y2)){
			co1<x,y1> = co2<x,y2>
			return true;
		}
		else if(distance(x1,x2) > distance(y1,y2)){
			co1<x1,y> = co2<x2,y>
			return true;
		}
		else{
			std::cout << "These are the same paths!" << std::endl;
			return false;
		}
}

#endif
