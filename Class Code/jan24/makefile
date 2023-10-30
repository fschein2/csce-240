# the -I is the include path flag, we will add the current directory
# ( . ) to the include path so that the compiler will find our user
# defined header files there
flags = -std=c++17 -Wall -I .

myfunctions.o : myfunctions.cc myfunctions.h
	g++ $(flags) -c $<

jan24.o : jan24.cc myfunctions.h
	g++ $(flags)  -c $<

jan24 : jan24.o myfunctions.o
	g++ $(flags) $^ -o $@
	./jan24

clean :
	rm jan24.o myfunctions.o jan24
