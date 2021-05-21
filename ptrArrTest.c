#include <stdio.h>

typedef struct _tmp_t
{
    int (*ptr)[3];
} tmp_t;

void func(tmp_t *tmp)
{
    for(int i=0; i < 2 ; i++)
    {
        printf("[");
        for(int j=0; j < 3; j++)
        {
            if(j < 2)
                printf("%d, ", tmp->ptr[i][j]);
            else
                printf("%d", tmp->ptr[i][j]);

        }
        printf("]\n");
    }
}


void main()
{
    int temp[2][3] =
    {
        {10, 11 ,12},
        {20, 12, 22}
    };
    
    tmp_t tmp;
    
    tmp.ptr = temp;

    func(&tmp);
}