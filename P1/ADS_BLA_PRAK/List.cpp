#include "List.h"
#define PERF

List::List()
{
	head = new Node;
	tail = new Node;
	_size = 0;
	head->next = tail;
	tail->prev = head;
}
List::~List()
{
 if(head == nullptr){return;}
    Node* tmp;
    Node* tmp_to_del;
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
void List::InsertFront(int _key)
{
 Node* tmp = new Node();
    tmp->key = _key;
    tmp->next = head->next;
    head->next->prev = tmp;
    head->next = tmp;
    tmp->prev = head;
    _size++;
    
}
void List::InsertBack(int _key)
{
  Node* tmp = new Node();
    tmp->key = _key;
    tmp->next = tail;
    tmp->prev = tail->prev;
    tail->prev->next = tmp;
    tail->prev = tmp;
    _size++;
}
bool List::getFront(int & _key)
{
   Node* it = head->next;
    if(it == nullptr){return false;}
    _key = it->key;
    if(it->next != nullptr){
        head->next = it->next;
        it->next->prev = head;
        delete it;
        _size--;
        return true;
    }
    return false;
}
bool List::getBack(int & _key)
{
    Node* it = tail->prev;
    if(it == nullptr){return false;}
    _key = it->key;
    
    if(it->prev != nullptr){
        it->prev->next = tail;
        tail->prev = it->prev;
        delete it;
        _size--;
         return true;
    }
 
    return false;
}
bool List::del(int _key)
{
    Node* it = head;
    while (it->next != nullptr) {
        if(it->key == _key){break;}
        if(it->next == nullptr){return false;}
        if(it->next == tail){return false;}
        it = it->next;
        if(it == nullptr){return false;}
        
    }
    it->prev->next = it->next;
    it->next->prev = it->prev;
    delete it;
    _size--;
    return true;
}
bool List::search(int _key)
{
    Node* it = head;
    while (it->next != nullptr) {
        if(it->key == _key){return true;}
        if(it->next == nullptr){return false;}
        if(it->next == tail){return false;}
        it = it->next;
        if(it == nullptr){return false;}

    }
    return true;
}

bool List::swap(int _key1, int _key2)
{
    Node* ksp = head;
    Node* k1 = nullptr;
    Node* k2 = nullptr;
    while (ksp->next != nullptr) {
        if(ksp->key == _key1){
            k1 = ksp;
        }
        if(ksp->key == _key2){
            k2 = ksp;
        }
         ksp = ksp->next;
    }
    if(k1 != nullptr && k2 != nullptr){
        int k1v = k1->key;
        int k2v = k2->key;
        k2->key = k1v;
        k1->key = k2v;
        return true;
    }
    return false;
}
int List::size(void)
{
    
#ifdef COUNT_HT
	return _size + 2; //+head + tail
#else
    return _size;
#endif
}


bool List::test(void)
{
    Node* it = head;
    while (it != tail) {
        if(it == nullptr || it->next == nullptr){return false;}
        it = it->next;
    }
    it = tail;
    while (it != head) {
        if(it == nullptr || it->prev == nullptr){return false;}
        it = it->prev;
    }
    return true;
}
void List::format(const std::string & start, const std::string & zwischen, const std::string & ende)
{
	// Setzen der Formatierung f�r den �berladenen Streamingoperator <<
	_form.start = start;			// Ausgabe zu Beginn der Liste
	_form.zwischen = zwischen;		// Ausgabe zwischen zwei Knoten
	_form.ende = ende;				// Ausgabe am Ende der Liste
    
    std::cout << start ;
    
    Node* it = head->next;
    while (it->next != nullptr) {
        //ähm sys calls ?
        std::cout << it->key << zwischen;
        if(it == nullptr){break;}
        it = it->next;
    }
    std::cout << ende;
}
List & List::operator = (const List & _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == & _List) return *this;	//  !! keine Aktion notwendig
	Node * tmp_node;
	if (_size)
	{
		Node * tmp_del;
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
List & List::operator = (const List * _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == _List) return *this;	//  !! keine Aktion notwendig
	Node * tmp_node;
	if (_size)
	{
		Node * tmp_del;
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
	return * this;
}
List & List::operator + (const List & List_Append) const
{
	List * tmp = new List;
	Node * tmp_node;
	tmp_node = head->next;
	while (tmp_node != tail){
		tmp->InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	if (!List_Append._size) return * tmp;
	tmp_node = List_Append.head->next;
	while (tmp_node != List_Append.tail){
		tmp->InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	return * tmp;
}
List & List::operator + (const List * List_Append) const
{
	List * tmp = new List;
	Node * tmp_node;
	tmp_node = head->next;
	while (tmp_node != tail){
		tmp->InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	if (!List_Append->_size) return *tmp;
	tmp_node = List_Append->head->next;
	while (tmp_node != List_Append->tail){
		tmp->InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	return *tmp;
}
std::ostream & operator<<(std::ostream  & stream, List const & Liste)
{
	stream << Liste._form.start;
	for (Node * tmp = Liste.head->next; tmp != Liste.tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste.tail ? Liste._form.ende : Liste._form.zwischen);
	return stream;
}
std::ostream & operator << (std::ostream & stream, List const * Liste)
{
	stream << Liste->_form.start;
	for (Node * tmp = Liste->head->next; tmp != Liste->tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste->tail ? Liste->_form.ende : Liste->_form.zwischen);
	return stream;
}
