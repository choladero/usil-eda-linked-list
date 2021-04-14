#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

// #include
// #include <vector>
// using namespace std;

template <typename T>
class LinkedList
{
  private:
  // members here
  public:
    T front(); // Retorna el elemento al comienzo
    T back(); // Retorna el elemento al final
    void push_front(T &elem); // Agrega un elemento al comienzo 
    void push_back(T &elem); // Agrega un elemento al final
    void pop_front(); // Remueve el elemento al comienzo pero no lo retorna
    void pop_back(); // Remueve el elemento al final pero no lo retorna
    T operator[](size_t pos); // Retorna el elemento en la posición indicada
    bool empty(); // Retorna si la lista está vacía o no
    size_t size(); // Retorna el tamaño de la lista 
    void clear(); // Elimina todos los elementos de la lista
    void sort(); // Ordena la lista
    void reverse(); // Revierte la lista
};

// Comments #2
template <typename T>
void LinkedList<T>::front(T &elem)
{

// Comments #3
{
template <class T>
class LinkedList {
	public:
		LinkedList() : size_(0), begin_(NULL), end_(NULL) {} 
		LinkedList(const LinkedList& other);
	
		~LinkedList();

		LinkedList<T> operator=(const LinkedList& other);

		T front() { return *begin_; }
		T front() const { return *begin_; }
	
		T back() { return *end_; }
		T back() const { return *end_; }
	
		ListIterator<T> begin();
		ListIterator<T> end();

		void push_back(const T&);
		void pop_back();
		
		void push_front(const T&);
		void pop_front();
		
		void insert(ListIterator<T>, const T&);

	private:
		ListNode<T>* begin_;
		ListNode<T>* end_;
		int size_;

};

template <class T>
ListIterator<T> LinkedList<T>::end() {
	ListIterator<T> e(end_);
	return e;
}

template <class T>
ListIterator<T> LinkedList<T>::begin() {
	ListIterator<T> t(begin_);
	return t;
}

template <class T>
LinkedList<T>::~LinkedList() {
	ListNode<T>* ptr = begin_;
	while ( ptr->next != NULL ) {
		ptr = ptr->next;
		delete ptr->prev;
	}
	delete ptr;
}

template <class T>
LinkedList<T> LinkedList<T>::operator=(const LinkedList& other) {
	ListNode<T>* ptr;
	LinkedList<T> new_list;

	for ( ptr = other.begin_; ptr != NULL; ptr = ptr->next ) {
        new_list.push_back(*ptr);
    }
	return new_list;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList& other) {
	ListNode<T>* ptr;
	for ( ptr = other.begin_ ; ptr != NULL; ptr = ptr->next ) {
		push_back(*ptr);
	}
}

template <class T>
void LinkedList<T>::insert(ListIterator<T> ptr, const T& element) {
	ListNode<T>* new_node = new ListNode<T>;

	new_node->element = element;
	
	new_node->prev = ptr->prev;
	ptr->prev->next = new_node;
	new_node->next = ptr;
	ptr->prev = new_node;
	
	size_++;
}	

template <class T>
void LinkedList<T>::push_front(const T& element) {
	ListNode<T>* new_node = new ListNode<T>;
	new_node->element = element;
	new_node->next = begin_;
	new_node->prev = NULL;

	if (begin_ == NULL) {
		begin_ = new_node;
	} else {
		begin_->prev = new_node;
		begin_ = new_node;
	}
	
	if ( end_ == NULL ) {
		end_ = new_node;
	}
	
	size_++;
}

template <class T>
void LinkedList<T>::pop_front() {
	size_--;
	begin_ = begin_->next;
	delete begin_->prev;
	begin_->prev = NULL;
}

template <class T>
void LinkedList<T>::push_back(const T& element) {
	ListNode<T>* new_node = new ListNode<T>;
	new_node->element = element;		
	new_node->prev = end_;
	new_node->next = NULL;

	if ( end_ == NULL ) {
		end_ = new_node;
	} else {
		end_->next = new_node;
		end_ = new_node;
	}

	if ( begin_ == NULL ) {
		begin_ = new_node;
	}

	size_++;
}

template <class T>
void LinkedList<T>::pop_back() {
	size_--;
	end_ = end_->prev;
	delete end_->next;
	end_->next = NULL;
}

#endif
