Amos Newswanger
csc 254 A5
Partner: Akihiro Minami

For this project we implemented a smart pointer with tombstones to catch memory
leaks and dangling references. The tombstone pointer has a pointer to the object
that the smart pointer points to.  All pointers that point to the same object
also point to the same tombstone.

Each smart pointer must have a tombstone pointer.
Each tombstone pointer has a bool value that signifies if its object has been freed.
Each tombstone also has a reference count.


Dangling references are caught when the program tries to dereference the
object pointed to by the tombstone but the tombstone is flagged as dead.

Memory leaks are caught whenever a tombstones reference count is decremented to
0, but the tombstone is not pointing to a null value.
