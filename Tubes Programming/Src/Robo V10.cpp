#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

struct Robot {
	int x = 13, y = 1;
	int health = 20;
	int damage = 5;
	int distMax = 5;
} R;

struct Kecoa {
	int x = rand() % 14, y = rand() % 14;
	int health = 5;
	int bosshealth = 15;
	int damage = 5;
	void move() {
		int move;
		move = rand() % 4;
		if (move == 0) x++;
		else if (move == 1) y++;
		else if (move == 2) x--;
		else if (move == 3) y--;
		if (x == 14) x -= 2;
		if (x == 0) x += 2;
		if (y == 14) y -= 2;
		if (y == 0) y += 2;
	}
} K;

double d(Robot R, Kecoa K) {
	return sqrt(double((R.x - K.x) * (R.x - K.x) + (R.y - K.y) * (R.y - K.y)));
}

void upd_map(char map[15][15]) {
	for (int i = 0; i < 15; i++)
	{
		map[0][i] = '#';
		map[14][i] = '#';
		map[i][0] = '#';
		map[i][14] = '#';
	}
	for (int i = 1; i < 14; i++)
	{
		for (int j = 1; j < 14; j++)
		{
			map[i][j] = '.';
		}
	}
	if (K.x == 0) K.x++;
	if (K.x == 14) K.x--;
	if (K.y == 0) K.y++;
	if (K.y == 14) K.y--;
	while (K.x == R.x && K.y == R.y) {
		K.x = rand() % 14, K.y = rand() % 14;
		if (K.x == 0) K.x++;
		if (K.x == 14) K.x--;
		if (K.y == 0) K.y++;
		if (K.y == 14) K.y--;
	}
	map[R.x][R.y] = 'R';
	map[K.x][K.y] = 'K';
}

void show_map(char map[15][15]) {
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << "Use wasd to move, e to shoot, and x to exit\n";
}

int main()
{
	char map[15][15];
	bool gameover, miss, nabrak;
	int score;
	char dir;

	score = 0;
	gameover = false;
	miss = false;
	nabrak = false;

	upd_map(map);
	cout << "Score         :" << score << endl;
	cout << "Robot Health  :" << R.health << endl;
	cout << "Distance      :" << d(R, K) << endl;
	show_map(map);

	//Commands
	while (!gameover)
	{
		miss = false;
		nabrak = false;

		cin >> dir;
		if (score % 3 == 0 && score != 0) {
			switch (dir) {
			case 'w':
				R.x -= 1;
				if (R.x == 0) R.x += 1;
				if (R.x == K.x && R.y == K.y) { R.x += 1, nabrak = true; }
				break;
			case 's':
				R.x += 1;
				if (R.x > 13) R.x -= 1;
				if (R.x == K.x && R.y == K.y) { R.x -= 1, nabrak = true; }
				break;
			case 'a':
				R.y -= 1;
				if (R.y == 0) R.y += 1;
				if (R.x == K.x && R.y == K.y) { R.y += 1, nabrak = true; }
				break;
			case 'd':
				R.y += 1;
				if (R.y > 13) R.y -= 1;
				if (R.x == K.x && R.y == K.y) { R.y -= 1, nabrak = true; }
				break;
			case 'e':
				if (d(R, K) <= R.distMax)
				{
					K.bosshealth -= R.damage;
				}
				else miss = true;
				break;
			case 'x':
				gameover = true;
			default:
				break;
			}

			if (K.bosshealth == 0) {
				Kecoa A;
				K = A;
				score += 4;
			}
		}
		else {
			switch (dir)
			{
			case 'w':
				R.x -= 1;
				if (R.x == 0) R.x += 1;
				if (R.x == K.x && R.y == K.y) { R.x += 1, nabrak = true; }
				break;
			case 's':
				R.x += 1;
				if (R.x > 13) R.x -= 1;
				if (R.x == K.x && R.y == K.y) { R.x += 1, nabrak = true; }
				break;
			case 'a':
				R.y -= 1;
				if (R.y == 0) R.y += 1;
				if (R.x == K.x && R.y == K.y) { R.y += 1, nabrak = true; }
				break;
			case 'd':
				R.y += 1;
				if (R.y > 13) R.y -= 1;
				if (R.x == K.x && R.y == K.y) { R.y -= 1, nabrak = true; }
				break;
			case 'e':
				if (d(R, K) <= R.distMax)
				{
					score += 1;
					K.x = rand() % 14;
					K.y = rand() % 14;
				}
				else miss = true;
				break;
			case 'x':
				gameover = true;
			default:
				break;
			}
		}

		//User Interface
		system("cls");
		if (score % 3 == 0 && score != 0) {
			cout << "Boss Health   :" << K.bosshealth << endl;
			int prevx = K.x, prevy = K.y;
			K.move();
			if (K.x == R.x && K.y == R.y) {
				nabrak = true;
				K.x = prevx, K.y = prevy;
			}
		}
		else cout << "Kecoak Health :" << K.health << endl;

		if (nabrak)
		{
			R.health -= K.damage;
			cout << "-" << K.damage << " Health" << endl;
		}
		upd_map(map);
		cout << "Score         :" << score << endl;
		cout << "Robot Health  :" << R.health << endl;
		cout << "Distance      :" << d(R, K) << endl;
		show_map(map);
		if (miss == true) cout << "You missed !" << endl;
		if (R.health == 0 || gameover)
		{
			gameover = true;
			cout << "Great Job, Fighter!" << endl;
			cout << "Your score is " << score << endl;

			char a;
			cout << "Try again? (y) (n)" << endl;
			cin >> a;
			switch (a) {
			case 'y': {gameover = false; score = 0; R.health = 20; system("cls"); show_map(map); break; }
			default: break;
			}
		}
	}
	return 0;
}