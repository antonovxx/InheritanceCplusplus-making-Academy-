#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

//                                               ACADEMY                             //

// DEFINITIONS:

// Human:
#define HUMAN_TAKE_PARAMETERS const string& first_name, const string& last_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS first_name, last_name, age
//Student:
#define STUDENT_TAKE_PARAMETERS const string& speciality, const string& group, unsigned int rating, unsigned int attending
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attending
//Teacher:
#define TEACHER_TAKE_PARAMETERS const string& speciality, unsigned int experience, unsigned int salary
#define TEACHER_GIVE_PARAMETERS speciality, experience, salary
//Employee:
#define EMPLOYEE_TAKE_PARAMETERS const string& position, unsigned int experience, unsigned int salary
#define EMPLOYEE_GIVE_PARAMETERS position, experience, salary

// ClASSES:

class Human {
    string first_name;
    string last_name;
    unsigned int age;
public:
    
    // Get - , Set - methods:

    const string& get_first_name()const
    {
        return first_name;
    }
    const string& get_last_name()const
    {
        return last_name;
    }
    unsigned int get_age()const
    {
        return age;
    }
    
    void set_first_name(const string& first_name)
    {
        this -> first_name = first_name;
    }
    void set_last_name(const string& last_name)
    {
        this -> last_name = last_name;
    }
    void set_age (unsigned int age)
    {
        this -> age = age;
    }
    // Constructors:
    
    Human(HUMAN_TAKE_PARAMETERS)
    {
        set_first_name(first_name);
        set_last_name(last_name);
        set_age(age);
        cout << "\nHuman Constructor: \t" << this << endl;
    }
    ~Human()
    {
        cout << "Human Destructor: \t" << this << endl;
    }
    // Methods:
    
    void print() const
    {
        cout << "Name: " << first_name << " " << last_name << " " << "\nAge: " << age << endl;
    }
};

class Student: public Human {
    string speciality;
    string group;
    unsigned int rating;
    unsigned int attending;
public:
    
    // Get - , Set - methods:
    
    const string& get_speciality() const
    {
        return speciality;
    }
    const string& get_group()const
    {
        return group;
    }
    unsigned int get_rating()
    {
        return rating;
    }
    unsigned int get_attending()
    {
        return attending;
    }
    
    void set_speciality(const string& speciality)
    {
        this -> speciality = speciality;
    }
    void set_group(const string& group)
    {
        this -> group = group;
    }
    void set_rating(unsigned int rating)
    {
        this -> rating = rating;
    }
    void set_attending(unsigned int attending)
    {
        this -> attending = attending;
    }
    // Constructors:
    
    Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) : Human (HUMAN_GIVE_PARAMETERS)
    {
        set_speciality(speciality);
        set_group(group);
        set_rating(rating);
        set_attending(attending);
        cout << "Student Constructor: \t" << this << endl;
    }
    ~Student()
    {
        cout << "Student Destructor: \t" << this << endl;
    }
    void print()const
    {
        Human::print();
        cout << "\nSpeciality: " << speciality << endl;
        cout << "\nFaculty: " << group << endl;
        cout << "\nRating: " << rating << endl;
        cout << "\nAttending: " << attending << endl;
    }
};

class Teacher : public Human {
    string speciality;
    unsigned int experience;
    unsigned int salary;
public:
    // Get - , Set - methods:
    
    const string& get_speciality()const
    {
        return speciality;
    }
    unsigned int get_experience()
    {
        return experience;
    }
    unsigned int get_salary()
    {
        return salary;
    }
    void set_speciality(const string& speciality)
    {
        this -> speciality = speciality;
    }
    void set_experience(unsigned int experience)
    {
        this -> experience = experience;
    }
    void set_salary(unsigned int salary)
    {
        this -> salary = salary;
    }
    // Constructors:
    
    Teacher (HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) : Human (HUMAN_GIVE_PARAMETERS)
    {
        set_speciality(speciality);
        set_experience(experience);
        set_salary(salary);
        cout << "Teacher constructor: \t" << this << endl;
    }
    ~Teacher()
    {
        cout << "Teacher Destructor: \t" << this << endl;
    }
    // Methods:
    
    void print() const
    {
        Human::print();
        cout << "Speciality: " << speciality << endl;
        cout << "Working experience: " << experience << endl;
        cout << "Salary: " << salary << endl;
    }
    
};

class Employee : public Human {
    string position;
    unsigned int experience;
    unsigned int salary;
public:
    
    // Get -, Set - Methods:
    
    const string& get_position()const
    {
        return position;
    }
    unsigned int get_experience()
    {
        return experience;
    }
    unsigned int get_salary()
    {
        return salary;
    }
    void set_position(const string& position)
    {
        this -> position = position;
    }
    void set_experience(unsigned int experience)
    {
        this -> experience = experience;
    }
    void set_salary(unsigned int salary)
    {
        this -> salary = salary;
    }
    // Constructors:
    
    Employee (HUMAN_TAKE_PARAMETERS, EMPLOYEE_TAKE_PARAMETERS) : Human (HUMAN_GIVE_PARAMETERS)
    {
        set_position(position);
        set_experience(experience);
        set_salary(salary);
        cout << "Employee constructor: \t" << this << endl;
    }
    ~Employee()
    {
        cout << "Employee Destructor: \t" << this << endl;
    }
    // Methods:
    
    void print() const
    {
        Human::print();
        cout << "Position: " << position << endl;
        cout << "Working experience: " << experience << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main(int argc, const char * argv[])
{
    Student* faculty[] =
    {
        new Student("Harry", "Potter", 15, "wizard", "Griffindor", 5, 100),
        new Student("Ronald", "Weaseley", 15, "wizard", "Griffindor", 5, 100),
        new Student("Hermione", "Granger", 15, "wizard", "Griggindor", 5, 100),
    };
    
    Teacher* department[] =
    {
        new Teacher("Severus", "Snape", 37, "potion-making", 14, 1587),
        new Teacher("Alastor", "Moody", 56, "defence-against-art-Dark", 1, 2600),
        new Teacher("Minerva", "McGonagall", 54, "transfiguration", 30, 3500),
    };
    
    Employee* staff[] =
    {
        new Employee("Argus", "Filch", 69, "caretaker", 32, 900),
    };
    
    unsigned int total_salary = 0;
    unsigned int total_experience = 0;
    
    for (int i = 0; i < sizeof(faculty) / sizeof(Student*) ; ++i)
    {
        cout << "\n _________________________ \n";
        faculty[i] -> print();
    }
    
    for (int i = 0; i < sizeof(department)/ sizeof(Teacher*); ++i)
    {
        cout << "\n _________________________ \n";
        department[i] -> print();
        total_salary += department[i] -> get_salary();
    }
    
    for (int i = 0; i < sizeof(staff)/ sizeof(Employee*); ++i)
    {
        cout << "\n _________________________ \n";
        staff[i] -> print();
    }
    
    total_salary += staff[0] -> get_salary();
    total_experience += staff[0] -> get_experience();
    
    cout << "\n _________________________ \n";
    cout << "Total salary: " << total_salary << endl;
    cout << "Total experience: " << total_experience << endl;
    cout << "\n _________________________ \n";
    
    for (int i = 0; i < sizeof(faculty) / sizeof(Student*) ; ++i)
    {
        delete faculty[i];
    }
    
    for (int i = 0; i < sizeof(department) / sizeof(Teacher*) ; ++i)
    {
        delete department[i];
    }
    
    for (int i = 0; i < sizeof(staff) / sizeof(Employee*) ; ++i)
    {
        delete staff[i];
    }
    
    return 0;
}
