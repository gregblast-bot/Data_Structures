/*This program was created as a clearing class for a Pokemon Go game.
 * The clearing classes main functionality is to make clearings when a
 * pokemon is found and when two pathways intersect. The would be pathway
 * class member functions are implemented in the Clearing class.
 * @author Gregory Wagonblast
 * @version 1.0
 * @since 25May2020
 */

//Include the c standard library, iostream, vector and random
#include <cstdlib>
#include <iostream>
#include <vector>
#include <random>

//Create a class header file for Clearing
class Clearing{
	
	//Private member variables declared here
	private:
	
	//x and y variables holds the x and y coordinates
	double x = 0, y = 0, x1, y1;
	//Vector c holds the coordinates in a 2D vector
	vector<coordinate> c;
	//Pathway is a pointer to some "path"
	double *pathway;
	//Count keeps track of the number of pathways and weight for how 
	//many times a pokeman was found at a spot
	int count, weight;
	
		
	//Public member variables declared here	
	public:
	
	//Some of these would normally belong to a path class
	Clearing();
	~Clearing();
	void coordinate();
	double distance(const coordinate & c1, const coordinate & c2);
	void deletePath();
	void characterFound();
	void setx(a);
	void sety(b);
	double setPath(x2,y2);
	double setClearing();
	double setWeight(w);
	double getx() const;
	double gety() const;
	double* getPath() const;
	bool getClearing() const;
	int getWeight() const;
	bool hasPath() const;
	bool connectPath() const;
	bool addPath() const;
};
