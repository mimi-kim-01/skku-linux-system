#include <stdio.h>
#include <stdbool.h>

//given functions
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

//given functions specific
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
bool Sign(int a){
    if (Equal(a, 0)) return 1;
    for (int i = 0;;i = Plusone(i)){
        if (Equal(i, a)) return 1;
    }
    return 0;
    
}

int Plus(int a, int b){
    int result = 0;
    if (Equal(Sign(a), 1)){
        if (Equal(Sign(b), 1)){    
            for (int i = 0; Equal(Equal(i, a), 0); i = Plusone(i)){
                result = Plusone(result);
            }
            for (int j = 0; Equal(Equal(j, b), 0); j = Plusone(j)){
                result = Plusone(result);
            }
        }
        else {
            printf("not yet not yet");
        }
    }
    return result;
}

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