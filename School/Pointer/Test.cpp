#include <iostream>
#include <string>

// Định nghĩa cấu trúc cho một Node trong danh sách liên kết
struct Student
{
    int id;
    std::string name;
    float score;
    int age;
    std::string dob;
    Student *next;
};

// Hàm để thêm một sinh viên vào danh sách liên kết
void addStudent(Student *&head, int id, std::string name, float score, int age, std::string dob)
{
    int n;
    cin >> n;
    while (n)
    {
        Student *newStudent = new Student;
        newStudent->id = id;
        newStudent->name = name;
        newStudent->score = score;
        newStudent->age = age;
        newStudent->dob = dob;
        newStudent->next = head;
        head = newStudent;
    }
}

// Hàm để xóa một sinh viên khỏi danh sách liên kết
void deleteStudent(Student *&head, int id)
{
    if (head == NULL)
        return;
    if (head->id == id)
    {
        Student *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Student *current = head;
    while (current->next != NULL && current->next->id != id)
    {
        current = current->next;
    }
    if (current->next != NULL)
    {
        Student *temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

// Hàm để in danh sách sinh viên
void printStudents(Student *head)
{
    Student *temp = head;
    while (temp != NULL)
    {
        std::cout << "ID: " << temp->id << ", Name: " << temp->name << ", Score: " << temp->score << ", Age: " << temp->age << ", DOB: " << temp->dob << std::endl;
        temp = temp->next;
    }
}

int main()
{
    Student *head = NULL;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
    }

    printStudents(head);

    // deleteStudent(head, 2);

    // printStudents(head);

    return 0;
}
