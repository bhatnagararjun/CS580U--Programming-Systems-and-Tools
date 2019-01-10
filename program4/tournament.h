#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Player{
	int offensive;
	int defensive;
	int number;
	int team;
	char * first;
	char * last;
} Player;

typedef struct Team{
	char * name;
	Player * players;
	void (*delete)( struct Team *);
} Team;

Player * draftPlayers(char * Filename,int team,int num_players);
Team * newTeam(char * name, Player * players);
Team *game(Team * team1,Team * team2);
Team * tournament(Team **winners,int count);
void deleteTeam(Team *team);
#endif
