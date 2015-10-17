
void simulateHands(){


	std::srand(static_cast<unsigned int>(std::time(0)));
	Deck deck;
	CHand CHand;
	int scores[num_scores] = {};
	const int num_CHands = 1000;
	const int num_width = static_cast<int>(std::log10(num_CHands) + 1);
	for (int i = 0; i < num_CHands; ++i)
	{
		deck.shuffle();
		deck.deal(CHand);
		++scores[CHand.GetScore()];
	}
	std::cout << "Results for " << num_CHands << " CHands:" << std::endl;
	for (int i = 0; i < num_scores; ++i)
	{
		std::cout << std::setw(num_width) << std::right << scores[i] << " - " << CHandScoreNames[i] << std::endl;
	}

}

void checkScore(){


	std::srand(static_cast<unsigned int>(std::time(0)));
	Deck deck;
	CHand CHand;
	int scores[num_scores] = {};
	deck.shuffle();
	deck.deal(CHand);

	//for (std::vector<Card>::size_type i = 0; i != deck.cards.size(); i++) {
	//	cout << "Deck:" << deck.cards[i];
	//}

	cout << "Score:" << CHand.GetScore() << endl;

}

