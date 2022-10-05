main:
	clang++ -o ./bin/main example.cc src/memorypool.cc

test:
	clang++ -o ./bin/test test.cc

run:
	./bin/main

runtest:
	./bin/test

clean:
	rm ./bin/*

.PHONY:clean

