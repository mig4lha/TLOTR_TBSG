// unit_management.h
#ifndef UNIT_BUILDING_MANAGEMENT_H
#define UNIT_BUILDING_MANAGEMENT_H

#define MAX_UNIT_TYPE_DESC_SIZE 10
#define MAX_BUILDING_TYPE_DESC_SIZE 8
#define MAX_FACTION_DESC_SIZE 7
#define MAX_UNIT_CODE_SIZE 3
#define MAX_BUILDING_CODE_SIZE 5

// Mine Building Set Income Value
#define MINE_INCOME 5

// Enum defining the factions
enum Faction {
    GONDOR,
    MORDOR,
    NUM_FACTIONS  // Total number of factions
};

// Enum defining different unit types
enum UnitType {
    INFANTRY,
    CAVALRY,
    ARTILLERY,
    NUM_UNIT_TYPES  // Total number of unit types
};

// Enum defining different building types
enum BuildingType {
    BASE,
    MINE,
    BARRACK,
    STABLE,
    ARMOURY,
    NUM_BUILDING_TYPES  // Total number of building types
};

// Struct representing a unit
struct Unit {
    enum Faction faction;
    char unit_faction_desc[MAX_FACTION_DESC_SIZE];
    enum UnitType unit_type;
    char unit_type_desc[MAX_UNIT_TYPE_DESC_SIZE];
    char unit_code[MAX_UNIT_CODE_SIZE];
    int unit_cost;
    int movement_costs;
    int health_points;
    int attack_power;
};

// Struct representing a building
struct Building {
    enum Faction faction;
    char building_faction_desc[MAX_FACTION_DESC_SIZE];
    enum BuildingType building_type;
    char building_type_desc[MAX_BUILDING_TYPE_DESC_SIZE];
    char building_code[MAX_UNIT_CODE_SIZE];
    int building_cost;
    int health_points;
};

// Struct representing a faction with its unit types and associated letter codes
struct FactionUnits {
    enum Faction faction;
    const char* unitTypeCodes[NUM_UNIT_TYPES];
};

// Struct representing a faction with its building types and associated letter codes
struct FactionBuildings {
    enum Faction faction;
    const char* buildingsTypeCodes[NUM_BUILDING_TYPES];
};

extern const char* factionNames[NUM_FACTIONS];
extern const char* unitTypeNames[NUM_UNIT_TYPES];
extern const char* buildingTypeNames[NUM_BUILDING_TYPES];
extern const char* unitTypeCodes[NUM_UNIT_TYPES * NUM_FACTIONS];
extern const char* buildingsTypeCodes[NUM_BUILDING_TYPES * NUM_FACTIONS];

void initializeFactionUnits(struct FactionUnits* factionUnits, enum Faction faction);
void initializeUnit(struct Unit* unit, enum UnitType unitType, const struct FactionUnits* factionUnits);
void initializeFactionBuildings(struct FactionBuildings* factionBuildings, enum Faction faction);
void initializeBuilding(struct Building* building, enum BuildingType buildingType, const struct FactionBuildings* factionBuildings);
#endif
