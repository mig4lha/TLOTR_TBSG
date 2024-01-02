// player_management.h
#ifndef PLAYER_MANAGEMENT_H
#define PLAYER_MANAGEMENT_H

#include "unit_building_management.h";

// Define the starting gold value
#define STARTING_GOLD 100

// Define the player structure
struct Player {
    enum Faction faction;
    int order;
    int gold;
};

// Define flags to track faction availability
extern int factionAvailable[NUM_FACTIONS];

// Function to initialize a player with starting gold
void initializePlayer(struct Player* player, enum Faction chosenFaction);
void displayMenu();
int performPlayerTurn();

// Function to display player information
void displayPlayer(const struct Player* player);

#endif  // PLAYER_MANAGEMENT_H
