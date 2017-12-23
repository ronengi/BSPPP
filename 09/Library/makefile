library:	Library.o  Book.o  ISBN.o  Chrono.o
		g++ -Wall Library.o  Book.o  ISBN.o  Chrono.o  -o library

Library.o:	Library.cpp  ../Chrono/Chrono.hpp  Book.hpp  ISBN.hpp  Patron.hpp  Library.hpp
		g++ -Wall -c Library.cpp  -o Library.o

Book.o:		Book.cpp  Book.hpp  ISBN.hpp  ../Chrono/Chrono.hpp
		g++ -Wall -c Book.cpp  -o Book.o

ISBN.o:		ISBN.cpp  ISBN.hpp
		g++ -Wall -c ISBN.cpp  -o ISBN.o

Chrono.o:	../Chrono/Chrono.cpp  ../Chrono/Chrono.hpp
		g++ -c ../Chrono/Chrono.cpp  -o Chrono.o
