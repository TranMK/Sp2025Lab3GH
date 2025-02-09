main:
	g++ --std=c++2b main.cpp heaplotlittle.hpp heaplotlittle.cpp; ./a.out

test: ./a.out
	g++ --std=c++2b main.cpp heaplotlittle.hpp heaplotlittle.cpp; ./a.out test
