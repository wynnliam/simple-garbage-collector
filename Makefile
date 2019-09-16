SRC= ./src/*.c
CMP= gcc
FLG= -g
OUT= ./bin/a.out

.phony: clean

all: $(SRC)
	$(CMP) $(FLG) $(SRC) -o $(OUT)

clean:
	rm ./bin/*.out
