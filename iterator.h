// Griffin Jones
// 10.24.16
// CS 2401 Project 4: Universal List
// iterator classe

template <class T>
class dlist;

template <class T>
class node_iterator
: public std::iterator<std::forward_iterator_tag, T>
{
public:
	friend class dlist<T>;
	node_iterator(dnode<T>* init = NULL) { current = init; }

	T operator *() const { return current -> data(); }
	
	node_iterator& operator ++() 
	{
		current = current -> next(); 
		return *this;
	}
	
	node_iterator operator ++(int)
	{
		node_iterator original(current);
		current = current -> next();
		return original;
	}
	
	node_iterator& operator --()
	{
		current = current -> previous();
		return *this;
	}

	node_iterator& operator --(int)
	{
		node_iterator original(current);
		current = current -> previous();
		return original;
	}

	bool operator ==(const node_iterator other) const
	{
		return current == other.current;
	}

	bool operator !=(const node_iterator other) const
	{
		return current != other.current;
	}

private:
	dnode<T>* current;

};