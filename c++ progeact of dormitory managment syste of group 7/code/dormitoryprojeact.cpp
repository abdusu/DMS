#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct dormitory {
    string blockname;
    string dormname;
    int capacity;
    int occupied;
};
struct student {
    string name;
    int idnumber;
    int age;
    string gender;
    string department;
    string blockname;
    string dormitory;
};
struct procter {
    string name;
    string blockname;
    string phone_no;
    string pasword;
};
struct notiffication {
    string time;
    procter notify;
};
void developer();
void System();
void proacter();
void studentheadoffice();
void Dormitorymanager();
void stude();
void addstudent();
void addblock();
void addroom();
void assignproactorre();
void assignStudent();
void searchInformation();
void updateInformation();
void generateReport();
void deleteinformation();
void accident();
void accidentteam();
void notification();
int  main() {
    developer();
    System();
    return 0;
}
void developer() {
    system("color 3");
    cout << "This system is developed by ABDLREZAK SULTAN he is fullstack devloper and application devloper  \n";
    string c;
    cout << "\n\nPlease Enter any key to get the system";
    cin >> c;
    system("cls");
}
void System() {
    system("color 3");
    system("cls");
    cout << "\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "\t\t\t@@@@@@@@ WELL COME TO WCU STUDENT DORMITORY MANAGMENT SYSTEM @@@@\n";
    cout << "\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "\t\t\t@@@@@@@@@@@@ TO USE THIS SYSTEM PLEASE USE MAIN MENU @@@@@@@@@@@@\n\n\n";
    p:
    string choice;
    cout << "MAIN MENU:\n\n";
    cout << " 1: STUDENT HEAD OFFICE:\n";
    cout << " 2: Dormitory manager:\n";
    cout << " 3: PROCTOR:\n";
    cout << " 4: STUDENT:\n";
    cout << " 5: TO EXIT PROGRAM:\n";
    cout << "\nPLEASE ENTER YOUR CHOICE: ";
    cin >> choice;

    if (choice == "1") {
        studentheadoffice();
    }
    else if (choice == "2") {
        Dormitorymanager();
    }
    else if (choice == "3") {
        proacter();
    }
    else if (choice == "4") {
        stude();
    }
    else if (choice == "5") {
        cout << " Exiting program..........";
    }
    else {
        cout << "\nInvalid choice.!please enter (1-5) to use this system!!" << endl;
        goto p;
    }
}
void studentheadoffice() {
    system("color 6");
    system("cls");
    string password;
    char choice;
p:
    cout << "Enter Head office password: ";
    cin >> password;
    // Check if password is correct
    if (password == "office") {
        do {
            cout << " 1. Add student information in to the system:\n";
            cout << " 2. Search Information:\n";
            cout << " 3. Generate Report:\n";
            cout << " 4. Exiting student head office menu: \n";
            cout << " 5. exit to programe      \n";
            cout << "Enter your choice:";
            cin >> choice;
            switch (choice) {
            case '1':
                addstudent();
                break;
            case '2':
                searchInformation();
                break;
            case '3':
                generateReport();
                break;
            case '4':
                cout << "Exiting proacter mode.\n";
                System();
                break;
            case '5':
                cout << "exit......";
                break;
            default:
                cout << "Invalid choice!!.\n";
                break;
            }
        } while (choice != '5');
    }
    else {
        char c;
        cout << "Incorrect password. please to enter the correct password press 1, To exit student head office menu press any key.\n";
        cin >> c;
        if (c == '1') {
            goto p;
        }
        else {
            cout << " exit ....\n";
            System();
        }
    }
}
void Dormitorymanager() {
    system("color 6");
    system("cls");
    string password;
    char choice;
    p:
    cout << "Enter procter manager password: ";
    cin >> password;
    // Check if password is correct
    if (password == "manager") {
        do {
            cout << "Dormitery manager Menu:\n";
            cout << " 1. Add block and assign procter:\n";
            cout << " 2. Search Information:\n";
            cout << " 3. Update Information:\n";
            cout << " 4. Generate Report:\n";
            cout << " 5. Delete Information:\n";
            cout << " 6. To see all acident Notification:\n";
            cout << " 7. Exiting dormitor manager menu: \n";
            cout << " 8. exit to programe      \n";
            cout << "Enter your choice:";
            cin >> choice;
            switch (choice) {
            case '1':
                addblock();
                break;
            case '2':
                searchInformation();
                break;
            case '3':
                updateInformation();
                break;
            case '4':
                generateReport();
                break;
            case '5':
                deleteinformation();
                break;
            case '6':
                char s;
                cout << "the system gives to you the word 'all' then pres any key to see notification\n";
                cout << "                                  ===\n";
                cin >> s;
                notification();
                break;
            case '7':
                cout << "Exiting procter manager mode.\n";
                System();
                break;
            case '8':
                cout << "Exiting program......\n";
                break;
            default:
                cout << "Invalid choice!!.\n";
                break;
            }
        } while (choice != '8');
    }
    else {
        char c;
        cout << "Incorrect password. please to enter the correct password press 1, To exit dormitory manager menu press any key.\n";
        cin >> c;
        if (c == '1') {
            goto p;
        }
        else {
            cout << " exit ....\n";
            System();
        }
    }
}
void proacter() {
    system("color 6");
    system("cls");
    char choice;
    p:
    string pasword;
    cout << "Enter procter private password:\n";
    cin >> pasword;
    bool cheack = false;
    ifstream infile("procter.txt");
    if (!infile.is_open()) {
        cout << "Error: Unable to open file.\n";
        return;
    }
    procter currenprocter;
    while (!infile.eof()) {
        infile >> currenprocter.name >> currenprocter.phone_no >> currenprocter.blockname >> currenprocter.pasword;
        if (currenprocter.pasword == pasword) {
            cheack = true;
            break;
        }
    }
    infile.close();
    if (cheack) {
        do {
            cout << "pocter menu:\n";
            cout << "1. add room to block \n";
            cout << "2. assign student  \n";
            cout << "3. Search information\n";
            cout << "4. Update Information:\n";
            cout << "5. Generate Report:\n";
            cout << "6. Delete Information:\n";
            cout << "7. to see accident notification \n";
            cout << "8. Exit procter mode\n";
            cout << "9. Exit to program\n";
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
            case '1':
                addroom();
                break;
            case '2':
                assignStudent();
                break;
            case '3':
                searchInformation();
                break;
            case '4':
                updateInformation();
                break;
            case '5':
                generateReport();
                break;
            case '6':
                deleteinformation();
                break;
            case '7':
                notification();
                break;
            case '8':
                System();
                break;
            case '9':
                cout << "Exiting program......\n";
                break;
            default:
                cout << "Invalid choice.\n";
                break;
            }
        } while (choice != '9');
    }
    else {
        char c;
        cout << "Incorrect password. please to enter the correct password press 1, To exit procter menu press any key.\n";
        cin >> c;
        if (c == '1') {
            goto p;
        }
        else {
            cout << " exit ....";
            System();
        }
    }
}
void stude() {
    system("color 2");
    system("cls");
    char choice;
    p:
    do {
        cout << "STUDENT MENU:\n";
        cout << " 1. Search student information:\n";
        cout << " 2. Report an accident:\n";
        cout << " 3. T0 Exit student mode:\n";
        cout << " 4. T0 Exit The program:\n";
        cout << "Enter your choice:";
        cin >> choice;
        switch (choice) {
        case '1':
            searchInformation(); // Search student information only and see room and block when assigned information
            break;
        case '2':
            accident(); // Report an accident
            break;
        case '3':
            cout << "Exiting student mode.\n";
            System();
            break;
        case '4':
            cout << "Exiting the program......\n";
            break;
        default:
            cout << "\nInvalid choice!. please enter (1-4)\n";
            goto p;
        }
    } while (choice != '4');
}
void addstudent() {
    int n;
    cout << " please enter number of student to add the system: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        student newStudent;
        cout << "Enter student name: ";
        cin >> newStudent.name;
        cout << "Enter student ID number: ";
        cin >> newStudent.idnumber;
        cout << "Enter student age: ";
        cin >> newStudent.age;
        cout << "Enter student gender: ";
        cin >> newStudent.gender;
        cout << "Enter student department: ";
        cin >> newStudent.department;
        ofstream outfile;
        outfile.open("student_list.txt", ios::app);
        if (!outfile.is_open()) {
            cout << "Error: Unable to open file.\n";
            return;
        }
        outfile << newStudent.name << " " << newStudent.idnumber << " " << newStudent.age << " " << newStudent.gender << " " << newStudent.department<<endl;
        outfile.close();
        cout << newStudent.name << " is succesfuly adead\n";
    }
}
void assignproactorre(string block, int i) {
    system("cls");
    // Assign the procter to the block
    cout << "\tPlease assign procter to block " << block << endl;
    procter newprocter;
    cout << "Enter procter name: ";
    cin >> newprocter.name;
    cout << "Enter procter phone number: ";
    cin >> newprocter.phone_no;
    cout << "Enter procter pasword : ";
    cin >> newprocter.pasword;
    newprocter.blockname = block;
    // Save procter and block information to file
    ofstream poutfile("procter.txt", ios::app);
    ofstream doutfile("block.txt", ios::app);
    if (poutfile.is_open() && doutfile.is_open()) {
        poutfile << newprocter.name << " " << newprocter.phone_no << " " << newprocter.blockname << " " << newprocter.pasword<<endl;
        doutfile << newprocter.blockname;
        poutfile.close();
        doutfile.close();
        cout << newprocter.blockname << " successfully added.\n";
    }
    else {
        cout << "eror!! unable to add " << newprocter.blockname << endl;
    }

}
void addblock() {
    system("cls");
    string block;
    int n;
    cout << "enter number of block to add : ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Enter block name: " << i << " ";
        cin >> block;
        assignproactorre(block, i);
    }
}
void addroom() {
    system("cls");
    string pasword, block;
    cout << "Enter private procter password to add room:\n";
    cin >> pasword;
    bool found = false, save = false;
    ifstream infile("procter.txt");
    if (!infile.is_open()) {
        cout << "Error: Unable to open file.\n";
        return;
    }
    procter currenprocter;
    while (!infile.eof()) {
        infile >> currenprocter.name >> currenprocter.phone_no >> currenprocter.blockname >> currenprocter.pasword;
        if (currenprocter.pasword == pasword) {
            found = true;
            int n;
            dormitory room;
            room.blockname = currenprocter.blockname;
            room.occupied = 0;
            cout << "please enter number of rooms to add\n";
            cin >> n;
            int j = 1;
            for (int i = 0; i < n; i++) {
                cout << "please enter room " << j << " name: ";
                cin >> room.dormname;
                cout << "please enter room " << j << " cappacity: ";
                cin >> room.capacity;
                j++;
                ofstream outfile("room.txt", ios::app);
                if (outfile.is_open()) {
                    save = true;
                    outfile << room.blockname << " " << room.dormname << " " << room.capacity << " " << room.occupied;
                    outfile.close();
                }
            }
            break;
        }
    }
    infile.close();
    if (found) {
        if (save) {
            cout << "roomes registerd succesfully.\n";
        }
        else {
            cout << "eror!! unable to open file!!";
            return;
        }
    }
    else {
        cout << "incoracte password!!\n";
    }
}
void assignStudent() {
    system("cls");
    system("color 3");
    string pasword, block, selectedDorm;
    A:
    cout << "Enter private procter password to assign student:\n";
    cin >> pasword;
    bool found = false, cheack = false, capacity = false,  abdu = false;
    ifstream infile("procter.txt");
    if (!infile.is_open()) {
        cout << "Error: Unable to open file.\n";
        return;
    }
    procter currenprocter;
    while (!infile.eof()) {
        infile >> currenprocter.name >> currenprocter.phone_no >> currenprocter.blockname >> currenprocter.pasword;
        if (currenprocter.pasword == pasword) {
            cheack = true;
            block = currenprocter.blockname;
            // Read available room from file
            ifstream list("room.txt");
            if (!list.is_open()) {
                cout << "Error: Unable to open file.\n";
                return;
            }
            dormitory Dorm;
            int i = 1;
            while (!list.eof()) {
                list >> Dorm.blockname >> Dorm.dormname >> Dorm.capacity >> Dorm.occupied;
                if (Dorm.blockname == block) {
                    cout << i << ". room name: " << Dorm.dormname << ", capacity: " << Dorm.capacity << ", occupied: " << Dorm.occupied << endl;
                    i++;
                }
            }
            list.close();
            // Prompt user to select a dormitory
            cout << "Enter the name of the room to assign the student: ";
            cin >> selectedDorm;
            // Check if the selected room exists and has available space
            ifstream cheak("room.txt");
            if (!cheak.is_open()) {
                cout << "Error: Unable to open file.\n";
                return;
            }
            dormitory dorm;
            while (!cheak.eof()) {
                cheak >> dorm.blockname >> dorm.dormname >> dorm.capacity >> dorm.occupied;
                if (dorm.dormname == selectedDorm && dorm.blockname == block) {
                    found = true;
                    if (dorm.occupied < dorm.capacity) {
                        capacity = true;
                        int id;
                        cout << " please enter student id number to assign :";
                        cin >> id;
                        ifstream read("student_list.txt");
                        fstream outfile;
                        if (read.is_open()) {
                            while (!read.eof()) {
                                student newStudent;
                                read >> newStudent.name >> newStudent.idnumber >> newStudent.age >> newStudent.gender >> newStudent.department;
                                if (newStudent.idnumber == id) {
                                    newStudent.blockname = block;
                                    newStudent.dormitory = selectedDorm;
                                    outfile.open("students.txt",ios::in);
                                    if(!outfile){
                                    	outfile.open("students.txt",ios::app|ios::out);
                                    	outfile << newStudent.name << " " << newStudent.idnumber << " " << newStudent.age << " " << newStudent.gender << " " << newStudent.department << " " << newStudent.blockname << " " << newStudent.dormitory<<endl ;
									    outfile.close();
									    abdu=true;
									}
									else{
									    student file;
									    while(!outfile.eof()){
									    	outfile >> file.name >> file.idnumber >> file.age >> file.gender >> file.department >> file.blockname >> file.dormitory;
									    	if(file.idnumber==id){
									    		cout<<" this student is already exist please enter onother student  ...\n";
									    		goto A;
											}
										}
										outfile.close();
										outfile.open("students.txt",ios::app|ios::out);
                                    	outfile << newStudent.name << " " << newStudent.idnumber << " " << newStudent.age << " " << newStudent.gender << " " << newStudent.department << " " << newStudent.blockname << " " << newStudent.dormitory<<endl ;
									    outfile.close();
									    abdu=true;
									}
                                }
                            }
                            read.close();
                        }
                        else {
                            cout << "file is not open to read student information!!";
                            return;
                        }
                    }
                }
            }
            cheak.close();
        }
    }
    infile.close();
    if (cheack) {
        if (found) {
            if (capacity) {
                if (abdu) {
                    cout << "the student is assignd sucessfuly\n";
                    ifstream Occupied("room.txt");
                    ofstream tempFile("temp_room.txt", ios::app);
                    if (Occupied.is_open() && tempFile.is_open()) {
                        dormitory tempDorm;
                        while (!Occupied.eof()) {
                            Occupied >> tempDorm.blockname >> tempDorm.dormname >> tempDorm.capacity >> tempDorm.occupied;
                            if (tempDorm.blockname == block & tempDorm.dormname == selectedDorm) {
                                tempDorm.occupied++;
                                tempFile << tempDorm.blockname << " " << tempDorm.dormname << " " << tempDorm.capacity << " " << tempDorm.occupied;
                            }
                            else {
                                tempFile << tempDorm.blockname << " " << tempDorm.dormname << " " << tempDorm.capacity << " " << tempDorm.occupied;
                            }
                        }
                        Occupied.close();
                        tempFile.close();
                        remove("room.txt");
                        rename("temp_room.txt", "room.txt");
                    }
                }
                else {
                    cout << "This student is not registerd in thi sistem please cominicat with student head office register the student!!\n";
                }
            }
            else {
                cout << "select room is full!!\n";
            }
        }
        else {
            cout << "incoract room selected!!!.\n";
        }
    }
    else {
        cout << "incoracte password!!\n";
    }
}
void searchInformation() {
    system("color 9");
    system("cls");
    char choice;
    cout << "Search menu:\n";
    cout << " 1. Search student information by ID number\n";
    cout << " 2. Search dormitory information\n";
    cout << " 3. Search procter information\n";
    cout << " 4. To exit search meanu\n";
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == '1') {
        // Search student information by ID number
        int searchID;
        cout << "Enter student ID number to search: ";
        cin >> searchID;
        bool found = false;
        ifstream infile("students.txt");
        if (!infile.is_open()) {
            cout << "Error: Unable to open file.\n";
            return;
        }
        student currentStudent;
        while (!infile.eof()) {
            infile >> currentStudent.name >> currentStudent.idnumber >> currentStudent.age >> currentStudent.gender >> currentStudent.department >> currentStudent.blockname >> currentStudent.dormitory;
            if (currentStudent.idnumber == searchID) {
                cout << "Name: " << currentStudent.name << ", ID: " << currentStudent.idnumber << ", Age: " << currentStudent.age << ", Gender: " << currentStudent.gender << ", Department: " << currentStudent.department << ", block name: " << currentStudent.blockname << ", Dormitory: " << currentStudent.dormitory << endl;
                found = true;
                break; // Stop searching after finding the student
            }
        }
        infile.close();
        if (!found) {
            cout << "Student not found.\n";
        }
    }
    else if (choice == '2') {
        string pasword, block;
        cout << "Enter private procter passwordor or student manager password to see dormitory room information:\n";
        cin >> pasword;
        bool found = false;
        ifstream cheack("procter.txt");
        if (!cheack.is_open()) {
            cout << "Error: Unable to open file.\n";
            return;
        }
        procter currenprocter;
        while (!cheack.eof()) {
            cheack >> currenprocter.name >> currenprocter.phone_no >> currenprocter.blockname >> currenprocter.pasword;
            // Check if password is correct
            if (currenprocter.pasword == pasword || pasword == "manager") {
                string searchdormname;
                // Search dormitory information
                cout << "Please enter the room name: ";
                cin >> searchdormname;
                bool found = false;
                ifstream infile("room.txt");
                if (!infile.is_open()) {
                    cout << "Error: Unable to open file.\n";
                    return;
                }
                dormitory currentdormitoy;
                while (!infile.eof()) {
                    infile >> currentdormitoy.blockname >> currentdormitoy.dormname >> currentdormitoy.capacity >> currentdormitoy.occupied;
                    if (currentdormitoy.blockname == currenprocter.blockname & currentdormitoy.dormname == searchdormname) {
                        cout << "1. " << "Room Name: " << currentdormitoy.dormname << ", capacity: " << currentdormitoy.capacity << ", occupied: " << currentdormitoy.occupied << endl;
                        found = true;
                        return; // Stop searching after finding the dormitory
                    }
                }
                infile.close();
            }
            if (pasword == "manager") {
                return;
            }
        }
        cheack.close();
        if (!found) {
            cout << "The room name is not found.\n";
        }
    }
    else if (choice == '3') {
        string searchpasword;
        cout << "Enter private procter password to Search procter information :\n";
        cin >> searchpasword;
        bool found = false;
        ifstream infile("procter.txt");
        if (!infile.is_open()) {
            cout << "Error: Unable to open file.\n";
            return;
        }
        procter currenprocter;
        while (!infile.eof()) {
            infile >> currenprocter.name >> currenprocter.phone_no >> currenprocter.blockname >> currenprocter.pasword;
            if (currenprocter.pasword == searchpasword) {
                cout << "procter name: " << currenprocter.name << ", phone number: " << currenprocter.phone_no << ", Block name: " << currenprocter.blockname << ", pasword: " << currenprocter.pasword << endl;
                found = true;
                break; // Stop searching after finding the procter
            }
            else {
                cout << "procter  information  is not found.\n";
            }
        }
        infile.close();
    }
    else if (choice == '4') {
        System();
    }
    else {
        cout << "Invalid choice.\n";
    }
}
void updateInformation() {
    system("cls");
    char choice;
    cout << "Update Menu: \n";
    cout << " 1: Update to student information:\n";
    cout << " 2: Update to dormitory information:\n";
    cout << " 3: Update to procter information:\n";
    cout << " 4: To exit update menu:\n";
    cin >> choice;
    if (choice == '1') {
        string searchpasword;
        cout << "Enter private procter password to update student information :\n";
        cin >> searchpasword;
        bool found1 = false, found=false;
        ifstream infile("procter.txt");
        if (!infile.is_open()) {
            cout << "Error: Unable to open file.\n";
            return;
        }
        procter currenprocter;
        while (!infile.eof()) {
            infile >> currenprocter.name >> currenprocter.phone_no >> currenprocter.blockname >> currenprocter.pasword;
            if (currenprocter.pasword == searchpasword) {
                found1 = true;
                int updateId;
                cout << "Enter student ID number to update: ";
                cin >> updateId;
                // Update student information	
                bool found = false;
                ifstream inFile("students.txt");
                ofstream tempFile("temp_students.txt");
                if (inFile.is_open() && tempFile.is_open()) {
                    student TempStudent;
                    student tempStudent;
                    while (inFile >> tempStudent.name >> tempStudent.idnumber >> tempStudent.age >> tempStudent.gender >> tempStudent.department >> tempStudent.blockname >> tempStudent.dormitory) {                       
                        if (tempStudent.idnumber == updateId & currenprocter.blockname == tempStudent.blockname) {
                            found = true;
                            cout << "Enter updated information:\n";
                            cout << "Name: ";
                            cin >> TempStudent.name;
                            cout << "Id number: ";
                            cin >> TempStudent.idnumber;
                            cout << "Age: ";
                            cin >> TempStudent.age;
                            cout << "Gender: ";
                            cin >> TempStudent.gender;
                            cout << "Department: ";
                            cin >> TempStudent.department;
                            cout << "room: ";
                            cin >> TempStudent.dormitory;
                            TempStudent.blockname = currenprocter.blockname;
                            tempFile << TempStudent.name << " " << TempStudent.idnumber << " " << TempStudent.age << " " << TempStudent.gender << " " << TempStudent.department << " " << TempStudent.blockname << " " << TempStudent.dormitory << endl;
                        }
                        else {
                            tempFile << tempStudent.name << " " << tempStudent.idnumber << " " << tempStudent.age << " " << tempStudent.gender << " " << tempStudent.department << " " << tempStudent.blockname << " " << tempStudent.dormitory << endl;
                        }
                    }
                    inFile.close();
                    tempFile.close();
                    remove("students.txt");
                    rename("temp_students.txt","students.txt");
                }
                else {
                    cout << "Error: Unable to open file.\n";
                    return;
                }
                if (!found) {
                    cout << "Student not found.\n";
                }
                else {
                    cout << "Student information updated successfully.\n";
                }
            }
        }
        infile.close();
        if (!found1) {
            cout << "incoract password!!";
        }
    }
    else if (choice == '2') {
        string searchpasword;
        cout << "Enter private procter password to Search procter information :\n";
        cin >> searchpasword;
        ifstream room("procter.txt");
        if (!room.is_open()) {
            cout << "Error: Unable to open file.\n";
            return;
        }
        bool found = false, roo = false;
        procter currenprocter;
        while (!room.eof()) {
            room >> currenprocter.name >> currenprocter.phone_no >> currenprocter.blockname >> currenprocter.pasword;
            if (currenprocter.pasword == searchpasword) {
                string updateDorm;
                found = true;
                cout << "Enter room name to update: ";
                cin >> updateDorm;
                ifstream inFile("room.txt");
                ofstream tempFile("temp_dormitories.txt");
                if (inFile.is_open() && tempFile.is_open()) {
                    dormitory tempDorm;
                    while (inFile >> tempDorm.blockname >> tempDorm.dormname >> tempDorm.capacity >> tempDorm.occupied) {
                        if (tempDorm.blockname == currenprocter.blockname & tempDorm.dormname == updateDorm) {
                            roo = true;
                            int i, j;
                            cout << "only update Capacity and occupide please enter new cappacity: ";
                            cin >> i;
                            cout << " please enter new occupied: ";
                            cin >> j;
                            tempFile << tempDorm.blockname << " " << tempDorm.dormname << " " << i << " " << j;
                        }
                        else {
                            tempFile << tempDorm.blockname << " " << tempDorm.dormname << " " << tempDorm.capacity << " " << tempDorm.occupied;
                        }
                    }
                    inFile.close();
                    tempFile.close();
                    remove("room.txt");
                    rename("temp_dormitories.txt","room.txt");
                }
                else {
                    cout << "Error: Unable to open file.\n";
                    return;
                }
            }
        }
        room.close();
        if (found) {
            if (roo) {
                cout << "room capacity and occupide is updated successfully.\n";
            }
            else {
                cout << "Dormitory not found.\n";
            }
        }
        else {
            cout << "incoracte pasword\n\n";
        }
    }
    else if (choice == '3') {
        string pasword, block;
        cout << "Enter student manager password to update proacter:\n";
        cin >> pasword;
        if (pasword == "manager") {
            string update;
            cout << "Enter procter password to update procter information: ";
            cin >> update;
            // Update procter information
            bool found = false;
            ifstream inFile("procter.txt");
            ofstream tempFile("temp_procter.txt");
            if (inFile.is_open() && tempFile.is_open()) {
                procter Tempprocter;
                procter tempprocter;
                while (!inFile.eof()) {
                    inFile >> tempprocter.name >> tempprocter.phone_no >> tempprocter.blockname >> tempprocter.pasword;
                    if (tempprocter.pasword == update) {
                        found = true;
                        cout << "Enter updated information:\n";
                        cout << "procter name: ";
                        cin >> tempprocter.name;
                        cout << "phone number: ";
                        cin >> tempprocter.phone_no;
                        cout << "block name: ";
                        cin >> tempprocter.blockname;
                        cout << "password: ";
                        cin >> tempprocter.pasword;
                        tempFile << tempprocter.name << " " << tempprocter.phone_no << " " << tempprocter.blockname << " " << tempprocter.pasword << endl;
                    }
                    else {
                        tempFile << tempprocter.name << " " << tempprocter.phone_no << " " << tempprocter.blockname << " " << tempprocter.pasword << endl;
                    }
                }
                inFile.close();
                tempFile.close();
                remove("procter.txt");
                rename("temp_procter.txt","procter.txt");
            }
            else {
                cout << "Error: Unable to open file.\n";
                return;
            }
            if (!found) {
                cout << "procter not found.\n";
            }
            else {
                cout << "procter information updated successfully.\n";
            }
        }
        else {
            cout << "incoracte pasword\n\n";
        }
    }
    else if (choice == '4') {
        System();
    }
    else {
        cout << "Invalid choice.\n";
    }
}

void generateReport() {
    system("color 3");
    system("cls");
    char choice;
G:
    cout << "TO Generate report\n";
    cout << " 1: student report:\n";
    cout << " 2: dormitory report:\n";
    cout << " 3: procter report:\n";
    cout << " 4: To exit :\n";
    cin >> choice;
    if (choice == '1') {
        string passs;
        cout << " please enter dormitory manager or student head office password: ";
        cin >> passs;
        if (passs == "manager" || passs == "office") {
            ifstream studentFile("students.txt");
            if (!studentFile.is_open()) {
                cout << "Error: Unable to open students file for reading.\n";
                return;
            }
            int countnumberofstudent = 0, i = 1;
            student students;
            cout << "Student Report:\n";
            cout << "----------------------------------------------------------------------------------------------------\n";
            while (studentFile >> students.name >> students.idnumber >> students.age >> students.gender >> students.department >> students.blockname >> students.dormitory) {
               
                cout << i << ". Name: " << students.name << ", ID: " << students.idnumber << ", Age: " << students.age << ", Gender: " << students.gender << ", Department: " << students.department << ", block name: " << students.blockname << ", Dormitory: " << students.dormitory << endl;
                cout << "-----------------------------------------------------------------------------------------------------\n";
                countnumberofstudent++;
            }
            studentFile.close();
            cout << "\n\t\tTotal number of student is: " << countnumberofstudent << endl << endl;
        }
        else {
            cout << "incoract paasword!!";
        }
    }
    else if (choice == '2') {
        char d;
    D:
        cout << "TO Generate dormitory report\n";
        cout << " 1: All dormitory report:\n";
        cout << " 2: One dormitory report:\n";
        cin >> d;
        if (d == '1') {
            string pasword;
            cout << "please enter student head office passwoed or dormitory manager: ";
            cin >> pasword;
            if (pasword == "office" || pasword == "manager") {
                ifstream dormitoryFile("room.txt");
                if (!dormitoryFile.is_open()) {
                    cout << "Error: Unable to open dormitories file for reading.\n";
                    return;
                }
                cout << "\nDormitory Report:\n";
                cout << "-------------------------------------------------------------\n";
                dormitory dorm;
                int i = 1, j = 0, t = 0;
                while (!dormitoryFile.eof()) {
                    dormitoryFile >> dorm.blockname >> dorm.dormname >> dorm.capacity >> dorm.occupied;
                    cout << i << ". block name: " << dorm.blockname << "| room: " << dorm.dormname << "| Capacity: " << dorm.capacity << "| occupied " << dorm.occupied << endl;
                    cout << "-------------------------------------------------------------\n";
                    j++;
                    i++;
                    t = t + dorm.occupied;
                }
                dormitoryFile.close();
                cout << "\n-> Total number of room in all block = " << j << endl;
                cout << "-> Total number of student  = " << t << endl;
            }
            else {
                char c;
                cout << "incoract paasword!!  to coontinue please enter any key: ";
                cin >> c;
                goto D;
            }
        }
        else if (d == '2') {
            string pass;
            cout << "please enteer procter password: ";
            cin >> pass;
            bool found = false, block = false;
            int i = 1, j = 0, t = 0;
            ifstream infile("procter.txt");
            if (!infile.is_open()) {
                cout << "Error: Unable to open file.\n";
                return;
            }
            procter currenprocter;
            while (!infile.eof()) {
                infile >> currenprocter.name >> currenprocter.phone_no >> currenprocter.blockname >> currenprocter.pasword;
                if (currenprocter.pasword == pass) {
                    found = true;
                    ifstream dormitoryFile("room.txt");
                    if (!dormitoryFile.is_open()) {
                        cout << "Error: Unable to open dormitories file for reading.\n";
                        return;
                    }
                    cout << "\nDormitory Report:\n";
                    cout << "-------------------------------------------------------------\n";
                    dormitory dorm;
                    while (dormitoryFile >> dorm.blockname >> dorm.dormname >> dorm.capacity >> dorm.occupied) {
                        if (currenprocter.blockname == dorm.blockname) {
                            block = true;
                            cout << i << ". block name: " << dorm.blockname << "| room: " << dorm.dormname << "| Capacity: " << dorm.capacity << "| occupied " << dorm.occupied << endl;
                            cout << "-------------------------------------------------------------\n";
                            j++;
                            i++;
                            t = t + dorm.occupied;
                        }
                    }
                    dormitoryFile.close();
                }
            }
            infile.close();
            if (found) {
                if (block) {
                    cout << "\n\n-> Total number of room = " << j << endl;
                    cout << "-> Total number of student when block occupied = " << t << endl;

                }
                else {
                    cout << "dornitory not found.\n";
                }
            }
            else {
                cout << "procter password is incoreact.\n";
            }
        }
        else {
            cout << "incoract choise!!\n";
        }
    }
    else if (choice == '3') {
        string manager;
        cout << "please enter  dormitory manager password: ";
        cin >> manager;
        if (manager == "manager") {
            ifstream procterFile("procter.txt");
            if (!procterFile.is_open()) {
                cout << "Error: Unable to open dormitories file for reading.\n";
                return;
            }
            int p = 1;
            cout << "\n\t\tProcter Report:\n";
            cout << "------------------------------------------------------------------------------------------\n";
            procter pro;
            while (procterFile >> pro.name >> pro.phone_no >> pro.blockname >> pro.pasword) {
                cout << p << ". Procter name: " << pro.name << "| phone number: " << pro.phone_no << "| Block name: " << pro.blockname << "| procter pasword: " << pro.pasword << endl;
                cout << "------------------------------------------------------------------------------------------\n";
                p++;
            }
            procterFile.close();
        }
        else {
            cout << "incoract password!!\n";
        }
    }
    else if (choice == '4') {
        System();
    }
    else {
        cout << "Invalid choice.\n";
        goto G;
    }
}
void deleteinformation() {
    system("color 4");
    system("cls");
    char choice;
D:
    cout << "To Delete information\n";
    cout << " 1: student information:\n";
    cout << " 2: dormitory information:\n";
    cout << " 3: procter information:\n";
    cout << " 4: To exit delate menu:\n";
    cin >> choice;
    if (choice == '1') {
        string pass;
        cout << "please enteer procter password: ";
        cin >> pass;
        bool found = false, id = false;
        ifstream password("procter.txt");
        if (!password.is_open()) {
            cout << "Error: Unable to open file.\n";
            return;
        }
        procter currenprocter;
        while (!password.eof()) {
            password >> currenprocter.name >> currenprocter.phone_no >> currenprocter.blockname >> currenprocter.pasword;
            if (currenprocter.pasword == pass) {
                found = true;
                int deleteId;
                cout << "Enter student ID number to delete: ";
                cin >> deleteId;
                // Delete student information
                ifstream inFile("students.txt");
                ofstream tempFile("temp_students.txt");
                if (inFile.is_open() && tempFile.is_open()) {
                    student tempStudent;
                    while (!inFile.eof()) {
                        inFile >> tempStudent.name >> tempStudent.idnumber >> tempStudent.age >> tempStudent.gender >> tempStudent.department >> tempStudent.blockname >> tempStudent.dormitory;
                        if (tempStudent.idnumber == deleteId && currenprocter.blockname == tempStudent.blockname) {
                            id = true;
                        }
                        else {
                            tempFile << tempStudent.name << " " << tempStudent.idnumber << " " << tempStudent.age << " " << tempStudent.gender << " " << tempStudent.department << " " << tempStudent.blockname << " " << tempStudent.dormitory << endl;
                        }
                    }
                    inFile.close();
                    tempFile.close();
                    // Remove old students file
                    remove("students.txt");
                    // Rename temp file to students file
                    rename("temp_students.txt","students.txt");
                }
                else {
                    cout << "Error: Unable to open file.\n";
                    return;
                }
            }
        }
        password.close();
        if (found) {
            if (id) {
                cout << "Student information deleted successfully.\n";
            }
            else {
                cout << "Student not found.\n";
            }
        }
        else {
            cout << "incoract password!!\n";
        }
    }
    else if (choice == '2') {
        string pass, deleteDorm;
        cout << "please enteer procter password: ";
        cin >> pass;
        bool found = false, Room = false;
        ifstream room("procter.txt");
        if (!room.is_open()) {
            cout << "Error: Unable to open file.\n";
            return;
        }
        procter currenprocter;
        while (!room.eof()) {
            room >> currenprocter.name >> currenprocter.phone_no >> currenprocter.blockname >> currenprocter.pasword;
            if (currenprocter.pasword == pass) {
                found = true;
                cout << "Enter room name to delete: ";
                cin >> deleteDorm;
                ifstream inFile("room.txt");
                ofstream tempFile("temp_room.txt");
                if (inFile.is_open() && tempFile.is_open()) {
                    dormitory tempDorm;
                    while (!inFile.eof()) {
                        inFile >> tempDorm.blockname >> tempDorm.dormname >> tempDorm.capacity >> tempDorm.occupied;
                        if (tempDorm.blockname == currenprocter.blockname && tempDorm.dormname == deleteDorm) {
                            Room = true;
                        }
                        else {
                            tempFile << tempDorm.blockname << " " << tempDorm.dormname << " " << tempDorm.capacity << " " << tempDorm.occupied;
                        }
                    }
                    inFile.close();
                    tempFile.close();
                    // Remove old dormitories file
                    remove("room.txt");
                    // Rename temp file to dormitories file
                    rename("temp_room.txt","room.txt");
                }
                else {
                    cout << "Error: Unable to open file.\n";
                    return;
                }
            }
        }
        room.close();
        if (found) {
            if (Room) {
                cout << "Room deleted successfully.\n";
            }
            else {
                cout << "room not found.\n";
            }
        }
        else {
            cout << "incoract pasword!!\n";
        }
    }
    else if (choice == '3') {
        string mpass, ppass;
        cout << "enter dormitory manager password to delater procter: ";
        cin >> mpass;
        bool dmanager = false, found = false;
        if (mpass == "manager") {
            dmanager = true;
            cout << "Enter procter password to deleate procter information: ";
            cin >> ppass;
            ifstream inFile("procter.txt");
            ofstream tempFile("temp_procter.txt");
            if (inFile.is_open() && tempFile.is_open()) {
                procter temp;
                while (!inFile.eof()) {
                    inFile >> temp.name >> temp.phone_no >> temp.blockname >> temp.pasword;
                    if (temp.pasword == ppass) {
                        found = true;
                    }
                    else {
                        tempFile << temp.name << " " << temp.phone_no << " " << temp.blockname << " " << temp.pasword << endl;
                    }
                }
                inFile.close();
                tempFile.close();
                // Remove old dormitories file
                remove("procter.txt");
                // Rename temp file to dormitories file
                rename("temp_procter.txt","procter.txt");
            }
            else {
                cout << "Error: Unable to open file.\n";
                return;
            }
        }
        if (dmanager) {
            if (found) {
                cout << "procter information deleted successfully.\n";
            }
            else {
                cout << "procter information not found to delate.\n";
            }
        }
        else {
            cout << "incoract manager pasword!!\n";
        }
    }
    else if (choice == '4') {
        System();
    }
    else {
        cout << "Invalid choice.\n";
        goto D;
    }
}
void accidentteam(int &studentID, string &blockname, string &dormname) {
    system("cls");
    string time;
    bool found = false, file = false;
    ifstream inFile("room.txt");
    if (inFile.is_open()) {
        dormitory Dorm;
        while (!inFile.eof()) {
            inFile >> Dorm.blockname >> Dorm.dormname >> Dorm.capacity >> Dorm.occupied;
            if (Dorm.blockname == blockname && Dorm.dormname == dormname) {
                found = true;
                cout << "please enter the time when acident occured please (enter the time in this way 2:00am/pm) :";
                cin >> time;
                ofstream outFile("accident_notification.txt", ios::app);
                if (outFile.is_open()) {
                    outFile << blockname << " " << dormname << " " << time << " " << studentID << endl;
                    outFile.close();
                }
                else {
                    file = false;
                }
            }
        }
        inFile.close();
        if (found) {
            if (file) {
                cout << "Error: Unable to open file to  notification.\n";
            }
            else {
                cout << "An accident has been reported. Please remain calm and await assistance.\n";
                cout << "and to get more information  call in this phone number 2519__________; 2519__________; \n";
            }
        }
        else {
            cout << "The block -> " << blockname << " and the room -> " << dormname << " are not found  please \n";
        }
    }
}
void accident() {
    system("color 4");
    system("cls");
    int studentID;
    dormitory dorm;
    cout << "Enter your student ID: ";
    cin >> studentID;
    cout << "please enter the block where accident occurred :\n";
    cin >> dorm.blockname;
    cout << " please enter the room where accident occurred :\n";
    cin >> dorm.dormname;
    bool found = false, room = false;
    ifstream infile("students.txt");
    if (!infile.is_open()) {
        cout << "Error: Unable to open file for reading.\n";
        return;
    }
    student currentStudent;
    while (!infile.eof()) {
        infile >> currentStudent.name >> currentStudent.idnumber >> currentStudent.age >> currentStudent.gender >> currentStudent.department >> currentStudent.blockname >> currentStudent.dormitory;
        if (currentStudent.idnumber == studentID) {
            found = true;
            if (dorm.blockname == currentStudent.blockname && dorm.dormname == currentStudent.dormitory) {
                room = true;
                break;
            }
            break;
        }
    }
    infile.close();
    if (found) {
        if (room) {
            accidentteam(studentID, dorm.blockname, dorm.dormname); // Call Accidentteam if student is found	
        }
        else {
            cout << "incoract room and block plese!!\n";
        }
    }
    else {
        cout << "Student with ID " << studentID << " does not exist please .\n";
    }
}
void notification() {
    system("cls");
    string pasword, block;
    cout << "Enter private procter passwordor or student manager password to see acident notification :\n";
    cin >> pasword;
    bool found = false, Notification = false;
    ifstream infile("procter.txt");
    if (!infile.is_open()) {
        cout << "Error: Unable to open file.\n";
        return;
    }
    procter currenprocter;
    while (!infile.eof()) {
        infile >> currenprocter.name >> currenprocter.phone_no >> currenprocter.blockname >> currenprocter.pasword;
        if (currenprocter.pasword == pasword || pasword == "manager") {
            found = true;
            ifstream noti("accident_notification.txt");
            if (!noti.is_open()) {
                cout << "Error: Unable to open file.\n";
                return;
            }
            cout << "if you are procetr please enter the block when you assigned if you are student manager please enter the word that system given to you:\n";
            cin >> block;
            notiffication Nptify;
            int id, i = 1;
            cout << "\t<<<<<<<<<<<<notification>>>>>>>>>>>>>>>>>>>>\n";
            while (noti >> Nptify.notify.blockname >> Nptify.notify.name >> Nptify.time >> id) {
                if (Nptify.notify.blockname == block || "all" == block) {
                    Notification = true;
                    cout << i << ". accident occured room " << Nptify.notify.name << " accident occured time " << Nptify.time << " acident reprtd student ID " << id << endl;
                    cout << "------------------------------------------------------------------------------------------\n";
                    i++;
                }
            }
            noti.close();
        }
        if (pasword == "manager") {
            return;
        }
    }
    infile.close();
    if (found) {
        if (!Notification) {
            cout << "inserted block or word is incorect \n";
        }
    }
    else {
        cout << "procter or dormitory manager password is incoreact.\n";

    }
}
