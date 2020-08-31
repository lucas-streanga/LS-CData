# LS-CData
My library for data structures in C. Currently, `vector` and `list` are implmented.

## Build
A pre-built binary .a file is included. Run `make` to build the library from source. The library can then be statically linked in your projects. Be sure to `include` lsvector.h or lslist.h.

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
memory overhead, making `vector` much lighter than a `list` in the right context.

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
-Pointers to specific elements within a `vector` can be troublesome, as memory location of elements can automatically
change when adding elements. Use `vget()` to always obtain an accurate and up-to-date pointer to `vector` data. Otherwise, `list`
allows static pointers to data.

## List
`list` is a dynamic data structure for C. `list` aims to be easy to use, efficient, safe, and general purpose.

### Features
Similar to `vector`, `list` can grow and shrink dynamically and hold any type of data. In addition, memory allocation is handled by the
`list` and the user does not need to worry about it. `list` also includes a structure for easy traversal, `iterator`. `list` differs from `vector` in a few different ways:

- elements in a `list` will not change location and are not stored sequentially, rather they are linked together. This means pointing
to specific elements in a `list` will not be troublesome.
- `list` is not random access, but is instead forward-moving access only. To avoid inefficient usage, `iterator` is implmented.
- `list` will only ever use as much memory as absolute necessary. `vector` will sometimes allocate more memory than is used to avoid
additional allocations in the future. `list` will not do this and will instead allocate memory as needed.

### Overhead
`list` will use 16 bytes of memory on most 64-bit systems. Each additional element will use another 16 bytes of overhead. An `iterator` will
use 16 bytes of memory as well, but iterators are optional and not part of the `list` structure.

### Summary of Functions
- `lcreate(size_t size_of_each_element)` will return a `list`. Initializes the `list`. Size of each element in the list is passed in.
For example, `sizeof(int)` may be passed in.
- `lempty(list)` will return an `int` on whether the list is empty.
- `lget(list *)` will return an `iterator` for the list passed in. This will initialize the iterator as well.
- `ladd(list *, void *)` will return `void` and will add data to the list. The address of the list should be passed in as well as
a pointer to the data to add. The data will be copied into the list, so this pointer can point to temporary data.
- `ladd_front(list *, void *)` will return `void` and functions the same as `ladd()` but will add an element to the front of the list.
Note this function is more efficient than `ladd()`, especially for larger lists.
- `lsize(list)` will return an `int` corresponding to how many elements are in the list.
- `lat(list *, int index)` will return a `void *` to some data in the list corresponding to the `int` index passed in. This pointer will always
be valid for the entire lifetime of the list, regardless of if elements are added/removed from the list, assuming that this specific element is
not removed. If the index is invalid, `NULL` will be returned. Note: for accessing far-away elements in the list (a large index), using an `iterator` will be more efficient.
- `lremove(list *, int index)` will return `void` and will delete an element in the list corresponding to the `int` index passed in. If the index is invalid, nothing will be deleted.
- `lfree(list *)` will return `void` and will free all data used by a list passed in. This should always be done when a list is no longer in use
to prevent memory leaks.

The following functions are specifically for use with `iterator`:

- `itreset(iterator *)` will return `void` and will reset and iterator to the start of the list it corresponds with. This will give an accurate iterator even if
elements are added to the front of the list, i.e. this will always reset the iterator to the actual start of the list.
- `itnext(iterator *)` will return `void` and will increment the iterator to the next item in the list. This can move the iterator to point to the end of the list,
defined by `ITEND` (`NULL`).
- `lat_iterator(list *, iterator)` will return a `void *` to the element in the list that the iterator corresponds to. If the iterator is pointing to nothing (i.e. ITEND or the list is empty),
`NULL` will be returned.

A for loop using an iterator can be formatted as seen below:
`iterator it = lget(&l);
for(it; it.current != ITEND; itnext(&it))
{
  printf("\nAt interator: %d", *(int *)lat_iterator(&l, it));
}`
