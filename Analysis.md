# g++ vs. CppCheck Output

## Compiling with g++

Compiling normally, we get no errors, but a couple of warnings:

- In the swatches.cc file, we get two warnings of using an unsigned integer where the argument specifies using an unsigned long  
- In the iterator.h file, we get one warning for returning a local variable associated with the stack memory  
- In the dlist.template file, we get one warning of using the decrement operator  
- In the main.cc file, we get one warning of requesting dlist<Swatch>::remove

## Running CppCheck

Running CppCheck, we get much more helpful results. It analyzes what is used in the program, and gives tips for eliminating redundancies:

- In dlist, it notes that the "garbage" variable can afford to be reduced in scope  
- In dnode.h, the data_field variable is assigned in the constructor. It could be more efficient if it were initialized in the initialization list.  
- The dlist class doesn't have a copy constructor  
- In iterator.h, the "note_iterator" class has a constructor with a non-explicit argument  
- Like using g++, it also points out a returned string requiring 'unsigned int' that receives an 'unsigned long'  
- It points out that a lot of the functions in the swatches.cc file aren't used
