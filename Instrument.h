/*  Types of instruments:
    - Piano
    - Bass
    - Guitar
    - Saxophone
    - Trumpet
    - Drums
    - Mayonnaise
*/

#include <string>
using namespace std;

class Instrument {
private:
    string name; // Define Instrument name

public:
    Instrument() { // Default constructor
        name = "Empty";
    }

    Instrument(string name1) { // Constructor to use
        name = name1;
    }

    Instrument(Instrument &old_Instrument) { // Copy constructor
        name = old_Instrument.name;
    }

    ~Instrument() {} // Destructor

    string getName() { // Getter for name
        return name;
    }

    void setName(string new_name) {
        name = new_name;
    }
};
