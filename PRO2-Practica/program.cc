    /** @mainpage
    
    El programa principal se encuentra en el módulo program.cc.
    Atendiendo a los tipos de datos sugeridos en el enunciado, necesitaremos cuatro módulos, uno para las operaciones aplicadas en las tablas de frecuencias, otro para las aplicadas en el treecode y la tabla de códigos, estos dos incluidos en el módulo idioma, desde el que se llaman i al que pertenecen, y finalmente otro para guardar el Conjunto de los idiomas.
    Por lo tanto se intruducen las clases <em>Taula</em>, <em>Treecode</em>, <em>Idioma</em> y <em>Cnjt_idioma</em>.
    
 */

/** @file program.cc
    @brief Programa principal para el ejercicio <em>Operaciones en idiomas</em>.
*/
#include "Cnjt_idioma.hh"

using namespace std;

int main() {
    int n; //Número d'idiomes a llegir
    cin >> n;
    Cnjt_idioma c;
    c.llegir(n);
    string op; //Codi de l'operació
    while(cin >> op and op != "fin") { 
        string nom; //Nom de l'idioma
        cin >> nom;
        if (op == "anadir/modificar") {
            bool r = c.existeix_idioma(nom);
            if (r) { 
                c.modificar_idioma(nom);
                cout << "Modificado " << nom << endl;
            } else {
                c.afegir_idioma(nom);
                cout << "Anadido " << nom << endl;
            }
        } else if (op == "codifica") {
             cout << "Codifica en " << nom << " el texto:" << endl;
            bool r = c.existeix_idioma(nom);
            string text;
            cin >> text;
            cout << text << endl;
            if (r) {
                Idioma& idiom = c.consultar_idioma(nom);
                bool s = true;
                idiom.codifica(text, s);
                if (s) cout << text << endl;
                else cout << "El texto no pertenece al idioma; primer caracter que falla: " << text << endl;
            }
            else cout << "El idioma no existe" << endl;
        } else if (op == "decodifica") {
            cout << "Decodifica en " << nom << " el texto:" << endl;
            bool r = c.existeix_idioma(nom);
            string text;
            cin >> text;
            cout << text << endl;
            if (r) {
                Idioma& idiom = c.consultar_idioma(nom);
                bool s = true;
                int i = 0;
                idiom.decodifica(text, s, i);
                if (s) cout << text << endl;
                else cout << "El texto no procede de una codificacion del idioma; ultima posicion del codigo correspondiente al ultimo caracter que se podria decodificar: " << i << endl;
            }
            else cout << "El idioma no existe" << endl;
        } else if (op == "tabla_frec") {
            cout << "Tabla de frecuencias de " << nom << ':' << endl;
            bool r = c.existeix_idioma(nom);
            if (r) {
                Idioma& idiom = c.consultar_idioma(nom);
                idiom.escriure_taula();
            }
            else cout << "El idioma no existe" << endl;
        } else if (op == "treecode") {
            cout << "Treecode de " << nom << ':' << endl;
            bool r = c.existeix_idioma(nom);
            if (r) {
                const Idioma& idiom = c.consultar_idioma(nom);
                idiom.escriure_treecode();
                //c.escriure_treecode(nom);
            }
            else cout << "El idioma no existe" << endl;
        } else {
            string t;
            cin >> t;
            bool r = c.existeix_idioma(nom);
            if (t == "todos") {
                cout << "Codigos de " << nom << ':' << endl;
                if (r) {
                    Idioma& idiom = c.consultar_idioma(nom);
                    idiom.escriure_codis();
                } else cout << "El idioma no existe" << endl;
            } else {
                cout << "Codigo de " << t << " en " << nom << ':' << endl;
                if (r) {
                    Idioma& idiom = c.consultar_idioma(nom);
                    bool s = idiom.pertany_codis(t);
                    if (s) idiom.escriure_codi(t);
                    else cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
                } else cout << "El idioma no existe o el caracter no esta en el idioma" << endl;
            }
        }
	cout << endl; 
    }
}
