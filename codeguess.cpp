#include<iostream>
#include<ctime>
using namespace std;

void PrintIntroduction(int Difficulty)
{
	// Print welcome messsage to the terminal
	cout << "\n\nYou are a secret agent breaking into a level "<<Difficulty<<" secure room";
	cout << "\nEnter the correct code to continue: ";
};

bool PlayGame(int Difficulty)
{
	//Level Difficulty increase logic
	PrintIntroduction(Difficulty);

	int CodeA = rand() % Difficulty + Difficulty;
	int CodeB = rand() % Difficulty + Difficulty;
	int CodeC = rand() % Difficulty + Difficulty;

	int CodeSum = CodeA + CodeB + CodeC;
	int CodeProduct = CodeA * CodeB * CodeC;

	//Print Codesum and Codeproduct to the terminal
	cout << "\n\n+ There are 3 numbers in the code: ";
	cout << "\n+ The number add up to:" << CodeSum;
	cout << "\n+ The codes multiply to give: " << CodeProduct;

	//Store player guess
	int GuessA, GuessB, GuessC;

	cout << "\n\nEnter your Guesses:\n";
	cin >> GuessA >> GuessB >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int	GuessProduct = GuessA * GuessB * GuessC;

	//Result
	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		cout << "\nCorrect Guess!";
		return true;
	}
	else
	{
		cout << "\nWrong Guess!\n\n***Please Retry***";
		return false;
	}
};


int main()
{
	srand(time(NULL)); //Create random sequence based on time of day
	int LevelDifficulty = 1;
	const int MaxDifficulty = 5;

	while (LevelDifficulty <= MaxDifficulty) //Loop till all levels are completed
	{	
		bool bLevelComplete = PlayGame(LevelDifficulty);
		cin.clear();
		cin.ignore();

		if (bLevelComplete)
		{
			++LevelDifficulty;
		}
	}

	cout << "Congratulations you completed the game !!";
	cin.get();
}
