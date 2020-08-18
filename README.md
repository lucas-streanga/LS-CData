# LS-CData
My library for data structures in C. Currently, only `vector` is implemented.

## Build
Run `make` to build the library from source. The library can then be statically linked in your projects. Be sure to `include` lsvector.h.

## Vector
`vector` is a dynamic data structure for C. Vector aims to be efficient, easy to use,
safe, and most importantly, general purpose.

### Features
`vector` allows use with any data, including complex user-defined data such as structs.
Vectors will automatically resize when necessary. The user does not have to worry about
making any memory allocation calls when using `vector`. `vector` allows:

- Any type of data to be used.
- Adding items to the front or back of the vector.
- Deleting items by index.
- Changing items in the vector by index.
- Accessing data using array notation, or
- Accessing data using a safer at function.

### Overhead
`vector` will use 24 bytes of memory on most 64-bit systems. This memory is used for
critical data for a vector. Each additional item added to a `vector` will not use any
memory overhead, making `vector` much lighter than a linked list.

### Summary of Functions
- `vcreate(size_t size_of_each_element)` will return a `vector`. Initializes the vector. Size of each
element in the vector must be passed in. For example, for an integer vector, `sizeof(int)` may be passed in.
-  `vget(vector)` will return a pointer to the data in the vector. NOTE: this data should always be cast to whatever
data your vector stores. For example: `int * int_data = (int *) vget(our_vector);`. Using vget allows array notation
to be used on the vector data. Vget should be called before accessing data, as data can be relocated as more items are added.
- `vadd(vector *, void * data)` will return void and will add data to the vector. Pointer to your vector must be passed in as
well as pointer to data. This can result in the vector being reallocated. For safety purposes, only the specified size given with `vcreate` will be used. This prevents data
destruction and/or undefined behavior if some other type of data is attempted to be added.
- `vadd_front(vector *, void * data)` is the same as `vadd` but will add data to the front of the vector. This can also
result in memory reallocation.
- `vsize(vector)` will return an `int` of how many items are in the vector. Useful for `for` loops.
- `vremove(vector *, int index)` will return an `int` and will remove an item at an index. A pointer to a `vector` must be
passed in as well as an `int` index. A `0` will be returned if the removal is unsuccessful due to an invalid index. A `1` will
be returned if the removal is successful. Note that this will move vector data to fill in the gap, keeping the vector contiguous.
- `vset(vector *, int index, void * data)` will return an `int` and will change an element in the vector at the index. A `vector`
pointer must be passed in as well an `int` index to be changed and a void pointer to data to be added. Will return `0` if the
change is unsuccessful due to an invalid index, and a `1` if the change is successful.
- `vat(vector *, int index)` will return a `void *` to the data at an index in the vector. A `vector` pointer must be passed in
as well as an `int` index. As opposed to the operator `[]`, this will always return either a valid pointer or `NULL`, preventing
undesirable events like segmentation faults. If the index is invalid, `NULL` will be returned.
- `vfree(vector *)` will return `void` and will clear memory used by the vector passed in. This should always be called once a vector is done being used to prevent memory leaks.

### Memory
`vector` will handle memory management for your data. Just be sure to call `vfree` once a vector is no longer useful or is about to
go out of scope to prevent memory leaks.

### Notes
- `vector` defaults to a size of 5 elements. This is defined in `lsvector.h`.
-  When `vector` reaches its max size, it will resize to twice the previous max size. The data location may or may not change.  
