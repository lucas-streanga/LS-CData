SRC1 = lsvector.c
SRC2 = lslist.c
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
LIB = liblsdata.a
TESTPROGSRC = testprogram.c
TESTPROG = testprogram

HFILES = lsvector.h lslist.h

all : $(LIB)

$(LIB) : $(OBJ1) $(OBJ2)
	ar rcs $(LIB) $(OBJ1) $(OBJ2)

$(OBJ1) : $(SRC1) $(HFILES)
	gcc -c $(SRC1)

$(OBJ2) : $(SRC2) $(HFILES)
	gcc -c $(SRC2)

cleanup:
	@echo "Deleting object files..."
	rm -f *.o

full-cleanup:
	@echo "Deleting executable and object files"
	rm -f *.o
	rm -f $(EXE)

clean:
	@echo "Clean build..."
	@make full-cleanup
	@make
	@make cleanup

testprogram: $(TESTPROGSRC)
	@echo "Building test program..."
	@make clean
	gcc -o $(TESTPROG) $(TESTPROGSRC) $(LIB)
