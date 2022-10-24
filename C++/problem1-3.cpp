template<typename T>
void list<T>::meage(list<T> a){
	typename list<T>::Node* p1 = head;
    typename list<T>::Node* p2 = a.head;
	if(this.len() > a.len()){
		// this linked list is bigger
		while(p1 != NULL){
			if(p1->next->elem > p2->next->elem)(
				
			)
		}
	}
	else{
		// other is biggest
		while(p2 != NULL){
			
		}
	}
	
}
template< typename T >
T list<T>::operator[](int pos) {
    typename list<T>::Node *current = new Node;
    int i = 0;

    for(current = head ;current != NULL;current = current->next) {
        if(i == pos) {
            return current->data;
        }
        i++;
    }
	
}