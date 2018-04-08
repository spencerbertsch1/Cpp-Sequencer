#include <iostream>
#include <chrono>
#include <thread>
#include <time.h>
#include "Interaction.h"

using namespace std;

class PlayBack{
    private:
        //takes in nothing, it only plays music
    public:
        PlayBack() {

        }

        PlayBack(const PlayBack &Old_playback) {

        }

        ~PlayBack() {

        }

        void play(Sequencer& S1){
            int i = 0;
            int bpm = S1.getBPM();

            time_t timer;

            while (i < 5) {
                for (int i = 0; i < S1.sequenceLength; i++) { // For every note in the sequence
                    for (int j = 0; j < S1.channels.size(); j++) { // For every instrument playing
                        string name = S1.channels.getData(j).instrument->getName();
                        int note = S1.channels.getData(j).notes[i];

                        cout << "| " << name << ":" << note << " |" << endl; // Output current note
                    }
                    this_thread::sleep_for(chrono::milliseconds(60000 / bpm)); // sleep for one beat

                }
                i++;

            }
        }

};
