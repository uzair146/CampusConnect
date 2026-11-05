#include<iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
using namespace std;
string mark1();
void quiz(string id, const string& file);
void assignment(string id, const string& file);
void sessional(string id, const string& file);
void final(string id, const string file);
string rightid();
void add(const string student, string id, string name, string studentclass);
void del(const string student, string id);
void addStudent(const string student);
void deleteStudent(const string& student);
float totalmarks(string file, string id);
float cgp(string id, string file);
void cgpa(string id, string file);
void avgcgpa(string file);
void assignmarks(string id2, const string teacher);
void passstudents(string file);
void passstudents(string file);
void teacher();// function of teacher
void addTeacher(const string& teacher);
void deleteTeacher(const string teacher);
void admin();//function of admin
void math(string id);
void physics(string id);
void english(string id);
void programming(string id);
void islamiat(string id);
void data(string id);
void viewgrades(string id);
void viewcgpa(string id);
void student();// function of student




int main() {
    cout << "\033[33mWelcome to Data management system .\033[0m" << endl;            // starting of the sysytem 
    string str1 = "/0";
    cout << "1.Admin" << endl;                                       // showing the menu
    cout << "2.Teacher" << endl;
    cout << "3.Student" << endl;
    cout << "4.Exit" << endl;
    cout << "\033[33mEnter your choice :\033[0m ";


    int choice = 0;
    while (choice != 4) {
        getline(cin, str1);
        for (int i = 0;i < str1.length();++i) {
            if (!isdigit(str1[i])) {
                cout << "\033[31mChoice can only be integers digits.\033[0m" << endl << "\033[34mTry again :\033[0m ";
                getline(cin, str1);
                i = -1;
            }
        }
        choice = stoi(str1);

        switch (choice) {
        case 1:
            //use of functions according to given choice
            admin();
            system("cls");
            break;
        case 2:
            teacher();
            system("cls");
            break;
        case 3:
            student();

            break;
        case 4:
            continue;

        default:
            cout << "\033[31mInvalid choice." << endl << " \033[34mTry again.\033[0m " << endl;
        }
        cout << "1.Admin" << endl;
        cout << "2.Teacher" << endl;
        cout << "3.Student" << endl;                                          // showing the menu again for again functioning
        cout << "4.Exit" << endl;
        cout << endl;
        cout << "\033[33mEnter your choice : \033[0m";
    }
    system("cls");
    cout << "\033[32mThank you for using data management system.\033[0m" << endl;                     //showing ending message
    system("pause");
    return 0;
}


string mark1() {                                                                           //function for right marks
    string marks;


    getline(cin, marks);                                                                  // getting input and testing it
    for (int i = 0;i < marks.length();++i) {
        if (!isdigit(marks[i]) || !marks[i] == '.') {
            cout << "\033[31mMarks can only be digits.\033[0m" << endl << "\033[34mEnter again :\033[0m ";                            // looping it unti its right
            getline(cin, marks);
            system("cls");
            i = -1;
            continue;
        }


    }
    system("cls");
    return marks;                                                                          //returning to the function call
}


void quiz(string id, const string& file) {

    float marks;
    string mark;
    cout << "\033[33mEnter the marks of the student(less than or equal to 10) :\033[0m ";                                        ///Getting marks of the student
    mark = mark1();
    marks = stof(mark);
    while (marks > 10 || marks < 0) {
        if (marks > 10) {                                                                      //checking for marks invalid or more than the total
            cout << "\033[31mMarks cannot be more than total marks.\033[0m" << endl << "\033[34mTry again :\033[0m ";
            mark = mark1();
            marks = stof(mark);
        }
        if (marks < 0) {
            cout << "\033[31mMarks cannot be negative :\033[0m ";
            mark = mark1();
            marks = stof(mark);
        }
    }
    ifstream infile(file, ios::beg);
    if (!infile.is_open()) {                                                                       //checking for file opening
        cout << "\033[31mError opening input file.\033[0m" << endl;
        cout << "\033[33mReturning .\033[0m" << endl;
        return;
    }

    string line, currentid = "", data = "", edit = "";                                            // getting the id from the file and reforming the rest of the data
    while (getline(infile, line) || !infile.eof()) {
        for (int i = 0;i < line.length() && line[i] != ',';++i) {
            currentid += line[i];
        }
        if (currentid != id) {
            data = data + line + "\n";

        }
        else if (currentid == id) {
            edit = line;
        }
        currentid = "";

    }
    infile.close();
    string edit2 = "";
    for (int i = 0;i < edit.length() && edit[i] != ',';++i) {                         // changing the marks  into assigned marks
        edit2 += edit[i];

    }
    edit2 += ',' + mark;
    char ar1[20] = { '\0' };
    for (int i = 0;i < edit.length();++i) {
        ar1[i] = edit[i];
    }
    int coma = 0, i = 0;
    while (ar1[i] != '\0') {
        if (edit[i] == ',') {
            coma += 1;
        }
        if (coma > 1) {
            edit2 += ar1[i];                                                      //getting the place to write marks
        }
        i++;
    }
    data += edit2;                                                           // adding the changing marks to the data
    ofstream outfile(file, ios::beg, ios::trunc);

    outfile << data;                                                             //refilling the file with the data
    outfile.close();
    cout << "\033[32mMarks entered sucessfully.\033[0m" << endl;

    cin.ignore();
    system("cls");
    return;

}
void assignment(string id, const string& file) {
    float marks;
    string mark;
    cout << "\033[33mEnter the marks of the student (less than or equal to 10)  :\033[0m ";                                              ///Getting marks of the student
    mark = mark1();
    marks = stof(mark);
    while (marks > 10 || marks < 0) {
        if (marks > 10) {
            cout << "\033[31mMarks cannot be more than total marks.\033[0m" << endl << "\033[34mTry again :\033[0m ";                                 //checking for marks invalid or more than the total
            mark = mark1();
            marks = stof(mark);
        }
        if (marks < 0) {
            cout << "\033[31mMarks cannot be negative :\033[0m ";
            mark = mark1();
            marks = stof(mark);
        }
    }
    ifstream infile(file, ios::beg);
    if (!infile.is_open()) {                                                                                           //checking for file opening
        cout << "\033[31mError opening input file.\033[0m" << endl;
        cout << "\033[33mReturning.\033[0m" << endl;
        return;
    }

    string line, currentid = "", data = "", edit = "";
    while (getline(infile, line) || !infile.eof()) {
        for (int i = 0;i < line.length() && line[i] != ',';++i) {
            currentid += line[i];                                                                             // getting the id from the file and reforming the rest of the data
        }
        if (currentid != id) {
            data = data + line + "\n";

        }
        else if (currentid == id) {
            edit = line;
        }
        currentid = "";


    }
    infile.close();
    string edit2 = "";
    int coma = 0, count = 0;
    for (int i = 0;i < edit.length();++i) {                                     // changing the marks  into assigned marks
        if (edit[i] == ',') {
            ++coma;
        }
        if (coma < 2) {
            edit2 += edit[i];
        }
        if (coma > 2) {
            edit2 += edit[i];
        }
        if (coma == 2) {                                                       //getting the place to write marks
            if (count == 0) {
                edit2 += ',' + mark;
                count++;
            }
        }

    }
    data += edit2;
    ofstream outfile(file, ios::beg, ios::trunc);

    outfile << data;                                //refilling file with data
    outfile.close();
    cout << "\033[32mMarks entered sucessfully.\033[0m" << endl;

    cin.ignore();
    system("cls");
    return;

}
void sessional(string id, const string& file) {
    int marks;
    string mark;
    cout << "\033[33mEnter the marks of the student(less than or equal to 30) :\033[0m ";
    mark = mark1();                                                                               ///Getting marks of the student
    marks = stof(mark);
    while (marks > 30 || marks < 0) {
        if (marks > 30) {
            cout << "\033[31mMarks cannot be more than total marks.\033[0m" << endl << "\033[34mTry again :\033[0m ";                       //checking for marks invalid or more than the total
            mark = mark1();
            marks = stof(mark);
        }
        if (marks < 0) {
            cout << "\033[31mMarks cannot be negative \033[0m: ";
            mark = mark1();
            marks = stof(mark);
        }
    }
    ifstream infile(file, ios::beg);
    if (!infile.is_open()) {                                                         //checking for file opening
        cout << "\033[31mError opening input file.\033[0m" << endl;
        cout << "\033[33mReturning.\033[0m" << endl;
        return;
    }

    string line, currentid = "", data = "", edit = "";
    while (getline(infile, line)) {
        for (int i = 0;i < line.length() && line[i] != ',';++i) {                       // getting the id from the file and reforming the rest of the data
            currentid += line[i];
        }
        if (currentid != id) {
            data = data + line + "\n";

        }
        else if (currentid == id) {
            edit = line;
        }
        currentid = "";

    }
    infile.close();
    string edit2 = "";
    int coma = 0, count = 0;
    for (int i = 0;i < edit.length();++i) {                          // changing the marks  into assigned marks
        if (edit[i] == ',') {
            coma++;
        }
        if (coma != 3) {
            edit2 += edit[i];
        }
        else {
            if (count == 0) {
                edit2 += ',' + mark;                      //getting the place to write marks
                count++;
            }
        }

    }
    data += edit2;
    ofstream outfile(file, ios::beg, ios::trunc);
    if (!outfile.is_open()) {
        cout << "\033[31mError opening file.\033[0m" << endl;
        cout << "\033[33mReturning.\033[0m" << endl;
        return;
    }
    outfile << data;                                       //refilling file with data
    outfile.close();
    cout << "\033[32mMarks entered sucessfully.\033[0m" << endl;

    cin.ignore();
    system("cls");

    return;
}
void final(string id, const string file) {
    int marks;
    string mark;
    cout << "\033[33mEnter the marks of the student(less than or equal to 50) :\033[0m ";
    mark = mark1();                                                                             ///Getting marks of the student
    marks = stof(mark);
    while (marks > 50 || marks < 0) {
        if (marks > 50) {
            cout << "\033[31mMarks cannot be more than total marks.\033[0m" << endl << "\033[34mTry again :\033[0m ";                               //checking for marks invalid or more than the total
            mark = mark1();
            marks = stof(mark);
        }
        if (marks < 0) {
            cout << "\033[31mMarks cannot be negative \033[0m: ";
            mark = mark1();
            marks = stof(mark);
        }
    }
    ifstream infile(file, ios::beg);                                                      //checking for file opening
    if (!infile.is_open()) {
        cout << "\033[31mError opening input file.\033[0m" << endl;
        cout << "\033[33mReturning.\033[0m" << endl;
        return;
    }

    string line, currentid = "", data = "", edit = "";
    while (getline(infile, line)) {
        for (int i = 0;i < line.length() && line[i] != ',';++i) {          // getting the id from the file and reforming the rest of the data
            currentid += line[i];
        }
        if (currentid != id) {
            data = data + line + "\n";

        }
        else if (currentid == id) {
            edit = line;
        }
        currentid = "";

    }
    infile.close();
    string edit2 = "";
    int coma = 0, count = 0;
    for (int i = 0;i < edit.length();++i) {                             // changing the marks  into assigned marks
        if (edit[i] == ',') {
            coma++;
        }
        if (coma != 4) {
            edit2 += edit[i];
        }
        if (coma == 4) {
            if (count == 0) {
                edit2 += ',' + mark;                                    //getting the place to write marks
                count++;
            }
        }

    }
    data += edit2;
    ofstream outfile(file, ios::beg, ios::trunc);

    outfile << data;                                                         //refilling file with data
    outfile.close();
    cout << "\033[32mMarks entered sucessfully.\033[0m" << endl;
    cin.ignore();
    system("cls");

    return;
}
string rightid() {
    string id;
    getline(cin, id);                                                                     //taking input of id
    for (int i = 0;i < 3;++i) {
        if (id.length() != 3) {
            cout << "\033[31mInvalid amount of digits.It can only be (3 digits).\033[0m" << endl << "\033[34mEnter again :\033[0m ";
            getline(cin, id);
            i = -1;
            system("cls");
            continue;
        }
        if (!isdigit(id[i])) {
            cout << "\033[31mId only contain Integer digits.\033[0m" << endl << "\033[34mEnter again :\033[0m ";                     //taking input of teacher info and checking invalid inputs
            getline(cin, id);
            i = -1;
            system("cls");
            continue;
        }

    }
    system("cls");
    return id;
}
void add(const string student, string id, string name, string studentclass) {        //adding the student in every file
    ofstream outfile(student, ios::app);

    outfile << id << "," <<"0" << "," <<"0,0,0" << "\n";

    outfile.close();  // Close the file

}
void del(const string student, string id) {
    ifstream infile(student, ios::beg);
    if (!infile) {                                                             //checking the file opening
        cout << "\033[31mError opening file.\033[0m\n";
        cout << "\033[33mReturning\033[0m" << endl;
        return;
    }
    bool found = true;
    string data = "", line;
    while (getline(infile, line))
    {
        string currentid = "";

        for (int i = 0;i < line.length() && line[i] != ',';++i) {                                 //Getting id number
            currentid += line[i];
        }
        if (currentid == id) {
            found = true;
        }
        else {
            data += line + "\n";                                                                 //storing the rest into the string
        }
    }
    if (found) {

        infile.close();
        ofstream outfile(student, ios::trunc);
        outfile << data;

    }
    return;

}
void addStudent(const string student) {
    ifstream infile(student, ios::beg);                                      //checking file opening
    if (!infile) {
        cout << "\033[31mError opening file.\033[0m\n";
        return;
    }

    string id, name, studentClass;
    cout << "\033[33mEnter  Student ID(3 digits ) :\033[0m ";                                       //getting the right id
    id = rightid();

    bool found = false;
    string line, currentid = "";

    while (getline(infile, line)) {                                              //  checking of already existing id
        for (int i = 0;i < line.length() && line[i] != ',';++i) {
            currentid += line[i];
        }
        if (id == currentid) {
            cout << "\033[33mId already exists.You cannot add same iD.\033[0m" << endl;
            found = true;
            break;
        }
        currentid = "";
    }
    if (found) {

        return;
    }


    infile.close();
    ofstream outFile(student, ios::app);

    cout << "\033[33mEnter Name:\033[0m ";                                                  //name of the student
    getline(cin, name);
    for (int i = 0;i < name.length();++i) {
        if (isdigit(name[i])) {
            cout << "\033[31mName cannot contain digits.\033[0m" << endl << "\033[34mEnter again : \033[0m";               // checking for invalid name
            getline(cin, name);
            i = -1;
            continue;



        }

    }

    cout << "\033[33mEnter Class:\033[0m ";
    getline(cin, studentClass);                                               //getting class name
    outFile << id << "," << name << "," << studentClass << "\n";

    outFile.close();  // Close the file


    add("Teacher1.txt", id, name, studentClass);
    add("Teacher2.txt", id, name, studentClass);                                     //adding in every file
    add("Teacher3.txt", id, name, studentClass);
    add("Teacher4.txt", id, name, studentClass);
    add("Teacher5.txt", id, name, studentClass);
    add("Teacher6.txt", id, name, studentClass);
    cout << "\033[32mStudent added successfully!\033[0m\n";
    cin.ignore();
    system("cls");
    return;
}

void deleteStudent(const string& student) {
    system("cls");
    ifstream outfile(student, ios::beg);
    string id;
    if (!outfile) {
        cout << "\033[31mError opening file.\033[0m\n";                               //checking the openig of the file
        return;
    }


    cout << "\033[33mEnter the ID of the Student to delete(3 digits):\033[0m ";                            //getting the id of the teacher to delete
    id = rightid();

    bool found = false;
    string data = "", line;
    while (getline(outfile, line) || !outfile.eof())
    {
        string currentid = "";

        for (int i = 0;i < line.length() && line[i] != ',';++i) {                                 //Getting id number
            currentid += line[i];
        }
        if (currentid == id) {
            found = true;
        }
        else {
            data += line + "\n";                                                                 //storing the rest into the string
        }
    }
    if (found) {

        outfile.close();
        ofstream oufile("Student.txt", ios::beg);
        oufile << data;
        del("Teacher1.txt", id);
        del("Teacher2.txt", id);
        del("Teacher3.txt", id);                                                               //deleting it into the rest of the files
        del("Teacher4.txt", id);
        del("Teacher5.txt", id);
        del("Teacher6.txt", id);
        oufile.close();

        cout << "\033[32mStudent with iD\033[0m " << id << "\033[32m deleted sucessfully.\033[0m " << endl;
    }
    else {
        cout << "\033[32mStudent with id\033[0m " << id << "\033[32m not found.\033[0m " << endl;                             // if id not found
        outfile.close();
    }
    cin.ignore();
    system("cls");
    return;

}
float totalmarks(string file, string id) {                                       // total marks of the id in a subject
    ifstream infile(file, ios::beg);
    string  filename = "Teacher1.txt", mark = "";
    float ar1[5] = { 0.0 };
    if (!infile.is_open()) {
        cout << "\033[31mError opening input file.\033[0m" << endl;                        // checking the file opening
        cout << "\033[33mReturnig.\033[0m" << endl;
        return 0.0;
    }
    string currentid = "", edit = "", line;
    while (getline(infile, line) || !infile.eof()) {
        for (int i = 0;i < line.length() && line[i] != ',';++i)                           // getting the id
            currentid += line[i];
        if (currentid == id) {
            edit = line;
            break;
        }
        currentid = "";
    }
    infile.close();


    int n = 0;
    mark = "";

    for (int i = 0;i <= edit.length();++i) {

        if (edit[i] == ',' || i == edit.length()) {

            float n1 = stof(mark);                                            //getting its marks
            ar1[n] = n1;

            n++;
            mark = "";
            continue;
        }
        mark += edit[i];


    }



    return ar1[1] + ar1[2] + ar1[3] + ar1[4];                              //adding all of it and returning to the call
}
float cgp(string id, string file) {                                   //calculating cgpa accorrding to the marks
    float mark = totalmarks(file, id), cgpa = 0.0;

    string status = "pass";
    if (mark >= 70) {
        cgpa = 4.0;

    }
    else if (mark >= 60) {                                         //setting assumed condition and absolute grading for cgpa
        cgpa = 3.5;


    }
    else if (mark >= 50) {
        cgpa = 3.0;

    }
    else if (mark >= 40) {
        cgpa = 2.0;

    }
    else if (mark < 40) {
        cgpa = 1.5;

    }

    return cgpa;                                  //returning cgpa to the function call

}
void cgpa(string id, string file) {             //cgpa of a student of a given subject
    float mark = totalmarks(file, id), cgpa = 0.0;
    char grade = 'F';
    string status = "pass";
    if (mark >= 70) {
        cgpa = 4.0;
        grade = 'A';
    }
    else if (mark >= 60) {                              //setting assumed conditionsand absolute grading for cgpa
        cgpa = 3.5;
        grade = 'B';

    }
    else if (mark >= 50) {
        cgpa = 3.0;
        grade = 'C';
    }
    else if (mark >= 40) {
        cgpa = 2.0;
        grade = 'D';
    }
    else if (mark < 40) {
        cgpa = 1.5;
        grade = 'F';
        status = "fail";
    }
    cout << "\033[36mStudent id :\033[0m  " << id << endl;
    cout << "\033[36mTotal marks :\033[0m " << mark << endl;
    cout << "\033[36mCgpa :\033[0m " << cgpa << endl;
    cout << "\033[36mGrade : \033[0m" << grade << endl;                                        //displaying cgpa,status,total marks
    cout << "\033[36mStatus  :\033[0m " << status << endl;
    cin.ignore();
    system("cls");
    return;
}
void avgcgpa(string file) {                                                //calculating average cgpa
    string ar2[50] = { "0" };
    float ar1[50] = { 0.0 };
    string line, currentid = "";
    int n = 0;
    ifstream infile(file, ios::beg);
    while (getline(infile, line) || !infile.eof()) {
        for (int i = 0;i < line.length() && line[i] != ',';++i) {                         // getting all ids of the file
            currentid += line[i];
        }
        if (currentid != "") {
            ar2[n] = currentid;
            n++;
        }
        currentid = "";
    }
    infile.close();
    for (int i = 0;i < n;++i) {
        ar1[i] = cgp(ar2[i], file);                                           //calling cgp for all cgpa's
    }
    float sum = 0, n1 = n / 1.0;

    for (int i = 0;i < n;++i) {
        sum += ar1[i];
    }
    cout << "\033[36mThe average cgpa  is :\033[0m  " << (sum / n1) << endl;                    //calculating average cgpa and returning
    cin.ignore();
    system("cls");
    return;
}
void assignmarks(string id2, const string teacher) {            //assigning marks
    string id, marks, choice2, line, currentid = "";
    bool found = false;
    cout << "\033[33mEnter id of the student you want to assign :\033[0m ";                   //entering id of the student
    id = rightid();
    ifstream infile("Student.txt", ios::beg);
    while (getline(infile, line) || !infile.eof()) {
        for (int i = 0;i < line.length() && line[i] != ',';++i) {
            currentid += line[i];
        }
        if (currentid == id) {
            found = true;
            break;
        }
        currentid = "";
    }
    if (!found) {
        cout << "\033[31mId doesn't exist.\033[0m" << endl;
        cout << "\033[33mReturning.\033[0m" << endl;
        return;
    }
    int choice = 0;
    cout << "1.Quiz" << endl;
    cout << "2.Assignment" << endl;
    cout << "3.Sessional" << endl;                         //showing the menu
    cout << "4.Finals" << endl;
    cout << "5.Back to menu" << endl;
    while (choice != 5) {
        getline(cin, choice2);
        for (int i = 0;i < choice2.length();++i) {
            if (!isdigit(choice2[i])) {
                cout << "\033[31mChoice can be only in Integers.\033[0m" << endl << "\033[34mEnter again :\033[0m ";
                getline(cin, choice2);
                system("cls");
                i = -1;
                continue;

            }
        }//handling Invalid inputs of different types



        choice = stoi(choice2);
        switch (choice) {
        case 1:
            quiz(id, teacher);                                              //calling the functions according to given choice
            break;
        case 2:
            assignment(id, teacher);
            break;
        case 3:
            sessional(id, teacher);
            break;
        case 4:
            final(id, teacher);
            break;
        case 5:
            continue;
            break;
        default:
            cout << "\033[31mInvalid option of choice.\033[0m" << endl << "\033[34mTry again\033[0m : ";                   //handling the choice that is not given

        }
        cout << "1.Quiz" << endl;
        cout << "2.Assignment" << endl;
        cout << "3.Sessional" << endl;                         //showing the menu
        cout << "4.Finals" << endl;
        cout << "5.Back to menu" << endl;
    }
    cout << "\033[33mReturning back to Teacher menu :\033[0m " << endl;                        // back to  menu
    return;

}

void passstudents(string file) {
    string ar2[50] = { "0" };
    float ar1[50] = { 0.0 };
    string line, currentid = "";
    int n = 0;
    ifstream infile(file, ios::beg);
    while (getline(infile, line) || !infile.eof()) {                                     //getting all ids
        for (int i = 0;i < line.length() && line[i] != ',';++i) {
            currentid += line[i];
        }
        if (currentid != "") {
            ar2[n] = currentid;
            n++;
        }
        currentid = "";
    }
    infile.close();
    for (int i = 0;i < n;++i) {
        ar1[i] = totalmarks(file, ar2[i]);                              //calculating marks of each id
    }

    cout << "\033[33mList of pass students  :\033[0m " << endl;

    for (int i = 0;i < n;++i) {
        if (ar1[i] >= 40) {
            cout << "\033[36mStudent Id :\033[0m " << ar2[i] << endl;                   //showing pass students according to the grading
            cout << "\033[36mTotal marks :\033[0m " << ar1[i];
        }
        cout << endl;

    }
    cin.ignore();
    return;
}
void failstudents(string file) {
    string ar2[50] = { "0" };
    float ar1[50] = { 0.0 };
    string line, currentid = "";
    int n = 0;
    ifstream infile(file, ios::beg);
    while (getline(infile, line) || !infile.eof()) {                               //getting all ids
        for (int i = 0;i < line.length() && line[i] != ',';++i) {
            currentid += line[i];
        }
        if (currentid != "") {
            ar2[n] = currentid;
            n++;
        }
        currentid = "";
    }
    infile.close();
    for (int i = 0;i < n;++i) {
        ar1[i] = totalmarks(file, ar2[i]);                                    //calculating marks according to the subjects
    }
    cout << "\033[33mList of fail students \033[0m: " << endl;
    for (int i = 0;i < n;++i) {
        if (ar1[i] < 40) {                                                     ///showing fail students according to the grading
            cout << "\033[36mStudent Id :\033[0m " << ar2[i] << endl;
            cout << "\033[36mTotal marks : \033[0m" << ar1[i];
        }
        cout << endl;

    }
    cin.ignore();
    return;

}

void teacher() {
    ifstream infile("Teachers.txt", ios::beg);
    if (!infile) {                                                    //checking the file opening
        cout << "\033[31mError opening file.\033[0m \n";
        return;
    }
    string id, line;
    bool found = false;
    cout << "\033[33mEnter your iD (3 digits ) :\033[0m ";
    id = rightid();

    string currentid = "", edit, edit2 = "";
    while (getline(infile, line) || !infile.eof())
    {
        for (int i = 0;i < line.length() && line[i] != ',';++i) {                                 //Getting id number
            currentid += line[i];
        }
        if (currentid == id) {
            found = true;
            edit = line;
            break;
        }
        currentid = "";

    }
    if (!found) {
        cout << "\033[31mId doesn't exist.\033[0m" << endl;
        cout << "\033[33mReturning.\033[0m" << endl;
        return;
    }
    int coma = 0;
    for (int i = 0;i < edit.length() - 1;i++) {                                    //getting the subject
        if (edit[i] == ',')
            coma += 1;
        if (coma > 2) {
            edit2 += edit[i + 1];
        }

    }
    string filename;
    if (edit2 == "Math") {                                                                //assigning file according to the subject
        filename = "Teacher1.txt";
    }
    else if (edit2 == "Physics") {
        filename = "Teacher2.txt";
    }
    else if (edit2 == "English") {
        filename = "Teacher3.txt";
    }
    else if (edit2 == "Programing") {
        filename = "Teacher4.txt";
    }
    else if (edit2 == "Islamiat") {
        filename = "Teacher5.txt";
    }
    else if (edit2 == "Data") {
        filename = "Teacher6.txt";
    }




    string passcode = "123abc", password = "";
    if (!found) {
        cout << "\033[31mID does not exist  :\033[0m " << endl;
        cout << "\033[33mReturning to the menu.\033[0m" << endl;
        return;
    }

    else {
        int count = 0;
        cout << "\033[33mEnter password :\033[0m ";
        getline(cin, password);
        while (password != passcode + id) {                                                     //checking password and handling invalid password

            if (count == 3) {
                cout << "\033[31mYou have write Invalid password to many times .\033[0m " << endl;
                cout << "\033[33mReturning to main menu  :\033[0m ";
                return;
            }
            cout << "\033[31mInvalid password.\033[0m" << endl << " \033[34mtry again  :\033[0m  ";
            getline(cin, password);
            system("cls");

            count++;

        }
    }
    infile.close();
    system("cls");
    cout << "\033[32mWelcome Teacher\033[0m  " << id << endl;                          //welcoming the teacher

    int choice = 0;
    string choice2 = "";

    cout << "1.Add Student" << endl;
    cout << "2. Delete Student" << endl;
    cout << "3.To see Cgpa of a student." << endl;
    cout << "4.To see Average CGPA OF class." << endl;
    cout << "5.Assign Marks" << endl;                                       //showing the menu
    cout << "6.list of passed students" << endl;
    cout << "7.List of fail students " << endl;
    cout << "8.Back to main menu." << endl;
    cout << "\033[33mEnter your choice :\033[0m ";

    while (choice != 8) {
        getline(cin, choice2);
        for (int i = 0;i < choice2.length();i++) {
            if (!isdigit(choice2[i])) {
                cout << "\033[31mInvalid input of choice cannot be other than digits.\033[0m" << endl << "\033[34mEnter again :\033[0m ";
                getline(cin, choice2);
                i = -1;
            }
        }

        choice = stoi(choice2);
        string id2;
        switch (choice) {

        case 1:
            addStudent("Student.txt");

            break;
        case 2:                                                                                 //assigning given function according to  the choice
            deleteStudent("Student.txt");

            break;
        case 3:
            cout << "\033[33mEnter id of the student  :\033[0m ";
            id2 = rightid();
            cgpa(id2, filename);
            system("cls");
            break;
        case 4:
            avgcgpa(filename);
            system("cls");
            break;
        case 5:
            assignmarks(id, filename);
            system("cls");
            break;
        case 6:
            passstudents(filename);
            system("cls");
            break;
        case 7:
            failstudents(filename);
            system("cls");
            break;
        case 8:
            continue;
            break;
        default:
            cout << "\033[31mInvalid choice.\033[0m" << endl << " \033[34mTry again :\033[0m ";
        }
        cout << "1.Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3.To see Cgpa of a student" << endl;
        cout << "4.To see Average CGPA" << endl;
        cout << "5.Assign Marks" << endl;
        cout << "6.list of passed students" << endl;
        cout << "7.List of fail students " << endl;
        cout << "8.Back to main menu." << endl;
        cout << "\033[33mEnter your choice :\033[0m ";
    }
    system("cls");
    return;

}


// Function to add a teacher



void addTeacher(const string& teacher) {
    ifstream inFile(teacher, ios::beg);

    if (!inFile) { // file opening constraints
        cout << "\033[31mError opening file.\033[0m\n"; // Red for error
        return;
    }
    string id, name, subject;
    cout << "\033[33mEnter Teacher ID (3 digits): \033[0m"; // Cyan for input prompt
    id = rightid();

    bool found = false;
    string line, currentid = "";

    while (getline(inFile, line)) {
        for (int i = 0; i < line.length() && line[i] != ','; ++i) {
            currentid += line[i];
        }
        if (id == currentid) {
            cout << "\033[31mId already exists.You cannot add the same ID.\033[0m" << endl; // Red for error
            found = true;
            break;
        }
        currentid = "";
    }

    if (found) {
        cout << "\033[31mid already exist cannot add same id.\033[0m";
        cout << "\033[33mReturning.\033[0m" << endl;
        return;
    }

    inFile.close();

    // Ask for teacher details
    cout << "\033[33mEnter Teacher Name: \033[0m"; // Cyan for input prompt
    getline(cin, name);
    for (int i = 0;i < name.length();++i) {
        if (!isalpha(name[i])&&name[i]!=' ') {
            cout<<"Name only contain letters.Enter again : ";
            getline(cin, name);
            i = -1;
            system("cls");
            continue;
        }
    }

    cout << "\033[33mEnter Subject: \033[0m"; //
    getline(cin, subject);

    // Determine the correct file based on the subject
    string filename;
    if (subject == "Math") {
        filename = "Teacher1.txt";
    }
    else if (subject == "Physics") {
        filename = "Teacher2.txt";
    }
    else if (subject == "English") {                           //assigning file to the sibject
        filename = "Teacher3.txt";
    }
    else if (subject == "Programing") {
        filename = "Teacher4.txt";
    }
    else if (subject == "Islamiat") {
        filename = "Teacher5.txt";
    }
    else if (subject == "Data") {
        filename = "Teacher6.txt";
    }
    else {
        cout << "\033[31mInvalid subject. No file associated with this subject.\033[0m" << endl;
        return;
    }

    // Open the correct file for appending the teacher's details
    ofstream outFile("Teachers.txt", ios::app);
    outFile << id << "," << name << ",," << subject << "\n";
    outFile.close();

    cout << "\033[32mTeacher added successfully!\033[0m\n"; // Green for success
}



// Function to delete a teacher
void deleteTeacher(const string teacher) {
    ifstream delteach(teacher, ios::beg);

    if (!delteach) {
        cout << "\033[31mError opening file.\033[0m\n";
        return;
    }

    string id, line;
    cout << "\033[33mEnter the ID of the teacher to delete(3 digits):\033[0m ";                            //getting the id of the teacher to delete
    id = rightid();
    bool found = false;
    string data = "";
    while (getline(delteach, line))
    {
        string currentid = "";

        for (int i = 0;i < line.length() && line[i] != ',';++i) {                                 //Getting id number
            currentid += line[i];
        }
        if (currentid == id) {
            found = true;
        }
        else {
            data += line + "\n";                                                                 //storing the rest into the string
        }
    }
    if (found) {

        delteach.close();
        ofstream delteach2(teacher, ios::beg, ios::trunc);

        delteach2 << data;                                                                       //writing the rest except the id string
        cout << "\033[32mTeacher  with iD\033[0m " << id << "\033[32m deleted sucessfully \033[0m" << endl;
        delteach2.close();
    }
    else {
        cout << "\033[32mTeacher with id\033[0m " << id << "\033[32m not found\033[0m " << endl;                             // if id not found
        delteach.close();
    }


    return;

}



void admin() {
    string filename = "Teachers.txt";
    int n = 0;
    string str1, str2 = "/0";
    cout << "\033[33mEnter password :\033[0m";                                   // Entering password
    getline(cin, str1);
    while (str1 != "abc123") {
        if (n == 3) {
            cout << "\033[31mYou  have  entered the wrong password to many times we cannot allow you to login .\033[0m" << endl;
            return;

        }
        cout << "\033[31mWrong password.\033[0m" << endl;
        cout << "\033[34mTry again : \033[0m";                                                    // handling password too many times
        getline(cin, str1);
        n++;

    }
    system("cls");
    cout << "   \033[32m   Welcome MrAdmin \033[0m  ";
    cout << "\033[33mWhat operations do you want to perform :\033[0m" << endl;
    cout << endl;
    int n1 = 0;
    while (n1 != 3) {
        cout << "1.Add Teacher " << endl;
        cout << "2.Delete Teacher " << endl;
        cout << "3.Exit" << endl;
        getline(cin, str2);
        for (int i = 0;i < str2.length();++i) {
            if (!isdigit(str2[i])) {
                cout << "\033[31mIt can only be digits.\033[0m" << endl << "\033[34mEnter again : \033[0m";
                getline(cin, str2);
                i = -1;
                continue;

            }

        }
        system("cls");
        n1 = stoi(str2);
        switch (n1) {                                                            //using fuctions according to given input
        case 1:
            addTeacher(filename);

            break;
        case 2:
            deleteTeacher(filename);

            break;
        case 3:
            continue;
        default:
            cout << "\033[31mInvalid option selected.\033[0m" << endl;

        }

        cout << "\033[34mSelect the options again :\033[0m ";

    }

    cout << "\033[32mThe Admin account logout sucessfully.\033[0m" << endl;                            //logging out the admin section
    return;


}
void math(string id) {
    string  filename = "Teacher1.txt", mark = "";
    float ar1[5] = { 0.0 };
    ifstream infile("Teacher1.txt", ios::beg);
    if (!infile.is_open()) {
        cout << "\033[31mError opening input file.\033[0m" << endl;
        cout << "\033[33mReturnig.\033[0m" << endl;
        return;
    }
    string currentid = "", edit, line;
    while (getline(infile, line) || !infile.eof()) {
        for (int i = 0;i < line.length() && line[i] != ',';++i)
            currentid += line[i];
        if (currentid == id) {
            edit = line;
            break;
        }
        currentid = "";
    }
    infile.close();


    int n = 0;
    mark = "";

    for (int i = 0;i <= edit.length();++i) {

        if (edit[i] == ',' || i == edit.length()) {

            float n1 = stof(mark);
            ar1[n] = n1;

            n++;
            mark = "";
            continue;
        }
        mark += edit[i];


    }
    cout << "\033[36m                           Your marks:\033[0m" << endl;
    cout << "\033[36mQuiz :                    \033[0m" << ar1[1] << endl;
    cout << "\033[36mAssignment  :             \033[0m" << ar1[2] << endl;
    cout << "\033[36mSessional :               \033[0m" << ar1[3] << endl;
    cout << "\033[36mFinal :                   \033[0m" << ar1[4] << endl;
    cout << endl;
    cout << "\033[32mTotal marks  :\033[0m" << ar1[1] + ar1[2] + ar1[3] + ar1[4] << endl;
    cin.ignore();
    system("cls");
    return;
}
void physics(string id) {
    ifstream infile("Teacher2.txt", ios::beg);
    string  filename = "Teacher1.txt", mark = "";
    float ar1[5] = { 0.0 };
    if (!infile.is_open()) {
        cout << "\033[31mError opening input file.\033[0m" << endl;
        cout << "\033[33mReturnig.\033[0m" << endl;
        return;
    }
    string currentid = "", edit, line;
    while (getline(infile, line) || !infile.eof()) {
        for (int i = 0;i < line.length() && line[i] != ',';++i)
            currentid += line[i];
        if (currentid == id) {
            edit = line;
            break;
        }
        currentid = "";
    }
    infile.close();


    int n = 0;
    mark = "";

    for (int i = 0;i <= edit.length();++i) {

        if (edit[i] == ',' || i == edit.length()) {

            float n1 = stof(mark);
            ar1[n] = n1;

            n++;
            mark = "";
            continue;
        }
        mark += edit[i];


    }
    cout << "\033[36m                           Your marks:\033[0m" << endl;
    cout << "\033[36mQuiz :                    \033[0m" << ar1[1] << endl;
    cout << "\033[36mAssignment  :             \033[0m" << ar1[2] << endl;
    cout << "\033[36mSessional :               \033[0m" << ar1[3] << endl;
    cout << "\033[36mFinal :                   \033[0m" << ar1[4] << endl;
    cout << endl;
    cout << "\033[32mTotal marks  :\033[0m" << ar1[1] + ar1[2] + ar1[3] + ar1[4] << endl;
    cin.ignore();
    system("cls");
    return;
}
void english(string id) {
    ifstream infile("Teacher3.txt", ios::beg);
    string  filename = "Teacher1.txt", mark = "";
    float ar1[5] = { 0.0 };
    if (!infile.is_open()) {
        cout << "\033[31mError opening input file.\033[0m" << endl;
        cout << "\033[33mReturnig.\033[0m" << endl;
        return;
    }
    string currentid = "", edit, line;
    while (getline(infile, line) || !infile.eof()) {
        for (int i = 0;i < line.length() && line[i] != ',';++i)
            currentid += line[i];
        if (currentid == id) {
            edit = line;
            break;
        }
        currentid = "";
    }
    infile.close();


    int n = 0;
    mark = "";

    for (int i = 0;i <= edit.length();++i) {

        if (edit[i] == ',' || i == edit.length()) {

            float n1 = stof(mark);
            ar1[n] = n1;

            n++;
            mark = "";
            continue;
        }
        mark += edit[i];


    }
    cout << "\033[36m                           Your marks:\033[0m" << endl;
    cout << "\033[36mQuiz :                    \033[0m" << ar1[1] << endl;
    cout << "\033[36mAssignment  :             \033[0m" << ar1[2] << endl;
    cout << "\033[36mSessional :               \033[0m" << ar1[3] << endl;
    cout << "\033[36mFinal :                   \033[0m" << ar1[4] << endl;
    cout << endl;
    cout << "\033[32mTotal marks  :\033[0m" << ar1[1] + ar1[2] + ar1[3] + ar1[4] << endl;
    cin.ignore();
    system("cls");
    return;
}
void programming(string id) {
    ifstream infile("Teacher4.txt", ios::beg);
    string  filename = "Teacher1.txt", mark = "";
    float ar1[5] = { 0.0 };
    if (!infile.is_open()) {
        cout << "\033[31mError opening input file\033[0m." << endl;
        cout << "\033[33mReturnig.\033[0m" << endl;
        return;
    }
    string currentid = "", edit, line;
    while (getline(infile, line) || !infile.eof()) {
        for (int i = 0;i < line.length() && line[i] != ',';++i)
            currentid += line[i];
        if (currentid == id) {
            edit = line;
            break;
        }
        currentid = "";
    }
    infile.close();


    int n = 0;
    mark = "";

    for (int i = 0;i <= edit.length();++i) {

        if (edit[i] == ',' || i == edit.length()) {

            float n1 = stof(mark);
            ar1[n] = n1;

            n++;
            mark = "";
            continue;
        }
        mark += edit[i];


    }
    cout << "\033[36m                           Your marks:\033[0m" << endl;
    cout << "\033[36mQuiz :                    \033[0m" << ar1[1] << endl;
    cout << "\033[36mAssignment  :             \033[0m" << ar1[2] << endl;
    cout << "\033[36mSessional :               \033[0m" << ar1[3] << endl;
    cout << "\033[36mFinal :                   \033[0m" << ar1[4] << endl;
    cout << endl;
    cout << "\033[32mTotal marks  :\033[0m" << ar1[1] + ar1[2] + ar1[3] + ar1[4] << endl;
    cin.ignore();
    system("cls");
    return;
}
void islamiat(string id) {
    ifstream infile("Teacher5.txt", ios::beg);
    string  filename = "Teacher1.txt", mark = "";
    float ar1[5] = { 0.0 };
    if (!infile.is_open()) {
        cout << "\033[31mError opening input file.\033[0m" << endl;
        cout << "\033[33mReturnig.\033[0m" << endl;
        return;
    }
    string currentid = "", edit, line;
    while (getline(infile, line) || !infile.eof()) {
        for (int i = 0;i < line.length() && line[i] != ',';++i)
            currentid += line[i];
        if (currentid == id) {
            edit = line;
            break;
        }
        currentid = "";
    }
    infile.close();


    int n = 0;
    mark = "";

    for (int i = 0;i <= edit.length();++i) {

        if (edit[i] == ',' || i == edit.length()) {

            float n1 = stof(mark);
            ar1[n] = n1;

            n++;
            mark = "";
            continue;
        }
        mark += edit[i];


    }
    cout << "\033[36m                           Your marks:\033[0m" << endl;
    cout << "\033[36mQuiz :                    \033[0m" << ar1[1] << endl;
    cout << "\033[36mAssignment  :             \033[0m" << ar1[2] << endl;
    cout << "\033[36mSessional :               \033[0m" << ar1[3] << endl;
    cout << "\033[36mFinal :                   \033[0m" << ar1[4] << endl;
    cout << endl;
    cout << "\033[32mTotal marks  :\033[0m" << ar1[1] + ar1[2] + ar1[3] + ar1[4] << endl;
    cin.ignore();
    system("cls");
    return;
}
void data(string id) {
    ifstream infile("Teacher6.txt", ios::beg);
    string  filename = "Teacher1.txt", mark = "";
    float ar1[5] = { 0.0 };
    if (!infile.is_open()) {
        cout << "\033[31mError opening input file.\033[0m" << endl;
        cout << "\033[33mReturnig.\033[0m" << endl;
        return;
    }
    string currentid = "", edit, line;
    while (getline(infile, line) || !infile.eof()) {
        for (int i = 0;i < line.length() && line[i] != ',';++i)
            currentid += line[i];
        if (currentid == id) {
            edit = line;
            break;
        }
        currentid = "";
    }
    infile.close();


    int n = 0;
    mark = "";

    for (int i = 0;i <= edit.length();++i) {

        if (i == edit.length() || edit[i] == ',') {

            float n1 = stof(mark);
            ar1[n] = n1;

            n++;
            mark = "";
            continue;
        }
        mark += edit[i];


    }
    cout << "\033[36m                           Your marks:\033[0m " << endl;
    cout << "\033[36mQuiz :                    \033[0m" << ar1[1] << endl;
    cout << "\033[36mAssignment  :             \033[0m" << ar1[2] << endl;
    cout << "\033[36mSessional :               \033[0m" << ar1[3] << endl;
    cout << "\033[36mFinal :                   \033[0m" << ar1[4] << endl;
    cout << endl;
    cout << "\033[32mTotal marks  :\033[0m" << ar1[1] + ar1[2] + ar1[3] + ar1[4] << endl;
    cin.ignore();
    system("cls");
    return;
}
void viewgrades(string id) {
    int choice = 0;
    string choice2 = "";
    cout << "\033[33mThe subjects to see marks :\033[0m " << endl;
    cout << "1.Math" << endl;
    cout << "2.Physics" << endl;
    cout << "3.English" << endl;
    cout << "4.Programming" << endl;
    cout << "5.Islamiat" << endl;
    cout << "6.Data" << endl;
    cout << "7.Back to student menu." << endl;
    cout << "\033[33mEnter your choice : \033[0m";


    while (choice != 7) {

        getline(cin, choice2);
        for (int i = 0;i < choice2.length();++i) {
            if (!isdigit(choice2[i])) {
                cout << "\033[31mChoice can be only in integers digits.\033[0m" << endl << "\033[34mEnter again :\033[0m ";
                getline(cin, choice2);
                i = -1;
                continue;
            }

        }
        choice = stoi(choice2);
        switch (choice) {
        case 1:
            math(id);
            break;
        case 2:
            physics(id);
            break;
        case 3:
            english(id);
            break;

        case 4:
            programming(id);
            break;
        case 5:
            islamiat(id);
            break;


        case 6:
            data(id);
            break;

        case 7:
            continue;
            break;
        default:
            cout << "\033[31mInvalid choice.\033[0m" << endl << "\033[34menter again : \033[0m" << endl;



        }
        cout << "1.Math" << endl;
        cout << "2.Physics" << endl;
        cout << "3.English" << endl;
        cout << "4.Programming" << endl;
        cout << "5.Islamiat" << endl;
        cout << "6.Data" << endl;
        cout << "7.Back to student menu." << endl;
        cout << "\033[33mEnter your choice : \033[0m";



    }
    return;

}

void viewcgpa(string id) {
    float ar1[6] = { 0.0 }, ar2[6] = { 0.0 };
    char grades[7] = { '\0' };
    ar1[0] = totalmarks("Teacher1.txt", id);
    ar1[1] = totalmarks("Teacher2.txt", id);
    ar1[2] = totalmarks("Teacher3.txt", id);
    ar1[3] = totalmarks("Teacher4.txt", id);
    ar1[4] = totalmarks("Teacher5.txt", id);
    ar1[5] = totalmarks("Teacher6.txt", id);
    for (int i = 0;i < 6;i++) {
        if (ar1[i] >= 70) {
            grades[i] = 'A';
            ar2[i] = 4.0;
        }
        else if (ar1[i] >= 60) {
            grades[i] = 'B';
            ar2[i] = 3.5;

        }
        else if (ar1[i] >= 50) {
            grades[i] = 'C';
            ar2[i] = 3.0;

        }
        else if (ar1[i] >= 40) {
            grades[i] = 'D';
            ar2[i] = 2.0;
        }
        else if (ar1[i] < 40) {
            grades[i] = 'F';
            ar2[i] = 1.5;
        }

    }


    cout << "\033[36mMath : \033[0m" << endl;
    cout << "\033[36mTotal Marks : \033[0m" << ar1[0] << endl;
    cout << "\033[36mSubject cgpa :\033[0m " << ar2[0] << endl;
    cout << "\033[36mGrade : \033[0m" << grades[0] << endl;
    cout << "\033[35mPhysics :\033[0m " << endl;
    cout << endl;
    cout << "\033[35mTotal Marks :\033[0m " << ar1[1] << endl;
    cout << "\033[35mSubjet cgpa :\033[0m " << ar2[1] << endl;
    cout << "\033[35mGrade : \033[0m" << grades[1] << endl;
    cout << endl;
    cout << "\033[34mEnglish : \033[0m" << endl;
    cout << "\033[34mTotal Marks :\033[0m " << ar1[2] << endl;
    cout << "\033[34mSubjet cgpa :\033[0m " << ar2[2] << endl;
    cout << "\033[34mGrade :\033[0m " << grades[2] << endl;
    cout << endl;
    cout << "\033[33mProgramming :\033[0m " << endl;
    cout << "\033[33mTotal Marks : \033[0m" << ar1[3] << endl;

    cout << "\033[33mSubjet cgpa :\033[0m " << ar2[3] << endl;
    cout << "\033[33mGrade :\033[0m " << grades[3] << endl;
    cout << endl;
    cout << "\033[32mIslamiat : \033[0m" << endl;
    cout << "\033[32mTotal Marks :\033[0m " << ar1[4] << endl;
    cout << "\033[32mSubjet cgpa :\033[0m " << ar2[4] << endl;
    cout << "\033[32mGrade :\033[0m " << grades[4] << endl;
    cout << endl;
    cout << "\033[31mData : \033[0m" << endl;
    cout << "\033[31mTotal Marks :\033[0m " << ar1[5] << endl;
    cout << "\033[31mSubjet cgpa :\033[0m " << ar2[5] << endl;
    cout << "\033[31mGrade :\033[0m " << grades[5] << endl;
    cout << "\033[36mTotal cgpa :\033[0m" << (ar2[0] + ar2[1] + ar2[2] + ar2[3] + ar2[4] + ar2[5]) / 6.0;
    cin.ignore();
    system("cls");
    return;
}

void student() {
    ifstream infile("student.txt", ios::beg);
    if (!infile) {
        cout << "\033[31mError opening file.\033[0m \n";
        return;
    }
    string id, line;
    bool found = false;
    cout << "\033[33mEnter your iD (3 digits ) :\033[0m ";
    id = rightid();
    string currentid = "";
    while (getline(infile, line))
    {
        for (int i = 0;i < line.length() && line[i] != ',';++i) {                                 //Getting id number
            currentid += line[i];
        }
        if (currentid == id) {
            found = true;
            break;
        }
        currentid = "";

    }
    string passcode = "123abc", password = "";
    if (!found) {
        cout << "\033[31mID does not exist  :\033[0m " << endl;
        cout << "\033[33mReturning to the menu.\033[0m" << endl;
        return;
    }
    else {
        int count = 0;
        cout << "\033[33mEnter password :\033[0m ";
        getline(cin, password);
        while (password != passcode + id) {
            if (count == 3) {
                cout << "\033[31mYou have write Invalid password to many times . \033[0m" << endl;
                cout << "\033[33mReturning to main menu  :\033[0m ";
                return;
            }
            cout << "\033[31mInvalid password.\033[0m" << endl << " \033[4mTry again  :\033[0m  ";
            getline(cin, password);
            system("cls");

            count++;

        }
    }
    infile.close();
    system("cls");
    cout << "\033[32mWelcome student \033[0m " << id << endl;
    cout << "\033[33mEnter your choice :\033[0m " << endl;
    int choice = 0;
    string choice3 = "";
    cout << "1.To see marks" << endl;
    cout << "2.To see cgpa" << endl;
    cout << "3.To back to menu" << endl;


    while (choice != 3) {
        getline(cin, choice3);
        for (int i = 0;i < choice3.length();++i) {
            if (!isdigit(choice3[i])) {
                cout << "\033[31mChoice can be only in integers digits.\033[0m" << endl << "\033[34mEnter again : \033[0m";
                getline(cin, choice3);
                i = -1;
                continue;
            }
        }

        choice = stoi(choice3);
        switch (choice) {
        case 1:
            viewgrades(id);
            break;
        case 2:
            viewcgpa(id);
            break;
        case 3:
            continue;
            break;

        default:
            cout << "\033[31mInvalid choice.\033[0m" << endl << " \033[34mTry again :\033[0m ";
        }
        cout << "1.To see marks" << endl;
        cout << "2.To see cgpa" << endl;
        cout << "3.To back to menu" << endl;

    }
    return;

}