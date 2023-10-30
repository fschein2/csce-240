flags = -std=c++17 -Wall -I .

factcheckedstatement.o : factcheckedstatement.cc factcheckedstatement.h
	g++ $(flags) -c $<

testconstructor : testconstructor.cc factcheckedstatement.o
	g++ $(flags) $^ -o $@
	./$@

testassignment : testassignment.cc factcheckedstatement.o
	g++ $(flags) $^ -o $@
	./$@

testsettruth : testsettruth.cc factcheckedstatement.o
	g++ $(flags) $^ -o $@
	./$@

compareoutput : compareoutput.cc
	g++ $(flags) $^ -o $@

testoutput : testoutput.cc factcheckedstatement.o compareoutput
	g++ $(flags) $< factcheckedstatement.o -o $@
	./$@ > studentoutput.txt
	./compareoutput

clean :
	rm studentoutput.txt *.o testoutput testsettruth testassignment testconstructor compareoutput

