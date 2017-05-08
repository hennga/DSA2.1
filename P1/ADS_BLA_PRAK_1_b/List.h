#ifndef _LIST_H
#define _LIST_H
#include "Node.h"
#include <string>
#include <iostream>

template <class T>
class List 
{
/* 
	Die Klasse List dient zur Verwaltung von Knoten (Node). Mit Hilfe der Klasse List
	kann ein Stapel oder Warteschlange realisiert werden.
*/
private:
	
	int _size;
public:
	Node<T> * head, *tail;
	struct form { std::string start = "<< "; std::string zwischen = ", "; std::string ende = " >>\n"; } _form;
	List();
//	List(List & _List);				// Copy Operator überladen
	~List();
	void InsertFront(T _key);		// Einfügen eines Knotens am Anfang
	void InsertBack(T _key);		// Einfügen eines Knotesn am Ende
	bool getFront(T & _key);		// Entnehmen eines Knoten am Anfang
	bool getBack(T & _key);		// Entnehmen eines Knoten am Ende
	bool del(T _key);			// löschen eines Knotens [key]
	bool search(T _key);			// Suchen eines Knoten
	bool swap(T _key1, T _key2);	// Knoten in der Liste vertauschen
	int size(void);					// Größe der Lise (Anzahl der Knoten)
	bool test(void);				// Überprüfen der Zeigerstruktur der Liste
	void format(const std::string & start, const std::string & zwischen, const std::string & ende);	// Mit der format-Methode kann die Ausgabe gesteuert werden: operator <<
	List<T> & operator = (const List & _List);						// Zuweisungsoperator definieren
	List<T> & operator = (const List * _List);						// Zuweisungsoperator definieren
	List<T> & operator + (const List & List_Append) const;			// Listen zusammenführen zu einer Liste
	List<T> & operator + (const List * List_Append) const;			// Listen zusammenführen zu einer Liste
	template <typename T>
	friend std::ostream & operator << (std::ostream & stream, List const & Liste);		// Ausgabeoperator überladen
	template <typename T>
	friend std::ostream & operator << (std::ostream & stream, List const * Liste);		// Ausgabeoperator überladen
};











template <class T>
List<T>::List()
{
	head = new Node<T>();
	tail = new Node<T>();
	_size = 0;
	head->next = tail;
	tail->prev = head;
}
template <class T>
List<T>::~List()
{
	if (head == nullptr) { return; }
	Node<T>* tmp;
	Node<T>* tmp_to_del;
	tmp = head;
	tmp_to_del = head;

	while (tmp->next != nullptr) {
		tmp_to_del = tmp;
		tmp = tmp_to_del->next;
		delete tmp_to_del;
	}
	delete tmp;
	_size = 0;
}
template <class T>
void List<T>::InsertFront(T _key)
{
	Node<T>* tmp = new Node<T>();
	tmp->key = _key;
	tmp->next = head->next;
	head->next->prev = tmp;
	head->next = tmp;
	tmp->prev = head;
	_size++;

}
template <class T>
void List<T>::InsertBack(T _key)
{
	Node<T>* tmp = new Node<T>();
	tmp->key = _key;
	tmp->next = tail;
	tmp->prev = tail->prev;
	tail->prev->next = tmp;
	tail->prev = tmp;
	_size++;
}
template <class T>
bool List<T>::getFront(T & _key)
{
	Node<T>* it = head->next;
	if (it == nullptr) { return false; }
	_key = it->key;
	if (it->next != nullptr) {
		head->next = it->next;
		it->next->prev = head;
		delete it;
		_size--;
		return true;
	}
	return false;
}

template <class T>
bool List<T>::getBack(T & _key)
{
	Node<T>* it = tail->prev;
	if (it == nullptr) { return false; }
	_key = it->key;

	if (it->prev != nullptr) {
		it->prev->next = tail;
		tail->prev = it->prev;
		delete it;
		_size--;
		return true;
	}

	return false;
}
template <class T>
bool List<T>::del(T _key)
{
	Node<T>* it = head;
	while (it->next != nullptr) {
		if (it->key == _key) { break; }
		if (it->next == nullptr) { return false; }
		if (it->next == tail) { return false; }
		it = it->next;
		if (it == nullptr) { return false; }

	}
	it->prev->next = it->next;
	it->next->prev = it->prev;
	delete it;
	_size--;
	return true;
}

template <class T>
bool List<T>::search(T _key)
{
	Node<T>* it = head;
	while (it->next != nullptr) {
		if (it->key == _key) { return true; }
		if (it->next == nullptr) { return false; }
		if (it->next == tail) { return false; }
		it = it->next;
		if (it == nullptr) { return false; }

	}
	return true;
}

template <class T>
bool List<T>::swap(T _key1, T _key2)
{
	Node<T>* ksp = head;
	Node<T>* k1 = nullptr;
	Node<T>* k2 = nullptr;
	while (ksp->next != nullptr) {
		if (ksp->key == _key1) {
			k1 = ksp;
		}
		if (ksp->key == _key2) {
			k2 = ksp;
		}
		ksp = ksp->next;
	}
	if (k1 != nullptr && k2 != nullptr) {
		int k1v = k1->key;
		int k2v = k2->key;
		k2->key = k1v;
		k1->key = k2v;
		return true;
	}
	return false;
}

template <class T>
int List<T>::size(void)
{

#ifdef COUNT_HT
	return _size + 2; //+head + tail
#else
	return _size;
#endif
}

template <class T>
bool List<T>::test(void)
{
	Node<T>* it = head;
	while (it != tail) {
		if (it == nullptr || it->next == nullptr) { return false; }
		it = it->next;
	}
	it = tail;
	while (it != head) {
		if (it == nullptr || it->prev == nullptr) { return false; }
		it = it->prev;
	}
	return true;
}

template <class T>
void List<T>::format(const std::string & start, const std::string & zwischen, const std::string & ende)
{
	// Setzen der Formatierung f�r den �berladenen Streamingoperator <<
	_form.start = start;			// Ausgabe zu Beginn der Liste
	_form.zwischen = zwischen;		// Ausgabe zwischen zwei Knoten
	_form.ende = ende;				// Ausgabe am Ende der Liste

	std::cout << start;

	Node<T>* it = head->next;
	while (it->next != nullptr) {
		//ähm sys calls ?
		std::cout << it->key << zwischen;
		if (it == nullptr) { break; }
		it = it->next;
	}
	std::cout << ende;
}

template <class T>
List<T> & List<T>::operator = (const List<T>& _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == &_List) return *this;	//  !! keine Aktion notwendig
	Node<T> * tmp_node;
	if (_size)
	{
		Node<T> * tmp_del;
		tmp_node = head->next;
		while (tmp_node != tail)		// Alle eventuell vorhandenen Knoten in this l�schen
		{
			tmp_del = tmp_node;
			tmp_node = tmp_node->next;
			delete tmp_del;
		}
		_size = 0;
		head->next = tail;
		tail->prev = head;
	}
	tmp_node = _List.head->next;
	while (tmp_node != _List.tail)
	{
		InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	return *this;
}

template <class T>
List<T> & List<T>::operator = (const List<T> * _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == _List) return *this;	//  !! keine Aktion notwendig
	Node<T> * tmp_node;
	if (_size)
	{
		Node<T> * tmp_del;
		tmp_node = head->next;
		while (tmp_node != tail)		// Alle eventuell vorhandenen Knoten in this l�schen
		{
			tmp_del = tmp_node;
			tmp_node = tmp_node->next;
			delete tmp_del;
		}
		_size = 0;
		head->next = tail;
		tail->prev = head;
	}
	tmp_node = _List->head->next;
	while (tmp_node != _List->tail)
	{
		InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	return *this;
}

template <class T>
List<T> & List<T>::operator + (const List<T> & List_Append) const
{
	List<T> * tmp = new List;
	Node<T> * tmp_node;
	tmp_node = head->next;
	while (tmp_node != tail) {
		tmp->InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	if (!List_Append._size) return *tmp;
	tmp_node = List_Append.head->next;
	while (tmp_node != List_Append.tail) {
		tmp->InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	return *tmp;
}

template <class T>
List<T> & List<T>::operator + (const List<T> * List_Append) const
{
	List<T> * tmp = new List;
	Node<T> * tmp_node;
	tmp_node = head->next;
	while (tmp_node != tail) {
		tmp->InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	if (!List_Append->_size) return *tmp;
	tmp_node = List_Append->head->next;
	while (tmp_node != List_Append->tail) {
		tmp->InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	return *tmp;
}
template <class T>
std::ostream & operator<<(std::ostream  & stream, List<T> const & Liste)
{
	stream << Liste._form.start;
	for (Node<T>* tmp = Liste.head->next; tmp != Liste.tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste.tail ? Liste._form.ende : Liste._form.zwischen);
	return stream;
}

template <class T>
std::ostream & operator << (std::ostream & stream, List<T> const * Liste)
{
	stream << Liste->_form.start;
	for (Node<T> * tmp = Liste->head->next; tmp != Liste->tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste->tail ? Liste->_form.ende : Liste->_form.zwischen);
	return stream;
}

#endif
