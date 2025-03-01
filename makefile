studentHeap.exe: main.o address.o date.o
	g++ -o studentHeap.exe main.o address.o date.o 

studentHeasearchp.exe: main.o address.o date.o student.o
	g++ -o studentHeasearchp.exe main.o address.o date.o student.o

student.o: student.cpp student.h
	g++ -c student.cpp

address.o: address.cpp address.h
	g++ -c address.cpp

date.o: date.cpp date.h
	g++ -c date.cpp

main.o: main.cpp address.h date.h
	g++ -c main.cpp

clan:
	rm *.o

run: studentHeap.exe
	./studentHeap.exe
