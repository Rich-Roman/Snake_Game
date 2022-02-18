
#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>

#include "snake.h"
#include "food.h"


using namespace std;

int WIDTH = 50;
int HEIGHT = 25;


void display(snake s,Food f,int score)
{
    cout << "SCORE : " << score << endl;
    for (int i = 0; i < HEIGHT; i++) {
        cout << '#';

        for (int j = 0; j < WIDTH-2; j++) {
            if (i == 0 || i == HEIGHT-1) {
                cout << '#';
            }
            else if (i == s.getHead().second && s.getHead().first == j) {
                cout << '$';
            }
            else if (i == f.getLocation().second && f.getLocation().first == j) {
                cout << '0';
            }
            else {
                bool isBody = false;
                for (int k = 0; k < s.getBodySize() - 1; k++)
                {
                    if (i == s.getBody(k).second && j == s.getBody(k).first)
                    {
                        cout << 'O';
                        isBody = true;
                        break;
                    }
                }

                if (!isBody) cout << ' ';
            }
        }
        cout << '#' << endl;
    }
}
int main() {
    bool gameover = false;
    char k;
    snake s;
    s.setSnake(WIDTH, HEIGHT);
    Food f;
    int score = 0;
  
    srand(time(NULL));
    f.genFood(WIDTH, HEIGHT);

    while (!gameover) {
       system("CLS");
       display(s,f,score);
       cout << s.getHead().first<< ' ' << s.getHead().second << endl;
       cout << f.getLocation().first<< ' ' << f.getLocation().second;
       if (_kbhit()) {
            k = _getch();
            if (k == 'w' || k == 'a' || k == 's' || k == 'd') {
                s.setdir(k);
            }
        }
        Sleep(1000 / 30); //limit framerate
        

       if (s.eat(f.getLocation())) {
       
           f.genFood(WIDTH, HEIGHT);
           s.growBody();
           score++;
       }

       s.movement();
       gameover = s.collision(WIDTH, HEIGHT);
        
         
    }
    //cout << s.getX();
    return 0;
}
