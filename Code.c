#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10
int main()
{
	int A[16][3], T[16][3] = {0};
	int x, y, j, i, c = 0, z = 0, flag, seat, t1c = 0, t2c = 0, flagtc1 = 0, flagtc2 = 0, end = 0;
	int row = 0, column = 0;
	int s, seattype;
	int type;
	srand(time(0));
	for (i = 1; i <= 15; i++)				//to creat the array
	{
		for (j = 1; j <= 2; j++)
		{
			c = c + 1;
			A[i][j] = c;
		}
	}

	printf("hello to flight reservation\n");
	printf("Type 1 for First Class\n");
	printf("Type 2 for Economy\n");
	do{											//seat
		if (t1c >= 10) flagtc1 = 1;
		if (t2c >= 20) flagtc2 = 1;
	do{										//Function to control the input
		seattype = 0;
		printf("chose the type : ");		//function to chose the type
		scanf("%d", &type);
		if (type == 1 && t1c < 10)
			seattype = 1;

		if (type == 2 && t2c < 20)
			seattype = 2;

		if (type == 1 && flagtc1 == 1)
			printf("The First Class is full\n");
		if (type == 2 && flagtc2 == 1)
			printf("The Economy is full\n");
		//if (t1c >= 10 && t2c >= 20) end = 1;
	} while (type != 1 && type != 2 || seattype == 0);

	do{																//to control the input
		printf("do you want to sealct the seat (yes 2 , no 1): ");	//to show the seat
		scanf("%d", &s);
	} while (s != 1 && s != 2);
												
		if (s == 2)
		{
				for (x = 1; x <= 15; x++)										//to print normal array
				{
					printf("%2d.\t", x);
					for (y = 1; y <= 2; y++)
					{
						if (T[x][y] == 0)
							printf("%d\t", A[x][y]);
						else
							printf("[%d]\t", A[x][y]);
					}
					printf("\n");
				}

			if (seattype == 2)										//to select seat thit the type 2
			{
				t2c++;
				do{
					printf("you can chose the seat from the sixth row to the fifteenth for Economy class\n");
					printf("Enter a raw : ");
					scanf("%d", &row);
					printf("Enter a column : ");
					scanf("%d", &column);
				} while (row < 6 || row > 15);
			}

			if (seattype == 1)										//to select seat thit the type 1
			{
				t1c++;
				do{
					printf("you can chose the seat from the first row to the fifth for First Class\n");
					printf("Enter a raw : ");
					scanf("%d", &row);
					printf("Enter a column : ");
					scanf("%d", &column);
				} while (row < 0 || row > 5);
			}

			if (row < 1 || row > 15 || column < 1 || column > 2)	//this function to contol input	
			{
				printf("Wrong choice, try again\n");
				printf("========================================================================================\n\n\n\n");
				for (x = 1; x <= 15; x++)
				{
					for (y = 1; y <= 2; y++)
					{
						if (T[x][y] == 0)
							printf("%d\t", A[x][y]);
						else
							printf("[%d]\t", A[x][y]);
					}
					printf("\n");
				}
			}

			else if (T[row][column] == 1)									//the to know if seat is taken					
			{
				if (seattype == 1) t1c--;
				if (seattype == 2) t2c--;
				printf("This seat is taken\n");
				printf("========================================================================================\n\n\n\n");
				for (x = 1; x <= 15; x++)
				{
					printf("%2d.\t", x);
					for (y = 1; y <= 2; y++)
					{
						if (T[x][y] == 0)
							printf("%d\t", A[x][y]);
						else
							printf("[%d]\t", A[x][y]);
					}
					printf("\n");
				}
				printf("\n\n\n\n");
			}

			else														//to print selected seat
			{

				z++;
				T[row][column] = 1;
				printf("\n\n\n\n");
				for (x = 1; x <= 15; x++)
				{
					printf("%2d.\t", x);
					for (y = 1; y <= 2; y++)
					{
						if (T[x][y] == 0)
							printf("%d\t", A[x][y]);
						else
							printf("[%d]\t", A[x][y]);
					}
					printf("\n");
				}
				printf("\n\n\n\n");
			}
		}// end if seat

		if (s == 1)
		{
			printf("your seat\n");
			if (seattype == 2 && t2c < 20)										//to select seat thit the type 2
			{
				do{
					x = 6 + rand() % 10;
					y = 1 + rand() % 2;
				} while (T[x][y] == 1 && t2c != 20);
				T[x][y] = 1;
				t2c++;
				z++;
			}

			if (seattype == 1 && t1c < 10)										//to select seat thit the type 1
			{
				do{
					x = 1 + rand() % 5;
					y = 1 + rand() % 2;
				} while (T[x][y] == 1);
				T[x][y] = 1;
				t1c++;
				z++;
			}
			for (x = 1; x <= 15; x++)
			{
				printf("%2d.\t", x);
				for (y = 1; y <= 2; y++)
				{
					if (T[x][y] == 0)
						printf("%d\t", A[x][y]);
					else
						printf("[%d]\t", A[x][y]);
				}
				printf("\n");
			}
			printf("\n\n\n\n");
		}
		

		} while ((row > 1 || row < 15) && (column > 1 || column < 2) && (z != 30));


		printf("This flight is full please try agian\n");

	
}