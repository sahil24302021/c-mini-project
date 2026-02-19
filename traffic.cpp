#include <iostream>
#include <thread>   
#include <chrono>   
#include <cstdlib>
#include <string>
using namespace std;

//ANSI escape codes
const string RED_COLOR = "\033[31m";
const string GREEN_COLOR = "\033[32m";
const string ORANGE_COLOR = "\033[33m";
const string RESET_COLOR = "\033[0m";

class TrafficSignal {

private: 
    int redDuration;
    int greenDuration;
    int orangeDuration;

public:

    TrafficSignal(int r, int g, int o) {
        redDuration = r;
        greenDuration = g;
        orangeDuration = o;
    }

    void drawGraphic(string activeLight, int secondsLeft) {
        
        system("clear"); 
        string currentColor = RESET_COLOR;
        
        if (activeLight == "RED") {
            currentColor = RED_COLOR;
        } else if (activeLight == "ORANGE") {
            currentColor = ORANGE_COLOR;
        } else if (activeLight == "GREEN") {
            currentColor = GREEN_COLOR;
        }

        // --- DRAWING THE GRAPHIC  ASCII ART ---

        cout << currentColor << "\n   TRAFFIC CONTROL SYSTEM" << endl;
        cout << "   ----------------------" << RESET_COLOR << endl;
        
        cout << "      ___________ " << endl;
        cout << "     |           | " << endl;


        // If RED is active, print (O) in Red. Otherwise, print empty ( ).
        if (activeLight == "RED") {
            cout << "     |   " << RED_COLOR << "(O)" << RESET_COLOR << "   |  <-- STOP" << endl;
        } else {
            cout << "     |   ( )   | " << endl;
        }

        // ORANGE CHECK
        if (activeLight == "ORANGE") {
            cout << "     |   " << ORANGE_COLOR << "(O)" << RESET_COLOR << "   |  <-- SLOW" << endl;
        } else {
            cout << "     |   ( )   | " << endl;
        }

        // GREEN CHECK
        if (activeLight == "GREEN") {
            cout << "     |   " << GREEN_COLOR << "(O)" << RESET_COLOR << "   |  <-- GO" << endl;
        } else {
            cout << "     |   ( )   | " << endl;
        }

        cout << "     |___________| " << endl;
        cout << "           | | " << endl;
        cout << "      =====   ===== " << endl;
        
        // Display the timer
        cout << "\n   " << currentColor << "Time Remaining: " << secondsLeft << " seconds" << RESET_COLOR << endl;
    }


    void runPhase(string color, int duration) {
        
        for (int i = duration; i > 0; i--) {
            drawGraphic(color, i); // Update the drawing
            std::this_thread::sleep_for(std::chrono::seconds(1)); // Wait 1 second
        }
    }

   
    void start() {
        while (true) {
            // Sequence: RED -> GREEN -> ORANGE
            runPhase("RED", redDuration);
            runPhase("GREEN", greenDuration);
            runPhase("ORANGE", orangeDuration);
        }
    }
};

int main() {
 
    TrafficSignal mySignal(5, 5, 2);
    
    // Start the simulation
    mySignal.start();

    return 0;
}
