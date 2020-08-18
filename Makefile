SRC1 = lsvector.c
OBJ1 = $(SRC1:.c=.o)
LIB = liblsdata.a

HFILES = lsvector.h

all : $(LIB)

$(LIB) : $(OBJ1)
	ar rcs $(LIB) $(OBJ1)

$(OBJ1) : $(SRC1) $(HFILES)
	gcc -c $(SRC1)

cleanup:
	@echo "Deleting object and executable files..."
	rm $(OBJ1)

clean:
	@echo "Clean build..."
	rm $(LIB)
	@make cleanup
	@make

full-rebuild:
	@echo "Full Rebuild..."
	@make clean
	@make cleanup
