
maxHeap: main.o maxHeap.o random_generator.o
	g++ -Wall -std=c++11 main.o maxHeap.o random_generator.o -o maxHeap

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

maxHeap.o: maxHeap.cpp maxHeap.h
	g++ -c -std=c++11 maxHeap.cpp

random_generator.o: random_generator.cpp random_generator.h
	g++ -c -std=c++11 random_generator.cpp

clean:
	rm *.o maxHeap