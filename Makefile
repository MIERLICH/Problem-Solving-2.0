build: p1.cpp p2.cpp p3.cpp
	g++ p1.cpp -o p1
	g++ p2.cpp -o p2
	g++ p3.cpp -o p3


run-p1: p1
	./p1

run-p2: p2
	./p2

run-p3: p3
	./p3 > p3.out

clean:
	rm -f p1 p2 p2