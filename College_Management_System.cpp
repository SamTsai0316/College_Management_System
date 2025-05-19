#include <iostream>
#include <vector>

class Student
{
    private:
        std::string Name, subject;
        int rollNo;
    public:
        Student(std::string Name, std::string subject, int rollNo)
        {
            this->Name = Name;
            this->subject = subject;
            this->rollNo = rollNo;

        }

        void setName(std::string n)     // 不用 constructure 在建立物件時就設定 name，而是用 set 來設定
        {
            Name = n;
        }
        void setRollNo(int r)
        {
            rollNo = r;
        }
        void setSubject(std::string s)
        {
            subject = s;
        }
        std::string getName()
        {
            return Name;
        }
        std::string getSubject()
        {
            return subject;
        }
        int getRollNumber()
        {
            return rollNo;
        }

};
class College
{
    private:
        std::vector<Student> studentVector;
    public:
        void addStudent(std::string studentName, std::string studentSubject, int studentRollNumber)
        {
            Student student(studentName, studentSubject, studentRollNumber);
            studentVector.push_back(student);
            std::cout<<"*****Student Added*****"<< std::endl << std::endl;

        }
        void displayStudent()
        {
            for(int i = 0; i < studentVector.size(); i++)
            {
                std::cout<<"Student "<< i << " : "<< studentVector[i].getName()<<", "<< studentVector[i].getSubject()<< ", "<< studentVector[i].getRollNumber()<< std::endl<< std::endl ;
            }
        }
        void uptedateSubject()   // 根據 rollNo 打印出舊資料，然後輸入要更改的 subject 做更新
        {
            int studentRollNo;
            std::cout<<"Enter Student's Roll Number :"; std::cin>>studentRollNo;
            for (int i = 0; i < studentVector.size(); i++)
            {
                if(studentRollNo == studentVector[i].getRollNumber())
                {
                    std::cout<<"Roll Number "<< studentVector[i].getRollNumber() << " is : "<< studentVector[i].getName()<<", "<< studentVector[i].getSubject()<< ", "<< studentVector[i].getRollNumber()<< std::endl ;
                    studentRollNo = i;
                    break;
                }            

            }
            std::string r;
            std::cout<<"Enter Student's New Subject : "; std::cin>>r;
            studentVector[studentRollNo].setSubject(r);
            std::cout<<"*****Updated Complete*****"<< std::endl<< std::endl;
        }
};
int main()
{   
    College college;
    while(true)
    {
        int value;
        std::cout<<"***** College Management System *****"<<std::endl<<std::endl;
        std::cout<<"Enter 1 for add student"<< std::endl;
	    std::cout<<"Enter 2 for display students"<< std::endl;
	    std::cout<<"Enter 3 for update record"<< std::endl;
	    std::cout<<"Enter 0 for exit from program"<< std::endl;
	    std::cout<<"Enter Choice: "; 
        std::cin>>value;
        
        if(value == 1)
        {
            std::string studentName, studentSubject;
            int studentRollNumber;
            std::cout<<"Enter Student Name : "; 
            std::cin>>studentName;
            std::cout<<"Enter Student Subject : "; 
            std::cin>>studentSubject;
            std::cout<<"Enter Student Roll Number : "; 
            std::cin>>studentRollNumber;
            college.addStudent(studentName, studentSubject, studentRollNumber);
        }
        else if (value == 2)
        {
            college.displayStudent();
        }
        else if (value == 3)
        {
            college.uptedateSubject();
        }
        else if(value == 0)
            exit(0);
        else
        {
            std::cout<<"Invalid Number, Please Enter Again"<< std::endl<<std::endl;
        }

    }
    return 0;
}