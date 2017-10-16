// Griffin Jones
// 10.24.16
// CS 2401 Project 4: Universal List
// dlist header file

#include <cstdlib>
#include <iostream>
#include "dnode.h"
#include "iterator.h"

template <class T>
class dlist
{
public:
	typedef node_iterator<T> iterator;

	// Default + Big 3
	dlist();
	~dlist();
	dlist(const T& other);
	T& operator = (const T& other);

	// Size and Show
	int size();
	void show();
	void reverse_show();

	// Insert and Remove
	void front_insert(T& thing);
	void rear_insert(T& thing);
	void front_remove();
	void rear_remove();

	// Iterator Controllers
	iterator begin() { return iterator(head -> next()); }
	iterator end() { return iterator(tail); }
	iterator r_begin() { return iterator(tail -> previous()); }
	iterator r_end() { return iterator(head); }
	void insert_before(iterator it, T& thing);
	void insert_after(iterator it, T& thing);
	void remove(iterator it);

private:
	dnode<T>* head;
	dnode<T>* tail;
};

#include "dlist.template"
