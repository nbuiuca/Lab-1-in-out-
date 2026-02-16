// Nhan Bui	
// Lab 1 In
// Draw a PolyLine

#include <iostream>
#include "graph1.h"

using namespace std;

//Add Function Prototypes Here
int getNoPoints();
void getPoints(int x[], int y[], int no_points);
void drawPolyLine(int x[], int y[], int no_points);

int main()
{
	//Variable Declaration/Initialization
	int no_points = 0;
	const int MAX_POINTS = 10;
	int x[MAX_POINTS];
	int y[MAX_POINTS];

	//Display Graphics Window
	displayGraphics();

	//Prompt for the number of points
	no_points = getNoPoints();

	//Prompt for the data for the points
	getPoints(x, y, no_points);

	//Draw the polyline

	drawPolyLine(x, y, no_points);
	
	return 0;
}

//Function Stubs Follows
int getNoPoints()
{
	//Declare local variables
	int no_points = 0;
	//Prompt for the number of points
	cout << "Enter # of Points: ";
	cin >> no_points;

	//Return the number of points
	return no_points;
}


void getPoints(int x[], int y[], int no_points)
{
	//Declare local variables
	int i = 0;
	//Using a for-loop, prompt for the coordinates of each point and store in arrays x and y
	for (i = 0; i < no_points; i++) {

		cout << "Enter x/y coordinates for Point" << i + 1 << ": ";
		cin >> x[i] >> y[i];
	}
}

void drawPolyLine(int x[], int y[], int no_points)
{
	//Declare local variables
	int j = 0;
	int circle = 0; // store object number for circle object
	int line = 0; // store object number for line object
	//Use 1 for-loop for drawing the red circle on each point
	for (j = 0; j < no_points; j++) {
		circle = drawCircle(5, x[j], y[j]);
		setColor(circle, 255, 0, 0);
	}
	//Use a second for-loop for drawing the lines - remember there is always one less line than there are points!
	for (j = 0; j < no_points - 1; j++) {
		line = drawLine( x[j], y[j], x[j+1], y[j+1], 2);
		setColor(line, 255, 255, 0);
	}

}
