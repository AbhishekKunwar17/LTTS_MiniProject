#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

int i, j, ht = 20, wh = 20;
int finish, score;
int x, y, fx, fy, flag;

// Function to generate the fruit
// within the boundary
void initialize()
{
	finish = 0;

	// Stores height and width
	x = ht / 2;
	y = wh / 2;
label1:
	fx = rand() % 20;
	if (fx == 0)
		goto label1;
label2:
	fy = rand() % 20;
	if (fy == 0)
		goto label2;
	score = 0;
}

// Function to draw the boundaries
void boundary()
{
	system("clear");
	for (i = 0; i < ht; i++) {
		for (j = 0; j < wh; j++) {
			if (i == 0 || i == wh - 1
				|| j == 0
				|| j == ht - 1) {
				printf("#");
			}
			else {
				if (i == x && j == y)
					printf("0");
				else if (i == fx
						&& j == fy)
					printf("*");
				else
					printf(" ");
			}
		}
		printf("\n");
	}

	// Print the score after the
	// game ends
	printf("score = %d", score);
	printf("\n");
	printf("press X to quit the game");
}

// Function to take the input
void input()
{
	if (getchar()) {
		switch (getchar()) {
		case 'a':
			flag = 1;
			break;
		case 's':
			flag = 2;
			break;
		case 'd':
			flag = 3;
			break;
		case 'w':
			flag = 4;
			break;
		case 'x':
			finish = 1;
			break;
		}
	}
}

// Function for the logic behind
// each movement
void logic()
{
	sleep(0.01);
	switch (flag) {
	case 1:
		y--;
		break;
	case 2:
		x++;
		break;
	case 3:
		y++;
		break;
	case 4:
		x--;
		break;
	default:
		break;
	}

	// If the game is over
	if (x < 0 || x > ht
		|| y < 0 || y > wh)
		finish = 1;

	// If snake reaches the fruit
	// then update the score
	if (x == fx && y == fy) {
	label3:
		fx = rand() % 20;
		if (fx == 0)
			goto label3;

	// After eating the above fruit
	// generate new fruit
	label4:
		fy = rand() % 20;
		if (fy == 0)
			goto label4;
		score += 10;
	}
}

// Driver Code
void main()
{
	int m, n;

	// Generate boundary
	initialize();

	// Until the game is over
	while (!finish) {

		// Function Call
		boundary();
		input();
		logic();
	}
}
