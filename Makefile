all:
	g++ countriesAndCapitalsFlashCards.cpp -o flashCards

run: all
	./flashCards
