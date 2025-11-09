#include <iostream>
#include <string>

class Transport {
protected:
    std::string brand;
    std::string model;
    int year;
    double weight;

public:
    Transport(const std::string& b, const std::string& m, int y, double w) 
        : brand(b), model(m), year(y), weight(w) {}

    Transport(const std::string& b, const std::string& m) 
        : Transport(b, m, 2024, 0) {}

    Transport() : Transport("Unknown", "Unknown", 2024, 0) {}

    virtual void printInfo() const {
        std::cout << "Brand: " << brand << "\nModel: " << model 
                  << "\nYear: " << year << "\nWeight: " << weight << " kg\n";
    }

    virtual ~Transport() {}
};

class Bicycle : public Transport {
private:
    int gears;
    std::string type;

public:
    Bicycle(const std::string& b, const std::string& m, int y, double w, int g, const std::string& t)
        : Transport(b, m, y, w), gears(g), type(t) {}

    Bicycle(const std::string& b, const std::string& m, int g) 
        : Bicycle(b, m, 2024, 10, g, "Mountain") {}

    void printInfo() const override {
        Transport::printInfo();
        std::cout << "Type: " << type << "\nGears: " << gears << "\n";
    }
};

class Truck : public Transport {
private:
    double cargoCapacity;
    int axles;

public:
    Truck(const std::string& b, const std::string& m, int y, double w, double cap, int a)
        : Transport(b, m, y, w), cargoCapacity(cap), axles(a) {}

    Truck(const std::string& b, const std::string& m, double cap)
        : Truck(b, m, 2024, 5000, cap, 2) {}

    void printInfo() const override {
        Transport::printInfo();
        std::cout << "Cargo capacity: " << cargoCapacity << " tons\nAxles: " << axles << "\n";
    }
};

class Airplane : public Transport {
private:
    double wingspan;
    int passengerCapacity;
    double maxAltitude;

public:
    Airplane(const std::string& b, const std::string& m, int y, double w, double ws, int pc, double alt)
        : Transport(b, m, y, w), wingspan(ws), passengerCapacity(pc), maxAltitude(alt) {}

    Airplane(const std::string& b, const std::string& m, int pc)
        : Airplane(b, m, 2024, 50000, 30.5, pc, 12000) {}

    void printInfo() const override {
        Transport::printInfo();
        std::cout << "Wingspan: " << wingspan << " m\nPassenger capacity: " 
                  << passengerCapacity << "\nMax altitude: " << maxAltitude << " m\n";
    }
};

class Ship : public Transport {
private:
    double length;
    double displacement;
    std::string shipType;

public:
    Ship(const std::string& b, const std::string& m, int y, double w, double len, double disp, const std::string& st)
        : Transport(b, m, y, w), length(len), displacement(disp), shipType(st) {}

    Ship(const std::string& b, const std::string& m, double len)
        : Ship(b, m, 2024, 100000, len, 50000, "Cargo") {}

    void printInfo() const override {
        Transport::printInfo();
        std::cout << "Length: " << length << " m\nDisplacement: " << displacement 
                  << " tons\nType: " << shipType << "\n";
    }
};

int main() {
    Bicycle bike("Trek", "X-Caliber", 2023, 12.5, 12, "Mountain");
    Truck truck("Volvo", "FH16", 2022, 8500, 25.5, 3);
    Airplane plane("Boeing", "737", 2020, 45000, 35.8, 189, 12500);
    Ship ship("Mitsubishi", "Heavy", 2019, 150000, 200.5, 80000, "Container");

    std::cout << "=== Bicycle ===\n";
    bike.printInfo();
    std::cout << "\n=== Truck ===\n";
    truck.printInfo();
    std::cout << "\n=== Airplane ===\n";
    plane.printInfo();
    std::cout << "\n=== Ship ===\n";
    ship.printInfo();

    Bicycle simpleBike("Giant", "ATX", 21);
    std::cout << "\n=== Simple Bicycle ===\n";
    simpleBike.printInfo();

    return 0;
}