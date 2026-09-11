#include <stdio.h>
#include <string.h>
#include "expense.h"

void addExpense(char categories[][30], float amounts[], int *n)
{
    if (*n >= MAX_EXPENSES)
    {
        printf("Expense limit reached.\n");
        return;
    }

    printf("\nEnter category: ");
    scanf(" %29[^\n]", categories[*n]);

    printf("Enter amount: ");
    scanf("%f", &amounts[*n]);

    if (amounts[*n] < 0)
    {
        printf("Amount cannot be negative.\n");
        return;
    }

    (*n)++;

    printf("Expense added successfully!\n");
}

void displayExpenses(char categories[][30], float amounts[], int n)
{
    if (n == 0)
    {
        printf("\nNo expenses recorded.\n");
        return;
    }

    printf("\n========== EXPENSES ==========\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d. %-20s Rs. %.2f\n",
               i + 1, categories[i], amounts[i]);
    }
}

float totalExpenses(float amounts[], int n)
{
    float total = 0;

    for (int i = 0; i < n; i++)
    {
        total += amounts[i];
    }

    return total;
}

int highestExpense(float amounts[], int n)
{
    if (n == 0)
    {
        return -1;
    }

    int index = 0;

    for (int i = 1; i < n; i++)
    {
        if (amounts[i] > amounts[index])
        {
            index = i;
        }
    }

    return index;
}

int searchCategory(char categories[][30], int n, char target[])
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(categories[i], target) == 0)
        {
            return i;
        }
    }

    return -1;
}

float averageExpense(float amounts[], int n)
{
    if (n == 0)
    {
        return 0;
    }

    return totalExpenses(amounts, n) / n;
}
