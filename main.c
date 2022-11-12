#include <stdio.h>
#include <math.h>

double getUserInputDouble();
double getTaylor(double value, int terms);
double getRealValue(double pow_e);
int getUserInputInt();
int factorial(int anInt);

int main() {
    while(1){
        printf("Enter the number of terms of the Taylor approximation\n");
        int numOfTerms = getUserInputInt();
        printf("Enter the value to be computed using the taylor approximation\n");
        double x = getUserInputDouble();
        double taylorApproximation = getTaylor(x, numOfTerms);
        double realValue = getRealValue(x);
        printf("The value of e^x^2 at %.2lf is approximately %.10lf after adding %d terms. \nThe actual value of the function is %.10lf.\n\n",
               x, taylorApproximation, numOfTerms, realValue);
    }
}

double getRealValue(double pow_e){
    double realVal = exp((pow_e*pow_e));
    return realVal;
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
