run:
	make build && ./build && make clean
build:
	clang++ -std=c++11 -stdlib=libc++ main.cpp -o build
clean:
	rm ./build
test:
	clang++ -std=c++11 -stdlib=libc++ test_cartes.cpp -o test && ./test && rm ./test