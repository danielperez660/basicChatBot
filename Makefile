
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/main


SRC= main.c hashing.c cmd.c nature.c

# generic build details

CC=      cc
COPT=    -g
CFLAGS= -lm

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE)

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o: main.c hashing.c cmd.c nature.c
hashing.o: hashing.c hashing.h nature.c
cmd.o: cmd.c cmd.h
nature.o: nature.c nature.h 

