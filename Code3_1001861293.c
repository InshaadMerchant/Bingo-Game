//Inshaad Merchant 1001861293
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int CheckUnique2D (int MyArr[5][5] , int num)
{
    int exist =0;
    for (int i =0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            if (num == MyArr[i][j])
            {
                exist =1;
            }
        }
    }
    return exist;
}
void FillArray(int MyArr[5][5])
{
    int i,j;
    int check;
    int temp;
    srand(time(0));
    for (i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            temp = rand() % 15 +15*i+1;
            check = CheckUnique2D(MyArr, temp);
            if (check == 0)
            {
                MyArr[j][i] = temp;
            }
            else
            {
                j--;
            }
        }
    }
}
void PrintArray(int MyArr[5][5])
{
  int i,j;
  printf("B\tI\tN\tG\tO\n\n");
  printf("------------------------------------------\n");
  for (i=0; i<5; i++)
  {
      for(j=0; j<5; j++)
      {
          printf("%d\t|",MyArr[i][j]);
      }
      printf("\n");
      printf("------------------------------------------\n");
  }
}
int CheckDup(int num, int Arr1D[75])
{
    int i,check;
    for (i=0; i<75; i++)
    {
        if (Arr1D[i]==num)
        {
            check =0;
        }
        else
        {
            check =1;
        }
    }
    return check;
}
int search (int num, int MyArr[5][5])
{
    int res=0;
    int i,j;
    for (i=0; i<5; i++)
    {
        for (j=0; j<5; j++)
        {
            if (num == MyArr[j][i])
            {
                res =1;
                MyArr[j][i] = 0;
                PrintArray(MyArr);
            }
        }
    }
    return res;
}

int CheckRow (int MyArr[5][5])
{
    int res =0;
    for (int i=0; i<5; i++)
    {
       if (MyArr[0][i]==0 && MyArr[1][i]==0 && MyArr[2][i]==0 && MyArr[3][i]==0 && MyArr[4][i]==0)
       {
           res =1;
       }
    }
    return res;
}
int CheckColumn (int MyArr[5][5])
{
    int res =0;
    for (int j=0; j<5; j++)
    {
        if (MyArr[j][0]==0 && MyArr[j][1]==0 && MyArr[j][2]==0 && MyArr[j][3]==0 && MyArr[j][4]==0)
       {
           res =1;
       }
    }
    return res;
}
int CheckDiagonal (int MyArr[5][5])
{
    int res =0;
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            if (MyArr[0][0]==0 && MyArr[1][1]==0 && MyArr[2][2]==0 && MyArr[3][3]==0 && MyArr[4][4]==0)  
            {
                res =1;
            }
            if (MyArr[0][4]==0 && MyArr[1][3]==0 && MyArr[2][2]==0 && MyArr[3][1]==0 && MyArr[4][0]==0)
            {
                res =1;
            }
        }
    }
    return res;
}

int main(void)
{
    int Array[75];
    int a,i,result;
    int x=0;
    int BINGO[5][5]={};
    FillArray(BINGO);
    PrintArray(BINGO);
    int win_check = 0;
    char answer;
    srand(time(0));
    for (i=0; i<75; i++)
    {
        Array[i] = rand() % 75 +1;
        a = Array[i];
        CheckDup(a,Array);
        while (CheckDup(a,Array)==0)
        {
           Array[i] = rand() % 75 +1;
        }
    }
    while ((win_check == 0) && (x<75))
    {
        if ((Array[x]>=1) && (Array[x]<=15))
        {
            printf("The random number called out is B%d\n",Array[x]);
        }
        if ((Array[x]>=16) && (Array[x]<=30))
        {
            printf("The random number called out is I%d\n",Array[x]);
        }
        if ((Array[x]>=31) && (Array[x]<=45))
        {
             printf("The random number called out is N%d\n",Array[x]);
        }
        if ((Array[x]>=46) && (Array[x]<=60))
        {
           printf("The random number called out is G%d\n",Array[x]); 
        }
        if ((Array[x]>=61) && (Array[x]<=75))
        {
            printf("The random number called out is O%d\n",Array[x]);
        }
        
        printf("Do you have this value? Enter Y or N:\n\n");
        scanf(" %c", &answer);
        if (answer == 'Y')
        {
            result = search(Array[x],BINGO);
            if (result == 0)
            {
                printf("Are you trying to cheat?\n");
                PrintArray(BINGO);
            }
            if (result == 1)
            {
                printf("You got it!\n");
            }
            
        }
        if (answer == 'N')
        {
            PrintArray(BINGO);
        }
        if (answer != 'Y' && answer != 'N')
        {
            printf ("Enter Y or N only!\n");
            PrintArray(BINGO);
        }
        CheckRow(BINGO);
        if (CheckRow(BINGO) == 1)
        {
            printf("You filled out a column! BINGO!\n");
            win_check=1;
        }
        CheckColumn(BINGO);   
        if (CheckColumn(BINGO)==1)
        {
            printf("You filled out a row! BINGO!\n");
            win_check=1;
        }
        if (CheckRow(BINGO)==1 && CheckColumn(BINGO)==1)
        {
            printf("You filled out a row and a column");
            win_check=1;
        }
        CheckDiagonal(BINGO);   
        if (CheckDiagonal(BINGO)==1)
        {
            printf("You filled out a diagonal! BINGO!\n");
            win_check=1;
        }
        x++;
    }
    return 0;
}
