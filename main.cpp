/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================     
 If you completed Project 3:
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.

 */
#include <iostream>
/*
 copied UDT 1:
 */
struct Car
{
    Car();
    ~Car();

    int numWheels = 4;
    int numSeats = 5;
    double maxVelocity, averageFuel, maxLoad;
    int serviceIntervalMonth = 12;

    struct Engine
    {
        Engine();
        ~Engine();
        
        bool isOriginalPart = true;
        std::string engineCode = "77AA3B";
        int numCylinder, numValves;
        double strokeVolume = 3.2;

        void burnFuel(std::string fuelType, int maxOctaneNumber = 98);
        void rotateAxles(double maxTorque, bool isFourWheelDrive = false);
        double compressAir(double resonanceFrequency);
    };

    void driveForward(int numGear, bool isBrakeReleased = true);
    double consumeFuel(bool pedalKickdown = true);
    void changeSparePart(Engine newEngine);
    void carService(int reminderTimeMonth);
    int refuelCar( int fuelCapacity );

    Engine engineBeingChanged;
};

Car::Car() : maxVelocity(210.5), averageFuel(6.5), maxLoad(215.5)
{
    std::cout << "Car being constructed!" << std::endl;
}

Car::~Car()
{
    std::cout << "Car deconstructed!" << std::endl;
}

Car::Engine::Engine() : numCylinder(6), numValves(16)
{
    std::cout << "Engine being constructed!" << std::endl;
}

Car::Engine::~Engine()
{
    std::cout << "Engine deconstructed!" << std::endl;
}

void Car::Engine::burnFuel(std::string fuelType, int maxOctaneNumber )
{
    if( maxOctaneNumber == 98 )
    {
        fuelType = "SuperPlus";
    }
}

void Car::Engine::rotateAxles(double maxTorque, bool isFourWheelDrive)
{
    if( isFourWheelDrive == true )
    {
        maxTorque += 10.5;
    }
}

double Car::Engine::compressAir(double resonaceFrequency)
{
    double pressure = 0.0;
    pressure = resonaceFrequency * 10;
    std::cout << "Compressing Air in " << numCylinder << " Cylinders" << std::endl;
    return pressure; 
}

void Car::driveForward(int numGear, bool isBrakeReleased)
{
    if( isBrakeReleased == true )
    {
        numGear = 1;
    }
}

double Car::consumeFuel(bool pedalKickdown)
{
    std::cout << "The average amount of fuel used is: " << averageFuel << std::endl;
    if( pedalKickdown == true )
    {
        averageFuel *= 2;
    }
    return averageFuel;
}

void Car::changeSparePart(Car::Engine newEngine)
{
    newEngine = engineBeingChanged;
}

void Car::carService(int reminderTimeMonth)
{
    int i = 0;
    while( i < serviceIntervalMonth )
    {
         ++i;
        if ( i == reminderTimeMonth )
        {
            std::cout << "It is time to book a service" << std::endl;
        }     
    }
    std::cout << "Service time overdue!" << std::endl;
}

int Car::refuelCar(int fuelCapacity)
{
    int currentFuel = 5;
    std::cout << "Starting Refueling. Fuel is: "  << currentFuel << std::endl;
        
    for ( currentFuel = 5; currentFuel <= fuelCapacity; currentFuel +=5 )
    {
        std::cout << "adding fuel" << std::endl;
    }
    return currentFuel;
}
/*
 copied UDT 2:
 */
struct Bicycle
{
    Bicycle();
    ~Bicycle();

    double diameterWheels, sizeFrame;
    int numGears = 21;
    std::string typeBrakes = "disc";
    double price = 500.50;

    void transportHuman();
    int shiftGear(int numActualGear);
    void decelarateBike();
    int checkGear( int startGear, int lastGear);
    
};

Bicycle::Bicycle() : diameterWheels(28.5), sizeFrame(40.5)
{
    std::cout << "Bicycle being constructed!" << std::endl;
}

Bicycle::~Bicycle()
{
    std::cout << "Bicycle deconstructed!" << std::endl;
}

void Bicycle::transportHuman()
{
}

int Bicycle::shiftGear(int numActualGear)
{
    int lastgear = numActualGear;
    numActualGear = lastgear + 1;
    return numActualGear;
}

void Bicycle::decelarateBike()
{
}

int Bicycle::checkGear(int startGear, int lastGear)
{
    int actualGear = startGear -1;
        
    while ( actualGear <= lastGear )
    {
        ++actualGear;
        std::cout << "Checking Gear Nr.:" << actualGear << std::endl;
        if ( actualGear == 8 || actualGear == 15)
        {
            std::cout << "changing to next wheel sprocket." << std::endl;  
        }
        if ( actualGear == lastGear)
        {
            std::cout << "This was the last gear to check." << std::endl;
            return actualGear;   
        }    
    }  
    return 0;
}

/*
 copied UDT 3:
 */
struct Player
{
    Player();
    ~Player();

    std::string namePlayer;
    float startXPos {0.0f};
    float startYPos = 10.05f;
    int speedX = 10;
    int speedY = 5;
    int timeLastShoot = 5;

    struct Weapon
    {
        Weapon();
        ~Weapon();
        
        bool isWeaponFreeZone = false;
        std::string weaponType;
        int numBullets = 10;
        int damage = 100;
        int noiseType = 2;

        void shootBullet(double bulletCoordinateX, double bulletCoordinateY);
        void makeNoise(bool isSoundDeviceActive = true);
        void changeBulletPattern(int bulletPatternNum);
    };

    void moveX();
    void moveY();
    void getWeaponUpgrade(Weapon newWeapon);
    int collisionCheck( int numCollisionObjects);

    Weapon weaponUpgrade;
};

Player::Player() : namePlayer("Player One")
{
    std::cout << "Player: " << namePlayer << " being constructed!" << std::endl;
}

Player::~Player()
{
    std::cout << "Player deconstructed!" << std::endl;
}

Player::Weapon::Weapon() : weaponType("Shotgun")
{
    std::cout << "Weapon being constructed!" << std::endl;
}

Player::Weapon::~Weapon()
{
    std::cout << "Weapon deconstructed!" << std::endl; 
}

void Player::Weapon::shootBullet(double bulletCoordinateX, double bulletCoordinateY)
{
    bulletCoordinateX += 1;
    bulletCoordinateY += 1;
}

void Player::Weapon::makeNoise(bool isSoundDeviceActive)
{
    if( isSoundDeviceActive == true)
    {
        noiseType = 1;
    }
}

void Player::Weapon::changeBulletPattern(int bulletPatternNum)
{
    bulletPatternNum += 1;  
}

void Player::moveX()
{
    std::cout << "Player " << namePlayer << " moved in X" << std::endl;
}

void Player::moveY()
{
    std::cout << "Player " << namePlayer << " moved in Y" << std::endl;
}

void Player::getWeaponUpgrade(Player::Weapon newWeapon)
{
    newWeapon = weaponUpgrade;
}

int Player::collisionCheck(int numCollisionObjects)
{
    for ( int i =1; i <= numCollisionObjects; ++i)
    { 
        std::cout << "Checking Collision" << std::endl;
    }
    return numCollisionObjects;
}
/*
 new UDT 4:
 with 2 member functions
 */

struct CarWorkShop
{
    CarWorkShop();
    ~CarWorkShop();

    Car car1;
    Car::Engine exchangeEngineOne;

    void standardService( Car );
    void chargeCustomer (int workingHours, int hourlyRate);
};

CarWorkShop::CarWorkShop()
{
    std::cout << "CarWorkshop constructed!" << std::endl;
}

CarWorkShop::~CarWorkShop()
{
    std::cout << "CarWorkshop deconstructed!" << std::endl;
}

void CarWorkShop::standardService( Car )
{
    std::cout << "Working on Order One." << std::endl;
}

void CarWorkShop::chargeCustomer(int workingHours, int hourlyRate)
{
    std::cout << "The invoice for: " << workingHours * hourlyRate << "Credits." << std::endl; 
}

/*
 new UDT 5:
 with 2 member functions
 */

struct ArcadeGame
{
    ArcadeGame();
    ~ArcadeGame();

    Player player1;
    Player::Weapon laser;

    int playerJump(int jumpX, int jumpY);
    void scoreCount(int points, int bonusCollected);
};

ArcadeGame::ArcadeGame()
{
    std::cout << "ArcadeGame constructed!\n";
}

ArcadeGame::~ArcadeGame()
{
    std::cout << "ArcadeGame deconstructed!\n";
}

int ArcadeGame::playerJump(int jumpX, int jumpY)
{
    int jumpLenghtX = player1.speedX * jumpX;
    int jumpHeightY = player1.speedY * jumpY;

    return jumpLenghtX * jumpHeightY;
}

void ArcadeGame::scoreCount(int points, int bonusCollected)
{
    std::cout << "Score Points: " << points * bonusCollected << std::endl;
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */


int main()
{
    Car truck;
    Car::Engine dieselEngine;
    
    truck.driveForward(1, true);
    truck.consumeFuel(true);
    truck.changeSparePart(dieselEngine);
    std::cout << "The car has " << truck.numWheels << " Wheels and " << truck.numSeats << " Seats." << std::endl;
    std::cout << "Amount of consumed fuel: " << truck.averageFuel << " Liters" <<std::endl;
    truck.carService(10);
    int newAmountOfFuel = truck.refuelCar(60);
    std::cout << "New quantity of fuel is: " << newAmountOfFuel << std::endl;
    
    dieselEngine.burnFuel("Diesel", 98);
    dieselEngine.rotateAxles(180.5, true);
    dieselEngine.compressAir(800.35);
    std::cout << "The engine Code is: " << dieselEngine.engineCode << std::endl;

    Bicycle sportBicycle;
    sportBicycle.transportHuman();
    sportBicycle.shiftGear(5);
    sportBicycle.decelarateBike();
    std::cout << "The actual gear is nr. " << sportBicycle.shiftGear(5) << std::endl;
    sportBicycle.checkGear(1, 21);

    Player player1;
    Player::Weapon railGun;
    
    player1.moveX();
    player1.moveY();
    player1.getWeaponUpgrade(railGun);
    std::cout << "Player Name: " << player1.namePlayer << std::endl;
    std::cout << player1.collisionCheck(5) << " possible Collisions checked." << std::endl;
    
    railGun.shootBullet(10.5,20.0);
    railGun.makeNoise(true);
    railGun.changeBulletPattern(2);

    CarWorkShop superGarage;
    superGarage.standardService(truck);
    superGarage.chargeCustomer(5, 70);

    ArcadeGame jumpAndRun;
    int playerJumpVector = jumpAndRun.playerJump(5, 5);
    std::cout << "Jump Vector is: " << playerJumpVector << std::endl;
    jumpAndRun.scoreCount(100, 2);
     
    std::cout << "good to go!" << std::endl;
}
