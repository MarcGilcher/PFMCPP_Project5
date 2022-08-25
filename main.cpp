/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
Additionally, you can mark class member functions as 'const'
If you do this, you are promising that the member function will not modify any member variables.

Mark every member function that is not modifying any member variables as 'const'
*/
#if false
//a function where the argument is passed by const-ref
void someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
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
        void printEngineCode();

    };

    void driveForward(int numGear, bool isBrakeReleased = true);
    double consumeFuel(bool pedalKickdown = true);
    void changeSparePart(Engine newEngine);
    void carService(int reminderTimeMonth);
    int refuelCar(int fuelCapacity);
    void printInfo();
    void printInfoFuel();
    void printNewAmountOfFuel();

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

void Car::printInfo()
{
    std::cout << "The car has " << this->numWheels << " Wheels and " << this->numSeats << " Seats." << std::endl;
}

void Car::printInfoFuel()
{
    std::cout << "Amount of consumed fuel: " << this->averageFuel << " Liters" <<std::endl;
}

void Car::Engine::printEngineCode()
{
    std::cout << "The engine Code is: " << this->engineCode << std::endl;
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

void Car::printNewAmountOfFuel()
{
    std::cout << this->refuelCar(60) << ": New quantity of fuel is displayed." << std::endl;
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
    void printActualGear();
    
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

void Bicycle::printActualGear()
{
    std::cout << "The actual gear is nr. " << this->shiftGear(5) << std::endl;
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
    void printPlayerName();
    void printCollisions();

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

void Player::printPlayerName()
{
    std::cout << "Player Name: " << this->namePlayer << std::endl;
}

void Player::printCollisions()
{
    std::cout << this->collisionCheck(5) << " possible Collisions checked." << std::endl;
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
    void printJumpVector();
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

void ArcadeGame::printJumpVector()
{
    std::cout << "Jump Vector is: " << this->playerJump(5,5) << std::endl;
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
    truck.printInfo();
    truck.printInfoFuel();
    std::cout << "Amount of consumed fuel: " << truck.averageFuel << " Liters" <<std::endl;
    truck.carService(10);
    int newAmountOfFuel = truck.refuelCar(60);
    std::cout << "New quantity of fuel is: " << newAmountOfFuel << std::endl;
    truck.printNewAmountOfFuel();
    
    dieselEngine.burnFuel("Diesel", 98);
    dieselEngine.rotateAxles(180.5, true);
    dieselEngine.compressAir(800.35);
    std::cout << "The engine Code is: " << dieselEngine.engineCode << std::endl;
    dieselEngine.printEngineCode();
    
    Bicycle sportBicycle;
    sportBicycle.transportHuman();
    sportBicycle.shiftGear(5);
    sportBicycle.decelarateBike();
    std::cout << "The actual gear is nr. " << sportBicycle.shiftGear(5) << std::endl;
    sportBicycle.printActualGear();
    sportBicycle.checkGear(1, 21);

    Player player1;
    Player::Weapon railGun;
    
    player1.moveX();
    player1.moveY();
    player1.getWeaponUpgrade(railGun);
    std::cout << "Player Name: " << player1.namePlayer << std::endl;
    player1.printPlayerName();
    std::cout << player1.collisionCheck(5) << " possible Collisions checked." << std::endl;
    player1.printCollisions();
    
    railGun.shootBullet(10.5,20.0);
    railGun.makeNoise(true);
    railGun.changeBulletPattern(2);

    CarWorkShop superGarage;
    superGarage.standardService(truck);
    superGarage.chargeCustomer(5, 70);

    ArcadeGame jumpAndRun;
    int playerJumpVector = jumpAndRun.playerJump(5, 5);
    std::cout << "Jump Vector is: " << playerJumpVector << std::endl;
    jumpAndRun.printJumpVector();
    jumpAndRun.scoreCount(100, 2);
     
    std::cout << "good to go!" << std::endl;
}
