CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/fatorial.o $(OBJ)/fibonacci.o
HDRS = $(INC)/fatorial.h $(INC)/fibonacci.h $(INC)/msgassert.h
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/run

run:  $(EXE)
	$(EXE) -t 1
	$(EXE) -t 2
	$(EXE) -t 3
	$(EXE) -t 4
	$(EXE) -t 5
	$(EXE) -t 6
	$(EXE) -t 7
	$(EXE) -t 8
	$(EXE) -t 9
	$(EXE) -t 10
	$(EXE) -t 11
	$(EXE) -t 12
	$(EXE) -t 13
	$(EXE) -t 14
	$(EXE) -t 15
	$(EXE) -t 16
	$(EXE) -t 17
	$(EXE) -t 18
	$(EXE) -t 19
	$(EXE) -t 20

	$(EXE) -b 1
	$(EXE) -b 2
	$(EXE) -b 3
	$(EXE) -b 4
	$(EXE) -b 5
	$(EXE) -b 6
	$(EXE) -b 7
	$(EXE) -b 8
	$(EXE) -b 9
	$(EXE) -b 10
	$(EXE) -b 11
	$(EXE) -b 12
	$(EXE) -b 13
	$(EXE) -b 14
	$(EXE) -b 15
	$(EXE) -b 16
	$(EXE) -b 17
	$(EXE) -b 18
	$(EXE) -b 19
	$(EXE) -b 20

$(BIN)/run: $(OBJS)
	$(CC) -o $(BIN)/run $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/fatorial.o: $(HDRS) $(SRC)/fatorial.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/fatorial.o $(SRC)/fatorial.cpp 

$(OBJ)/fibonacci.o: $(HDRS) $(SRC)/fibonacci.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/fibonacci.o $(SRC)/fibonacci.cpp 

clean:
	rm -f $(EXE) $(OBJS) gmon.out
