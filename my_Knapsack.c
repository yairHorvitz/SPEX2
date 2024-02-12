#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "my_Knapsack.h"
#define products 5
#define capacity 20
#define max_str_len 20

int knapSack(int weights[], int values[], int selected_bool[]);

int main()
{
    char items[products][max_str_len + 1];
    int values[products];
    int weights[products];
    int selected_bool[products] = {0};

    for (int i = 0; i < products; i++)
    {
        scanf("%s", items[i]);
        scanf("%d", &values[i]);
        scanf("%d", &weights[i]);
    }

    int maxProfit = knapSack(weights, values, selected_bool);
  
    printf("Maximum profit: %d", maxProfit);
    int counter = 0;
    for (int i = 0; i < products; i++)
    {
        if (selected_bool[i] == 1)
        {
            counter++;
        }
    }
    printf("\nSelected items:");
    for (int i = 0; i < products; i++)
        if (selected_bool[i] == 1)
        {
            printf(" %s", items[i]);
        }
}

int knapSack(int weights[], int values[], int selected_bool[])
{
    int bag[products + 1][capacity + 1];
    for (int i = 0; i <= products; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
            {
                bag[i][w] = 0;
            }
            else if (weights[i - 1] <= w)
            {
                if (values[i - 1] + bag[i - 1][w - weights[i - 1]] >= bag[i - 1][w])
                {
                    bag[i][w] = values[i - 1] + bag[i - 1][w - weights[i - 1]];
                }
                else
                {
                    bag[i][w] = bag[i - 1][w];
                }
            }
            else
            {
                bag[i][w] = bag[i - 1][w];
            }
        }
    }
    //  for(int i=0;i<=products;i++)
    //  {
    // for(int w=0;w<=capacity;w++)
    // printf("%d\n",bag[i][w]);}

    int i = products;
    int w = capacity;
    while (i > 0 && w > 0)
    {
        if (bag[i][w] != bag[i - 1][w])
        {
            selected_bool[i - 1] = 1;
            w = w - weights[i-1];
        }
        i--;
    }
    return bag[products][capacity];
}