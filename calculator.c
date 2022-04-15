#include <stdio.h>
#include <stdbool.h>

//given functions
int Plusone(int a); 
bool Equal(int a, int b);

//additional functions
bool Sign(int a); //get the sign (1: positive or zero, 0: negative)
bool Not(int a, int b);//opposite of Equal function
int Greater(int a, int b);//get greater value
int Lesser(int a, int b);//get lesser value
int Absolute(int a); //get absolute value
int EvenOdd(int a); //1: even, 0: odd
void Add(int a, int b); //addition
void Subtract(int a, int b); //subtraction
void Multiply(int a, int b); //multiplication
void Divide(int a, int b); //division
int Plus(int a, int b); //used in divide function
int Multi(int a, int b); //used in divide and power function
void Power(int a, int b); //power
void Menu(); //print menu

//main
int main() {
    Menu();
    while (true) {
        char oper; 
        int a, b;
        printf("\nOperator\n>>> ");
        scanf(" %c", &oper);
        if (Equal(oper, 'Q')) {
            printf("This program will end soon.\n");
            break;
        }
        else if (Equal(oper, 'M')) {
            Menu();
            continue;
        }
        printf("First operand\n>>> ");
        scanf("%d", &a);
        printf("Second operand\n>>> ");
        scanf("%d", &b);
        switch (oper){
        case '+':
            Add(a, b);
            break;
        case '-':
            Subtract(a, b);
            break;
        case '*':
            Multiply(a, b);
            break;
        case '/':
            Divide(a, b);
            break;
        case '^':
            Power(a, b);
            break;
        case '#':
            printf("[Absolute value of a: %d]\n", Absolute(a));
            printf("[Absolute value of b: %d]\n", Absolute(b));
            break;
        default:
            printf("ERROR: Wrong operator.");
            break;
        }
    }
    return 0;
}

//given functions specific
int Plusone(int a) {
    return ++a;
}

bool Equal(int a, int b) {
    if (a == b) return true;
    else return false;
}

//additional functions specific
bool Sign(int a) {
    if (Equal(a, Absolute(a))) return 1; 
    else return 0; 
}//get the sign (1: positive or zero, 0: negative)

bool Not(int a, int b) {
    if (Equal(a, b)) return false;
    else return true;
}//opposite of Equal function

int Greater(int a, int b) {
    for (int i = 0; Not(i, a); i = Plusone(i)) {
        if (Equal(i, b)) return a;
    }
    return b;
}//get greater value

int Lesser(int a, int b) {
    for (int i = 0; Not(i, a); i = Plusone(i)) {
        if (Equal(i, b)) return b;
    }
    return a;
}//get lesser value

int Absolute(int a) {
    int count = 0, original = a;
    for (count; Not(a, 0); count = Plusone(count)) {
        a = Plusone(a);
        if (Equal(count, original)) return original; //positive
    } 
    for (int i = 0; Not(i, count); i = Plusone(i)) {
        a = Plusone(a);
    } 
    return a;
}//get absolute value

int EvenOdd(int a) {
    a = Absolute(a);
    for (int i = Lesser(a, 2); Not(i, Greater(a, 2)); i = Plusone(i)) {
        i = Plusone(i);
        if (Equal(i, Greater(a, 2))) return 0;
    }
    return 1;
}//1: even, 0: odd

void Add(int a, int b) { 
    int result = 0, minus;
    if (Equal(Sign(a), Sign(b))) {//same sign
        if (Sign(a)) minus = 0; 
        else minus = 1; 
        a = Absolute(a), b = Absolute(b);
        for (int i = 0; Not(i, a); i = Plusone(i)) {
            result = Plusone(result);
        }
        for (int i = 0; Not(i, b); i = Plusone(i)) {
            result = Plusone(result);
        }
    }
    else {//different signs
        if (Equal(Sign(a), Equal(Absolute(a), Greater(Absolute(a), Absolute(b))))) {
            minus = 0;
        }
        else minus = 1;
        a = Absolute(a), b = Absolute(b);
        for (int i = Lesser(a, b); Not(i, Greater(a, b)); i = Plusone(i)) {
            result = Plusone(result);
        }
    }
    if (Equal(result, 0)) printf("[Result: %d]\n", result);
    else if (minus) printf("[Result: -%d]\n", result);
    else printf("[Result: %d]\n", result);
}//addition

void Subtract(int a, int b) {
    int result = 0, minus;
    if (Equal(Sign(a), Sign(b))) {//same sign
        if (Equal(Sign(a), Equal(Absolute(a), Greater(Absolute(a), Absolute(b))))) {
            minus = 0;
        }
        else minus = 1;
        a = Absolute(a), b = Absolute(b);
        for (int i = Lesser(a, b); Not(i, Greater(a, b)); i = Plusone(i)) {
            result = Plusone(result);
        }
    }
    else {//different signs
        if (Sign(a)) minus = 0;
        else minus = 1;
        a = Absolute(a), b = Absolute(b);
        for (int i = 0; Not(i, a); i = Plusone(i)) {
            result = Plusone(result);
        }
        for (int i = 0; Not(i, b); i = Plusone(i)) {
            result = Plusone(result);
        }
    }
    if (Equal(result, 0)) printf("[Result: %d]\n", result);
    else if (minus) printf("[Result: -%d]\n", result);
    else printf("[Result: %d]\n", result);
}//subtraction

void Multiply(int a, int b) {
    int result = 0, minus;
    if (Equal(Sign(a), Sign(b))) minus = 0;
    else minus = 1;
    a = Absolute(a), b = Absolute(b);
    for (int i = 0; Not(i, a); i = Plusone(i)) {
        for (int j = 0; Not(j, b); j = Plusone(j)) {
            result = Plusone(result);
        }
    }
    if (Equal(result, 0)) printf("[Result: %d]\n", result);
    else if (minus) printf("[Result: -%d]\n", result);
    else printf("[Result: %d]\n", result);
}//multiplication

void Divide(int a, int b) {
    int current = 0, quotient = 0, remain = 0, minus1, minus2;
    if (Equal(b, 0)) {
        printf("ERROR: Cannot divide by zero.\n");
        return;
    }
    if (Equal(Sign(a), Sign(b))) minus1 = 0;
    else minus1 = 1;
    if (Sign(a)) minus2 = 0;
    else minus2 = 1;
    a = Absolute(a), b = Absolute(b);
    if (Equal(a, Lesser(a, b))) {//a <= b
        if (Equal(a, b)) quotient = 1;
        else quotient = 0;
    }
    for (int i = 1; Not(Plus(current, b), Greater(Plus(current, b), a)); i = Plusone(i)) {
        quotient = Plusone(quotient);
        current = Multi(b, i);
        if (Equal(Plus(current, b), a)) {
            quotient = Plusone(quotient);
            break;
        }
    }
    current = Multi(b, quotient);
    for (int i = current; Not(i, a); i = Plusone(i)) {
        remain = Plusone(remain);
    }
    if (Equal(quotient, 0)) printf("[Quotient: %d]\n", quotient);
    else if (minus1) printf("[Quotient: -%d]\n", quotient);
    else printf("[Quotient: %d]\n", quotient);
    if (Equal(remain, 0)) printf("[Remainder: %d]\n", remain);
    else if (minus2) printf("[Remainder: -%d]\n", remain);
    else printf("[Remainder: %d]\n", remain);
}//division

int Plus(int a, int b) {
    int result = 0;
    a = Absolute(a), b = Absolute(b);
    for (int i = 0; Not(i, a); i = Plusone(i)) {
        result = Plusone(result);
    }
    for (int i = 0; Not(i, b); i = Plusone(i)) {
        result = Plusone(result);
    }
    return result;
}//used in divide function

int Multi(int a, int b) {
    int result = 0;
    a = Absolute(a), b = Absolute(b);
    for (int i = 0; Not(i, a); i = Plusone(i)) {
        for (int j = 0; Not(j, b); j = Plusone(j)) {
            result = Plusone(result);
        }
    }
    return result;
}//used in divide and power function

void Power(int a, int b) {
    int result = 0, minus, form;
    if (Equal(b, 0)) {
        printf("[Result: 1]\n");
        return;
    }
    if (Sign(a)) minus = 0;
    else if (EvenOdd(b)) minus = 0;
    else minus = 1;
    if (Sign(b)) form = 0;
    else form = 1;
    a = Absolute(a), b = Absolute(b);
    result = a;
    for (int i = 0; Not(Plusone(i), b); i = Plusone(i)) {
        result = Multi(result, a);
    }
    if (Equal(minus, 0)) {
        if (form) printf("[Result: 1/%d]\n", result);
        else printf("[Result: %d]\n", result);
    }
    else if (form) printf("[Result: -1/%d]\n", result);
    else printf("[Result: -%d]\n", result);
}//power

void Menu() {
    printf("           [Restricted Calculator]\n\n");
    printf("               * WARNINGS *\n");
    printf("1. The maximum result is 2,147,483,647.\n");
    printf("2. The result of division is based on C.\n");
    printf("3. Do not put commas in numbers.\n");
    printf("4. Do not use space bar.\n\n");
    printf("               *  MANUAL *\n");
    printf("   +           Addition|  -        Subtraction\n");
    printf("   *     Multiplication|  /        Division\n");
    printf("   ^              Power|  #        Absolute\n");
    printf("   Q               Quit|  M        Manual\n\n");
}//print menu