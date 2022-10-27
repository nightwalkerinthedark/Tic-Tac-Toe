#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <unistd.h>
#include <Bits/stdc++.h>
using namespace std;

void ClearBoard();
void Script_For_Winner(string script , int Counter);
void PlayerMove(string Player);
void TheComputerMove(int n);
void Printboard();
char Checkwinner();
char CheckWinner();
int FreePlaces();
string check_Input();

char Board[3][3];

string Player1,Player2;
int Score_Of_Player1 = 0, Score_Of_Player2 = 0;

int main(){
	srand(time(NULL));
	int Counter_of_Matches = 0, playerTurn;
	cout << "Please enter 1 to play against computer or 2 to play against a friend:";
	cin >> playerTurn;
	sleep(1);
	system("cls");
	string Input;
	if(playerTurn == 2){
		cout << "Player1 Username: ";
		getline(cin, Player1);
		getline(cin, Player1);
		cout << "Player2 Username: ";
		getline(cin, Player2);
		while(toupper(Player1[0] == toupper(Player2[0]))){
			cout << "I see what you did there" << '\n';
			sleep(1);
			cout << "Now Change it" << '\n';
			getline(cin, Player2);
		}
		do{
		    char Winner = ' ';
		    ClearBoard();
		    while(1){
			    system("cls");
			    Printboard();
				if(Counter_of_Matches % 2 == 0){
					PlayerMove(Player1);
					Printboard();
					Winner = Checkwinner();
					
					if(Winner != ' '){
						cout << Player1 << " You have won " << Player2 << '\n';
						Score_Of_Player1++;
						Counter_of_Matches++;
						break;
					}
					if(FreePlaces() == 0){
					    cout << "You were Both Tied" << '\n';
					    Counter_of_Matches++;
					    break;
				    }
					PlayerMove(Player2);
					Printboard();
					Winner = Checkwinner();
					
					if(Winner != ' '){
						cout << Player2 << " You have won " << Player1 << '\n';
						Score_Of_Player2++;
						Counter_of_Matches++;
						break;
					}
				}else{
					PlayerMove(Player2);
					Printboard();
					Winner = Checkwinner();
					
					if(Winner != ' '){
						cout << Player2 << " You have won " << Player1 << '\n';
						Score_Of_Player2++;
						Counter_of_Matches++;
						break;
					}
	                if(FreePlaces() == 0){
					    cout << "You were Both Tied" << '\n';
					    Counter_of_Matches++;
					    break;
				    }
					PlayerMove(Player1);
					Printboard();
					Winner = Checkwinner();
					if(Winner != ' '){
						cout << Player1 << " You have won " << Player2 << '\n';
						Score_Of_Player1++;
						Counter_of_Matches++;
						break;
					}
				}
		    }
		    Input = check_Input();
	    }while(Input == "Y" || Input == "YES" || Input == "YEAH");
	    Script_For_Winner(Player2 , Counter_of_Matches);
	}else{
		sleep(1);
		string Names[99] = {"Ninja","Mario","Top G","Dick&Balls","Hartcringle","Holystonedireful","Luckygoofy","Foretelljackstaff","Deltasfifty","Languagegravelly","Assistantugly","Blowfishmarvel","Blazerodfizzle","Wrestlinghidden","MustacheGuy"};
		int CounterOfTurns = 0;
		cout << "Player Username: ";
		getline(cin, Player1);
		getline(cin, Player1);
		string script = Names[rand() % 15];
		cout << "Bot username: ";
		for(int i = 0;i < script.length();i++){
			cout << script[i];
			usleep(400000);
		}
		sleep(3);
		system("cls");
		do{
			char Winner = ' ';
			ClearBoard();
			while(1){
				system("cls");
				if(Counter_of_Matches % 2 == 0){
					Printboard();
					PlayerMove(Player1);
					Winner = Checkwinner();
					if(Winner != ' '){
						cout << "You have beaten " << script << '\n';
						Printboard();
						Score_Of_Player1++;
						Counter_of_Matches++;
						break;
					}
					if(FreePlaces() == 0){
						system("cls");
						cout << "That's a draw" << '\n';
						Printboard();
						Counter_of_Matches++;
						break;
					}
					cout << script << " turn" << '\n';
					CounterOfTurns++;
					Printboard();
					sleep(1);
					system("cls");
					TheComputerMove(CounterOfTurns);
					Winner = Checkwinner();
					Printboard();
					if(Winner != ' '){
						cout << "You have lost to " << script << '\n';
						Printboard();
						Score_Of_Player2++;
						break;
					}
					CounterOfTurns++;
				}else{
					TheComputerMove(CounterOfTurns);
					CounterOfTurns++;
					Printboard();
					cout << "It's The " << script << " turn" << '\n';
					Winner = Checkwinner();
					if(Winner != ' '){
						cout << "You have lost to " << script << '\n';
						Printboard();
						Score_Of_Player2++;
						Counter_of_Matches++;
						break;
					}
					if(FreePlaces() == 0){
						cout << "That's a draw" << '\n';
						Printboard();
						Counter_of_Matches++;
						break;
					}
					PlayerMove(Player1);
					CounterOfTurns++;
					Winner = Checkwinner();
					Printboard();
					if(Winner != ' '){
						cout << "You have somehow beaten " << script << '\n';
						Printboard();
						Score_Of_Player1++;
						Counter_of_Matches++;
						break;
					}
				}
			}
			Input = check_Input();
		}while(Input == "Y" || Input == "YES" || Input == "YEAH");
		Script_For_Winner(script , Counter_of_Matches);
	}
}
void ClearBoard(){
    for(int i = 0;i < 3;i++){
    	for(int j = 0; j < 3; j++){
    		Board[i][j] = ' ';
		}
	}
}
void Printboard(){
    cout << "    " << Board[0][0] << "    |    " << Board[0][1] << "    |    " << Board[0][2] << '\n';
	cout << "-----------------------------" << '\n';
	cout << "    " << Board[1][0] << "    |    " << Board[1][1] << "    |    " << Board[1][2] << '\n';
    cout << "-----------------------------" << '\n';
	cout << "    " << Board[2][0] << "    |    " << Board[2][1] << "    |    " << Board[2][2] << '\n' << '\n';
}
int FreePlaces(){
	int FreeSpaces = 9;
	for(int i = 0;i < 3;i++){
    	for(int j = 0; j < 3; j++){
    		if(Board[i][j] != ' '){
    	    	FreeSpaces--;
    	    }
		}
	}
	return FreeSpaces;
}
void PlayerMove(string Player){
	int x , y;
	do{
		cout << "It's " << Player << " Turn" << '\n';
	    cout << "Print The row(1-3): ";
	    cin >> x;
	    x--;
	    while(0 > x || x > 3){
	    	system("cls");
	    	cout << "You can't go there" << '\n';
	    	Printboard();
	    	cout << "Print The row(1-3): ";
	    	cin >> x;
		}
	    cout << "Print The column(1-3): ";
	    cin >> y;
	    y--;
	    while(0 > y || y > 3){
	    	system("cls");
	    	cout << "That place dosn't exist" << '\n';
	    	Printboard();
	    	cout << "Print The row(1-3): " << x << '\n';
	    	while(0 > x || x > 3){
	    		system("cls");
	    		cout << "You can't go there" << '\n';
	    		Printboard();
	    		cout << "Print The row(1-3): ";
	    		cin >> x;
			}
	    	cout << "Print The column(1-3): ";
	    	cin >> y;
		}
	    if(Board[x][y] != ' '){
			cout << "That Place is already occupied" << '\n';
        }else{
        	if(Player == Player1){
        		Board[x][y] = 'X';
        		break;
			}else{
				Board[x][y] = 'O';
        		break;
			}
		}
    }while(1);
}
void TheComputerMove(int n){
	srand(time(NULL));
	if(n == 1){
		if(Board[1][1] == 'X'){
			int m = rand() % 4;
			if(m == 0)
				Board[0][0] = 'O';
			else if(m == 1)
				Board[0][2] = 'O';
			else if(m == 2)
				Board[2][0] = 'O';
			else
				Board[2][2] = 'O';
		}else{
			Board[1][1] = 'O';
		}
		return;
	}
	if(n == 3 && ((Board[0][0] == 'X' && Board[2][2] == 'X') || (Board[0][2] == 'X' && Board[2][0] == 'X'))){
		int m = rand() % 4;
		if(m == 0)
			Board[0][1] = 'O';
		else if(m == 1)
			Board[1][0] = 'O';
		else if(m == 2)
			Board[1][2] = 'O';
		else
			Board[2][1] = 'O';
		return;
	}
	int x = 4, y, l = 0;
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			if(Board[i][j] != ' ')
				continue;
			Board[i][j] = 'O';
			if(CheckWinner() == 'O'){
				x = i;
				y = j;
				l = 1;
				break;
			}
			Board[i][j] = 'X';
			if(CheckWinner() == 'X'){
				x = i;
				y = j;
			}
			Board[i][j] = ' ';
		}
		if(l)
			break;
	}
	while(x == 4 || Board[x][y] != ' '){
		x = rand() % 3;
		y = rand() % 3;
	}
	Board[x][y] = 'O';
}
string check_Input(){
	string Input;
	cout << "Do You want to play againg(Y/N):";
	cin >> Input;
    transform(Input.begin() , Input.end() , Input.begin() , ::toupper);
    return Input;
}
char Checkwinner(){
	char winner = ' ';
	for(int i = 0;i < 3;i++){
		if(Board[0][i] == Board[1][i] && Board[0][i] == Board[2][i] && Board[0][i] != ' '){
			winner = Board[0][i];
			Board[0][i] = '|';
			Board[1][i] = '|';
			Board[2][i] = '|';
		}
		if(Board[i][0] == Board[i][1] && Board[i][0] == Board[i][2] && Board[i][0] != ' '){
			winner = Board[i][0];
			Board[i][0] = '-';
			Board[i][1] = '-';
			Board[i][2] = '-';
		}
	}
	if(Board[0][0] == Board[1][1] && Board[0][0] == Board[2][2] && Board[0][0] != ' '){
		winner = Board[0][0];
		Board[0][0] = '\\';
		Board[1][1] = '\\';
		Board[2][2] = '\\';
	}
	if(Board[0][2] == Board[1][1] && Board[0][2] == Board[2][0] && Board[0][2] != ' '){
		winner = Board[0][2];
		Board[0][2] = '/';
		Board[1][1] = '/';
		Board[2][0] = '/';
	}
	return winner;
}
char CheckWinner(){
	for(int i = 0;i < 3;i++){
		if(Board[0][i] == Board[1][i] && Board[0][i] == Board[2][i] && Board[0][i] != ' '){
	        return Board[0][i];
		}
		if(Board[i][0] == Board[i][1] && Board[i][0] == Board[i][2] && Board[i][0] != ' '){
			return Board[i][0];
		}
	}
	if(Board[0][0] == Board[1][1] && Board[0][0] == Board[2][2] && Board[0][0] != ' '){
		return Board[0][0];;
	}
	if(Board[0][2] == Board[1][1] && Board[0][2] == Board[2][0] && Board[0][2] != ' '){
        return Board[0][2];
	}
	return ' ';
}
void Script_For_Winner(string script , int Counter){	
	system("cls");
	cout << "Thanks for playing" << '\n';
	sleep(3);
	cout << "Your overall score is: " << '\n';
	sleep(1);    
	cout << '\n' << Player1 << " : " << Score_Of_Player1 << '\n';
	cout << script << " : " << Score_Of_Player2 << '\n' << '\n';
    sleep(1.5);

	if(Score_Of_Player1 > Score_Of_Player2){
	    if(Score_Of_Player1 - 10 >= Score_Of_Player2){
	    	cout << "Congrats " << Player1 << " On destroying " << script << endl;
		}else if(Score_Of_Player1 - 3 >= Score_Of_Player2){
	        cout << "Congrats " << Player1 << " On smashing " << script << endl;
	    }else{
	        cout << "Congrats " << Player1 << " On winning " << script << endl;
		}
	}
	else if(Score_Of_Player2 > Score_Of_Player1){
		if(Score_Of_Player2 - 10 >= Score_Of_Player1){
	    	cout << "Congrats " << script << " On destroying " << Player1 << endl;
		}else if(Score_Of_Player2 - 3 >= Score_Of_Player1){
	    	cout << "Congrats " << script << " On smashing " << Player1 << endl;
    	}else{
			cout << "Congrats " << script << " On winning " << Player1 << endl;
		}
	}else{
		cout << "Well That was a good draw" << endl;
	}
	if(Counter >= 30){
		cout << "You have played a lot ot of games!!" << endl;
	}
}
