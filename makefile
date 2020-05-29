run:
	make build && ./build && make clean
build:
	clang++ -std=c++17 -stdlib=libc++ *.cpp -o build
clean:
	rm ./build
test:
	clang++ -std=c++17 -stdlib=libc++ test_cartes.cpp -o test && ./test && rm ./test