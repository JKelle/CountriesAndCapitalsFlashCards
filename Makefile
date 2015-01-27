all: flashCards

flashCards:
	@g++ countriesAndCapitalsFlashCards.cpp -o flashCards	

run: flashCards
	@./flashCards

clean:
	@rm -f flashCards
