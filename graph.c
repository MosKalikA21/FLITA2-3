  
    #include <stdio.h>
#include <locale.h>


void print_graph(int n, int arr[n][n]) {
    int i = 0; int j = 0; 
    printf("Матрица смежности:\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}


void print_dot(int n, int arr[n][n]) {
    FILE* f = fopen("graph.dot", "w");
    fprintf(f, "graph{\n");
    printf("graph{\n");
    int i = 0; int j = 0; 
    for (i = 0; i < n; i++){
        for (j = i; j < n; j++){
                if(arr[i][j]==1){
            printf("%d -- %d;\n", i, j );
            fprintf(f, "%d -- %d;\n", i, j );
        }
    }
    } 
    printf("}");
    fprintf(f, "}");
    fclose(f);
}

// 1, если граф связный, 0, если нет
int connected(int n, int arr[n][n]) {
    int found[n] = {};
    int queue[n] = {};
    found[0] = 1;
    int j = 0;
    for (j = 0; j < n; j++){
            if(arr[0][j] == 1){
             found[j] = 1;
             // queue
            }
    
        
}


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
        scanf("    %d" "%d", &a1, &a2);
               arr[a1][a2] = 1;
               arr[a2][a1] = 1;      
    }
    print_graph(n, arr);
    print_dot(n, arr);
    // -----------------------------------------
    
    
    return 0;
    }
  8888888888888888888888888888888888888888888888888888888888888
    #include <stdio.h>
#include <locale.h>

void print_graph(int n, int arr[n][n]) {
    int i = 0; int j = 0; 
    printf("Матрица смежности:\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void print_dot(int n, int arr[n][n]) {        
    FILE* f = fopen("graph.dot", "w");    // открытие файла graph.dot,   "w"=write
    fprintf(f, "graph{\n");
    printf("graph{\n");                   // реализовываем вид, который будет понятен, для Graphviz,          
    int i = 0; int j = 0;                 // который содержит такой синтаксис: graph{
    for (i = 0; i < n; i++){              //                                      0--1;
        for (j = i; j < n; j++){          //                                     и т.д.
                if(arr[i][j]==1){         //                                          }
            printf("%d -- %d;\n", i, j );
            fprintf(f, "%d -- %d;\n", i, j );
        }
    }
    } 
    printf("}");
    fprintf(f, "}");
    fclose(f);
}

void connected(int n, int r, int arr[n][n]) {
    if (r < ((n - 1) * (n - 2)) / 2) {
      printf("Граф несвязный, теорема не работает\n");  
      } 
    else {
      printf("Граф связный, теорема работает\n");   
      }
 }
 
int main()
{   setlocale(LC_ALL, "RUS");
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
        scanf(" %d" "%d", &a1, &a2);
               arr[a1][a2] = 1;
               arr[a2][a1] = 1;      
    }
    print_graph(n, arr);
    print_dot(n, arr);
    return 0;
    }
