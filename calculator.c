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
int Add(int a, int b); //addition
int Subtract(int a, int b); //subtraction
int Multiply(int a, int b); //multiplication
void Divide(int a, int b); //division

//main
int main(){
    //메뉴판에 basic operations랑 추가 기능도 만들기! (제곱이나 절댓값 출력이나 등등)
    //여기에 그 sign변수 하나 만들어서 중간중간 넣어두다가 나중에 이게 1이면 -표시 다는 걸로 ㄱㄱ

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


int Add(int a, int b){//addition
    int result = 0;
    if (Equal(Sign(a), Sign(b))){//if two numbers have the same sign
        a = Absolute(a), b = Absolute(b);
        for (int i = 0; Equal(Equal(i, a), 0); i = Plusone(i)){
            result = Plusone(result); 
        }
        for (int j = 0; Equal(Equal(j, b), 0); j = Plusone(j)){
            result = Plusone(result);
        }
    }
    else { //if two numbers have different signs
        a = Absolute(a), b = Absolute(b);
        for (int i = Lesser(a, b); Equal(Equal(i, Greater(a, b)), 0); i = Plusone(i)){
            result = Plusone(result);
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