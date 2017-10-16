// Griffin Jones
// 10.24.16
// CS 2401 Project 4: Universal List
// dnode header file

#ifndef DNODE_H
#define DNODE_H
#include <cstdlib>
#include <iostream>

template<class T>
class dnode{
public:
	T dlist;
	// Universal constructor
    dnode(const T& init_data = T(), dnode *next = NULL, dnode *prev = NULL) 
    {data_field = init_data; next_field = next; prev_field = prev;}

    // Mutator functions
	void set_data(T& init_data) {data_field = init_data;}
	void set_next(dnode *n) {next_field = n;}
	void set_previous(dnode *p) {prev_field = p;}

    // Accessor functions
    T data() const {return data_field;}
    dnode* next() {return next_field;}
    dnode* previous() {return prev_field;}
	dnode* next() const {return next_field;}
    dnode* previous() const {return prev_field;}

private:
    T data_field;
	dnode *next_field;
	dnode *prev_field;
};

#endif
