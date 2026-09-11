#define EXPENSE_H

#define MAX_EXPENSES 100

void addExpense(char categories[][30], float amounts[], int *n);
void displayExpenses(char categories[][30], float amounts[], int n);
float totalExpenses(float amounts[], int n);
int highestExpense(float amounts[], int n);
int searchCategory(char categories[][30], int n, char target[]);
float averageExpense(float amounts[], int n);

#endifw
