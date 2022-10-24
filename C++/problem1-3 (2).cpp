/*template<typename T>
void list<T>::meage(list<T> a){
	typename list<T>::Node* p1 = head;
    typename list<T>::Node* p2 = a.head;
	
    for(int i = 0; i <= len(); i++){
        for(int j = 0; j <= a.len(); j++){
            if(p1->elem > a[j]){
               p2 = p1->next;
            }
            p2 = p2->next;
        }
        p2 = a.head;
        p1 = p1->next;
    }
}
*/

template<typename T>
Node* merge(Node* h1, Node* h2) 
{ 
    if (!h1) 
        return h2; 
    if (!h2) 
        return h1; 
  
    // start with the linked list 
    // whose head data is the least 
    if (h1->elem < h2->elem) { 
        h1->next = merge(h1->next, h2); 
        return h1; 
    } 
    else { 
        h2->next = merge(h1, h2->next); 
        return h2; 
    } 
} 
  
