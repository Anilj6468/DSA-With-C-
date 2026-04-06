#include <iostream>;
using namespace std;

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b == 0) {
        printf("Error! Division by zero is not allowed.\n");
        return 0;
    }
    return a / b;
}

int modulus(int a, int b) {
    if (b == 0) {
        printf("Error! Modulus by zero is not allowed.\n");
        return 0;
    }
    return a % b;
}

int main() {
    int choice;
    float num1, num2;
    char cont;

    do {
        printf("\n===== Arithmetic Menu =====\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Modulus (%%)\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);

        switch (choice) {
            case 1:
                printf("Result = %.2f\n", add(num1, num2));
                break;

            case 2:
                printf("Result = %.2f\n", subtract(num1, num2));
                break;

            case 3:
                printf("Result = %.2f\n", multiply(num1, num2));
                break;

            case 4:
                printf("Result = %.2f\n", divide(num1, num2));
                break;

            case 5:
                printf("Result = %d\n", modulus((int)num1, (int)num2));
                break;

            default:
                printf("Invalid choice!\n");
        }

        printf("\nPress 'e' to exit or any other key to continue: ");
        scanf(" %c", &cont);

    } while (cont != 'e' && cont != 'E');

    printf("Program terminated.\n");
    return 0;
}