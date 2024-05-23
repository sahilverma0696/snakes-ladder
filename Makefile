
debug:
	g++ --std=c++17  ./src/expressionMatchSingle.cpp  ./test/test.cpp -o ./bin/regex_debug.out 
	./bin/regex_debug.out --debug ./data/regularExpressions.txt > ./logs/debug_log.log

testall:
	g++ --std=c++17  ./single_threaded/expressionMatchSingle.cpp  ./test/test.cpp -o ./bin/regex_test.out
	./bin/regex_test.out --test ./data/regularExpressions.txt ./data/bodies.txt > ./logs/all_test.log


benchmark:
	g++ --std=c++17  ./single_threaded/expressionMatchSingle.cpp  ./test/test.cpp -o ./bin/regex_benchmark.out
	./bin/regex_benchmark.out --benchmark ./data/regularExpressions.txt ./data/bodies.txt >> ./logs/benchmark.csv

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

# make test_all
test_all: test_player test_object test_cell

#make clean
clean:
	rm -rf *.log
	rm -rf *.out
	cd bin; rm -rf *.out
	cd logs; rm -rf *.log