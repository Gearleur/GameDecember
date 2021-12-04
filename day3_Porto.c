#include <stdio.h>
#include <stdlib.h>

int main() { 
    
    int count1 = 0;
    int count0 = 0;
    int **copie;
    int **copie2;
    int **sauv;
    int **sauv2;
    int tab[1000][12]= {{1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0},
{1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1},
{1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1},
{0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0},
{0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
{0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0},
{0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
{1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0},
{1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1},
{1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0}};
    int taille = 10;
    sauv = (int**)malloc(10* sizeof(int*));
    for(int p = 0; p < taille; p++)
    {
        *(sauv+p) = (int*)malloc(12* sizeof(int));
        for(int m=0; m<=11; m++)
        {
            *(*(sauv+p)+m) = tab[p][m];
        }
    }

    for (int i = 0; i < 12; i++)
    {
        count1 = 0;
        count0 = 0;
        for(int j = 0; j < taille; j++)
        {
            if (*(*(sauv+j)+i)==1)
            {
                count1++;
            }
            else{
                count0++;
            }
        }

        printf("%d\n", count1);
        printf("%d\n", count0);
        printf("%d\n", taille);

        copie = (int**)malloc(taille* sizeof(int*));
        copie = sauv;
        
        for(int i = 0; i < taille; i++)
            free(*(sauv+i));
        free(sauv);


        sauv = (int**)malloc(count1* sizeof(int*));

        if(count1 >= count0){


            int pos = 0;

            for(int k =0; k < taille; k++)
            {
                
                if(*(*(copie+k)+i)==1)
                {
                    *(sauv+pos) = (int*)malloc(12* sizeof(int));
                    for(int m = 0; m<=11; m++)
                    {
                        *(*(sauv+pos)+m) = *(*(copie+k)+m);
                        printf("%d",*(*(sauv+pos)+m));
                        
                    }
                    printf("\n");
                    pos++;
                   
                }
            }
            taille = count1;
        }

        if(count1 < count0){

            int pos = 0;

            for(int k =0; k < taille; k++)
            {
                
                if(*(*(copie+k)+i)==0)
                {
                    *(sauv+pos) = (int*)malloc(12* sizeof(int));
                    for(int m=0; m<=11; m++)
                    {
                        *(*(sauv+pos)+m) = *(*(copie+k)+m);
                        printf("%d",*(*(sauv+pos)+m));
                    }
                    printf("\n");
                    pos++;

                }
            }
            taille = count0;
            printf("%d", taille);
        }
    }
}
    
    