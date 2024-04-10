#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

int money = 1000;
bool game = 0;
int bet = 0;
int card1, card2, suma;
int dealcard1, dealcard2, sumadeal;
int carti_trase = 0, cartivec[100];

void reset() {
    srand(time(NULL));
}

void joc() {
    system("cls");
    reset();
    if (!game) {
        cout << "You have " << money << " credits left.\nPlace your bet: ";
        cin >> bet; 
        while (bet < 1) {
            cout << "Input error! Place a positive bet: ";
            cin >> bet;
        }
        money -= bet;
        system("cls");
    }
    cout << "You have " << money << " credits left.\nYour bet is: " << bet<<"";

    if (!game) {
        cout << "\nDealer is shuffling the cards ";
        for (int i = 1; i <= 3; i++) {
            cout << ". ";
            Sleep(500);
        }
    }
    
    cout << "\n\nYour cards: ";
    
    if (!game) {
        card1 = rand() % 12 + 1;
        card2 = rand() % 12 + 1;
        suma = card1 + card2;
    }
    if (card1 < 10) cout << card1 << " ";
    else if (card1 == 10) cout << "J ";
    else if (card1 == 11) cout << "Q ";
    else if (card1 == 12) cout << "K ";

    if (card2 < 10) cout << card2 << " ";
    else if (card2 == 10) cout << "J ";
    else if (card2 == 11) cout << "Q ";
    else if (card2 == 12) cout << "K ";

    for (int i = 0; i < carti_trase; i++) {
        if (cartivec[i] < 10) cout << cartivec[i] << " ";
        else if (cartivec[i] == 10) cout << "J ";
        else if (cartivec[i] == 11) cout << "Q ";
        else if (cartivec[i] == 12) cout << "K ";
    }

    cout << '\n';

    cout << "Dealer's cards: ";
    
    if (!game) {
        reset();
        dealcard1 = rand() % 6 + 7;
        dealcard2 = rand() % 12 + 1;
        sumadeal = dealcard1 + dealcard2;
        game = 1;
    }

    if (dealcard1 < 10) cout << dealcard1 << " ";
    else if (dealcard1 == 10) cout << "J ";
    else if (dealcard1 == 11) cout << "Q ";
    else if (dealcard1 == 12) cout << "K ";

    cout << "#\n\n";

    cout << "Draw a card (1) or Show your cards (2): ";
    int opt; cin >> opt;
    if (opt == 1) { 
        reset();
        int cardtras = rand() % 12 + 1;
        if (cardtras < 10)
            suma += cardtras;
        else
            suma += 10;
        cartivec[carti_trase] = cardtras;
        carti_trase++;
        system("cls");
        if (suma > 21) {
            system("cls");
            cout << "You have " << money << " credits left.\nYour bet is: " << bet << "\n";
            cout << "\n\nYour cards: ";
            if (card1 < 10) cout << card1 << " ";
            else if (card1 == 10) cout << "J ";
            else if (card1 == 11) cout << "Q ";
            else if (card1 == 12) cout << "K ";

            if (card2 < 10) cout << card2 << " ";
            else if (card2 == 10) cout << "J ";
            else if (card2 == 11) cout << "Q ";
            else if (card2 == 12) cout << "K ";

            for (int i = 0; i < carti_trase; i++) {
                if (cartivec[i] < 10) cout << cartivec[i] << " ";
                else if (cartivec[i] == 10) cout << "J ";
                else if (cartivec[i] == 11) cout << "Q ";
                else if (cartivec[i] == 12) cout << "K ";
            }

            cout << "\nDealer's cards: ";
            if (dealcard1 < 10) cout << dealcard1 << " ";
            else if (dealcard1 == 10) cout << "J ";
            else if (dealcard1 == 11) cout << "Q ";
            else if (dealcard1 == 12) cout << "K ";

            if (dealcard2 < 10) cout << dealcard2 << " ";
            else if (dealcard2 == 10) cout << "J ";
            else if (dealcard2 == 11) cout << "Q ";
            else if (dealcard2 == 12) cout << "K ";
            cout << "\nYou lost!\n\n";
            suma = 0, sumadeal = 0;
            carti_trase = 0;
            game = 0;

            cout << "Another game (1) or Exit (2): ";
            int c; cin >> c;
            if (c == 1)
                joc();
        }
        else joc();
    }
    else {
        system("cls");
        cout << "You have " << money << " credits left.\nYour bet is: " << bet << "\n";
        cout << "\n\nYour cards: ";
        if (card1 < 10) cout << card1 << " ";
        else if (card1 == 10) cout << "J ";
        else if (card1 == 11) cout << "Q ";
        else if (card1 == 12) cout << "K ";

        if (card2 < 10) cout << card2 << " ";
        else if (card2 == 10) cout << "J ";
        else if (card2 == 11) cout << "Q ";
        else if (card2 == 12) cout << "K ";

        for (int i = 0; i < carti_trase; i++) {
            if (cartivec[i] < 10) cout << cartivec[i] << " ";
            else if (cartivec[i] == 10) cout << "J ";
            else if (cartivec[i] == 11) cout << "Q ";
            else if (cartivec[i] == 12) cout << "K ";
        }

        cout << "\nDealer's cards: ";
        if (dealcard1 < 10) cout << dealcard1 << " ";
        else if (dealcard1 == 10) cout << "J ";
        else if (dealcard1 == 11) cout << "Q ";
        else if (dealcard1 == 12) cout << "K ";

        if (dealcard2 < 10) cout << dealcard2 << " ";
        else if (dealcard2 == 10) cout << "J ";
        else if (dealcard2 == 11) cout << "Q ";
        else if (dealcard2 == 12) cout << "K ";

        cout << "\n\n";
        if (suma >= sumadeal) {
            cout << "You won!\n\n";
            suma = 0, sumadeal = 0;
            dealcard1 = 0, dealcard2 = 0;
            card1 = 0, card2 = 0;
            carti_trase = 0;
            game = 0;
            money += 2*bet;
        }
        else {
            cout << "You lost!\n\n";
            suma = 0, sumadeal = 0;
            carti_trase = 0;
            game = 0;
        }

        cout << "Another game (1) or Exit (2): ";
        int c; cin >> c;
        if (c == 1)
            joc();
    }
    
}

int main()
{
    //cout << "\033[8;15;50t";
    cout << "   BlackJack Magic ver 0.3\n\n";

    cout << "1. Start Game \n2. Exit\n\nEnter Option: ";
    int opt; cin >> opt;
    if (opt == 1) joc();
    else return 0;

}
