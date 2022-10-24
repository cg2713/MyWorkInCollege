#include <iostream>
#include <string>
#include "scores1.hpp"


using namespace std;

int main(){
    GameEntry* e1 = new GameEntry("alic", 100);
    GameEntry* e1 = new GameEntry("bob", 110);
    GameEntry* e1 = new GameEntry("oscar", 99);
    
    Scores s(5);
    s.add(*e1);
    s.add(*e2);
    s.add(*e3);
    s.add(GameEntry("john", 109));
    s.add(GameEntry("pete", 190));
    
    cout << "hall of fame: " << s << endl << endl;
    
    s.add(GameEntry("Danial", 105));
    s.add(GameEntry("George", 100));
    
    cout << "hall of fame: " << s << endl << endl;
    
    s.remove(0);
    s.remove(6);
    
    delete e1;
    delete e2;
    delete e3;
    
}

class GameEntry{
private:
    std::string name;
    int score;
public:
    GameEntry(const std::string& n="", int s=0);
    std::string getNmae() const;
    int getScore const;
    friend std::ostream& operator<<(std::ostream& out, const GameEntry& obj):
};

inline GameEntry::GameEntry(const std::string& n, int s) : name(n), score(s) {}

    
class Scores {
private:
    int maxEntries;
    int numEntries;
    
    GameEntry* entries;
public:
    Scores(int maxent=10);
    ~Scores();
    void add(const GameEntry& e);
    GameEntry remove(int i);
    GameEntry& operator[](size_t i);
    friend std::ostream& operator<<(std::ostream& out, const Scores& obj);
};

Scores::Scores(int maxent) {
        
}

