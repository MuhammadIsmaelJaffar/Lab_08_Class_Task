#include <stdio.h>
int main()
{
    int matrixS[3][3];
    int matrixP[3][2];
    int matrixR[3][2];
    int profit[3];
    int input;
    int cost;
    int sell;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("\nEnter for branch %d , quantity of item %d      ,These are the items: 1-Charger , 2-Earphones , 3-Cover   \n",i+1,j+1);
            scanf("%d",&input);
            matrixS[i][j] = input;
        }
    }


for(int i=0;i<3;i++)
{
        printf("\nEnter for product %d the cost price , \n",i+1);
        scanf("%d",&cost);
        printf("\nEnter for product %d the selling price \n",i+1);
        scanf("%d",&sell);
        matrixP[i][0] = cost;
        matrixP[i][1] = sell;
}


for (int i = 0; i < 3; i++) 
{
    for (int j = 0; j < 2; j++) 
    {
        matrixR[i][j] = 0; 
    }
}


for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 2; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            matrixR[i][j] += matrixS[i][k] * matrixP[k][j];
        }
    }
}

for(int i = 0; i < 3; i++)
{
    profit[i] = matrixR[i][1] - matrixR[i][0];
}

int max_profit = profit[0];
for(int i = 1; i < 3; i++)
{
    if(profit[i] > max_profit)
    {
        max_profit = profit[i];
    }
}

printf("\n Original Price Analysis \n");
printf("Highest Profit Branch: ");
for(int i = 0; i < 3; i++)
{
    if(profit[i] == max_profit)
    {
        printf("Branch %d (Profit: %d) ", i + 1, profit[i]);
    }
}
printf("\n");

for (int i = 0; i < 3; i++)
{
    matrixP[i][1] = (matrixP[i][1] * 9) / 10;
}

for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 2; j++)
    {
        matrixR[i][j] = 0;
    }
}

for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 2; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            matrixR[i][j] += matrixS[i][k] * matrixP[k][j];
        }
    }
}

for (int i = 0; i < 3; i++)
{
    profit[i] = matrixR[i][1] - matrixR[i][0];
}

max_profit = profit[0];
for (int i = 1; i < 3; i++)
{
    if (profit[i] > max_profit)
    {
        max_profit = profit[i];
    }
}

printf("\n--- 10%% Discounted Price Analysis ---\n");
printf("New Highest Profit Branch(es): ");
for (int i = 0; i < 3; i++)
{
    if (profit[i] == max_profit)
    {
        printf("Branch %d (Profit: %d) ", i + 1, profit[i]);
    }
}
printf("\n");
return 0;
}