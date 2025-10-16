all: tests/testa_backup.cpp src/backup.cpp src/backup.hpp backup.o
	g++ -std=c++17 -Wall backup.o tests/testa_backup.cpp third_party/catch/catch_amalgamated.cpp -o testa_backup
	./testa_backup
	#use comentario se necessario

compile: tests/testa_backup.cpp   src/backup.cpp src/backup.hpp backup.o
	g++ -std=c++17 -Wall backup.o tests/testa_backup.cpp -o testa_backup

backup.o : src/backup.cpp src/backup.hpp
	g++ -std=c++17 -Wall -c src/backup.cpp
	
testa_backup: 	tests/testa_backup.cpp   src/backup.cpp src/backup.hpp backup.o
	g++ -std=c++17 -Wall backup.o tests/testa_backup.cpp -o testa_backup
	
test: testa_backup	
	./testa_backup
	
cpplint: tests/testa_backup.cpp   src/backup.cpp src/backup.hpp
	cpplint   --exclude=catch_amalgamated.hpp  *.*
	
gcov: tests/testa_backup.cpp   src/backup.cpp src/backup.hpp 
	g++ -std=c++17 -Wall -fprofile-arcs -ftest-coverage -c src/backup.cpp
	g++ -std=c++17 -Wall -fprofile-arcs -ftest-coverage backup.o tests/testa_backup.cpp -o testa_backup
	./testa_backup
	gcov *.cpp	
	 
debug: tests/testa_backup.cpp   src/backup.cpp src/backup.hpp 
	g++ -std=c++17 -Wall -g -c src/backup.cpp
	g++ -std=c++17 -Wall  -g backup.o tests/testa_backup.cpp -o testa_backup
	gdb testa_backup
	
	
cppcheck: tests/testa_backup.cpp   src/backup.cpp src/backup.hpp
	cppcheck  --enable=warning .

valgrind: testa_backup
	valgrind --leak-check=yes --log-file=valgrind.rpt testa_backup

doxygen: Doxyfile
	doxygen Doxyfile


clean:
	rm -rf *.o *.exe *.gc* testa_backup
	
	
