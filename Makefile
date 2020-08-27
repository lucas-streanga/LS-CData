SRC1 = lsvector.c
SRC2 = lslist.c
SRC3 = lsstring.c
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJ3 = $(SRC3:.c=.o)
LIB = liblsdata.a
TESTPROGSRC = testprogram.c
TESTPROGOBJ = $(TESTPROGSRC:.c=.o)
TESTPROG = testprogram

HFILES = lsvector.h lslist.h lsstring.h

all : $(LIB)

$(LIB) : $(OBJ1) $(OBJ2) $(OBJ3)
	ar rcs $(LIB) $(OBJ1) $(OBJ2) $(OBJ3)

$(OBJ1) : $(SRC1) $(HFILES)
	gcc -g -c $(SRC1)

$(OBJ2) : $(SRC2) $(HFILES)
	gcc -g -c $(SRC2)

$(OBJ3) : $(SRC3) $(HFILES)
	gcc -g -c $(SRC3)

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
	@make
	gcc -g -c $(TESTPROGSRC)
	gcc -o $(TESTPROG) $(TESTPROGOBJ) $(OBJ1) $(OBJ2) $(OBJ3)
	@make cleanup
