#include <stddef.h>
#include <stdio.h>
#include "my_mat.h"



void matrixVarible(int matrix[ROWS][COLS])
{
    int x;
    for (size_t i = 0; i < COLS; i++)
    {
        for (size_t j = 0; j < ROWS; j++)
        {
          scanf("%d",&x);  /* code */
          matrix[i][j]=x;
        }
        
    }
        
}

void pathExist(int matrix[ROWS][COLS]) 
{
for(int i=0 ;i<COLS;i++)
{
  for(int j=0;j<ROWS;j++){
    if(i == j || matrix[i][j] == 0)
    {matrix[i][j]=__INT_MAX__;}
   // printf("%d ",matrix[i][j]);
    }
}
int c=0;
int r=0;
scanf("%d",&c);
scanf("%d",&r);

for (int k = 0; k < COLS; k++)     //number of edges
{
  for (int i = 0; i < COLS; i++)   
  {
    for (int j = 0; j < COLS; j++)
    {
       if(i == j || matrix[i][j] == 0){matrix[i][j] = __INT_MAX__;}
       else if(matrix[i][k]==__INT_MAX__||matrix[k][j]==__INT_MAX__){continue;}
    else  if(matrix[i][j]> matrix[i][k]+matrix[k][j])
    { // printf("befor ij:  %d\n", matrix[i][j]);
    //  printf("befor ik:  %d\n", matrix[i][k]);
     // printf("befor jk:  %d\n", matrix[k][j]);
    
      {matrix[i][j] =matrix[i][k]+matrix[k][j];}
      // printf("ij:  %d\n", matrix[i][j]);
   //   printf("ik:  %d\n", matrix[i][k]);
    //  printf("jk:  %d\n", matrix[k][j]);
      }
    }
  }
}
 // for (size_t i = 0; i < 10; i++)
   //     for (size_t j = 0; j < 10; j++)
       // printf("after the shortest %d\n", matrix[i][j]);

if(matrix[c][r]!=__INT_MAX__){printf("TRUE\n");}
else{printf("FALSE\n");}

}




int shortestPath (int matrix[ROWS][COLS])
{
for(int i=0 ;i<COLS;i++)
{
for(int j=0;j<ROWS;j++){
  if(matrix[i][j]==0||i==j){matrix[i][j]=__INT_MAX__;}
}
}
int c=0;
int r=0;
scanf("%d",&c);
scanf("%d",&r);
for (int k = 0; k < COLS; k++)     //number of edges
{
  for (int i = 0; i < COLS; i++)   
  {
    for (int j = 0; j < COLS; j++)
    {
       if(matrix[i][j]==0||i==j){matrix[i][j]=__INT_MAX__;}
       else if(matrix[i][k]==__INT_MAX__||matrix[k][j]==__INT_MAX__){continue;}
      else if(matrix[i][j]>matrix[i][k]+matrix[k][j])
      {matrix[i][j]=matrix[i][k]+matrix[k][j];}
    }
  }
}
if((matrix[c][r]!=__INT_MAX__)||(matrix[c][r]==0)){return matrix[c][r];}
return-1;

}