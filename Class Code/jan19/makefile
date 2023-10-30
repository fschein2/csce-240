# this is the comment symbol in a makefile
# target : prerequisites/dependencies
# $@ target
# $< first prerequisite
# $^ all prerequisites
flags = -std=c++17 -Wall

jan19.o : jan19.cc
	g++ $(flags) -c $<

jan19 : jan19.o
	g++ $(flags) $< -o $@
	./jan19

clean : 
	rm jan19.o jan19
