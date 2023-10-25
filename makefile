# Nome do arquivo executável
TARGET = trabalho_pthreads_SO

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -g -pthread

# Arquivos de origem
SOURCES = monitor_threads.c main.c

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

