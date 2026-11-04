#include <iostream>
#include <string>

using namespace std;

class Car{
    public:
        virtual void startEngine() = 0;
        virtual void shiftGear(int gear) = 0;
        virtual void accelerate() = 0;
        virtual void brake() = 0;
        virtual void stopEngine() = 0;
        virtual ~Car() {}
};

class sportsCar: public Car{
    public:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;
    
        sportsCar(string brand, string model){
            this->brand = brand;
            this->model = model;
            isEngineOn = false;
            currentGear = 0;
            currentSpeed = 0;
        }

        void startEngine(){
            isEngineOn = true;
            cout<<"Car"<<brand << " " << model << " is started. \n";
        }

        void shiftGear(int gear){
            currentGear = gear;
            cout<<"Car"<<brand << " " << model << " is shifted to "<< gear << " gear. \n";
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
            currentGear = 0;
            currentSpeed = 0;
            isEngineOn = false;
            cout << "Car is Stopped !!. \n";
        }
};


int main(){

    Car* myCar = new sportsCar("Ford", "Mustang");
    
    
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


    return 0;
}

