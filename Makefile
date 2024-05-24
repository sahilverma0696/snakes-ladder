# make test_player
test_player:
	g++ -std=c++17  ./src/player.cpp ./test/test_player.cpp  -o ./bin/test_player.out
	./bin/test_player.out >./logs/test_player.log

# make test_object
test_object:
	g++ -std=c++17  ./src/object.cpp ./test/test_object.cpp  -o ./bin/test_object.out
	./bin/test_object.out >./logs/test_object.log

# make test_cell
test_cell:
	g++ -std=c++17  ./src/player.cpp ./src/object.cpp ./src/cell.cpp ./test/test_cell.cpp  -o ./bin/test_cell.out
	./bin/test_cell.out >./logs/test_cell.log

# make test_board
test_board:
	g++ -std=c++17   ./src/player.cpp ./src/object.cpp ./src/cell.cpp ./src/board.cpp ./test/test_board.cpp  -o ./bin/test_board.out
	./bin/test_board.out >./logs/test_board.log

# make test_simulator
test_simulator:
	g++ -std=c++17   ./src/player.cpp ./src/object.cpp ./src/cell.cpp ./src/board.cpp ./src/simulator.cpp ./test/test_simulator.cpp  -o ./bin/test_simulator.out
	./bin/test_simulator.out >./logs/test_simulator.log

# make test_all
test_all: test_player test_object test_cell test_board test_simulator

#make clean
clean:
	rm -rf *.log
	rm -rf *.out
	cd bin; rm -rf *.out
	cd logs; rm -rf *.log