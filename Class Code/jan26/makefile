# target  : prerequisites/dependencies
# tab command
#
#	$@ target
# $< first prerequisite
# $^ all prerequisites

# the -I is the include path flag, we will add the current
# directory (.) to the include path so that the compiler
# will find our user defined header files there
flags = -std=c++17 -Wall -I .

mynumericfunctions.o : mynumericfunctions.cc mynumericfunctions.h
	g++ $(flags) -c $<

testfactorial.o : testfactorial.cc mynumericfunctions.h
	g++ $(flags) -c $<

testfactorial : testfactorial.o mynumericfunctions.o
	g++ $(flags) $^ -o $@
	./testfactorial

testquad.o : testquad.cc mynumericfunctions.h
	g++ $(flags) -c $<

testquad : testquad.o mynumericfunctions.o
	g++ $(flags) $^ -o $@
	./testquad

testaverage.o : testaverage.cc mynumericfunctions.h
	g++ $(flags) -c $<

testaverage : testaverage.o mynumericfunctions.o
	g++ $(flags) $^ -o $@
	./$@

clean :
	rm *.o testfactorial testquad