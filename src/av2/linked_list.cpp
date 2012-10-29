#include <iostream>
#include <stdlib.h>
using namespace std;

class Node {
	Node *_right;
public:
	Node(Node *right = NULL) :
		_right(right) {
	}
	Node(const Node &val) :
		_right(val._right) {
	}
	const Node *right() const {
		return _right;
	}
	Node *&right() {
		return _right;
	}
	Node &operator =(const Node &val) {
		_right = val._right;
		return *this;
	}
	const int operator ==(const Node &val) const {
		return _right == val._right;
	}
	const int operator !=(const Node &val) const {
		return !(*this == val);
	}
};

template<typename T>
class DataNode: public Node {
	T _data;
public:
	DataNode(const T data, DataNode *right = NULL) :
		Node(right), _data(data) {
	}
	DataNode(const DataNode &val) :
		Node(val), _data(val._data) {
	}
	const DataNode *right() const {
		return ((DataNode *) Node::right());
	}
	DataNode *&right() {
		return ((DataNode<T> *&) Node::right());
	}
	const T &data() const {
		return _data;
	}
	T &data() {
		return _data;
	}
	DataNode &operator =(const DataNode &val) {
		Node::operator =(val);
		_data = val._data;
		return *this;
	}
	const int operator ==(const DataNode &val) const {
		return (Node::operator ==(val) && _data == val._data);
	}
	const int operator !=(const DataNode &val) const {
		return !(*this == val);
	}
};

template<typename T>
class ListBase {
public:
	virtual ~ListBase() {
	} // Force destructor to be virtual
	virtual void flush() = 0; // gi brise site elementi od listata
	virtual void putInFront(const T data) = 0; // dodava element na pocetokot na listata
	virtual void append(const T data) = 0; // dodava element na krajot na listata
	virtual void delFromFront() = 0;
	virtual const T &getFirst() const = 0; // zemanje na vrednosta na prviot element od listata
	virtual T &getFirst() = 0;
	virtual const T &getLast() const = 0; // zemanje na vrednosta na posledniot element od listata
	virtual T &getLast() = 0;
	virtual bool isEmpty() const = 0; // dali e prazna
};

template<typename T>
class List: public ListBase<T> {
	DataNode<T> *_head, *_tail;
public:
	List() :
		_head(NULL), _tail(NULL) {
	}
	List(const List &val) :
		_head(NULL), _tail(NULL) {
		*this = val;
	}
	virtual ~List() {
		flush();
	}
	virtual void flush();
	virtual void putInFront(const T data);
	virtual void append(const T data);
	virtual void delFromFront();
	virtual const T &getFirst() const {
		return _head->data();
	}
	virtual T &getFirst() {
		return _head->data();
	}
	virtual const T &getLast() const {
		return _tail->data();
	}
	virtual T &getLast() {
		return _tail->data();
	}
	virtual bool isEmpty() const {
		return _head == NULL;
	}
	List &operator =(const List &);
	bool operator ==(const List &) const;
	bool operator !=(const List &val) const {
		return !(*this == val);
	}
	template<typename X> friend class ListIterator;
};

template<typename T>
List<T> &List<T>::operator =(const List<T> &val) {
	flush();
	DataNode<T> *walkp = val._head;
	for (; walkp; walkp = walkp->right())
		append(walkp->data());
	return *this;
}
;

template<typename T>
bool List<T>::operator ==(const List<T> &val) const {
	if (isEmpty() && val.isEmpty())
		return 1;
	DataNode<T> *thisp = _head, *valp = val._head;
	while (thisp && valp) {
		if (thisp->data() != valp->data())
			return 0;
		thisp = thisp->right();
		valp = valp->right();
	}
	return 1;
}
;

template<typename T>
void List<T>::append(const T data) {
	if (!_tail)
		_tail = _head = new DataNode<T> (data, NULL);
	else {
		_tail->right() = new DataNode<T> (data, NULL);
		_tail = _tail->right();
	}
} /* append */

template<typename T>
void List<T>::delFromFront() {
	if (_head) {
		DataNode<T> *p = _head;
		_head = _head->right();
		delete p;
	} else {
		cerr << "ERROR: Can not delFromFront of a empty list!" << endl;
		exit(-1);
	}
}

template<typename T>
void List<T>::flush() {
	while (_head) {
		_tail = _head->right();
		delete _head;
		_head = _tail;
	}
}
;

template<typename T>
void List<T>::putInFront(const T data) {
	_head = new DataNode<T> (data, _head);
	if (!_tail)
		_tail = _head;
} /* putInFront */

template<typename Data, typename Element>
class Iterator {
protected:
	Element _start, _current;
public:
	Iterator(const Element start) :
		_start(start), _current(start) {
	}
	Iterator(const Iterator &val) :
		_start(val._start), _current(val._current) {
	}
	virtual ~Iterator() {
	}
	virtual const Data current() const = 0;
	virtual void succ() = 0;
	virtual bool terminate() const = 0;
	virtual void rewind() {
		_current = _start;
	}
	Iterator &operator =(const Iterator &val) {
		_start = val._start;
		_current = val._current;
		return *this;
	}
	Iterator &operator =(const Element &eval) {
		_start = _current = eval;
		return *this;
	}
	const int operator ==(const Iterator &val) const {
		return (_start == val._start && _current == val._current);
	}
	const int operator !=(const Iterator &val) const {
		return !(*this == val);
	}
};

template<typename T>
class ListIterator: public Iterator<T, DataNode<T> *> {
public:
	ListIterator(const List<T> &list) :
		Iterator<T, DataNode<T> *> (list._head) {
	}
	ListIterator(const ListIterator &val) :
		Iterator<T, DataNode<T> *> (val) {
	}
	virtual const T current() const {
		return Iterator<T, DataNode<T> *>::_current->data();
	}
	virtual void succ() {
		Iterator<T, DataNode<T> *>::_current
				= Iterator<T, DataNode<T> *>::_current->right();
	}
	virtual bool terminate() const {
		return Iterator<T, DataNode<T> *>::_current == NULL;
	}
	T &operator ++(int) {
		T &tmp = Iterator<T, DataNode<T> *>::_current->data();
		succ();
		return tmp;
	}
	ListIterator &operator =(const ListIterator &val) {
		Iterator<T, DataNode<T> *>::operator =(val);
		return *this;
	}
};

int main() {
	List<int> list;
	for (int i = 1; i < 10; i++) {
		list.append(i);
	}
	ListIterator<int> iter(list);
	while (!iter.terminate()) {
		cout << iter.current() << ' ';
		iter.succ();
	}
	cout << endl;

	list.putInFront(0);
	iter.rewind(); //	iter=list;
	list.append(10);
	while (!iter.terminate())
		cout << iter++ << ' ';
	cout << endl;

	return 0;
}
