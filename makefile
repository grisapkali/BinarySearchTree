hepsi: derle calistir
Nesneler :=  ./lib/Agac.o ./lib/BagilList.o ./lib/Islem.o

derle:
	g++ -I ./include/ -o ./lib/Agac.o -c ./src/Agac.cpp
	g++ -I ./include/ -o ./lib/BagilList.o -c ./src/BagilList.cpp
	g++ -I ./include/ -o ./lib/Islem.o -c ./src/Islem.cpp
	g++ -I ./include/ -o ./bin/Test $(Nesneler) ./src/Test.cpp
	
	
calistir:
	./bin/Test