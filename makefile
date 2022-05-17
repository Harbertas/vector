main:
	g++ -o main test.cpp vector.cpp
test:
	g++ -o main main.cpp container_functions/*.cpp functions/*.cpp student/*.cpp person/*.cpp -O3