#include<stdio.h>

int sum(int a, int b) {
    return a+b;
}

int main() {


    // if (condition == true) {
    //     // do something
    // }else if(another condition == true) {
    //     // do something else
    // }else {
    //     // do something else
    // }

    // int age;

    int a = 10;
    int b = 20;

    int c = a+b;

    // int c = sum(a, b);

    // scanf("%d", &age);

    // if (age >= 18) {
    //     printf("You are not a child, watch porn");
    // }else if(age >= 10 || age <= 18) {
    //     printf("You can watch only nude");
    // }else {
    //     printf("You cannot watch porn");
    // }
    
    printf("the sum of %d and %d is %d", a, b, c);
    return 0;
}