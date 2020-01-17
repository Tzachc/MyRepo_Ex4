all:frequency
main.o: main.c
	gcc -Wall -fPIC -c main.c
trie.o: trie.c trie.h
	gcc -Wall -fPIC -c trie.c
frequency: main.o trie.o trie.h
	gcc -Wall -fPIC -o frequency main.o trie.o
clean:
	rm -f *.o *.a frequency
