SRC1 = lsvector.c
OBJ1 = $(SRC1:.c=.o)
LIB = liblsvector.a

HFILES = lsvector.h

all : $(LIB)

$(LIB) : $(OBJ1)
	ar rcs $(LIB) $(OBJ1)

$(OBJ1) : $(SRC1) $(HFILES)
	gcc -c $(SRC1)

cleanup:
	@echo "Deleting object and executable files..."
	rm $(OBJ1)
	rm $(LIB)

clean:
	@echo "Clean build..."
	@make cleanup
	@make
