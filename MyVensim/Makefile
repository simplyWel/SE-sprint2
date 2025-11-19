.PHONY: all DLL BUILD_PRODUCT product BUILD_UNIT_TEST unit BUILD_FUNC_TEST funcional clean

all: BUILD_PRODUCT BUILD_UNIT_TEST BUILD_FUNC_TEST

DLL:
	@g++ -shared -fPIC -o ./bin/libbib.so ./src/*.cpp

BUILD_PRODUCT: DLL
	@g++ ./src/*.cpp ./bin/libbib.so -o ./bin/product

product:
	./bin/product

BUILD_UNIT_TEST: DLL
	@g++ ./test/unit/*.cpp ./bin/libbib.so -o ./bin/unit_tests

unit:
	./bin/unit_tests

BUILD_FUNC_TEST: DLL
	@g++ ./test/funcional/*.cpp ./bin/libbib.so -o ./bin/funcional_tests

funcional: 
	./bin/funcional_tests

clean:
	rm -f ./bin/*.o
	rm -f ./bin/*.so
	rm -f ./bin/unit_tests
	rm -f ./bin/funcional_tests
	rm -f ./bin/product