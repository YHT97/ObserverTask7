#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
    private:
        string Name;
        string SecondName;
        int Age;
    public:
        Student() = default;
        Student(string Name, string SecondName, int Age) {
            this->Name = Name;
            this->SecondName = SecondName;
            this->Age = Age;
        }
        string getName() { return this->Name; }
        string getSecondName() { return this->SecondName; }
        int getAge() { return this->Age; }

        void setName(string Name) { this->Name = Name; }
        void setSecondName(string SecondName) { this->SecondName = SecondName; }
        void setAge(int Age) { this->Age = Age; }
};

class Group {
    private:
        string GroupName;
        vector<Student> Students;
    public:
        Group() = default;
        Group(string GroupName, vector<Student> Students) {
            this->GroupName = GroupName;
            this->Students = Students;
        }
        string getGroupName() { return this->GroupName; }
        vector<Student> getStudents() { return this->Students; }
        void OutputStudents() {
            for (int i = 0; i < this->Students.size(); i++) {
                cout << '\t' << "Name: " << this->Students[i].getName() << "    " << "SecondName: "
                << this->Students[i].getSecondName() << "    " << "Age: " << this->Students[i].getAge() << '\n';
            }
        }
        void Output() {
            cout << "Group Name: " << this->GroupName << '\n'
            << "Students:" << '\n';
            OutputStudents();
            cout << '\n';
        }
};

int main() {
    auto AS = Group("AS-21-2",
                    {
                        Student("Vadim", "Breev", 21),
                        Student("Alexey", "Ryumkin", 19),
                        Student("Karen", "Khachatryan", 18)
                     });
    int operationNumber;
    do {
        cout << "1 - Append Record" << '\n'
        << "2 - Delete Record" << '\n'
        << "3 - Change the Record" << '\n'
        << "4 - Output the Record" << '\n'
        << "Enter the operation number: ";
        cin >> operationNumber;
        cout << '\n';
        switch (operationNumber) {
            case 1 : {
                string StudentName;
                string StudentSecondName;
                int StudentAge;

                vector<Student> students;
                for (int i = 0; i < AS.getStudents().size() + 1; i++) {
                    students[i].setName(AS.getStudents()[i].getName());
                    students[i].setSecondName(AS.getStudents()[i].getSecondName());
                    students[i].setAge(AS.getStudents()[i].getAge());
                }

                cout << "Enter the name of new student: "; cin >> StudentName;
                cout << "Enter the second name of new student: "; cin >> StudentSecondName;
                cout << "Enter the age of new student: "; cin >> StudentAge;
                students.emplace_back(StudentName, StudentSecondName, StudentAge);
                AS = Group("AS-21-2", students);
                break;
            }
            case 2 : {}
            case 3 : {}
            case 4 : {
                AS.Output();
            }
        }
    } while (operationNumber != 0);
    return 0;
}