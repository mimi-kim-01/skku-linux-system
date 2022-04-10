#include <stdio.h>
#include <stdbool.h>

//given functions
int Plusone(int a);
bool Equal(int a, int b);

//additional functions
bool Greater(int a, int b); //고민 중인데 걍 int로 바꿔서 큰 수 return 할까?
bool Lesser(int a, int b); 
bool Sign(int a); //get the sign (1: positive or zero, 0: negative)
int Absolute(int a); //get absolute value
int Add(int a, int b); //addition
int Subtract(int a, int b); //subtraction
int Multiply(int a, int b); //multiplication
void Divide(int a, int b); //division

//main
int main(){
    //메뉴판에 basic operations랑 추가 기능도 만들기! (제곱이나 절댓값 출력이나 등등)

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

bool Sign(int a){//get the sign (1: positive or zero, 0: negative)
    if (Equal(a, Absolute(a))) return 1; //positive or zero
    else return 0; //negative
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


int Add(int a, int b){
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
    else if (Equal(Sign(b), 1)) {
        //not yet
    }
    else {
        //not yet
    }
    }
    return result;
}

int Subtract(int a, int b); //둘 중 작은 값부터 큰값 될 때까지 더하면 되나? 웅 그러면 될듯

int Multiply(int a, int b){
    int result = 0;
    if (Equal(Sign(a), 1)){
        if (Equal(Sign(b), 1)){    
            for (int i = 0; Equal(Equal(i, a), 0); i = Plusone(i)){
                for (int j = 0; Equal(Equal(j, b), 0); j = Plusone(j)){
                    result = Plusone(result);
                }
            }
        }
        else {
            printf("not yet not yet");
        }
    }
    return result;
}

void i(int a, int b);