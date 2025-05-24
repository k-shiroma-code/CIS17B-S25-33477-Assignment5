//Kyle Shiroma Spr25
#include <iostream>
#include <string>
#include <array>
#include <typeinfo>

template<typename T>
class Package {
private:
    T item;
public:
    Package(T i) : item(i) {}
    void label() {
        std::cout << "Generic package containing: " << typeid(T).name() << "\n";
    }
};

// Specialization for std::string
template<>
class Package<std::string> {
private:
    std::string item;
public:
    Package(std::string i) : item(i) {}
    void label() {
        std::cout << "Book package: \"" << item << "\"\n";
    }
};

// Partial specialization for pointers
template<typename T>
class Package<T*> {
private:
    T* item;
public:
    Package(T* i) : item(i) {}
    void label() {
        std::cout << "Fragile package for pointer to type: " << typeid(T).name() << "\n";
    }
};

template<typename T, int Size>
class Box {
private:
    std::array<T, Size> items;
    int count = 0;
public:
    bool addItem(const T& item) {
        if (count < Size) {
            items[count++] = item;
            std::cout << "Added item to box: \"" << item << "\"\n";
            return true;
        }
        return false;
    }

    void printItems() const {
        std::cout << "Box contents:\n";
        for (int i = 0; i < count; ++i) {
            std::cout << " - " << items[i] << "\n";
        }
    }
};

template<typename T>
void shipItem(const T& item) {
    std::cout << "Shipping item of type: " << typeid(T).name() << "\n";
}

template<>
void shipItem(const double& item) {
    std::cout << "Shipping temperature-controlled item: " << item << "°C\n";
}

int main()
{
    //Create a Package<int>
    Package<int> p1(42);
    p1.label();//Call their label() methods to demonstrate specialization behavior.

    //Package<std::string>
    Package<std::string> p2("C++ Primer");
    p2.label();

    //Crate a Package<double*>
    double temp = 36.6;
    Package<double*> p3(&temp);
    p3.label();

    //Create a Box<std::string, 3> and add 2–3 book titles to it.
    Box<std::string, 3> bookBox;
    bookBox.addItem("The Pragmatic Programmer");
    bookBox.addItem("Clean Code");
    bookBox.printItems(); //Call printItems() to verify.

    //Call shipItem() on an int, a std::string, and a double
    shipItem(100);
    shipItem(std::string("Warehouse Scanner"));
    shipItem(22.5);

    return 0;
}
