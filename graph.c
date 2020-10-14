#include <stdio.h>
#include <stdlib.h>
#define N 6 //// определяем максимальное количество вершин в графе

// структура данных для хранения графика
struct Graph {
	// массив указателей на узел для представления списка смежности
	struct Node* head[N];
};

// структура данных для хранения узлов списка смежности графа
struct Node {
	int dest, weight;
	struct Node* next;
};

// структура данных для хранения ребер графа
struct Edge {
	int src, dest, weight;

};

// функция для создания списка смежности из указанных ребер
struct Graph* createGraph(struct Edge edges[], int n)
{
	unsigned i;

	// выделяем память для структуры данных графа
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

	// инициализируем указатель  для всех вершин
	for (i = 0; i < N; i++)
		graph->head[i] = NULL;

	// добавляем ребра к ориентированному графу одно за другим
	for (i = 0; i < n; i++)
	{
		// получаем исходную и конечную вершины
		int src = edges[i].src;
		int dest = edges[i].dest;
		int weight = edges[i].weight;

		// выделяем новый узел списка смежности из src в dest
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->dest = dest;
		newNode->weight = weight;

		// указываем новый узел на текущий
		newNode->next = graph->head[src];

		// указываем указатель на новый узел
		graph->head[src] = newNode;
	}

	return graph;
}

// функция для печати представления графа в виде списка смежности
void printGraph(struct Graph* graph)
{
	int i;
	for (i = 0; i < N; i++)
	{
		// выводим текущую вершину и всех ее соседей
		struct Node* ptr = graph->head[i];
		while (ptr != NULL)
		{
			printf("%d -> %d (%d)\t", i, ptr->dest, ptr->weight);
			ptr = ptr->next;
		}

		printf("\n");
	}
}

// реализация взвешенного ориентированного графа на Cи
int main(void)
{
	// входной массив, содержащий ребра графа (как на диаграмме)
	struct Edge edges[] =
	{
		{ 0, 1, 6 }, { 1, 2, 7 }, { 2, 0, 5 }, { 2, 1, 4 },
		{ 3, 2, 10 }, { 4, 5, 1 }, { 5, 4, 3 }
	};

	// вычисляем количество ребер
	int n = sizeof(edges)/sizeof(edges[0]);

	// строим граф по заданным ребрам
	struct Graph *graph = createGraph(edges, n);

	// выводим представление графа в виде списка смежности
	printGraph(graph);

	return 0;
}
