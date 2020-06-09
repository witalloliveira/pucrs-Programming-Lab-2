EXEC = app

SRC = src
HEADER = header
OBJ = obj
BIN = bin

MAIN = $(SRC)/main.cpp $(HEADER)/ListaLRU.hpp
LRU = $(SRC)/ListaLRU.cpp $(HEADER)/ListaLRU.hpp

OBJS = $(OBJ)/main.o $(OBJ)/ListaLRU.o

CFLAGS = -std=c++11 -Wall
LFLAGS = -std=c++11

all:				$(EXEC)

$(EXEC):			$(OBJS)
					@g++ $(LFLAGS) $(OBJS) -o $(BIN)/$(EXEC)

$(OBJ)/main.o:		$(MAIN)
					@g++ $(CFLAGS) -o $@ -c $(SRC)/main.cpp

$(OBJ)/ListaLRU.o:	$(LRU)
					@g++ $(CFLAGS) -o $@ -c $(SRC)/ListaLRU.cpp

run:				$(EXEC)
					@./$(BIN)/$(EXEC)

clean:
					@rm -rf $(OBJ)/*.o $(BIN)/$(EXEC)