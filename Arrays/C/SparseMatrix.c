/*
Implementing Sparse Matrix in C
*/

#include <stdio.h>
#include <stdlib.h>

struct Elements
{
    int i;
    int j;
    int val;
};

struct SparseM
{
    int m;
    int n;
    int num;
    struct Elements *ele;
};

// Creating the Sparse Matrix
void CreateM(struct SparseM *spm)
{
    printf("Enter dimensions: ");
    scanf("%d%d", &spm->m, &spm->n);
    printf("Enter Number of non-zero elemets: ");
    scanf("%d", &spm->num);

    spm->ele = (struct Elements *)malloc(spm->num * sizeof(struct Elements));
    printf("Enter all non-Zero elements\n");
    for (int i = 0; i < spm->num; i++)
    {
        scanf("%d%d%d", &spm->ele[i].i, &spm->ele[i].j, &spm->ele[i].val);
    }
}

// Displaying the matrix

void Display(struct SparseM *spm)
{
    int i, j, k = 0;
    for (i = 0; i < spm->m; i++)
    {
        for (j = 0; j < spm->n; j++)
        {
            if (i == spm->ele[k].i && j == spm->ele[k].j)
            {
                printf("%d ", spm->ele[k++].val);
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}

// Adding two Sparse Matrices

struct SparseM *add(struct SparseM *s1, struct SparseM *s2)
{
    struct SparseM *sum;
    int i, j, k;
    i = j = k = 0;
    if (s1->n != s2->n || s1->m != s2->m)
        return NULL;
    sum = (struct SparseM *)malloc(sizeof(struct SparseM));
    sum->ele = (struct Elements *)malloc((s1->num + s2->num) * sizeof(struct Elements));
    while (i < s1->num && j < s2->num)
    {
        if (s1->ele[i].i < s2->ele[j].i)
            sum->ele[k++] = s1->ele[i++];
        else if (s1->ele[i].i > s2->ele[j].i)
            sum->ele[k++] = s2->ele[j++];
        else
        {
            if (s1->ele[i].j < s2->ele[j].j)
                sum->ele[k++] = s1->ele[i++];
            else if (s1->ele[i].j > s2->ele[j].j)
                sum->ele[k++] = s2->ele[j++];
            else
            {
                sum->ele[k] = s2->ele[i];
                sum->ele[k++].val = s1->ele[i++].val + s2->ele[j++].val;
            }
        }
    }
    for (; i < s1->num; i++)
        sum->ele[k++] = s1->ele[i];
    for (; j < s2->num; j++)
        sum->ele[k++] = s1->ele[j];
    sum->m = s1->m;
    sum->n = s2->m;
    sum->num = k;
    return sum;
}
int main()
{
    struct SparseM sm1, sm2, *sum;
    CreateM(&sm1);
    CreateM(&sm2);
    sum = add(&sm1, &sm2);
    Display(&sm1);
    printf("\n");
    Display(&sm2);
    printf("\nSum of both matrices\n");
    Display(sum);
    return 0;
}