#include <iostream>     // Prepocessor Directive 
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Expression Statement
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " locker room...\nEnter your correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    
    // Declaration Statement 
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;
 
    /*
    This is a multi-line comment section (sample) - refers to not execute statements!
    */

    const int CodeProduct = CodeA * CodeB * CodeC;
    const int CodeSum = CodeA + CodeB + CodeC;
  
    // Final Output Statements in the terminal
    std::cout << std::endl;  
    std::cout << "+ There are 3 numbers in the code!\n";
    std::cout << "\n+ The product of the code: " << CodeProduct; 
    std::cout << "\n+ The summation of the code: " << CodeSum << std::endl;
    
    // Store Player Guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;   
   

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;


    // Check if the player guess is correct or not
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {  
        std::cout << "\n*** Well Done Agent! You have extracted a file! Keep going ***"; 
        return true;
    }    
    else
    {
        std::cout << "\n*** Wrong Code! Beware! Try again! ***";
        return false; 
    }  

}

int main()     // Main Function
{ 
    srand(time(NULL));   // Create New Random Sequence based on time of day

    int LevelDifficulty = 1;
    int const MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel)  // Loop game until all levels completed!
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();  // Clear any errors
        std::cin.ignore();  // Discards the buffer
       
       if (bLevelComplete) 
       {
          ++LevelDifficulty; 
       } 


    }
    std::cout << "\n*** Well Done Agent! Now Get Out and Grab my KitKat! ***\n";
    // Return Statement 
    return 0;
}