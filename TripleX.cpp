#include <iostream>
#include <ctime>


void PrintIntroduction(int Difficulty){
    std::cout << "\nWelcome to TripleX\n\n";
    //initial declarations, story start
    std::cout << "You are a secret agent breaking into a level " << Difficulty <<" secure server room\n";
    std::cout << "You need to enter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty){

    PrintIntroduction(Difficulty);

    int randomnumberMod = Difficulty * 3;

    //declaring variables for the story
    const int CodeA = rand() % randomnumberMod + 1;
    const int CodeB = rand() % randomnumberMod + 1;
    const int CodeC = rand() % randomnumberMod + 1;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "There are 3 numbers in the code";
    std::cout << "\nThe code adds-up to " << CodeSum;
    std::cout << "\nThe code multiplied to give " << CodeProduct<< std::endl;


    //store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if(GuessSum == CodeSum && GuessProduct == CodeProduct){
        std::cout << "\n*** You win, get the files ***\n";
        return true;
    }else{
        std::cout << "\n*** wrong code, try again! ***\n";
        return false;
    }

}

int main(){

    srand(time(NULL));

    int LevelDifficulty = 1;
    const int maxLevel = 3;
    while(LevelDifficulty <= maxLevel){
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    std::cout << "*** You are a master spy! Thanks for the files, get out quick ***";
    
    return 0;

}


