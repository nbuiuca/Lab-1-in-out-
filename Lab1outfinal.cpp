//Nhan Bui
//Lab 1 out

#include <iostream>
#include"graph1.h"

using namespace std;
void getData(int no_months, int sales[]);
int getNoMonths();
int getHeight(int sales, int max);
void displayBarchart(int xasis, int yasis, int width, int height, string label);
int getHeight(int sales, int max);
int getMax(int sales[], int no_months);
int getMin(int sales[], int no_months);
double getAverage(int sales[], int no_months);
int main() {
	int obj_no = 0;
	int sales[6];
	int max;
	int min;
	int average ;
	string monthLabels[6] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun" };
	displayGraphics();
	drawPoint(200, 280);
	drawLine(200, 280, 200, 150, 1);
	drawLine(200, 280, 700, 280, 1);
	drawLine(200, 345, 500, 345, 1);
	drawLine(200, 345, 200, 500, 1);
	drawLine(200, 500, 500, 500, 1);
	drawLine(500, 500, 500, 345, 1);
	displayBMP("sales1.bmp", 250, 25);
	gout << setPos(80, 250) << setColor(0, 255, 0) << "Monthly sales " << endg;
	gout << setPos(380, 300) << setColor(0, 255, 0) << "Month " << endg;
	
	gout << setPos(205, 340) << setColor(0, 255, 0) << "Sales Statistics " << endg;

	int no_months = getNoMonths();
	gout << setPos(375, 65) << setColor(0, 255, 0) << "Sales for " << no_months << " months" << endg;
	getData(no_months, sales);
	max = getMax(sales, no_months);
	gout << setPos(205, 380) << setColor(0, 255, 0) << "Max Sales: $ " <<max << endg;
	min = getMin(sales, no_months);
	gout << setPos(205, 400) << setColor(0, 255, 0) << "Min Sales: $ " <<min<< endg;
	int height[6];
	average = getAverage(sales, no_months);
	gout << setPos(205, 420) << setColor(0, 255, 0) << "Avg Sales: $ " << average << endg;
	int xasis = 200;
	int j = 0;
	int line = 0;
	for (j = 0; j < no_months; j++) {


		height[j] = getHeight(sales[j], max);
		
		int yasis = 280;
	
			displayBarchart(xasis, yasis - height[j], 45, height[j],monthLabels[j]);
		
			xasis += 75;
			
	}
	return 0;
}
int getNoMonths() {
	int no_Months = 0;

	cout << "Enter # of months to process: <betwwen 3 and 6 inclusive>: ";
	cin >> no_Months;

	return no_Months;

}
void getData(int no_months, int sales[]) {

	int i = 0;
	for (i = 0; i < no_months; i++) {
		cout << "Enter sales for month # " << i + 1 << ":";
		cin >> sales[i];

	}

}
int getHeight(int sales, int max) {
	int height;



	height = ((double)sales / max) * 100.0;

	if (height < 1) {
		height = 1;
	}


	return height;
}
int getMax(int sales[], int no_months)
{
	int max = 0; int i; sales[0]; for (i = 0; i < no_months; i++) {
		if (sales[i] > max) max = sales[i];
	} return max;
}
int getMin(int sales[], int no_months) {
	int min; int i; min = sales[0]; for (i = 0; i < no_months; i++) {
		if (sales[i] < min) min = sales[i];
	}return min;
}
double getAverage(int sales[], int no_months) {
	int total = 0;
	int average = 0;
	int i; for (i = 0; i < no_months; i++) {
		 total += sales[i];

		 average = total / no_months;
	}
	return average;
}
void displayBarchart(int xasis, int yasis, int width, int height, string label) {
	int RectCOLOR = 0;
	RectCOLOR =drawRect(xasis, yasis, width, height);
	gout << setPos(xasis + 2, yasis - 12) << label << endg;
	if (xasis == 200) {
		setColor(RectCOLOR, 255, 0, 0);
	}
	else if (xasis == 275) {
		setColor(RectCOLOR, 0, 255, 0);
	}
	else if (xasis == 350) {
		setColor(RectCOLOR, 0, 0, 255);
	}
	else if (xasis == 425) {
		setColor(RectCOLOR, 255, 255, 0);
	}
	else if (xasis == 500) {
		setColor(RectCOLOR, 255, 0, 255);
	}
	else if (xasis == 575) {
		setColor(RectCOLOR, 0, 255, 255);
	}

}
