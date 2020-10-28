#include <stdio.h>
#include <locale.h>
int main()
{       setlocale(LC_ALL, "RUS");
    int n; int i = 0; int j = 0; int r; int a1; int a2;
    printf("Введите количество вершин:");
    scanf("%d", &n);
    int arr[n][n]; 
    printf("Введите количество ребер:");
    scanf("%d", &r);
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            arr[i][j] = 0;       //заполнение массива нулями
        }
    }
    printf("Введите вершины, которые нужно соединить в качестве ребер:\n");
            for (i = 0; i < r; i++){
        scanf("%d" "%d", &a1, &a2);
               arr[a1][a2] = 1;
               arr[a2][a1] = 1;      
    }
    printf("Матрица смежности:\n");
        for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%d ", arr[i][j]);     
        }
        printf("\n");
    }
    return 0;
    }
