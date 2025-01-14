#include <iostream>
#include <string>

using namespace std;

class SignalProcessingDevice {
private:
    std::string deviceName;
    double inputSignalStrength;
    double outputSignalStrength;

public:
    SignalProcessingDevice(string name, double inputSignal, double outputSignal):
    deviceName(name), inputSignalStrength(inputSignal), outputSignalStrength(outputSignal) {}
    //First line is the constructor and what follows after the colon is the initializer list

    void setDeviceName(string name) {deviceName = name; }
    std::string getdeviceName() const {return deviceName; }
    void setinputSignalStrength(double inputSignal) {inputSignalStrength = inputSignal; }
    double getinputSignalStrength() const {return inputSignalStrength; }
    void setoutputSignalStrength(double outputSignal) {outputSignalStrength = outputSignal; }
    double getoutputSignalStrength() const {return outputSignalStrength; }
    // Setter and getter methods

    virtual void displayInfo() const = 0;
    // Allows for other derived classes later on in the code to override this and display a specific message

    virtual void processSignal() = 0;
    // Allows for other derived classes later on in the code to override this and use a specific signal processing function
};

// Amplifier derived Class
class Amplifier : public SignalProcessingDevice {
private:
    double gainFactor;

public:
    Amplifier(string name, double inputSignal, double gain):
    SignalProcessingDevice(name, inputSignal, inputSignal * gain), gainFactor(gain) {}
    // First line is the constructor and what follows after the colon is the initializer list

    void processSignal() override {setoutputSignalStrength(getinputSignalStrength() * gainFactor); }
    // Overrides virtual method processSignal with specific function tailored to Amplifier

    void displayInfo() const override {
        cout << "Amplifier Info: Name: " << getdeviceName() << ", Input Signal: " << getinputSignalStrength() << " dB, Output Signal: " << getoutputSignalStrength() << " dB, Gain Factor: " << gainFactor << endl;}
    // Overrides virtual method displayInfo with specific message tailored to Amplifier
};

// Filter derived class
class Filter : public SignalProcessingDevice {
private:
    double attenuationFactor;

public:
    Filter(string name, double inputSignal, double attenuation):
    SignalProcessingDevice(name, inputSignal, inputSignal * attenuation), attenuationFactor(attenuation) {}
    // First line is the constructor and what follows after the colon is the initializer list

    void processSignal() override { setoutputSignalStrength(getinputSignalStrength() * attenuationFactor); }
    // Overrides virtual method processSignal with specific function tailored to Filter

    void displayInfo() const override {
        cout << "Filter Info: Name: " << getdeviceName() << ", Input Signal: " << getinputSignalStrength()<< " dB, Output Signal: " << getoutputSignalStrength() << " dB, Attenuation Factor: " << attenuationFactor<< endl;}
    // Overrides virtual method displayInfo with specific message tailored to Filter
};

// Signal Generator derived class
class SignalGenerator : public SignalProcessingDevice {
private:
    double outputStrength;

public:
    SignalGenerator(string name, double inputSignal, double strength)
        : SignalProcessingDevice(name, inputSignal, strength), outputStrength(strength) {}
    // First line is the constructor and what follows after the colon is the initializer list

    void processSignal() override { setoutputSignalStrength(outputStrength); }
    // Overrides virtual method processSignal with specific function tailored to SignalGenerator

    void displayInfo() const override {
        cout << "SignalGenerator Info: Name: " << getdeviceName() << ", Input Signal: " << getinputSignalStrength()<< " dB, Output Signal: " << getoutputSignalStrength() << " dB" << endl;}
    // Overrides virtual method displayInfo with specific message tailored to SignalGenerator
};

//The following adds arbitrary examples of devices to an array that will displayed
int main() {
    SignalProcessingDevice* devices[15];
    devices[0] = new Filter("Filter1", 15.0, 0.30);
    devices[1] = new Filter("Filter2", 20.0, 0.50);
    devices[2] = new Filter("Filter3", 10.0, 0.80);
    devices[3] = new Filter("Filter4", 5.0, 0.40);
    devices[4] = new Filter("Filter5", 3.0, 0.90);
    devices[5] = new Amplifier("Amplifier1", 20.5, 2.0);
    devices[6] = new Amplifier("Amplifier2", 34.6, 4.0);
    devices[7] = new Amplifier("Amplifier3", 15.5, 1.5);
    devices[8] = new Amplifier("Amplifier4", 26.5, 4.8);
    devices[9] = new Amplifier("Amplifier5", 13.6, 6.0);
    devices[10] = new SignalGenerator("SignalGenerator1", 3.0, 40.0);
    devices[11] = new SignalGenerator("SignalGenerator2", 18.7, 29.5);
    devices[12] = new SignalGenerator("SignalGenerator3", 4.0, 35.0);
    devices[13] = new SignalGenerator("SignalGenerator4", 2.0, 20.0);
    devices[14] = new SignalGenerator("SignalGenerator5", 5.0, 15.0);



//The following uses polymorphism to allow different behavior for each device
    for (int i = 0; i < 15; i++) {
        devices[i]->processSignal();
        devices[i]->displayInfo();
    }


    return 0;
}

