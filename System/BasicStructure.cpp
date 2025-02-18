#include "BasicStructure.h"

/// @brief Constructs a BasicStructure with a specified name, building type, and capacity.
/// @param name The name of the structure.
/// @param Btype The type of building: 'R' for Residential, 'C' for Commercial, 'L' for Landmark, and 'I' for Industrial.
/// @param capacity The maximum capacity of citizens for the structure.
/// @throws std::invalid_argument If capacity is not within a valid range (1-1000).
BasicStructure::BasicStructure(const string& name, char Btype, int capacity)
{
    this->name = name;
    this->type = Btype;
    if ( capacity > 1000 && capacity <= 0){
        throw std::invalid_argument("All parameters must be positive and less than 1000.");
    }


    this->maxCitizen = capacity;
    switch (Btype)
    {
    case 'R':
        maintenanceCost = 20*capacity;
        ResourceConsumption = 0.5*capacity;
        citizenSatisfactionImpact = 100;
        break;
        
    case 'C':
        maintenanceCost = 50*capacity;
        ResourceConsumption = 1.3*capacity;
        citizenSatisfactionImpact = 80;
        break;

    case 'L':
        maintenanceCost = 30*capacity;
        ResourceConsumption = 0.8*capacity;
        citizenSatisfactionImpact = 100;
        break;

    case 'I' :
        maintenanceCost = 70*capacity;
        ResourceConsumption = 1.5*capacity;
        citizenSatisfactionImpact = 40;
        break;
    
    default:
        break;
    }
}


/// @brief Adds a citizen to the structure if space allows.
/// @param c Pointer to the Citizen to add.
/// @throws std::invalid_argument If the citizen is null or the structure is at max capacity.
void BasicStructure::addcitizen(int number)
{
    if( number < 0){
        throw invalid_argument("Citizen cannot be negative"); 
    }

    // Check if there is enough space in the structure
    if((numCitizen + number) > maxCitizen ){
        throw invalid_argument("Structure is already full");
    }
    
    numCitizen += number;
}

/// @brief Gets the type of building as a string representation.
/// @return A string representing the building type (Residential, Commercial, Industrial, Landmark).
string BasicStructure::getType()
{
    switch (type)
    {
    case 'R':
        return "Residential";
        break;
    case 'C':
        return "Commercial";
        break;

    case 'I':
        return "Industrial";
        break;

    case 'L':
        return "Landmark";
        break;
    default:
        break;
    }
    return "";
}

/// @brief Removes a citizen from the structure, decrementing the count.
void BasicStructure::removeCitizen(int number)
{
    if((numCitizen -= number) < 0){
        throw invalid_argument("amount to be removed is more than amount of citizens in building");  // Throw an error if the number of citizens to be removed is negative
    }else{
        numCitizen -= number;  // Decrement the number of citizens in the building
    }
}

/// @brief Throws an exception because BasicStructure is a leaf node and cannot contain children.
/// @param structure The structure to add (not used).
/// @throws std::runtime_error Always, as BasicStructure cannot contain children.
void BasicStructure::add(Structure* structure) {
    throw std::runtime_error("Operation not supported: BasicStructure is a leaf and cannot contain children.");
}

/// @brief Throws an exception because BasicStructure is a leaf node and cannot contain children.
/// @param structure The structure to remove (not used).
/// @throws std::runtime_error Always, as BasicStructure cannot contain children.
void BasicStructure::remove(Structure* structure) {
    throw std::runtime_error("Operation not supported: BasicStructure is a leaf and cannot contain children.");
}

// @brief Retrieves child structures (not applicable for BasicStructure).
/// @return An empty vector, as BasicStructure has no children.
std::vector<Structure*> BasicStructure::getChildren() {
    return {};  // Return an empty vector, as BasicStructure has no children
}

/// @brief Gets the name of the structure.
/// @return The name of the structure.
string BasicStructure::getName() 
{
    return name;
}

/// @brief Gets the maintenance cost of the structure.
/// @return The maintenance cost.
float BasicStructure::getMaintenance() 
{
    return maintenanceCost;
}

/// @brief Gets the resource consumption of the structure.
/// @return The resource consumption
float BasicStructure::getResourceConsumption() 
{
    return ResourceConsumption;
}

/// @brief Gets the citizen satisfaction impact of the structure.
/// @return The citizen satisfaction impact.
float BasicStructure::getCitizenSatisfactionImpact() {
    return citizenSatisfactionImpact;
}

/// @brief Destructor for BasicStructure.
BasicStructure::~BasicStructure(){
    // No resources to deallocate
}
/// @brief Adds utilities to a specific building
void BasicStructure::addUtilities(string &request, Structure* s){
    Utilities *ut = new Utilities(s);
    Utilities *pt = new PowerUtility(s);
    Utilities *wt = new WaterUtility(s);
    Utilities *wst = new WasteUtility(s);
    Utilities *st = new SewageUtility(s);
    ut->setNext(pt);
    pt->setNext(wt);
    wt->setNext(wst);
    wst->setNext(st);
    ut->processRequest(request);
}

void BasicStructure::subTract(){
    if(kilowatts < 50){
        kilowatts = 0;
    }
    else{
        kilowatts = kilowatts - 50;
    }
    if(availableWater < 50){
        availableWater = 0;
    }
    else{
        availableWater = availableWater - 50;
    }
    sewageThere += 50;
    wasteThere += 50;
}
float BasicStructure::getKilowatts() {
    return kilowatts;
}

/// @brief  Setter for kilowatts
void BasicStructure::setKilowatts(float kw) {
    kilowatts = kw;
}

/// @return  Getter for availableWater
float BasicStructure::getAvailableWater() {
    return availableWater;
}

/// @brief Setter for availableWater
void BasicStructure::setAvailableWater(float water) {
    availableWater = water;
}

/// @return  Getter for sewageAmount
float BasicStructure::getSewageAmount() {
    return sewageThere;
}

/// @brief Setter for sewageAmount
void BasicStructure::setSewageAmount(float sewage) {
    sewageThere = sewage;
}

/// @brief Getter for wasteAmount
float BasicStructure::getWasteAmount() {
    return wasteThere;
}

/// @brief Setter for wasteAmount
void BasicStructure::setWasteAmount(float waste) {
    wasteThere = waste;
    // No resources to deallocate
}
