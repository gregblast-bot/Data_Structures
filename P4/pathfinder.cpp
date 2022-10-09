#include "lib/image.cpp"
#include <iostream>
#include <cstdlib>
#include "deque.hpp"
using namespace std;

int * initial(Image<Pixel>&);
bool goal(int *, Image<Pixel>&);
int * getCoords(int **, int);
int* breadth_first_search(Image<Pixel>&);
int ** actions(int *, Image<Pixel>&);

int main(int argc, char *argv[])
{
	Image<Pixel> im = readFromFile(argv[1]);
	
	//or (int i = 0; i < im.width(); i++)
		//or (int j = 0; j < im.height(); j++)
			//if (im(i,j) == RED) { cout << "red pixe at: " << i << ", " << j << endl; return 0;}
				
	//cout << "no   pixel" << endl;
	//exit(EXIT_FAILURE);
				
	
	Image<Pixel> imCopy = readFromFile(argv[1]);
	
	int * p = breadth_first_search(imCopy);
		
	im(p[0], p[1]) = GREEN;
	
	cout << "Solution at: " << p[0] << " " << p[1] << endl;
	writeToFile(im, "tests/my_output.png");
	
	exit(EXIT_SUCCESS);
	
	/*
	Image<Pixel> im = readFromFile("tests/maze00.png");
	
	for (unsigned int i = 0; i < im.width(); i++) {
		for (unsigned int j = 0; j < im.height(); j++) {
			if (im(i,j) == BLACK) { std::cout << "B "; }
			else if (im(i,j) == RED) { std::cout << "R "; }
			else if (im(i,j) == GREEN) { std::cout << "G "; }
			else if (im(i,j) == WHITE) { std::cout << "W "; }
			else if (im(i,j) == BLUE) { std::cout << "Bl "; }
			else { std::cout << "Huh?" << std::endl; }
		}
		std::cout << "\n" << std::endl;
	}
	*/
}


int * initial(Image<Pixel> &problem) {
	int * c = new int[2];
	for (int i = 0; i < problem.width(); i++) {
		for (int j = 0; j < problem.height(); j++) {
			if (problem(i,j) == RED) { 
				c[0] = i; c[1] = j;
				return c;
			}
		}
	}
}


int * breadth_first_search(Image<Pixel> &problem){
	int * s = initial(problem);
	
	if(goal(s, problem)) {
		return s;
	}

	Deque<int*> frontier;
	frontier.pushBack(s);
	     
	while(true){
		if(frontier.isEmpty()){
			exit(EXIT_FAILURE);
		}
	
		s = frontier.back();
		frontier.popBack();

		int ** acts = actions(s, problem);

		for(int i = 0; i < 4; i++) {
			if (acts[i][0] > -1 && acts[i][1] > -1) {
				int *c = getCoords(acts, i);
				if ( goal(c, problem) ) {
					return c;
				}
				else {
					if( c == nullptr){
						exit(EXIT_FAILURE);
					}
					frontier.pushBack( c );
				}
			}
		}
	}
}

int * getCoords(int ** array, int row) {
	int * c = new int[2];
	c[0] = array[row][0];
	c[1] = array[row][1];
	return c;
}

bool goal(int * s, Image<Pixel> &problem) {
	return ((s[0]-1 < 0 || s[0]+1 > problem.width()) || (s[1]-1 < 0 || s[1]+1 > problem.height()));
}

int ** actions(int * s, Image<Pixel> & problem) {
	int ** acts = 0;
	acts = new int*[4];
	// init as -1
	for (int j = 0; j < 4; j++) {
		acts[j] = new int[2];
		for (int k = 0; k < 2; k++) {
			acts[j][k] = -1;
		}
	}
	
	unsigned int i = 0;
	if (s[1]+1 <= problem.height() && s[1]-1 >= 0) {
		if (problem(s[0], s[1]+1) == WHITE) { 
			acts[i][0] = s[0];
			acts[i][1] = s[1]+1;
			problem(s[0], s[1]+1) = BLUE;
			i++;
		}
		if (problem(s[0], s[1]-1) == WHITE) {
			acts[i][0] = s[0];
			acts[i][1] = s[1]-1;
			problem(s[0], s[1]-1) = BLUE;
			i++;
		}
	}
	if (s[0]+1 <= problem.width() && s[0]-1 >= 0) { 
		if (problem(s[0]+1, s[1]) == WHITE) {
			acts[i][0] = s[0]+1;
			acts[i][1] = s[1];
			problem(s[0]+1, s[1]) = BLUE;
			i++;
		}	
		if (problem(s[0]-1, s[1]) == WHITE) {
			acts[i][0] = s[0]-1;
			acts[i][1] = s[1];
			problem(s[0]-1, s[1]) = BLUE;
		}
	}
	
	return acts;
}
