#include <stdio.h>
#include <math.h>

double getRSum(double a, double b, int n);
double getUserInput();

int main() {
printf("Enter your values for lower and upper bounds of integration as well as number of rectangles.\nLower bound:\n");
double lowerBound = getUserInput();
printf("Upper bound:\n");
double upperBound = getUserInput();
printf("Number of rectangles:\n");
int numOfRectangles = getUserInput();
double Area = getRSum(lowerBound, upperBound, numOfRectangles);
printf("The area under the curve e^(x^2) from %lf to %lf is approximately %lf for %d rectangles\n", lowerBound, upperBound, Area, numOfRectangles);
}

double getRSum(double a, double b, int n){
    double recArray[n];
    double dx = 0;
    double sum = 0;
    double xi = 0;
    dx = (b-a)/n;
    for(int i = 0; i<n; i++){
        xi = a + i * dx;
        recArray[i] = dx*(exp((xi*xi)));
    }
    for(int i = 0; i<n; i++){
        sum += recArray[i];
    }
    return sum;
}

double getUserInput(){
    double aNum;
    scanf("%lf", &aNum);
    return aNum;
}