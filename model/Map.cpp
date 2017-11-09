//
// Created by whyar on 11/6/2017.
//

#include <iostream>
#include <vector>
#include "Map.h"
#include <string>

using namespace std;

/**
* Class representing a Map.
*/

	//basic constructor for making a map of any size
	Map::Map(int width, int height) {
		
		//NOTE---- Unsure how we want to initialize a map, so I am going to leave this blank for now. 

		for (int i = 0; i < width; i++) {

		}

		for (int j = 0; j < height; j++) {

		}
	}

	// some function that controls how this cell is displayed, will be based on whether or not this Cell is "inhabited"
	void draw() {
		//holds the body of the function where SDL will display the graphical representation of the map
	}


