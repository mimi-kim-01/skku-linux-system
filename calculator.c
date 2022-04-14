#include <stdio.h>
#include <stdbool.h>

//given functions
int Plusone(int a);
bool Equal(int a, int b);

//additional functions
bool Sign(int a); //get the sign (1: positive or zero, 0: negative)
int Greater(int a, int b);//get greater value
int Lesser(int a, int b);//get lesser value
int Absolute(int a); //get absolute value
void Add(int a, int b); //addition
void Subtract(int a, int b); //subtraction
void Multiply(int a, int b); //multiplication
void Divide(int a, int b); //division
void Menu();

//main
int main(){
    char oper; //변수설정 주석달기
    int a, b;
    Menu();
    scanf("%d %d", &a, &b);
    Add(a, b);
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
bool Sign(int a){//get the sign (1: positive or zero, 0: negative)
    if (Equal(a, Absolute(a))) return 1; //positive or zero
    else return 0; //negative
}

int Greater(int a, int b){//get greater value
    for (int i = 0; Equal(Equal(i, a), 0); i = Plusone(i)){
        if (Equal(i, b)) return a;
    }
    return b;
}

int Lesser(int a, int b){//get lesser value
    for (int i = 0; Equal(Equal(i, a), 0); i = Plusone(i)){
        if (Equal(i, b)) return b;
    }
    return a;
}

int Absolute(int a){//get absolute value
    int count = 0;
    int original = a;
    for (count; Equal(Equal(a, 0), 0); count = Plusone(count)){
        a = Plusone(a);
        if (Equal(count, a)) return original; //return original if positive
    } //becomes zero
    for (int i = 0; Equal(Equal(i, count), 0); i = Plusone(i)){
        a = Plusone(a);
    } //get absolute value
    return a;
}


void Add(int a, int b){//addition 
    int result = 0, minus;
    if (Equal(Sign(a), Sign(b))){//if two numbers have the same sign
        if (Sign(a)) minus = 0; //if positive 'minus' becomes 0
        else minus = 1; //if negative 'minus' becomes 1
        a = Absolute(a), b = Absolute(b);
        for (int i = 0; Equal(Equal(i, a), 0); i = Plusone(i)){
            result = Plusone(result); 
        }
        for (int j = 0; Equal(Equal(j, b), 0); j = Plusone(j)){
            result = Plusone(result);
        }
    }
    else {//if two numbers have different signs
        if (Equal(Sign(a), Equal(Absolute(a), Greater(Absolute(a), Absolute(b))))) minus = 0; 
        else minus = 1;
        a = Absolute(a), b = Absolute(b);
        for (int i = Lesser(a, b); Equal(Equal(i, Greater(a, b)), 0); i = Plusone(i)){
            result = Plusone(result);
        }
    }
    if (minus) printf("-%d", result);
    else printf("%d", result);
}

void Subtract(int a, int b){//subtraction
    int result = 0;
    if (Equal(Sign(a), Sign(b))){//if two numbers have the same sign
        a = Absolute(a), b = Absolute(b);
        for (int i = Lesser(a, b); Equal(Equal(i, Greater(a, b)), 0); i = Plusone(i)){
            result = Plusone(result);
        }
    }
    else {//if two numbers have different signs
        a = Absolute(a), b = Absolute(b);
        for (int i = 0; Equal(Equal(i, a), 0); i = Plusone(i)){
            result = Plusone(result); 
        }
        for (int j = 0; Equal(Equal(j, b), 0); j = Plusone(j)){
            result = Plusone(result);
        }
    }
}

void Multiply(int a, int b){//multiplication
    int result = 0;
    a = Absolute(a), b = Absolute(b);
    for (int i = 0; Equal(Equal(i, a), 0); i = Plusone(i)){
        for (int j = 0; Equal(Equal(j, b), 0); j = Plusone(j)){
            result = Plusone(result);
        }
    }       
}

void Divide(int a, int b){//division
    int result = 0;
    
}

void Menu(){
    printf("=================CALCULATOR=================\n");
    printf("");

}