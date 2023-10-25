# Nome do arquivo executável
TARGET = pratica_grafos_Vitor_Rodrigues

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -g

# Diretórios de origem
SRC_DIR = matriz_adjacencia list_vertex

# Arquivos de origem
SOURCES = $(wildcard $(addsuffix /*.c, $(SRC_DIR))) grafo_comparation.c graph.c input_output.c memory_functions.c main.c

# Objetos gerados a partir dos arquivos de origem
OBJECTS = $(SOURCES:.c=.o)

# Regra de compilação
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

# Regra para cada arquivo objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra padrão
all: $(TARGET)

# Regra para limpar os arquivos objeto e executável
clean:
	rm -f $(OBJECTS) $(TARGET)

