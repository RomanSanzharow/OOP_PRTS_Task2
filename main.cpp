#include <iostream>
using std::cout;
using std::endl;

template<typename Q>
struct node{
	Q data;
	node* nextptr;
	node* prevptr;
};

template<typename Q>
class List{
	node<Q>* first;
	node<Q>* last;
	int l_size;
public:
	List();
	//List(const List&);
	void Add(const Q &value);
	void Del();
	void Show();
	void Swap(node<Q> &node1, node<Q> &node2);
	void Sort();
	~List();
};

template<typename Q>
List<Q>::List(){
	first = nullptr;
	last = nullptr;
	l_size = 0;
}

template<typename Q>
List<Q>::~List(){
	node<Q>* tmp;
	while (first){
		tmp = first;
		first = first->nextptr;
		delete tmp;
	}
	l_size = 0;
}

template<typename Q>
void List<Q>::Add(const Q &value){
	auto* newnode = new node<Q>;
	newnode -> data = value;
	newnode -> prevptr = last;
	if (first == nullptr) first = newnode;
	if (last != nullptr) last -> nextptr = newnode;
	l_size++;
	last = newnode;
}

template<typename Q>
void List<Q>::Show(){
	node<Q>* tmp;
	tmp = first;
	while (tmp){
		cout << tmp -> data << endl;
		tmp = tmp -> nextptr;
	}
}

template<typename Q>
void List<Q>::Del(){
	if (last == nullptr) return;
	node<Q>* tmp = last;
	last = last -> prevptr;
	if (last != nullptr) last -> nextptr = nullptr;
	l_size--;
	delete tmp;
}

template<typename Q>
void List<Q>::Swap(node<Q> &node1, node<Q> &node2){
	std::swap(node1.data, node2.data);
    std::swap(node1.nextptr, node2.nextptr);
    std::swap(node1.prevptr, node2.prevptr);
}

template<typename Q>
void List<Q>::Sort(){
	node<Q>* left = first;
    node<Q>* right = first->nextptr;

    auto* tmp = new node<Q>;
    while (left->nextptr) {
        while (right) {
            if ((left->data) > (right->data)) {
                tmp->data = left->data;
                left->data = right->data;
                right->data = tmp->data;
            }
            right = right->nextptr;
        }
        left = left->nextptr;
        right = left->nextptr;
    }
}

int main(){
	List<float> spisok;
	spisok.Add(4.4);
	spisok.Add(3.3);
	spisok.Add(2.2);
	spisok.Add(1.1);
	spisok.Add(0.0);
	spisok.Del();
	spisok.Show();
	spisok.Sort();
	spisok.Show();
	system("pause");
	return 0;
}
