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

# Analyzing doxygen and CppCheck

## Analyzing CppCheck with doxygen

It really puts the tiny project that I did for my CS 2401 class into perspective just how exponentially more complicated these larger projects become. Doxygen certainly makes it easier to understand, explaining and showing the connections between all of the files and classes. It automates the process of understanding a project, so adding a new programmer to a team isn't as big of a liability.

## Analyzing doxygen with CppCheck

Analyzing doxygen, it's a little humbling to know that even widely used, professional, open source products like doxygen still spit out a bunch of warnings and tips when looked at by Cppcheck. Granted, there's not nearly as many considering the very large number of files used to create a tool like doxygen, which is clearly the result of hundreds of thousands of hours programmers all around the world have contributed to keeping this project alive so that everybody can use it. I think that's very nice.
