#include <stdio.h>

enum MenuChoice {
    ADD = 1,
    SUBTRACT = 2,
    MULTIPLY = 3,
    DIVIDE = 4,
    EXIT = 5
};

int main()
{
    int choice;
    float a, b;

    while (1)
    {
        printf("\n--- Calculator Menu ---\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == EXIT)
        {
            printf("Exiting calculator. Goodbye!\n");
            break;
        }

        if (choice < ADD || choice > EXIT)
        {
            printf("Invalid choice! Please choose between 1 and 5.\n");
            continue;
        }

        printf("Enter two numbers: ");
        scanf("%f %f", &a, &b);

        switch (choice)
        {
            case ADD:
                printf("Result = %.2f\n", a + b);
                break;
            case SUBTRACT:
                printf("Result = %.2f\n", a - b);
                break;
            case MULTIPLY:
                printf("Result = %.2f\n", a * b);
                break;
            case DIVIDE:
                if (b == 0.0f)
                    printf("Error: Division by zero is not allowed!\n");
                else
                    printf("Result = %.2f\n", a / b);
                break;
        }
    }

    return 0;
}
