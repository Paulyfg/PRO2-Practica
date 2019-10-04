/** @file Treecode.cc
    @brief Código de la clase Treecode
*/

#include "Treecode.hh"

bool operator<(const BinTree<pair<string, int> >& a1, const BinTree<pair<string, int> >& a2) {
  if ( (a1.value()).second == (a2.value()).second ) return (a1.value()).first < (a2.value()).first;
 else return (a1.value()).second < (a2.value()).second;
}

Treecode::Treecode() {}

Treecode::~Treecode() {}

void Treecode::next_symbol(const string& s, int& i, string& out){
    if (s[i] >= 0) {
        out = string(1, s[i]); 
        ++i;
    } else {
        out = string(s, i, 2); 
        i += 2;
    }
}

void Treecode::codif(string& text, bool& s) {
    string result, aux;
    int i = 0;
    int j = text.length();
    while (i < j and s) {
        next_symbol(text,i,aux);
        
        if (codis.count(aux) == 0) s = false;
        else {
            map<string, string>::const_iterator it = codis.find(aux);
            result += (*it).second;
        }
    }
    if (s) text = result;
    else text = aux;
}

void Treecode::decod(const BinTree<pair<string, int> >& b, const string& text, string& result, int& n, int& i, bool& s){
    s = true;
    if (b.left().empty() and b.right().empty()) {
        result += b.value().first;
        i = n;
        if (text.length() > n) decod(bin, text, result, n, i, s);
    } else if (text.length() == n) s = false;
    if (text[n] == '0') {
        ++n;
        if (not b.left().empty()) decod(b.left(), text, result, n, i, s);
    } else if (text[n] == '1') {
        ++n;
        if (not b.right().empty()) decod(b.right(), text, result, n, i, s);
    }
}

void Treecode::decodif(string& text, bool& s, int& i) {
    string result = "";
    int n = 0;
    decod(bin, text, result, n, i, s);
    if (s) text = result;
}

bool Treecode::pertany(string t) const {
    if (codis.count(t) == 0) return false;
    return true;
}

void Treecode::obtenirtc(Taula t) {  
    conjt_bin.clear();
    
    t.inici();
    while(not t.fi()) { 
        BinTree<pair<string, int> > b(t.actual());
        conjt_bin.insert(b);
         t.avanca();
  }
    obtenir_treecode(conjt_bin);
    string cami;
    codis.clear();
    obtenir_codis(bin, cami, codis);
}

void Treecode::obtenir_treecode(set<BinTree<pair<string, int> > >& conjt_bin) {
    while (conjt_bin.size() > 1) {
        BinTree<pair<string, int> > a1 = *(conjt_bin.begin());
        conjt_bin.erase (conjt_bin.begin());
        BinTree<pair<string, int> > a2 = *(conjt_bin.begin());
        conjt_bin.erase (conjt_bin.begin());
        pair<string,int> ar;
        if ((a2.value()).first > (a1.value()).first) {
	  ar = make_pair((a1.value()).first + (a2.value()).first , (a1.value()).second + (a2.value()).second);
        } else {
	  ar = make_pair((a2.value()).first + (a1.value()).first, (a1.value()).second + (a2.value()).second);
        }
        BinTree<pair<string, int> > a3(ar,a1,a2);
        conjt_bin.insert(a3);
    }
    bin = *(conjt_bin.begin());
    conjt_bin.erase(conjt_bin.begin());
}

void Treecode::obtenir_codis(const BinTree <pair<string, int> >& bin, string cami, map<string, string>& codis) {
    bool hoja = false;
    if (not (bin.left()).empty()) obtenir_codis (bin.left(), cami + '0', codis);
    else hoja = true;
    if (not (bin.right()).empty()) {
        obtenir_codis (bin.right(), cami + '1', codis); 
        hoja = false;
    }
    if (hoja) {
      string aux = (bin.value()).first;
        codis.insert(make_pair(aux, cami));
    }
}

void Treecode::escriuretc() const {
    cout << "recorrido en preorden:" << endl;
    escriure_preordre(bin);
    cout << "recorrido en inorden:" << endl;
    escriure_inordre(bin);
}

void Treecode::escriure_preordre(const BinTree<pair<string, int> >& bin) {
    if (not bin.empty()) {
        pair<string, int> x = bin.value();
        cout << x.first << ' ' << x.second << endl;
        escriure_preordre(bin.left());
        escriure_preordre(bin.right());
    }
}

void Treecode::escriure_inordre(const BinTree<pair<string, int> >& bin)  {
       if (not bin.empty()) {
        pair<string, int> x = bin.value();
        escriure_inordre(bin.left());
        cout << x.first << ' ' << x.second << endl;
        escriure_inordre(bin.right());
       }
}

void Treecode::escriurecs() const {
    map<string, string>::const_iterator it;
    for (it = codis.begin(); it != codis.end(); ++it) {
        cout << (*it).first << ' ' << (*it).second << endl;
    }
}

void Treecode::escriurec(string t) const {
    map<string, string>::const_iterator it = codis.find(t);
    cout << (*it).first << ' ' << (*it).second << endl;
}



