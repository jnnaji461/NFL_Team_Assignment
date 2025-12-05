/*Program name: NFL Football Team Roster Program.cpp
Author: Judith Nnaji
Date: 12/05/2025
Purpose: This program demonstrates object-oriented programming by modeling an NFL football team.
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

//=====================================================
// ABSTRACT BASE CLASS
//=====================================================
class Player {
protected:
    string name;
    int playerID;

public:
    Player(string n, int id) : name(n), playerID(id) {}
    virtual ~Player() {}

    string getName() const { return name; }
    int getPlayerID() const { return playerID; }

    virtual string getPlayerPosition() const = 0;
    virtual string play() const = 0;
    virtual string toString() const = 0;
};

//=====================================================
// OFFENSE POSITIONS
//=====================================================
class QuarterBack : public Player {
public:
    QuarterBack(string n, int id) : Player(n, id) {}
    string getPlayerPosition() const override { return "Quarterback"; }
    string play() const override { return "Throws passes and directs the offense"; }
    string toString() const override {
        return "Name: " + name + " | Number: " + to_string(playerID) +
            " | Position: Quarterback | Action: " + play();
    }
};

class WideReceiver : public Player {
public:
    WideReceiver(string n, int id) : Player(n, id) {}
    string getPlayerPosition() const override { return "Wide Receiver"; }
    string play() const override { return "Catches passes and runs routes"; }
    string toString() const override {
        return "Name: " + name + " | Number: " + to_string(playerID) +
            " | Position: Wide Receiver | Action: " + play();
    }
};

class TightEnd : public Player {
public:
    TightEnd(string n, int id) : Player(n, id) {}
    string getPlayerPosition() const override { return "Tight End"; }
    string play() const override { return "Blocks and catches passes"; }
    string toString() const override {
        return "Name: " + name + " | Number: " + to_string(playerID) +
            " | Position: Tight End | Action: " + play();
    }
};

class RunningBack : public Player {
public:
    RunningBack(string n, int id) : Player(n, id) {}
    string getPlayerPosition() const override { return "Running Back"; }
    string play() const override { return "Runs with the ball and blocks"; }
    string toString() const override {
        return "Name: " + name + " | Number: " + to_string(playerID) +
            " | Position: Running Back | Action: " + play();
    }
};

class OffensiveLineman : public Player {
public:
    OffensiveLineman(string n, int id) : Player(n, id) {}
    string getPlayerPosition() const override { return "Offensive Lineman"; }
    string play() const override { return "Blocks defensive players"; }
    string toString() const override {
        return "Name: " + name + " | Number: " + to_string(playerID) +
            " | Position: Offensive Lineman | Action: " + play();
    }
};

//=====================================================
// DEFENSE POSITIONS
//=====================================================
class DefensiveLineman : public Player {
public:
    DefensiveLineman(string n, int id) : Player(n, id) {}
    string getPlayerPosition() const override { return "Defensive Lineman"; }
    string play() const override { return "Rushes quarterback and stops runs"; }
    string toString() const override {
        return "Name: " + name + " | Number: " + to_string(playerID) +
            " | Position: Defensive Lineman | Action: " + play();
    }
};

class Linebacker : public Player {
public:
    Linebacker(string n, int id) : Player(n, id) {}
    string getPlayerPosition() const override { return "Linebacker"; }
    string play() const override { return "Tackles runners and covers receivers"; }
    string toString() const override {
        return "Name: " + name + " | Number: " + to_string(playerID) +
            " | Position: Linebacker | Action: " + play();
    }
};

class DefensiveBack : public Player {
public:
    DefensiveBack(string n, int id) : Player(n, id) {}
    string getPlayerPosition() const override { return "Defensive Back"; }
    string play() const override { return "Covers receivers and intercepts passes"; }
    string toString() const override {
        return "Name: " + name + " | Number: " + to_string(playerID) +
            " | Position: Defensive Back | Action: " + play();
    }
};

//=====================================================
// SPECIAL TEAMS POSITIONS
//=====================================================
class Kicker : public Player {
public:
    Kicker(string n, int id) : Player(n, id) {}
    string getPlayerPosition() const override { return "Kicker"; }
    string play() const override { return "Kicks field goals and extra points"; }
    string toString() const override {
        return "Name: " + name + " | Number: " + to_string(playerID) +
            " | Position: Kicker | Action: " + play();
    }
};

class Holder : public Player {
public:
    Holder(string n, int id) : Player(n, id) {}
    string getPlayerPosition() const override { return "Holder"; }
    string play() const override { return "Holds the ball for field goals"; }
    string toString() const override {
        return "Name: " + name + " | Number: " + to_string(playerID) +
            " | Position: Holder | Action: " + play();
    }
};

class Punter : public Player {
public:
    Punter(string n, int id) : Player(n, id) {}
    string getPlayerPosition() const override { return "Punter"; }
    string play() const override { return "Punts the football"; }
    string toString() const override {
        return "Name: " + name + " | Number: " + to_string(playerID) +
            " | Position: Punter | Action: " + play();
    }
};

class Returner : public Player {
public:
    Returner(string n, int id) : Player(n, id) {}
    string getPlayerPosition() const override { return "Returner"; }
    string play() const override { return "Returns kickoffs and punts"; }
    string toString() const override {
        return "Name: " + name + " | Number: " + to_string(playerID) +
            " | Position: Returner | Action: " + play();
    }
};

//=====================================================
// FUNCTION DECLARATIONS
//=====================================================
void displayMainMenu();
void addPlayerMenu(vector<shared_ptr<Player>>& team);
void addOneOfEachPosition(vector<shared_ptr<Player>>& team);
void showTeamRoster(const vector<shared_ptr<Player>>& team);
void showPlayerCount(const vector<shared_ptr<Player>>& team);

//=====================================================
// MAIN PROGRAM
//=====================================================
int main() {
    vector<shared_ptr<Player>> team;
    int choice;

    cout << "=== NFL FOOTBALL TEAM MANAGEMENT SYSTEM ===\n";

    do {
        displayMainMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addPlayerMenu(team);
            break;
        case 2:
            addOneOfEachPosition(team);
            break;
        case 3:
            showTeamRoster(team);
            break;
        case 4:
            showPlayerCount(team);
            break;
        case 5:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}

//=====================================================
// FUNCTION DEFINITIONS
//=====================================================
void displayMainMenu() {
    cout << "\n========== MAIN MENU ==========\n";
    cout << "1. Add a player (choose position)\n";
    cout << "2. Add one player from EACH position\n";
    cout << "3. Show team roster\n";
    cout << "4. Show number of players on team\n";
    cout << "5. Exit\n";
    cout << "===============================\n";
}

void addPlayerMenu(vector<shared_ptr<Player>>& team) {
    cout << "\n=== ADD PLAYER ===\n";
    cout << "Select position:\n";
    cout << "1. Quarterback\n2. Wide Receiver\n3. Tight End\n4. Running Back\n5. Offensive Lineman\n";
    cout << "6. Defensive Lineman\n7. Linebacker\n8. Defensive Back\n";
    cout << "9. Kicker\n10. Holder\n11. Punter\n12. Returner\n";
    cout << "Enter position number (1-12): ";

    int pos;
    cin >> pos;

    if (pos < 1 || pos > 12) {
        cout << "Invalid position number!\n";
        return;
    }

    cout << "Enter player name: ";
    cin.ignore();
    string name;
    getline(cin, name);

    cout << "Enter player number: ";
    int number;
    cin >> number;

    shared_ptr<Player> newPlayer;

    switch (pos) {
    case 1: newPlayer = make_shared<QuarterBack>(name, number); break;
    case 2: newPlayer = make_shared<WideReceiver>(name, number); break;
    case 3: newPlayer = make_shared<TightEnd>(name, number); break;
    case 4: newPlayer = make_shared<RunningBack>(name, number); break;
    case 5: newPlayer = make_shared<OffensiveLineman>(name, number); break;
    case 6: newPlayer = make_shared<DefensiveLineman>(name, number); break;
    case 7: newPlayer = make_shared<Linebacker>(name, number); break;
    case 8: newPlayer = make_shared<DefensiveBack>(name, number); break;
    case 9: newPlayer = make_shared<Kicker>(name, number); break;
    case 10: newPlayer = make_shared<Holder>(name, number); break;
    case 11: newPlayer = make_shared<Punter>(name, number); break;
    case 12: newPlayer = make_shared<Returner>(name, number); break;
    }

    team.push_back(newPlayer);
    cout << "\n✅ Player added: " << name << " (#" << number << ")\n";
}

void addOneOfEachPosition(vector<shared_ptr<Player>>& team) {
    cout << "\n=== ADD ONE PLAYER FROM EACH POSITION ===\n";
    cout << "Please enter information for each position:\n\n";

    // Offense positions
    cout << "--- OFFENSE ---\n";

    cout << "Quarterback:\n";
    cout << "  Name: ";
    cin.ignore();
    string qbName;
    getline(cin, qbName);
    cout << "  Number: ";
    int qbNum;
    cin >> qbNum;
    team.push_back(make_shared<QuarterBack>(qbName, qbNum));
    cin.ignore();

    cout << "\nWide Receiver:\n";
    cout << "  Name: ";
    string wrName;
    getline(cin, wrName);
    cout << "  Number: ";
    int wrNum;
    cin >> wrNum;
    team.push_back(make_shared<WideReceiver>(wrName, wrNum));
    cin.ignore();

    cout << "\nTight End:\n";
    cout << "  Name: ";
    string teName;
    getline(cin, teName);
    cout << "  Number: ";
    int teNum;
    cin >> teNum;
    team.push_back(make_shared<TightEnd>(teName, teNum));
    cin.ignore();

    cout << "\nRunning Back:\n";
    cout << "  Name: ";
    string rbName;
    getline(cin, rbName);
    cout << "  Number: ";
    int rbNum;
    cin >> rbNum;
    team.push_back(make_shared<RunningBack>(rbName, rbNum));
    cin.ignore();

    cout << "\nOffensive Lineman:\n";
    cout << "  Name: ";
    string olName;
    getline(cin, olName);
    cout << "  Number: ";
    int olNum;
    cin >> olNum;
    team.push_back(make_shared<OffensiveLineman>(olName, olNum));
    cin.ignore();

    // Defense positions
    cout << "\n--- DEFENSE ---\n";

    cout << "\nDefensive Lineman:\n";
    cout << "  Name: ";
    string dlName;
    getline(cin, dlName);
    cout << "  Number: ";
    int dlNum;
    cin >> dlNum;
    team.push_back(make_shared<DefensiveLineman>(dlName, dlNum));
    cin.ignore();

    cout << "\nLinebacker:\n";
    cout << "  Name: ";
    string lbName;
    getline(cin, lbName);
    cout << "  Number: ";
    int lbNum;
    cin >> lbNum;
    team.push_back(make_shared<Linebacker>(lbName, lbNum));
    cin.ignore();

    cout << "\nDefensive Back:\n";
    cout << "  Name: ";
    string dbName;
    getline(cin, dbName);
    cout << "  Number: ";
    int dbNum;
    cin >> dbNum;
    team.push_back(make_shared<DefensiveBack>(dbName, dbNum));
    cin.ignore();

    // Special Teams positions
    cout << "\n--- SPECIAL TEAMS ---\n";

    cout << "\nKicker:\n";
    cout << "  Name: ";
    string kName;
    getline(cin, kName);
    cout << "  Number: ";
    int kNum;
    cin >> kNum;
    team.push_back(make_shared<Kicker>(kName, kNum));
    cin.ignore();

    cout << "\nHolder:\n";
    cout << "  Name: ";
    string hName;
    getline(cin, hName);
    cout << "  Number: ";
    int hNum;
    cin >> hNum;
    team.push_back(make_shared<Holder>(hName, hNum));
    cin.ignore();

    cout << "\nPunter:\n";
    cout << "  Name: ";
    string pName;
    getline(cin, pName);
    cout << "  Number: ";
    int pNum;
    cin >> pNum;
    team.push_back(make_shared<Punter>(pName, pNum));
    cin.ignore();

    cout << "\nReturner:\n";
    cout << "  Name: ";
    string rName;
    getline(cin, rName);
    cout << "  Number: ";
    int rNum;
    cin >> rNum;
    team.push_back(make_shared<Returner>(rName, rNum));

    cout << "\n✅ All 12 positions filled! Team now has " << team.size() << " players.\n";
}

void showTeamRoster(const vector<shared_ptr<Player>>& team) {
    if (team.empty()) {
        cout << "\nNo players on the team yet.\n";
        return;
    }

    cout << "\n=== TEAM ROSTER ===\n";
    cout << "Total players: " << team.size() << "\n";
    cout << "========================================\n";

    int count = 1;
    for (const auto& player : team) {
        cout << count << ". " << player->toString() << "\n";
        count++;
    }
    cout << "========================================\n";
}

void showPlayerCount(const vector<shared_ptr<Player>>& team) {
    cout << "\n=== TEAM SIZE ===\n";
    cout << "Number of players on team: " << team.size() << "\n";
    cout << "=================\n";

}
