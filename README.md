# c_battleship

A program that follows the principles of the strategy game Battleship with planes, but with different tasks to solve matrix problems.

## Getting Started

The information about planes is stored in a generic array *void* **info*, in order, plane after plane.


* At first, you have to dereference the pointers to the data you need for further tasks. In order to do this, you should cast the void pointer to the right type.

* For drawing the planes in a matrix of NxN dimension, representing your map, filled with **' . '** you have to traverse the matrix and assign **' * '** to the right positions, following the given two plane images.

* The **qsort** function is used for sorting the planes by type, direction and velocity.

* The obstacles are added to the matrix following the same principle above mentioned.

* The final task is to determine if your planes will collide with obstacles and how many will get to finish their way to the end of the map.


## Tools

In ***planes.c*** are stored the implemented functions for drawing each type of planes by their size and direction, also the functions to detect the obstacles.

## Build

You can run this program on your machine using make build command. 

You can find some input samples in utils/.
