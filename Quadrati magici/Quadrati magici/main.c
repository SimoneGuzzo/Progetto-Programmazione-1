//
//  main.c
//  Quadrati magici
//
//  Created by Simone Guzzo on 09/02/2020.
//  Copyright © 2020 Simone Guzzo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
#define cycle 1000

int main ()
{
  int array[10][10];
  //int* sum_row_arr;
  //int* sum_col_arr;
  int sum_row_arr[1000];
  int sum_col_arr[1000];
  int i, j, n, y, l;
  int sum_rig = 0;
  int sum_col = 0;
  int sum_diag_sx,sum_diag_dx;
  int prob = 0;
  int cont = 0;
  int num = 0;
  int trovato = 0;
      
  printf("Inserisci le dimensioni della matrice n*n (n max %d): ", cycle);
  scanf("%d", &n);
  
 

  l= n*n;
  srand (time(NULL));//numeri diversi
  
  for (y=0 ; y<cycle ; y++)
  {
      
      printf("\n * Cycle %d *\n",y+1);
      
       for (i=0 ; i<n ; i++)
      {
      for (j=0 ; j<n ; j++)
       {
        array[i][j] = rand() % (l) + 1;
        }
    }
    
    //separatori
    for (i = 0; i < n; ++i)
    {
        printf("\n");
            for (j = 0; j < n; ++j)
            {
               printf("|%d|",array[i][j]);
            }
    }
    
    //somma riga
    for (i = 0; i < n; ++i)
    {
        sum_rig=0;
        for (j = 0; j < n; ++j)
         {
            sum_rig = sum_rig + array[i][j];
         }
         sum_row_arr[i] = sum_rig;
         //printf("\nsomma r  : %d", sum_row_arr[i]);
    }
     
    //somma colonna
    for (j = 0; j < n; ++j)
    {
        sum_col=0;
        for (i = 0; i < n; ++i)
         {
            sum_col = sum_col + array[i][j];
         }
        
        sum_col_arr[j] = sum_col;
        //printf("\nsomma c  : %d", sum_col_arr[j]);
    }

    //somma diagonale da sx a dx
    sum_diag_sx = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if(i==j){
                sum_diag_sx=sum_diag_sx+array[i][j];
            }
        }
    }

    //somma diagonale da dx a sx
    sum_diag_dx=0;
    i=0;
    for(j = n-1 ; j >= 0 ; j--)
    {
        //printf("\n i:%d j:%d value:%d", i, j,array[i][j]);
        sum_diag_dx=sum_diag_dx + array[i][j];
        i+=1;
    }
    
    //printf("\nsomma sx : %d", sum_diag_sx);
    //printf("\nsomma dx : %d", sum_diag_dx);
    
    if((sum_rig == sum_col) && (sum_rig == sum_diag_dx) && (sum_rig == sum_diag_sx)){
        i=0;
        trovato=0;
        do{
            if((sum_row_arr[i] == sum_row_arr[i+1]) && (sum_col_arr[i] == sum_col_arr[i+1]))
                trovato=1;
            else
                trovato=0;
            //printf("\nI:%d Trovato:%d\n",i,trovato);
            i++;
        }while((trovato==1)&&(i<n-1));
        
        if(trovato==1){
            printf("\nla matrice restituisce un quadrato perfetto\n");
            cont++;
            system("pause");
        }
        else
            printf("\nla matrice non restituisce un quadrato perfetto.\n");
    }else
        printf("\nla matrice non restituisce un quadrato perfetto.\n");

 }
     prob = (cont*100)/1000;
     printf("\n%d quadrati perfetti trovati - Percentuale di successo: %d \n",cont, prob);
     system("pause");
     return 0;
}
