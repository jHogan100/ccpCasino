//notes.
//program can crash if unexpected values are entered. could make a toInt() function or something.
//program could be tidier by breaking more things down into seperate functions.
//code logic works okay and is playable until you run out of cash

#include <iostream>
#include <random>
using namespace std;

void welcomeMessage (int coins){ //welcome message, prints coins
    cout << "welcome to the gambling game, stick around for some insane rng\n";
    cout << "your starting cash is: ";
    cout << coins;
}

bool affordBet(int& bet, int& coins) {
    bool result; //checks for sufficient funds. called before each roll.
    
    if (bet <= coins) {
        result = true;
    } else {
        result = false;
    }
    return result;
} 

int diceGameCalc(int& bet) { //contains all the logic for the dice roll and handles the win/loss.
    cout << "\n rolling dice.........\n";
    int prize;
    int randomNumber;
    random_device rd; // rng generator from the cpp library
    mt19937 gen(rd()); 
    uniform_int_distribution<int> distribution(1, 100);
    randomNumber = distribution(gen);

    cout << "#####";
    cout << randomNumber;
    cout << "#####\n";

    if (randomNumber == 100) {
        cout << "jackpot!!\n";
        prize = bet * 10;
        cout << "you've won: ";
        cout << prize;
        } 
    else if (randomNumber >= 55) {
        cout << "winner, x2!!\n";
        prize = bet; 
        cout << "you've won: ";
        cout << prize;
        } 
    else {
        prize = 0;
        cout << "ooft";
        }
    return prize; //prize is returned and checked to add/subtract from coins.
}

int diceGameMenu(int& coins, int& bet) {
    int option;
    int prize;
    int newCoins;
    cout << "\n55x2 game, roll a 100 for jackpot";
    do {
    cout << "\n1. roll dice \n";
    cout << "2. return to main menu \n"; //add a print rules option?
    cin >> option;

    switch (option) {
        case 1: { 
            
            if (affordBet(bet, coins) == true) {
                prize = diceGameCalc(bet);//this allows the roll to happen if the bet is equal or less than coins
                if (prize <= 0){// this statement checks for a win or loss, and calculates the new value for coins.
                newCoins = coins - bet;
                coins = newCoins;
                return coins;
                }
                else {
                newCoins = prize + coins;
                coins = newCoins; 
                return coins;
                }
            } else {
                cout << "bet too high";
            }
            break;
        }
        case 2: {
           cout << "returning to main menu";
            break;
        }
    }
    }
    while (option != 2);

return coins;
}

int changeBet(int& bet){ //allows the user to alter the bet amount after initialisation
    int result;
    cout << "\nchange bet amount: \n";
    cin >> result;
    return result;

}
int main() {
    int coins = 500;
    int option;
    int bet;
    welcomeMessage(coins); // could ask for initial bet and then create a change bet function
    cout << "\nset initital bet: \n";
    cin >> bet;

    do {
    cout << "\nplease select an option: \n";
    cout << "1. 55x2\n";
    cout << "2. print coins & bet\n";
    cout << "3. change bet\n"; 
    cout << "4. exit\n"; 
    cin >> option;

    switch (option) { //create a seperate fuction for this menu
        case 1:
            coins = diceGameMenu(coins, bet);
            break;

        case 2:
            cout << "coins: \n";
            cout << coins;//make this a lil print info function?
            cout << "\n bet: \n";
            cout << bet;

            break;

        case 3:
            bet = changeBet(bet); 
            break;

        case 4:
            cout << "exitting\n"; 
            break;
        
    }
    }
    while (option != 4);
    return 0; 
}


//could make some cookie clicker function to gain money if you get cleaned
// could add some custom agorithms (to calc odds) for flavour
