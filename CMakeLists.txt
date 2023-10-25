cmake_minimum_required(VERSION 3.26)
project(untitled68 C)

set(CMAKE_C_STANDARD 23)

add_executable(untitled68 main.c
        graph.c
        graph.h
        memory_functions.c
        memory_functions.h
        list_vertex/no_vertex.h
        list_vertex/no_vertex.c
        list_vertex/list_vertex.c
        matriz_adjacencia/grafo_matriz_adjacencia.h
        matriz_adjacencia/grafo_matriz_adjacencia.c
        grafo_comparation.c
        input_output.c
        respost_search/respost_search.c
        respost_search/queue.c
)
