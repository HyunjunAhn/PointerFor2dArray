#include <stdio.h>
#define COLS1D 2
#define ROWS2D 2
#define COLS2D 3

typedef struct _tmp_t
{
    int *ptr;
    int (*ptr2d)[COLS2D];
} tmp_t;

void func(tmp_t *tmp)
{
    int *ptr = tmp->ptr;
    int (*ptr2d)[COLS2D] = tmp->ptr2d;

    printf("Pointer Array\n[");
    for(int i=0; i<COLS1D; i++)
    {
        if(i < COLS1D-1)
            printf("%d, ", ptr[i]);
        else
            printf("%d", ptr[i]);
    }
    printf("]\n\n");

    printf("Pointer 2-D Array\n");
    for(int i=0; i < ROWS2D ; i++)
    {
        printf("[");
        for(int j=0; j < COLS2D; j++)
        {
            if(j < ROWS2D)
                printf("%d, ", ptr2d[i][j]);
            else
                printf("%d", ptr2d[i][j]);
        }
        printf("]\n");
    }
}


void main()
{
    int temp[COLS1D] = {0, 1};
    int temp2d[ROWS2D][COLS2D] =
    {
        {10, 11 ,12},
        {20, 12, 22}
    };
    tmp_t tmp;
    tmp = (tmp_t){temp, temp2d};
    func(&tmp);
}