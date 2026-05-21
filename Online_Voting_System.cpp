#include <iostream>
#include <string>
using namespace std;
//structure of party 
struct Party {
int id;
string name;
int votes;
};
Party parties[10];//object of party
string voters[100];
int partyCount = 0;
int voterCount = 0;
void setupParties() {
parties[0] = {1, "PTI", 0};//array of structure
parties[1] = {2, "PMLN", 0};
parties[2] = {3, "PPP", 0};
partyCount = 3;
}
//admin fuction 
void admin() {
string pass;
cout << "Password: ";
cin >> pass;
if(pass != "admin") {
cout << "Wrong password\n";
return;
}
cout << "\nResults:\n";
for(int i = 0; i < partyCount; i++) {
cout << parties[i].name << " = " << parties[i].votes << endl;
} 
}

//voter function
void voter() {
string id;
cout << "Enter CNIC: ";
cin >> id;
for(int i = 0; i < voterCount; i++) {
if(voters[i] == id) {
cout << "You already voted\n";
return;
}
}
cout << "\nParties:\n";
for(int i = 0; i < partyCount; i++) { 
cout << parties[i].id << " " << parties[i].name << endl; 
}
int choice;
cout << "Your choice: ";
cin >> choice;
for(int i = 0; i < partyCount; i++) {
if(parties[i].id == choice) {
parties[i].votes++;
voters[voterCount++] = id;
cout << "---Vote added successfully ---\n";
return;
}
}
cout << "Invalid party\n";

}
int main() {
setupParties();
while(true) {
cout << "\n===== Online Voting System =====\n";
cout << "\n\t1 Admin\n \t2 cast vote \n \t3 Exit\n\n\nChoice: ";
int ch;
cin >> ch;
if(ch == 1) admin();
else if(ch == 2) voter();
else if(ch == 3) break;
else cout << "Wrong option\n";
}
return 0;
}
