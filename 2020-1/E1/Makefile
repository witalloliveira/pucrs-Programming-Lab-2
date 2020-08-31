EXEC = app

SRC = src
HEADER = header
OBJ = obj
BIN = bin

MAIN = $(SRC)/main.cpp $(HEADER)/Conta.hpp $(HEADER)/Banco.hpp
BANCO = $(SRC)/Banco.cpp $(HEADER)/Banco.hpp $(HEADER)/Conta.hpp
CONTA = $(SRC)/Conta.cpp $(HEADER)/Conta.hpp

OBJS = $(OBJ)/main.o $(OBJ)/Banco.o $(OBJ)/Conta.o

CFLAGS = -std=c++11 -Wall
LFLAGS = -std=c++11

all:			$(EXEC)

$(EXEC):		$(OBJS)
				@g++ $(LFLAGS) $(OBJS) -o $(BIN)/$(EXEC)

$(OBJ)/main.o:	$(MAIN)
				@g++ $(CFLAGS) -o $@ -c $(SRC)/main.cpp

$(OBJ)/Banco.o:	$(BANCO)
				@g++ $(CFLAGS) -o $@ -c $(SRC)/Banco.cpp

$(OBJ)/Conta.o:	$(CONTA)
				@g++ $(CFLAGS) -o $@ -c $(SRC)/Conta.cpp

run:			$(EXEC)
				@./$(BIN)/$(EXEC)

clean:
				@rm -f $(OBJS) $(BIN)/$(EXEC)