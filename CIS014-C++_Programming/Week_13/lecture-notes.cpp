#include <iostream>
#include <string>

using namespace std;

// In C, a class is called struct
class Student // C++ class
{
    // Member variables (also sometimes called instance variables)
    string name; // This is a private variable since it is not under the public access modifier. Private is the default access modifier

    // Access Modifiers
    public:
        // Default Constructor
        Student()
        {

        };

        // User defined constructor
        Student(string name)
        {
            // This refers to this instance of the class
            this->name = name;
        }

        // Getter accessor method
        string getName()
        {
            return name; // You can use name or this->name here
        }

        // Setter accessor method declaration
        void setName(string name); // Good practice to define your setter method outside of the class since it may have a lot of lines of code
};

// This is how you define a function that was declared in a class
void Student::setName(string name)
{
    // You can use this-> here even though it is outside of the class
    this->name = name;
}

class CRectangle
{
    int width;
    int height;

    public:
        // Default constructor
        CRectangle(); 

        // User defined constructor
        CRectangle(int width, int height)
        {
            this->width = width;
            this->height = height;
        }

        // Member function
        void display()
        {
            cout << "width = " << this->width << endl;
            cout << "height = " << this->height << endl;
        }

        // In line member function
        int area() {return (width * height);}

        // Default destructor. 
        // Destructors do not take arguments or return anything. 
        // Destructor is where all your dynamically allocated variables are de-allocated
        // You do not need to declare a default destructor, it is automatically be supplied for you
        // The destructor is automatically called when an object goes out of scope: function ends, program ends, delete is called on object, etc. 
        ~CRectangle()
        {
            cout << "Inside Destructor" << endl;
        } 
};

CRectangle::CRectangle()
{
    width = 5;
    height = 5;
}

// Struct is a C concept that existed before the Class concept arrived
// Structs are similar to classes, but do not have a lot of OOP traits such as inheritance, polymorphism, and access specification (public is the onlay data encapcilation in a struct)
// Structs encapcsulate data but do not implement behaviors
    // You cannot declare functions inside a struct, you must use function pointers instead
struct product
{
    int weight;
    float price;
} apple, banana, melon;

// You can use arrays with structs like so
const int NUM_FRUITS = 3;
struct produce
{
    int weight;
    float price;
} fruits [NUM_FRUITS];

// Structs can have pointers pointing to them
struct fruitProduct
{
    int weight;
    float price;
};

int main()
{
    // Statically allocate a Student object
    Student static_s("Anthony"); // This uses the user defined constructor of the class
    cout << static_s.getName() << endl; // Use the getter function to get the name

    // Dynamic memory allocation
    Student* dynamic_s = new Student("Henry"); // Dynamic memory allocation requires a pointer and the new keyword
    cout << dynamic_s->getName() << endl; // When you use a pointer, you must use -> to use member functions
    // Whenever you dynamically allocate memory, you must de-allocate it with the delete keyword
    delete dynamic_s;

    // Dynamic memory allocation with default constructor
    Student* dynamic_d = new Student();
    // Use the setter function to set the name
    dynamic_d->setName("Hernandez");
    cout << dynamic_d->getName() << endl;
    delete dynamic_d;

    cout << "---" << endl;

    // Declare an instance of CRectangle
    CRectangle rect(10,20);
    // Run the display function of rect
    rect.display();
    cout << rect.area() << endl;
    // When the program ends, the default destructor will be called

    // Structs
    cout << apple.weight << endl;
    cout << fruits[0].price << endl;
    // Structs with pointers
    fruitProduct orange;
    fruitProduct* pFruit = &orange;

    // When you de-allocate an array, you must include [] after the delete keyword
    int* p = new int[5];
    delete [] p;

    return 0;
}