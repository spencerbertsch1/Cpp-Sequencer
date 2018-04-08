#include <iostream>
#include <fstream>
#include <sstream>
#include "DoublyLinkedList.h"
#include "string"

class Sequencer {
private:
    friend class Interaction; // Interaction is a friend so we can modify sequencers
    friend class PlayBack;
    int sequenceLength; // How long the sequence is
    int bpm; // How fast the sequence is being played
    DoublyLinkedList channels;

public:
    Sequencer() {
    } // Default constructor

    Sequencer(int length, int new_bpm) { // Constructor
        sequenceLength = length; // How long the sequence is (Hardcode?)
        bpm = new_bpm; // How fast the song is being played
    };

    Sequencer(Sequencer &old_sequencer) {
        sequenceLength = old_sequencer.sequenceLength;
        bpm = old_sequencer.bpm;
    }

    Sequencer& operator=(Sequencer &rhs) {
        if (this != &rhs) {
            this->sequenceLength = rhs.sequenceLength;
            this->bpm = rhs.bpm;
        }
        return *this;
    }

    ~Sequencer() {} // Destructor

    void addChannel() { // Add new channel
        Channel* new_channel = new Channel(sequenceLength);
        channels.insertFront(*new_channel);
    }

    void removeChannel(int index) { // Remove a channel
        channels.removeIndex(index);
    }

    void clear() { // Remove everything from the sequencer
        int size = channels.size();
        for(int i = 0; i < size; i++) {
            channels.removeFront();
        }
    }

    void changeBPM(int new_bpm) { // Change bpm
        bpm = new_bpm;
    }

    int getBPM() {
        return bpm;
    }

    int getLength() {
        return sequenceLength;
    }

    void setLength(int length) {
        sequenceLength = length;
    }

    void setInstrument(int index, string name) { // Changes the instrument of specified channel number
        channels.getData(index).setInstrument(name);
    }

    bool search(string inst) { // See if a certain instrmuent exists in the sequencer
        bool found = false;
        for (int i = 0; i < channels.size(); i++){
            if ((channels.getData(i).instrument->getName()) == inst) {
                found = true;
                break;
            }
        }
        return found;
    };

    void display() { // Prints out a graphical display of the sequencer
        cout << "BPM: " << bpm << endl;
        for(int i = 0; i < channels.size(); i++) {
            for(int k = 0; k < sequenceLength + 4; k++ ) {
                cout << "--";
            }

            cout << endl << channels.getData(i).instrument->getName() << " | ";

            for(int j = 0; j < sequenceLength; j++) {
                cout << channels.getData(i).notes[j] << " ";
            }

            cout << endl;
        }

        for(int k = 0; k < sequenceLength + 4; k++ ) {
            cout << "--";
        }

        cout << endl;
    }

    void saveSequence(string filename) { // Saves the current sequence to a text file
        ofstream savefile;
        savefile.open(filename, std::ofstream::out | std::ofstream::trunc); // Overwrite existing files

        savefile << "Sequence" << endl; // Add header
        savefile << sequenceLength << endl; // Add sequence length for convenience
        savefile << bpm; // Add bpm

        for(int i = 0; i < channels.size(); i++) {
            savefile << endl << channels.getData(i).instrument->getName() << endl;

            for(int j = 0; j < sequenceLength; j++) {
                savefile << channels.getData(i).notes[j] << " ";
            }
        }

        savefile.close();
    }

    void loadSequence(string filename) { // Loads a saved sequence from file DOESNT FULLY WORK YET
        ifstream loadfile;
        loadfile.open(filename);
        if (!loadfile.is_open()) {
            cerr << "File not found" << endl;
            exit(-1);
        }

        string line;

        getline(loadfile, line); // Get first line

        if (line != "Sequence") { // Make sure file is a save file
            cerr << "Invalid save file" << endl;
            exit(-1);
        }

        getline(loadfile, line); // Get second line (sequence length)
        sequenceLength = stoi(line);

        getline(loadfile, line); // Get third line (bpm)
        bpm = stoi(line);

        clear(); // Empty sequencer before we repopulate it

        while (getline(loadfile,line)) {
            // First line will be instrument name
            string instrument_name = line;
            addChannel();

            // Set instrument name accordlingly, addChannel
            // pushes to front so we will always access the first channel
            channels.getData(0).setInstrument(instrument_name);

            // Get next line, will be note values
            getline(loadfile, line);
            std::istringstream noteStream(line);

            int i = 0; // Use this to count
            string value; // Use to store token
            while (noteStream >> value) {
                channels.getData(0).setNote(i, stoi(value)); // Set note value
                i++;
            }
        }
    }
};
