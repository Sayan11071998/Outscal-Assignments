#include <iostream>

class NFSCar
{
  private:
    int engine;
    int doors;
    int capacity;
    int topSpeed;

  public:

    //---------------------Setter------------------------------
    void setEngine(int _engine)        
    {    
      engine = _engine;        
    }
    void setDoors(int _doors)         
    {    
      doors = _doors;          
    }
    void setCapacity(int _capacity)    
    {    
      capacity = _capacity;    
    }
    void setTopSpeed(int _topSpeed)    
    {    
      topSpeed = _topSpeed;    
    }

    //---------------------Getters------------------------------
    int getEngine()                    
    {    
      return engine;           
    }
    int getDoors()                     
    {    
      return doors;            
    }
    int getCapacity()                  
    {    
      return capacity;         
    }
    int getTopSpeed()                  
    {    
      return topSpeed;         
    }

    //------------------------------------------------------------
    virtual void startVehicle()
    {
      std::cout << "Hear the rumbling of my car.\n";
    }
    virtual void accelerateCar()
    {
      std::cout << "I'm about to touch the sky.\n";
    }
    virtual void stopVehicle()
    {
      std::cout << "I guess I will stop now.\n";
    }
    virtual ~NFSCar()
    {
      std::cout << "Destroying this car object\n";
    }
};

class Lamborghini : public NFSCar
{
  public:

    void startVehicle()
    {
      std::cout << "Hear the rumbling of my Lambo.\n";
    }
    void accelerateCar()
    {
      std::cout << "You're about to see a flying Lambo.\n";
    }
    void stopVehicle()
    {
      std::cout << "Stopping vehicle of type - Lamborghini.\n";
    }
    ~Lamborghini()
    {
      std::cout << "Destroying a perfectly fine Lamborghini\n";
    }
};

class Mercedes : public NFSCar
{
  public:

    void startVehicle()
    {
      std::cout << "Hear the rumbling of my Mercedes.\n";
    }
    void accelerateCar()
    {
      std::cout << "You're about to see a flying Mercedes.\n";
    }
    void stopVehicle()
    {
      std::cout << "Stopping vehicle of type - Mercedes.\n";
    }
    ~Mercedes()
    {
      std::cout << "Destroying a perfectly fine Mercedes\n";
    }
};

class BMW : public NFSCar
{
  public:

    void startVehicle()
    {
      std::cout << "Hear the rumbling of my BMW.\n";
    }
    void accelerateCar()
    {
      std::cout << "You're about to see a flying BMW.\n";
    }
    void stopVehicle()
    {
      std::cout << "Stopping vehicle of type - BMW.\n";
    }
    ~BMW()
    {
      std::cout << "Destroying a perfectly fine BMW\n";
    }
};

int main()
{
  //Vehicle *car = new Car();
  NFSCar *lamboObject = new Lamborghini();
  NFSCar *mercedesObject = new Mercedes();
  NFSCar *bMWObject = new BMW();

  lamboObject->startVehicle();
  lamboObject->accelerateCar();
  lamboObject->stopVehicle();
  
  std::cout << std::endl;
  
  mercedesObject->startVehicle();
  mercedesObject->accelerateCar();
  mercedesObject->stopVehicle();
  
  std::cout << std::endl;
  
  bMWObject->startVehicle();
  bMWObject->accelerateCar();
  bMWObject->stopVehicle();
  
  std::cout << std::endl;
  
  delete lamboObject;
  delete mercedesObject;
  delete bMWObject;
}