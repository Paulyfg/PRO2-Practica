OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11


program.exe: program.o Cnjt_idioma.o Idioma.o Treecode.o Taula.o
	g++ -o program.exe program.o Cnjt_idioma.o Idioma.o Treecode.o Taula.o $(OPCIONS)
	
	
program.o: program.cc Cnjt_idioma.hh Idioma.hh Treecode.hh Taula.hh
	g++ -c program.cc $(OPCIONS)

Cnjt_idioma.o: Cnjt_idioma.cc Cnjt_idioma.hh Idioma.hh Treecode.hh Taula.hh
	g++ -c Cnjt_idioma.cc $(OPCIONS)

Idioma.o: Idioma.cc Idioma.hh Treecode.hh Taula.hh
	g++ -c Idioma.cc  $(OPCIONS)

Treecode.o: Treecode.cc Treecode.hh Taula.hh
	g++ -c Treecode.cc $(OPCIONS)
	
Taula.o: Taula.cc Taula.hh
	g++ -c Taula.cc $(OPCIONS)
	
	
practica.tar: program.cc Cnjt_idioma.cc Cnjt_idioma.hh Idioma.cc Idioma.hh Treecode.cc Treecode.hh Taula.cc Taula.hh
	tar -cvf practica.tar program.cc Cnjt_idioma.cc Cnjt_idioma.hh Idioma.cc Idioma.hh Treecode.cc Treecode.hh Taula.cc Taula.hh Makefile
	
clean:
	rm -f *.o
	rm -f *.exe
