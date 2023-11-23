// unit_management.c
#include "unit_building_management.h"

// Array of string representations (letter codes) for each unit type for each Faction
const char* unitTypeCodes[NUM_UNIT_TYPES * NUM_FACTIONS] = {
    // Gondor/Rivendell Units
    "G",    // Infantry (Gondorian Guards)
    "SK",   // Cavalry (Swan-Knights)
    "T",    // Artillery (Trebuchets)
    // Mordor Units
    "OW",   // Infantry (Orc Warriors)
    "W",    // Cavalry (Wargs)
    "ST",   // Artillery (Siege Towers)
};

// Array of string representations (letter codes) for each building type for each Faction
const char* buildingsTypeCodes[NUM_BUILDING_TYPES * NUM_FACTIONS] = {
    // Gondor/Rivendell Buildings
    "GGGG",     // Base (Gondor)
    "SS",       // Mines (Shire)
    "RR",       // Barracks (Rohan)
    "LL",       // Stables (Lothlórien)
    "GF",       // Armoury (Gondorian Forge)
    // Mordor Buildings
    "MMMM",     // Base (Mordor)
    "EE",       // Mines (Erebor)
    "II",       // Barracks (Isengard)
    "MK",       // Stables (Mirkwood)
    "DF",       // Armoury (Dark Forge)
};

// Function to initialize units with their letter codes for a faction
void initializeFactionUnits(struct FactionUnits* factionUnits, enum Faction faction) {
    factionUnits->faction = faction;
    int startIndex = faction * NUM_UNIT_TYPES;

    for (int i = 0; i < NUM_UNIT_TYPES; ++i) {
        factionUnits->unitTypeCodes[i] = unitTypeCodes[startIndex + i];
    }
}

// Function to initialize buildings with their letter codes for a faction
void initializeFactionBuildings(struct FactionBuildings* factionBuildings, enum Faction faction) {
    factionBuildings->faction = faction;
    int startIndex = faction * NUM_BUILDING_TYPES;

    for (int i = 0; i < NUM_BUILDING_TYPES; ++i) {
        factionBuildings->buildingsTypeCodes[i] = buildingsTypeCodes[startIndex + i];
    }
}

// Function to initialize a unit with its properties
void initializeUnit(struct Unit* unit, enum UnitType unitType, const struct FactionUnits* factionUnits) {
    unit->unit_type = unitType;
    unit->attack_power = 1;
    unit->health_points = 1;
    unit->movement_costs = 1;
    unit->unit_cost = 1;
    strcpy(unit->unit_code, factionUnits->unitTypeCodes[unitType]);
}

// Function to initialize a building with its properties
void initializeBuilding(struct Building* building, enum BuildingType buildingType, const struct FactionBuildings* factionBuildings) {
    building->building_type = buildingType;
    building->health_points = 1;
    building->building_cost = 1;
    strcpy(building->building_code, factionBuildings->buildingsTypeCodes[buildingType]);
}

void initializeAllUnitsAndBuildings() {
    struct FactionUnits mordorUnits, gondorUnits;
    struct FactionBuildings mordorBuildings, gondorBuildings;

    // Initialize faction units and buildings
    initializeFactionUnits(&mordorUnits, MORDOR);
    initializeFactionUnits(&gondorUnits, GONDOR);

    initializeFactionBuildings(&mordorBuildings, MORDOR);
    initializeFactionBuildings(&gondorBuildings, GONDOR);

    struct Unit mordorInfantry, mordorCavalry, mordorArtillery;
    struct Unit gondorInfantry, gondorCavalry, gondorArtillery;

    struct Building mordorBase, mordorMine, mordorBarrack, mordorStable, mordorArmoury;
    struct Building gondorBase, gondorMine, gondorBarrack, gondorStable, gondorArmoury;

    // Define units and buildings with their properties (placeholder values)

    // Mordor units
    initializeUnit(&mordorInfantry, INFANTRY, &mordorUnits);
    initializeUnit(&mordorCavalry, CAVALRY, &mordorUnits);
    initializeUnit(&mordorArtillery, ARTILLERY, &mordorUnits);
    // Mordor buildings
    initializeBuilding(&mordorBase, BASE, &mordorBuildings);
    initializeBuilding(&mordorMine, MINE, &mordorBuildings);
    initializeBuilding(&mordorBarrack, BARRACK, &mordorBuildings);
    initializeBuilding(&mordorStable, STABLE, &mordorBuildings);
    initializeBuilding(&mordorArmoury, ARMOURY, &mordorBuildings);

    // Gondor units
    initializeUnit(&gondorInfantry, INFANTRY, &gondorUnits);
    initializeUnit(&gondorCavalry, CAVALRY, &gondorUnits);
    initializeUnit(&gondorArtillery, ARTILLERY, &gondorUnits);
    // Gondor buildings
    initializeBuilding(&gondorBase, BASE, &gondorBuildings);
    initializeBuilding(&gondorMine, MINE, &gondorBuildings);
    initializeBuilding(&gondorBarrack, BARRACK, &gondorBuildings);
    initializeBuilding(&gondorStable, STABLE, &gondorBuildings);
    initializeBuilding(&gondorArmoury, ARMOURY, &gondorBuildings);

    // Display the letter code for each unit and building by faction (debugging prints)
    printf("Game Unit and Building Information:\n");
    printf("Mordor Infantry Unit Code: %s\n", mordorInfantry.unit_code);
    printf("Mordor Cavalry Unit Code: %s\n", mordorCavalry.unit_code);
    printf("Mordor Artillery Unit Code: %s\n", mordorArtillery.unit_code);

    printf("Mordor Base Unit Code: %s\n", mordorBase.building_code);
    printf("Mordor Mine Unit Code: %s\n", mordorMine.building_code);
    printf("Mordor Barrack Unit Code: %s\n", mordorBarrack.building_code);
    printf("Mordor Stable Unit Code: %s\n", mordorStable.building_code);
    printf("Mordor Armoury Unit Code: %s\n", mordorArmoury.building_code);

    printf("\nGondor Infantry Unit Code: %s\n", gondorInfantry.unit_code);
    printf("Gondor Cavalry Unit Code: %s\n", gondorCavalry.unit_code);
    printf("Gondor Artillery Unit Code: %s\n", gondorArtillery.unit_code);

    printf("Gondor Base Unit Code: %s\n", gondorBase.building_code);
    printf("Gondor Mine Unit Code: %s\n", gondorMine.building_code);
    printf("Gondor Barrack Unit Code: %s\n", gondorBarrack.building_code);
    printf("Gondor Stable Unit Code: %s\n", gondorStable.building_code);
    printf("Gondor Armoury Unit Code: %s\n", gondorArmoury.building_code);
    printf("\n\n");
}

