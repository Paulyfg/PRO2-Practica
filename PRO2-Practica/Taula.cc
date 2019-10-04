/** @file Taula.cc
    @brief Código de la clase Taula
*/

#include "Taula.hh"

Taula::Taula() {}

Taula::~Taula() {}

void Taula::sumart() {
    int n;
    cin >> n;
    string p;
    int freq;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        cin >> freq;
        if (taula.count(p) == 0) taula.insert(make_pair(p, freq));
        else  {
           map<string, int>::iterator it = taula.find(p);
           (*it).second += freq;
        }
    }
}

void Taula::llegirt() {
    int n;
    cin >> n; 
    string p;
    int freq;
    for(int i = 0; i < n; ++i) {
        cin >> p;
        cin >> freq;
        taula.insert(make_pair(p, freq));
    }
}

void Taula::escriuret(){
    inici();
    while(not fi()) { 
        cout << (actual()).first << ' ' << (actual()).second << endl;
        avanca();        
    }
}

void Taula::inici() {
    it = taula.begin();
}

void Taula::avanca() {
    ++it;
}

pair<string, int> Taula::actual() const{
    return (*it);
}

bool Taula::fi() const{
    return (it == taula.end());
}
