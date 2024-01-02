// player_management.c
#define _CRT_SECURE_NO_WARNINGS

#include "player_management.h"
#include <stdio.h>

// Initialize faction availability flags
int factionAvailable[NUM_FACTIONS] = { 1, 1 };  // Initially, both factions are available

// Function to initialize a player with starting gold
void initializePlayer(struct Player* player, enum Faction chosenFaction, int order) {
    // Check if the chosen faction is available
    if (factionAvailable[chosenFaction]) {
        // Set the chosen faction
        player->faction = chosenFaction;

        // Set the initial amount of gold
        player->gold = STARTING_GOLD;

        player->order = order;

        // Mark the chosen faction as not available for the next player
        factionAvailable[chosenFaction] = 0;
    }
    else {
        // Faction is not available, handle error or choose a default faction
        // For simplicity, let's choose the other faction as the default
        player->faction = (chosenFaction == MORDOR) ? GONDOR : MORDOR;
        player->gold = STARTING_GOLD;
        player->order = order;
    }
}

// Function to display the menu options
void displayMenu() {
    printf("Menu:\n");
    printf("1. Place Unit\n");
    printf("2. Place Building\n");
    printf("3. Move Unit\n");
    printf("4. Move Building\n");
    printf("5. End Turn\n");
}

// Function to perform player actions during their turn
int performPlayerTurn() {
    int action;

    // Display the menu options
    displayMenu();

    // Get the player's chosen action
    printf("\nChoose an action (1-5): ");
    scanf("%d", &action);

    // Handle the chosen action
    return action;
}

// Function to display player information
void displayPlayer(const struct Player* player) {
    printf("Player %d's Turn\n", player->order);

    const char* factionNames[NUM_FACTIONS] = {
        "MORDOR",
        "GONDOR"
    };

    printf("Faction: %s\n", factionNames[player->faction]);
    printf("Gold: %d\n", player->gold);
    printf("Order: %d\n", player->order);
}
