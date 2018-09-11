// A class to modify sequencer objects between user input and playback.
// This class is intended to have side effects on sequencer objects

#include <vector>
#include "Sequencer.h"

using namespace std;

class Interaction {
private:
    void PianoSolo(Sequencer& sequencer) {
        sequencer.addChannel(); // Add new channel for piano solo
        sequencer.channels.getData(0).setInstrument("Piano");

        vector<int> solo(sequencer.getLength(), 127); // Generate new note vector and add it to channel
        sequencer.channels.getData(0).notes = solo;
    }

    void BassSolo(Sequencer& sequencer) {
        sequencer.addChannel(); // Add new channel for piano solo
        sequencer.channels.getData(0).setInstrument("Bass");

        vector<int> solo(sequencer.getLength(), 127); // Generate new note vector and add it to channel
        sequencer.channels.getData(0).notes = solo;
    }

    void GuitarSolo(Sequencer& sequencer) {
        sequencer.addChannel(); // Add new channel for piano solo
        sequencer.channels.getData(0).setInstrument("Guitar");

        vector<int> solo(sequencer.getLength(), 127); // Generate new note vector and add it to channel
        sequencer.channels.getData(0).notes = solo;
    }

    void SaxSolo(Sequencer& sequencer) {
        sequencer.addChannel(); // Add new channel for piano solo
        sequencer.channels.getData(0).setInstrument("Saxophone");

        vector<int> solo(sequencer.getLength(), 127); // Generate new note vector and add it to channel
        sequencer.channels.getData(0).notes = solo;
    }

    void TrumpetSolo(Sequencer& sequencer) {
        sequencer.addChannel(); // Add new channel for piano solo
        sequencer.channels.getData(0).setInstrument("Trumpet");

        vector<int> solo(sequencer.getLength(), 127); // Generate new note vector and add it to channel
        sequencer.channels.getData(0).notes = solo;
    }

    void DrumSolo(Sequencer& sequencer) {
        sequencer.addChannel(); // Add new channel for piano solo
        sequencer.channels.getData(0).setInstrument("Drums");

        vector<int> solo(sequencer.getLength(), 127); // Generate new note vector and add it to channel
        sequencer.channels.getData(0).notes = solo;
    }

    void Mayonnaise(Sequencer& sequencer) {
        sequencer.addChannel(); // Add new channel for piano solo
        sequencer.channels.getData(0).setInstrument("Mayonnaise");

        vector<int> solo(sequencer.getLength(), 127); // Generate new note vector and add it to channel
        sequencer.channels.getData(0).notes = solo;
    }

public:
    Interaction() { // Nothing to do here (No data)

    }

    ~Interaction() { // Nothing to do here (No data)

    }

    void interact(Sequencer& sequencer) { // Runs different interactions if certain criteria are true
        if (sequencer.search("Piano") == false) {
            PianoSolo(sequencer);
        }
        else if (sequencer.search("Bass") == false) {
            BassSolo(sequencer);
        }
        else if (sequencer.search("Guitar") == false) {
            GuitarSolo(sequencer);
        }
        else if (sequencer.search("Saxophone") == false) {
            SaxSolo(sequencer);
        }
        else if (sequencer.search("Trumpet") == false) {
            TrumpetSolo(sequencer);
        }
        else if (sequencer.search("Drums") == false) {
            DrumSolo(sequencer);
        }
        else if (sequencer.search("Mayonnaise") == false) {
            Mayonnaise(sequencer);
        }
    }

};


