#include <stdio.h>
#include "my_mat.h"

int main()
{
    int matrix[ROWS][COLS];
    char letter;
    scanf("%c", &letter);
    while (letter != 'D')
    {
        if (letter == 'A')
        {matrixVarible(matrix);}
        if (letter == 'B')
        {pathExist(matrix);}
        if (letter == 'C')
        {int ans=shortestPath(matrix);
         printf("%d\n",ans);}
        scanf("%c", &letter);
    }
}
