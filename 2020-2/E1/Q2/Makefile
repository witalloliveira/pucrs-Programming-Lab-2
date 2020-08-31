EXEC = app

SRC = src
OBJ = obj
BIN = bin

MAIN = $(SRC)/main.cpp
OBJS = $(OBJ)/main.o

CFLAGS = -std=c++11 -Wall
LFLAGS = -std=c++11

all:				$(EXEC)

$(EXEC):			$(OBJS)
					@g++ $(LFLAGS) $(OBJS) -o $(BIN)/$(EXEC)

$(OBJ)/main.o:		$(MAIN)
					@g++ $(CFLAGS) -o $@ -c $(SRC)/main.cpp

run:				$(EXEC)
					@./$(BIN)/$(EXEC)

clean:
					@rm -rf $(OBJ)/*.o $(BIN)/$(EXEC)