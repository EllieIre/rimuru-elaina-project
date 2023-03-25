#include <iostream>
#include <algorithm>
#include <windows.h>
#include <windef.h>
using namespace std;

// Invalid move message function
void invalidMsg(){
	cout << "Invalid move! Rimuru cannot move onto an obstacle or outside the map boundaries." << endl;
}

int main(){
	HWND hwnd = GetConsoleWindow();
	HICON hicon = (HICON) LoadImage(GetModuleHandle(NULL), "icon.ico", IMAGE_ICON, 128, 128, LR_LOADFROMFILE);
	SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM) hicon);
	// Map array assignment
	char map[6][12] = {
		'o', '-', '&', '-', '-', '-', '-', '%', '#', '-', '-', '-',
		'-', '-', '-', '%', '%', '-', '%', '-', '-', '-', '%', '-',
		'&', '-', '&', '-', '-', '-', '#', '-', '$', '%', '-', '-',
		'-', '-', '-', '-', '-', '&', '-', '-', '-', '$', '-', '#',
		'-', '-', '#', '%', '-', '&', '-', '#', '-', '&', '-', '-',
		'&', '#', '#', '#', '-', '-', '-', '-', '%', '-', '#', '+'
		
	};
	
	// Find initial position of Rimuru on the map
	int row = -1;
	int col = -1;
	for (int i = 0; i < 6; i++) {
	    for (int j = 0; j < 12; j++) {
	        if (map[i][j] == 'o') {
	            row = i;
	            col = j;
	            break;
	        }
	    }
	    if (row != -1) {
	        break;
	    }
	}
	
	// Giving instructions to end-user
	cout << "Hey! Welcome to the game! You've been given a task from me! Let me explain.." << endl;
	sleep(3);
	cout << "So, A person called Rimuru Tempest (o) wants to meet with her friend, Elaina (+)." << endl;
	sleep(3);
	cout << "Here is the map!" << endl << "----------------------" << endl;
	
	// Printing the map
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 12; j++){
			cout << map[i][j] << " ";
			
		}
		cout << endl;
	}
	
	cout << "----------------------" << endl;
	sleep(4);
	cout << "Your task is to make Rimuru meet with Elaina with your keyboard moves!" << endl;
	
	// Init the user's move in string data-type
	string userMove;
	sleep(3);
	
	// Navigation system
	while (true){
		cout << "Please specify your move (use 'up', 'down', 'left', and 'right'): " << endl << ">> ";
		cin >> userMove;
		
		// Convert user input to lowercase
    	transform(userMove.begin(), userMove.end(), userMove.begin(), [](unsigned char c){ return tolower(c); });
    	
    	// Check if the input is valid
		if (userMove != "up" && userMove != "down" && userMove != "left" && userMove != "right") {
		    cerr << "Invalid input! Please enter the navigation words!" << endl;
		    continue;
		}
		
		if (userMove == "up") {
    		// Move Rimuru up
		    if (row > 0 && (map[row-1][col] == '-' || map[row-1][col] == '+')) {
		        if (map[row-1][col] != '&' && map[row-1][col] != '%' && map[row-1][col] != '#' && map[row-1][col] != '$') {
		            map[row][col] = map[row][col] == '+' ? '+' : '-';
		            row--;
		            map[row][col] = 'o';
		        } else {
		            invalidMsg();
		            continue;
		        }
		    } else {
		        invalidMsg();
		        continue;
		    }
		} else if (userMove == "down") {
		    // Move Rimuru down
		    if (row < 5 && (map[row+1][col] == '-' || map[row+1][col] == '+')) {
		        if (map[row+1][col] != '&' && map[row+1][col] != '%' && map[row+1][col] != '#' && map[row+1][col] != '$') {
		            map[row][col] = map[row][col] == '+' ? '+' : '-';
		            row++;
		            map[row][col] = 'o';
		        } else {
		            invalidMsg();
		            continue;
		        }
		    } else {
		        invalidMsg();
		        continue;
		    }
		} else if (userMove == "left") {
		    // Move Rimuru left
		    if (col > 0 && (map[row][col-1] == '-' || map[row][col-1] == '+')) {
		        if (map[row][col-1] != '&' && map[row][col-1] != '%' && map[row][col-1] != '#' && map[row][col-1] != '$') {
		            map[row][col] = map[row][col] == '+' ? '+' : '-';
		            col--;
		            map[row][col] = 'o';
		        } else {
		            invalidMsg();
		            continue;
		        }
		    } else {
		        invalidMsg();
		        continue;
		    }
		} else if (userMove == "right") {
		    // Move Rimuru right
		    if (col < 11 && (map[row][col+1] == '-' || map[row][col+1] == '+')) {
		        if (map[row][col+1] != '&' && map[row][col+1] != '%' && map[row][col+1] != '#' && map[row][col+1] != '$') {
		            map[row][col] = map[row][col] == '+' ? '+' : '-';
		            col++;
		            map[row][col] = 'o';
		        } else {
		            invalidMsg();
		            continue;
		        }
		    } else {
		        invalidMsg();
		        continue;
		    }
		}


		// Position checking
		if (row == 5 && col == 11) {
			cout << "Congrats! You have successfully completed the game! Omedetou!" << endl;
			break;
		}
		
		sleep(1);
		// Print the updated map
	    cout << endl << "----------------------" << endl;
	    for (int i = 0; i < 6; i++) {
	        for (int j = 0; j < 12; j++) {
	            cout << map[i][j] << " ";
	        }
	        cout << endl;
	    }
	    cout << endl << "----------------------" << endl;
	    
	}
		
}
