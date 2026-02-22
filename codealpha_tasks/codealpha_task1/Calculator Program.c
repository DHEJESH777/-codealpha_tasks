#include <stdio.h>

int main() {
    float num1, num2;
    char operator;

    printf("=== Basic Calculator Program ===\n");
    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);  // Space before %c avoids input issues

    printf("Enter second number: ");
    scanf("%f", &num2);

    switch(operator) {
        case '+':
            printf("Result: %.2f\n", num1 + num2);
            break;

        case '-':
            printf("Result: %.2f\n", num1 - num2);
            break;

        case '*':
            printf("Result: %.2f\n", num1 * num2);
            break;

        case '/':
            if(num2 != 0)
                printf("Result: %.2f\n", num1 / num2);
            else
                printf("Error! Division by zero is not allowed.\n");
            break;

        default:
            printf("Invalid operator selected.\n");
    }

    return 0;
}