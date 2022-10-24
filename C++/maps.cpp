#include <iomanip>
#include <string>
#include <map>
#include <utility>
#include "name.hpp"

using namespace std;

pair<const Name, int> get_entry();
void list_entries(map<name, int>& m);
void list_entries(map<Name, int, greater<Name> >& m);

int main(){
    map<Name, int> friend;
    cout << "friend empty: " << (friend.empty() ? "Y" : "N") << endl;
    
    
    friends.insert(make_pair(Name("harry","Potter"), 25));
    friends.insert(make_pair(Name("Draco","Malfoy"), 25));
    friends.insert(make_pair(Name("Cho","Chang"), 10));
    friends.insert(make_pair(Name("Oliver","Wood"), 9));
    friends.insert(make_pair(Name("Fleur","Delacour"), 8));
    friends.insert(make_pair(Name("Cedric","Diggory"), 7));
    friends.insert(make_pair(Name("Fred","Wasley"), 6));
    friends.insert(make_pair(Name("George","Wesley"), 6));
    friends.insert(make_pair(Name("Neville","Longbottom"), 5));
    friends.insert(make_pair(Name("luna","Lovegood"), 4));
    friends.insert(make_pair(Name("Rubeus","Hagrid"), 3));
    friends.insert(make_pair(Name("Hermione","Granger"), 2));
    friends.insert(make_pair(Name("Ron","Weasley"), 1));
    
    
    cout << end << "initial contents of friend[" << friends. size() << "]" << endl;
    list_entries(friends2);
    
    map<Name, int> friend_copy(friends);
    
    cout << "inital content of friends copy is: " << friend_copy.size() << endl;
    
    list_entries(friend_copy);
    friend_copy.clear();
    cout << "cleaerd friends copy: " << friend_copy.size() << endl;
    
    //list_entries;
    
    char answer = 'y';
    cout << endl << endl << "adding an entrie";
    
    while(answer = 'y'){
        pair<const Name, int> entry = get_entry()
    }
    
}



pair<const


pair<const Name, int> get_entry() {
    
}

void list_entries(map<Name, int>& m){
    for(map<Name, int>::iterator it = m.begin(); it != m.end(); ++it){
        cout << left << setw(30) << it->first << right << setw(4) << it->second << endl;
    }
    cout << endl << endl;
}

void list_entries(map<Name, int, greater<name> > & m){
    
}
