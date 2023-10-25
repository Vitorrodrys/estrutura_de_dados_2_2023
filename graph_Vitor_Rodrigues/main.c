#include <stdio.h>
#include "grafo_comparation.h"
#include "input_output.h"
int main() {

    int choice = 1;

    int is_target;
    int n_vertex;
    printf("do you want create a graph targeted? Type 0 for not, or 1 for yes: ");
    verificaNumero("%d", &is_target);
    printf("what number of vertex of the graph? ");
    verificaNumero("%d", &n_vertex);
    GraphComparation *gp = create_graph_c(is_target, n_vertex);


    while (choice != 6){

        menu(
                6,
                "selected a option:",
                "insert new edge",
                "which better storage for graph that is represented",
                "the graph current is complete",
                "the current graph has cicles",
                "show graph",
                "exit"
                );
        verificaNumero("%d", &choice);

        switch (choice) {

            case 1:
            {
                int from;
                int to;
                printf("type number of the vertex of source: ");
                verificaNumero("%d", &from);
                printf("type nnumber of the vertex of destine: ");
                verificaNumero("%d", &to);
                insert_new_edge(gp, from, to);
                break;
            }
            case 2:
            {
                betterGraph better = what_is_better(gp);
                printf(better == graphMtxAdj?"Graph with matrix ajd is better\n":"graph with list of ajd is better\n");
                break;
            }
            case 3:
                printf(is_complete(gp)?"is complete\n":"don't is complete\n");
                break;

            case 4:
                printf(have_cicles_in_graph(gp)?"has cicles\n":"don't has cicles\n");
                break;

            case 5:
                show_graphs(gp);
                break;
            case 6:
                gp = destroy_graph_c(gp);
                break;
            default:
                printf("type an options correct!");

        }


    }


}
