#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tournament.h"

Player * newMyPlayer(Player *ptr){
	ptr->offensive;
	ptr->defensive;
	ptr->number;
	ptr->team;
	char * first= malloc(32);
	char * last= malloc(32);
	return ptr;
	
}
Player * draftPlayers(char * filename,int team,int num_players){
	FILE * f = fopen(filename,"r");
       	int flag=0,flag1;
        char buf[100];
        Player * ptr = malloc(sizeof(Player)* num_players);
	char *ptr1;
        int k=0;
        int player_count=0;
	if(f != NULL){
		while(fgets(buf,100,f)){
			ptr1=strtok(buf,",");
			while(ptr1 != NULL){
				if(flag==0){
					ptr= newMyPlayer(ptr);
                              		if(team == atoi(ptr1)){
                                        	ptr[player_count].team=atoi(ptr1);
                                        	flag++;
                                        	flag1=1;
                                	}
					else {
						break;
					}
                        	}	
                        	else if(flag == 1){
                                	if(flag1==1){
						ptr[player_count].first=malloc(32);
                                        	strcpy(ptr[player_count].first,ptr1);
                                        	flag++;
                                	}
                        	}
                        	else if(flag == 2){
                                	if(flag1==1){
						ptr[player_count].last=malloc(32);
                                        	strcpy(ptr[player_count].last,ptr1);
                                        	flag++;
                                	}
                        	}
                        	else if(flag ==3){
                                	if(flag1==1){
                                        	ptr[player_count].number=atoi(ptr1);
                                        	flag++;
                                	}
                        	}
                        	else if(flag ==4){
                                	if(flag1==1){
                                        	ptr[player_count].offensive=atoi(ptr1);
                                        	flag++;
                                	}
                        	}
                        	else if(flag==5){
                                	if(flag1==1){
                                        	ptr[player_count].defensive=atoi(ptr1);
                                        	flag++;
						player_count ++;
                                	}
                        	}	
                	ptr1= strtok(NULL,",");
			}
                	flag=0;
                	flag1=0;
        	}
        	fclose(f);
	}
	return ptr;
}
Team * newTeam(char * name, Player * players){
        Team * ptr= malloc(sizeof(Team));
	ptr->name=malloc(sizeof(name));
	strcpy(ptr->name,name);
	ptr->players = players;
     	ptr->delete=&deleteTeam;
     	return ptr;
}

Team * game(Team * team1,Team * team2){
	if(team1 == NULL || team2 == NULL)
		return NULL;
        int total_defensive=0;
        int total1_defensive=0;
        int total_offensive=0;
        int total1_offensive=0;
        int count1=0;
        int count2=0;
        for(int i =0;i<10;i++){
                        total1_defensive += team1->players[i].defensive;
                        total_defensive +=team2->players[i].defensive;
                        total1_offensive +=team1-> players[i].offensive;
                        total_offensive += team2-> players[i].offensive;
        }
	int x1=rand()%total1_offensive;
	int x2=rand()%total_offensive;
	for(int i=1;i<=2;i++){
               	if(total_defensive > x1){
                       	count1++;
               	}
               	if(total1_defensive > x2){
                       	count2++;
               	}
	}
        if(count1>count2)
                return team1;
        else
                return team2;
}

Team * tournament(Team ** winners, int count){
	
    int n = count;
    int flag = 0;
    int team_cnt = n;
    int team_cnt1 = n-1;
    int j=0;
    Team *stgwinner=NULL;
    Team *ch1 = NULL;
    Team *ch2 = NULL;
    Team *ch3 = NULL;
    Team *ch4 = NULL;
    Team *ch5 = NULL;
    Team *ch6 = NULL;
    Team *ch7 = NULL;
    while(n>1){
    	if(n%2!=0){
    		flag=1;
    		break;
    	}
    	n=n/2;
    }
    if(flag==1){
    	printf("Team count is invalid");
    	return NULL;
    }
    int value;
    if  (team_cnt  >= 8){
    	value = team_cnt / 8;
    }
   if (team_cnt == 2){
    ch1 =  game(winners[0], winners[1]);
    return ch1;
   }
   if (team_cnt == 4){
    ch1 =  game(winners[0], winners[1]);
    ch2 =  game(winners[2], winners[3]);
    ch3 =  game(ch1,ch2);
    return ch3;
   }
   if (team_cnt >= 8)
   {
   for (;j<value;j++)
    {
        if (j==0)
        {
            team_cnt = team_cnt - 1;
            ch1 =  game(winners[team_cnt1-team_cnt], winners[team_cnt]);
            team_cnt = team_cnt - 1;
	    ch2 =  game(winners[team_cnt1-team_cnt], winners[team_cnt]);
	    team_cnt = team_cnt -1;
	    ch3 =  game(winners[team_cnt1-team_cnt], winners[team_cnt]);
	    team_cnt = team_cnt -1;
            ch4 =  game(winners[team_cnt1-team_cnt], winners[team_cnt]);
            ch5 = game(ch1,ch2);
	    ch6 = game(ch3,ch4);
            stgwinner = game(ch5,ch6);
        }
        if (j > 0)
        {
            team_cnt = team_cnt - 1;
            ch1 =  game(winners[team_cnt1-team_cnt], winners[team_cnt]);
            team_cnt = team_cnt - 1;
            ch2 =  game(winners[team_cnt1-team_cnt], winners[team_cnt]);
            team_cnt = team_cnt -1;
            ch3 =  game(winners[team_cnt1-team_cnt], winners[team_cnt]);
            team_cnt = team_cnt -1;
            ch4 =  game(winners[team_cnt1-team_cnt], winners[team_cnt]);
            ch5 = game(ch1,ch2);
            ch6 = game(ch3,ch4);
            ch7 = game(ch5,ch6);
	    stgwinner = game(ch7,stgwinner);
        }
    }
    }
    return stgwinner;
}



void deleteTeam(Team * teamA){
	free(teamA->players);
	free(teamA);
}

