#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int source;
    int destination;
};

struct Graph {
    int v_count, e_count;
    Edge *edge;
};

Graph *create_graph(int v_count, int e_count) {
    Graph *new_graph = (Graph *)malloc(sizeof(Graph));
    new_graph->v_count = v_count;
    new_graph->e_count = e_count;
    new_graph->edge = (Edge *)malloc(sizeof(Edge) * e_count);

    return new_graph;
}

int find_parent(int parent[], int index) {
    if(parent[index] == index) return index;
    else {
        return parent[index] = find_parent(parent, parent[index]);
    }
}

bool is_cycle(Graph *graph) {
    int parent[graph->v_count];

    for(int i = 0; i < graph->v_count; i++) {
        parent[i] = i; // make set
    }


	for(int i = 0 ; i < graph->e_count ; i++){
		struct Edge * edge = graph->edge;
		
		int source_parent = find_parent(parent, edge[i].source);
		int destination_parent = find_parent(parent, edge[i].destination);
		
		if (source_parent == destination_parent){
			return true;
		}
		
		parent[source_parent] = destination_parent;
	}

    return false;
}

int main() {

    int v_count = 4;
    int e_count = 3;
    // Create the graph
    Graph *graph = create_graph(v_count, e_count);
    puts("Succesfully Created Graph");
    // Connect the vertex
    graph->edge[0].source = 0;
    graph->edge[0].destination = 1;
    
    graph->edge[1].source = 0;
    graph->edge[1].destination = 2;

    graph->edge[2].source = 2;
    graph->edge[2].destination = 3;

    graph->edge[3].source = 2;
    graph->edge[3].destination = 1;

    printf("This graph is %s", is_cycle(graph) ? "Cyclic" : "Not Cyclic");

    return 0;
}
