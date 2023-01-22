#include <stdio.h>

// Normally all the scores starts off with a zero
	
	int gamesA = 0, gamesB = 0;
	int pointsA = 0, pointsB = 0;
	int setsA = 0 , setsB = 0;
	
	int A[5], B[5];
	int service = -1, counter=0, i, j; // service is an odd number because the players switch sides when the scores are odd
	
	// ffuntion to display results 

int results()
{
				if(service==-1)
					{
						printf("Team A to serve\n");
					}
					else {
						printf("Team B to serve\n");
					}
				for(j=0; j<counter; j++)
				{
					if(service == -1)
					{
						printf("%d - %d\n", A[j], B[j]);
					}
					else {
						printf("%d - %d\n", B[j], A[j]);
					}
				}
				/* now we can print the current set score */
	            if ( service == -1 )
	                printf("%d - %d\n", gamesA, gamesB);
	            else
	                printf("%d - %d\n", gamesB, gamesA);
	            /* and now print the current game score */
	            
            if (pointsA < 3 || pointsB <3)
            {
                if ( service == -1 )
                {
                    if (pointsA == 0)
                    {
                        printf("Love");
                    }
                    else
                    {
                        printf("%d", pointsCalc(pointsA));
                    }
                    printf(" - ");
                    if (pointsB == 0)
                    {
                        printf("Love");
                    }
                    else
                    {
                        printf("%d", pointsCalc(pointsB));
                    }
                }
                else
                {
                    if (pointsB == 0)
                    {
                        printf("Love");
                    }
                    else
                    {
                        printf("%d", pointsCalc(pointsB));
                    }
                    printf(" - ");
                    if (pointsA == 0)
                    {
                        printf("Love");
                    }
                    else
                    {
                        printf("%d", pointsCalc(pointsA));
                    }
                }
                printf("\n");
            }
            else if (pointsA == pointsB)
            {
                printf("Deuce");
            }
            else
            {
                if (service == -1)
                {
                    if (pointsA > pointsB)
                    {
                        printf("Advantage Server\n");
                    }
                    else
                        printf("Advantage Receiver\n");
                }
                else
                {
                    if (pointsB > pointsA)
                    {
                        printf("Advantage Server\n");
                    }
                    else
                        printf("Advantage Receiver\n");
                }
            }
}
	
int pointsCalc(int pointsWon)
{
    if (pointsWon == 1)
    {
        return 15;
    }
    if (pointsWon == 2)
    {
        return 30;
    }
    if (pointsWon == 3)
    {
        return 40;
    }
}

int main()
{
	printf("============================\n");
	printf("\n          SCOREBOARD        \n");
	printf("\n============================\n");
	
	char team;
	printf("\nEnter the team\n\n");
	printf("A: TEAM A SCORES\nB: TEAM B SCORES\n\n");
	for(i=0; i<144; i++)
	{
		scanf("%c", &team);
		switch(team)
		{
			case 'A':
				pointsA++;
				if (pointsA >= 4 && (pointsA - pointsB) >= 2  )
            	{
                /* we are updating the games won */
                	gamesA++;
                	 //checking to see if he won the game
                	if (gamesA >= 6 && (gamesA-gamesB) >= 2)
                	{
                		
                    /* player A has won the set, so we save the set score and update the games won */
                    A[counter] = gamesA;
                    B[counter] = gamesB;
                    counter ++ ;
                    gamesA = 0;
                    gamesB = 0;

                    /* we are updating the sets won */
                    setsA ++;
                    
                    /* now we check to see did player A won the game,
                        that means that he won at least 3 sets */
                    if (setsA >= 3)
                    {
                        printf("Player A wins: ");
                        int i;
                        for (i=0; i<counter; i++)
                        {
                                printf("%d - %d ", A[i], B[i]);
                        }
                        printf("\n");
                    }
					}
					/* player A has won the game so we can reset the points for both player */
                pointsA = 0;
                pointsB = 0;
                /* and after every game we need to change the player serving */
                service = service * -1;
            }
            	// Now for displaying the results
					printf("%d", results());
					
			break;
			
			case 'B':
				pointsB++;
				if (pointsB >= 4 && (pointsB - pointsA) >= 2  )
            {
                /* we are updating the games won */
                gamesB++;
                /* now we need to check did player B won the set
                    that means that he won at least 6 games, and the
                    diffrence between the games won is >=2 */
                if (gamesB >= 6 && (gamesB - gamesA) >= 2)
                {
                    /* player A has won the set, so we save the set score and update the games won */
                    A[counter] = gamesA;
                    B[counter] = gamesB;
                    counter ++ ;
                    gamesA = 0;
                    gamesB = 0;

                    /* we are updating the sets won */
                    setsB++;
                     /* now we check to see did player A won the game,
                        that means that he won at least 3 sets */
                    if (setsB >= 3)
                    {
                        printf("Player B wins: ");
                        int i;
                        for (i=0; i<counter; i++)
                        {
                                printf("%d - %d ", B[i], A[i]);
                        }
                        printf("\n");
                    }
                }
                /* player A has won the game so we can reset the points for both player */
                pointsA = 0;
                pointsB = 0;
                /* and after every game we need to change the player serving */
                service = service * -1;
		}
		printf("%d", results());
	}
}
}

