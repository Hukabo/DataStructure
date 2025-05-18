#include <stdio.h>
#include <stdlib.h>

// 정점의 개수
#define V 5 

//그래프 구조체
struct graph {

    struct vertex *point[V];
    // 각 정점의 포인터 배열
};

// 정점 구조체
struct vertex {

    int end;
    // 정점이 가리키는 방향
    struct vertex *next;
    /* 또 다른 경로를 가리키는 동일한 정점
        ex) 1 -- 2(end)
              \
                0(end)
    */
};

// 간선(link)
struct Edge {

    int end, start;
};

struct graph *create_graph(struct Edge edges[], int n) {
    int i;
    struct graph *graph = (struct graph *)malloc(sizeof(struct graph));

    // 쓰레기 데이터 지우기
    for (i = 0; i < V; i++) {
        graph->point[i] = NULL;
    }
    
    for(i = 0; i < n; i++) {
        int start = edges[i].start;
        int end = edges[i].end;

        struct vertex *v = (struct vertex *)malloc(sizeof(struct vertex));
        v->end = end;
        v->next = graph->point[start];
        graph->point[start] = v;
    }
    return graph;
}

int main() {
    struct Edge edges[] = { {0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 4}, {2, 4},
     {2, 3}, {3, 1}};
    int n = sizeof(edges) / sizeof(edges[0]);

    struct graph *graph = create_graph(edges, n);

    printf("The graph created is: ");

    for (int i = 0; i < V; i++) {
        struct vertex *ptr = graph->point[i];
        while(ptr != NULL) {
            printf("(%d -> %d)\t", i, ptr->end);
            ptr = ptr->next;
        }
        printf("\n");
    }

    return 0;
}