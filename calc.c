#include <stdio.h>

// Function declarations
float add(float num1, float num2);
float subtract(float num1, float num2);
float multiply(float num1, float num2);
float divide(float num1, float num2);
int calculateLCM(int num1, int num2);

int main() {
    char operator;
    float num1, num2, result;

    // Get user input
    printf("Enter operator (+, -, *, /, LCM): ");
    scanf(" %c", &operator);  // Note the space before %c to consume the newline character

    if (operator != 'LCM') {
        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);
    }

    // Perform calculation based on the operator
    switch (operator) {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        case 'LCM':
            if (num1 >= 0 && num2 >= 0) {
                int lcm = calculateLCM((int)num1, (int)num2);
                printf("LCM: %d\n", lcm);
                return 0;
            } else {
                printf("Error: LCM requires non-negative integers\n");
                return 1;
            }
        default:
            printf("Invalid operator\n");
            return 1; // Exit the program with an error code
    }

    // Display the result
    printf("Result: %f\n", result);

    return 0;
}

// Function definitions
float add(float num1, float num2) {
    return num1 + num2;
}

float subtract(float num1, float num2) {
    return num1 - num2;
}

float multiply(float num1, float num2) {
    return num1 * num2;
}

float divide(float num1, float num2) {
    if (num2 != 0) {
        return num1 / num2;
    } else {
        printf("Error: Division by zero\n");
        return 0;
    }
}

int calculateLCM(int num1, int num2) {
    int max = (num1 > num2) ? num1 : num2;
    while (1) {
        if (max % num1 == 0 && max % num2 == 0) {
            return max;
        }
        max++;
    }
}
