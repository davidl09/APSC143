#include <stdio.h>
#include <math.h>

double getTRSum(double a, double b, int n);
double getRSum(double a, double b, int n);
double getUserInputDouble();
double getTaylor(double value, int terms);
int getUserInputInt();
int factorial(int anInt);

int main() {
    printf("Enter the bounds to compute the Riemann Sum: \n");
    double lowerBound = getUserInputDouble();
    double upperBound = getUserInputDouble();
    printf("Riemann Sum with 5 intervals: %.2lf\n", getRSum(lowerBound, upperBound, 5));
    printf("Riemann Sum with 25 intervals: %.2lf\n", getRSum(lowerBound, upperBound, 25));
    printf("Riemann Sum with 100 intervals: %.2lf\n", getRSum(lowerBound, upperBound, 100));
    printf("--------------------------------------------------------\n");
    printf("Taylor Series Approximation at x = %f with 3 terms: %.2lf\n", lowerBound, getTaylor(lowerBound, 3));
    printf("Taylor Series Approximation at x = %f with 5 terms: %.2lf\n", lowerBound, getTaylor(lowerBound, 5));
    printf("Taylor Series Approximation at x = %f with 10 terms: %.2lf\n", lowerBound, getTaylor(lowerBound, 10));
    printf("--------------------------------------------------------\n");
    printf("Taylor Series Riemann Sum with 5 intervals: %.2lf\n", getTRSum(lowerBound, upperBound, 5));
    printf("Taylor Series Riemann Sum with 25 intervals: %.2lf\n", getTRSum(lowerBound, upperBound, 25));
    printf("Taylor Series Riemann Sum with 100 intervals: %.2lf\n", getTRSum(lowerBound, upperBound, 100));
    printf("--------------------------------------------------------\n");


}

double getUserInputDouble(){
    double userInputD;
    scanf("%lf", &userInputD);
    return userInputD;
}

int getUserInputInt(){
    int userInputI;
    scanf("%d", &userInputI);
    return userInputI;
}

double getTaylor(double value, int terms){
    double taylorApprox = 1;
    for(int i = 1; i < terms; i++){
        taylorApprox = taylorApprox + (pow((pow(value, 2)), i))/factorial(i); //taylor series: inf sum of ((x^2)^n)/n! starting at n=0.
    }
    return taylorApprox;
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

double getTRSum(double a, double b, int n){
    double recArray[n];
    double dx = 0;
    double sum = 0;
    double xi = 0;
    dx = (b-a)/n;
    for(int i = 0; i<n; i++){
        xi = a + i * dx;
        recArray[i] = dx* getTaylor(xi, 10);
    }
    for(int i = 0; i<n; i++){
        sum += recArray[i];
    }
    return sum;
}

int factorial(int anInt){
    int factorialOfAnInt = anInt;
    if(anInt==0)
        factorialOfAnInt = 1;
    else{for(int i = anInt-1; i>0; i--){
            factorialOfAnInt = factorialOfAnInt*i;
        }
    }
    return factorialOfAnInt;
}