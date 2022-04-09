#include <stdio.h>
#include <stdbool.h>

//basic functions
int Plusone(int a);
bool Equal(int a, int b);

//additional functions
bool Greater(int a, int b);
bool Lesser(int a, int b);
bool Not(int a, int b);
bool Sign(int a);
int Plus(int a, int b);
int Minus(int a, int b);
int Multiply(int a, int b);
void Devide(int a, int b);

//main
int main(){

    return 0;
}

//basic functions specific
int Plusone(int a){
    return ++a;
}

bool Equal(int a, int b){
    if (a == b) return true;
    else return false;
}

//additional functions specific
bool Greater(int a, int b);
bool Lesser(int a, int b);
bool Not(int a, int b);
bool Sign(int a);
int Plus(int a, int b);
int Minus(int a, int b);

int Multiply(int a, int b){
    int result = 0;
    for (int i = 0; Equal(Equal(i, a), 0); i = Plusone(i)){
        for (int j = 0; Equal(Equal(j, b), 0); j = Plusone(j)){
            result = Plusone(result);
        }
    }
    return result;
}

void Devide(int a, int b);