#include <stdio.h>
#include "expense.h"

int main()
{
    char categories[MAX_EXPENSES][30];
    float amounts[MAX_EXPENSES];

    int n = 0;
    int choice;
    int index;
    char target[30];

    do
    {
        printf("\n\n===== EXPENSE TRACKER =====\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Total expenses\n");
        printf("4. Highest expense\n");
        printf("5. Search category\n");
        printf("6. Average expense\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addExpense(categories, amounts, &n);
                break;

            case 2:
                displayExpenses(categories, amounts, n);
                break;

            case 3:
                printf("\nTotal expenses: Rs. %.2f\n",
                       totalExpenses(amounts, n));
                break;

            case 4:
                index = highestExpense(amounts, n);

                if (index == -1)
                {
                    printf("\nNo expenses recorded.\n");
                }
                else
                {
                    printf("\nHighest expense:\n");
                    printf("Category: %s\n", categories[index]);
                    printf("Amount  : Rs. %.2f\n", amounts[index]);
                }

                break;

            case 5:
                if (n == 0)
                {
                    printf("\nNo expenses recorded.\n");
                    break;
                }

                printf("\nEnter category to search: ");
                scanf(" %29[^\n]", target);

                index = searchCategory(categories, n, target);

                if (index == -1)
                {
                    printf("Category not found.\n");
                }
                else
                {
                    printf("Found: %s - Rs. %.2f\n",
                           categories[index], amounts[index]);
                }

                break;

            case 6:
                printf("\nAverage expense: Rs. %.2f\n",
                       averageExpense(amounts, n));
                break;

            case 7:
                printf("\nExiting Expense Tracker. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
        }

    } while (choice != 7);

    return 0;
}
