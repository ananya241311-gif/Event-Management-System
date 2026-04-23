#include <iostream>
#include <vector>
using namespace std;

// ---------------- PARTICIPANT CLASS ----------------
class Participant {
public:
    string name;
    int id;

    Participant(string n, int i) {
        name = n;
        id = i;
    }

    void display() {
        cout << "Participant ID: " << id << ", Name: " << name << endl;
    }
};

// ---------------- EVENT CLASS ----------------
class Event {
public:
    string eventName;
    vector<Participant> participants;

    Event(string name) {
        eventName = name;
    }

    void addParticipant(string name, int id) {
        participants.push_back(Participant(name, id));
        cout << "Participant added successfully!\n";
    }

    void showParticipants() {
        cout << "\nParticipants in " << eventName << ":\n";
        if (participants.empty()) {
            cout << "No participants yet.\n";
            return;
        }
        for (auto &p : participants) {
            p.display();
        }
    }
};

// ---------------- MAIN ----------------
int main() {
    Event event("College Fest");

    int choice;

    while (true) {
        cout << "\n1. Add Participant\n";
        cout << "2. Show Participants\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int id;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter ID: ";
            cin >> id;

            event.addParticipant(name, id);
        }
        else if (choice == 2) {
            event.showParticipants();
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}