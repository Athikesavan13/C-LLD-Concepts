#include <iostream>
#include <string>

using namespace std;

// protected accesed by sub class not by any other external objects

class Car{
    protected:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
    public:    
        Car(string brand, string model){
            this->brand = brand;
            this->model = model;
            isEngineOn = false;
            currentSpeed = 0;
        }


        void startEngine(){
            isEngineOn = true;
            cout<<"Car"<<brand << " " << model << " is started. \n";
        }


        void accelerate(){
            currentSpeed += 10;
            if(currentSpeed >= 80){
                currentSpeed = 80;
                cout << "Car is exceeding 80 kmph !!. \n";
                return ;
            }
            cout<<"Car"<<brand << " " << model << " is running at "<< currentSpeed << " kmph. \n";
        }

        void brake(){
            currentSpeed -= 10;
            if(currentSpeed < 0){
                currentSpeed = 0;
                cout << "Car is Stopped !!. \n";
                return ;
            }
            cout<<"Car"<<brand << " " << model << " is running at "<< currentSpeed << " kmph. \n";
        }
        void stopEngine(){
            currentSpeed = 0;
            isEngineOn = false;
            cout << "Car is Stopped !!. \n";
        }
};


class ManualCar : public Car{
    private:
        int currentGear;
    
    public:
        ManualCar(string brand, string model):Car(brand, model){
            this->currentGear = 0;
        }

        void shiftGear(int gear){
            currentGear = gear;
            cout<<"Car"<<brand << " " << model << " is shifted to "<< gear << " gear. \n";
        }
};

class ElectricCar : public Car{
    private:
        int batteryLevel;
    
    public:
        ElectricCar(string brand, string model):Car(brand, model){
            this->batteryLevel = 0;
        }

        void chargeBattery(){
            batteryLevel = 100;
            cout<<"Car"<<brand << " " << model << " is charged to "<< batteryLevel << " %. \n";
        }
};

int main(){

    ManualCar* myCar = new ManualCar("Ford", "Mustang");
    
    
    myCar->startEngine();
    myCar->shiftGear(1);
    myCar->accelerate();
    myCar->accelerate();

    myCar->brake();
    myCar->shiftGear(2);
    myCar->brake();
    myCar->brake();
    myCar->stopEngine();

    delete myCar;


    ElectricCar* evCar = new ElectricCar("Ford", "Mustang");
    
    
    evCar->startEngine();
    evCar->chargeBattery();
    evCar->accelerate();
    evCar->accelerate();

    evCar->brake();
    evCar->chargeBattery();
    evCar->brake();
    evCar->brake();
    evCar->stopEngine();

    delete evCar;

    return 0;
}

