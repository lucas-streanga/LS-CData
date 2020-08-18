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
	@echo "Deleting object and executable files..."
	rm *.o

clean:
	@echo "Clean build..."
	rm $(LIB)
	@make cleanup
	@make

full-rebuild:
	@echo "Full Rebuild..."
	@make clean
	@make cleanup

testprogram: $(TESTPROGSRC) $(LIB)
	@echo "Building test program..."
	gcc -o $(TESTPROG) $(TESTPROGSRC) $(LIB)
