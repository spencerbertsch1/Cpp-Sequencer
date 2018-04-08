#include "Instrument.h"
#include <iostream>
#include <vector>

using namespace std;

class Channel {

private:
    friend class Sequencer;
    friend class Interaction;
    friend class PlayBack;
    Instrument *instrument; // Points to the instrument associated with the channel
    vector<int> notes; // Stores user input

public:
    Channel() {

    } // Default constructor

    Channel(int length) { // Constructor to use
        instrument = new Instrument(); // Every channel is initialized with an empty instrument
        for(int i = 0; i < length; i++) {
            notes.push_back(0); // Initialize notes to 0
        }
    }

    Channel(const Channel &old_channel) { // Copy constructor
        instrument = old_channel.instrument;
        notes = old_channel.notes;
    }

    ~Channel() { // Destructor
        // delete instrument; This throws an error for some reason
    }

    Channel& operator=(Channel &rhs){ // Assignment operator" << endl;
        if (this != &rhs) {
            this->instrument = rhs.instrument;
            this->notes = rhs.notes;
        }
        return *this;
    }

    void setNote(int index, int value) { // Change note at index to given value
        if (value > 127 || value < 0) { // Make sure note is a valid MIDI note
            cerr << "MIDI Note values must be 0-127" << endl;
            exit(-1);
        }

        notes[index] = value;
    }

    void setInstrument(string instrument_name) {
        instrument->setName(instrument_name);
    }

    void linkInstrument(Instrument& new_instrument) {
        instrument = &new_instrument;
    }
};
