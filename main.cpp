#include <iostream>
#include "PlayBack.h"


using namespace std;

int main() {
    Sequencer sequencer(0, 0); // Create empty sequencer
    PlayBack player;

    cout << endl;
    cout << " -------- Welcome to the Sequencer! --------    " << endl;
    cout << "Enter 0 to load from a file or 1 to create a new sequence: ";

    int flag;
    cin >> flag;

    if (flag == 0) {
        string filename;
        cout << "Enter the filename: ";
        cin >> filename;

        sequencer.loadSequence(filename); // Load text file

        cout << "Playing Sequence" << endl;
        while(true) {
            player.play(sequencer);
        }
    }
    else if (flag == 1) {
        int user_in;
        int bpm;
        int length;


        cout << "Enter a BPM: ";
        cin >> bpm;
        sequencer.changeBPM(bpm);

        cout << "Enter the length of the sequence in beats: ";
        cin >> length;
        sequencer.setLength(length);

        while(user_in != 7)
        {
            cout << endl << endl;
            cout << "    Please Enter an Option        " << endl;
            cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    " << endl;
            cout << " (1)  Add Piano " << endl;
            cout << " (2)  Add Bass  " << endl;
            cout << " (3)  Add Guitar   " << endl;
            cout << " (4)  Add Saxophone" << endl;
            cout << " (5)  Add Trumpet" << endl;
            cout << " (6)  Add Drums" << endl;
            cout << " (7)  Exit, and listen to your newly created tune. " << endl;
            cout << " Your choice : ";
            cin >> user_in;

            switch(user_in)
            {
                case 1 :
                    sequencer.addChannel();
                    sequencer.setInstrument(0, "Piano");
                    break;

                case 2 :
                    sequencer.addChannel();
                    sequencer.setInstrument(0, "Bass");
                    break;

                case 3 :
                    sequencer.addChannel();
                    sequencer.setInstrument(0, "Guitar");
                    break;

                case 4 :
                    sequencer.addChannel();
                    sequencer.setInstrument(0, "Saxophone");
                    break;

                case 5 :
                    sequencer.addChannel();
                    sequencer.setInstrument(0, "Trumpet");
                    break;

                case 6 :
                    sequencer.addChannel();
                    sequencer.setInstrument(0, "Drums");
                    break;

                case 7 :
                    break;
            }
        }

        cout << endl << endl;
        cout << "      Playing the sequence     " << endl;
        cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    " << endl;
        player.play(sequencer);


    }

    return 0;
}
