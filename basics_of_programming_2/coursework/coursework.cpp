#include <iostream>
#include <string>
#include "algorithm"
#include <vector>
#include <set>

class Lesson
{
private:
    std::string subject;
    std::string auditorium;
    std::string time;
    std::string day;

public:
    Lesson(
            const std::string& subject,
            const std::string& auditorium,
            const std::string& time,
            const std::string& day
    ) : subject(subject), auditorium(auditorium), time(time), day(day) {}

    std::string getSubject() const {
        return subject;
    }

    std::string getAuditorium() const {
        return auditorium;
    }

    std::string getTime() const {
        return time;
    }

    std::string getDay() const {
        return day;
    }
};

class Student {
private:
    std::string name;
    std::string group;
    std::string specialty;

public:
    Student(const std::string& name, const std::string& group, const std::string& specialty)
            : name(name), group(group), specialty(specialty) {}

    std::string getName() const {
        return name;
    }

    std::string getGroup() const {
        return group;
    }

    std::string getSpecialty() const {
        return specialty;
    }
};

class Lecture : public Lesson {
private:
    std::string specialty;

public:
    Lecture(
            const std::string& subject,
            const std::string& auditorium,
            const std::string& _specialty,
            const std::string& time,
            const std::string& day
    ) : Lesson(subject, auditorium, time, day)
    {
        specialty = _specialty;
    }

    std::string getSpecialty() const {
        return specialty;
    }
};

class Practice : public Lesson {
private:
    std::string specialty;
    std::string group;

public:
    Practice(
            const std::string& subject,
            const std::string& auditorium,
            const std::string& _specialty,
            const std::string& _group,
            const std::string& time,
            const std::string& day
    ) : Lesson(subject, auditorium, time, day)
    {
        specialty = _specialty;
        group = _group;
    }

    std::string getSpecialty() const {
        return specialty;
    }

    std::string getGroup() const {
        return group;
    }
};

class Faculty {
private:
    std::vector<Student> students;
    std::vector<Lecture> lectures;
    std::vector<Practice> practices;

public:
    std::vector<Student> getStudents() {
        return students;
    }

    std::vector<Lecture> getLectures() {
        return lectures;
    }

    std::vector<Practice> getPractices() {
        return practices;
    }

    void addStudent(const std::string& name, const std::string& group, const std::string& specialty) {
        Student student(name, group, specialty);

        addStudent(student);
    }

    void addStudent(const Student& student) {
        students.push_back(student);

        std::cout << "Студента успішно додано!" << std::endl;
    }

    void addLecture(
            const std::string& subject,
            const std::string& auditorium,
            const std::string& specialty,
            const std::string& time,
            const std::string& day
    ) {
        Lecture lecture(subject, auditorium, specialty, time, day);

        addLecture(lecture);
    }

    void addLecture(const Lecture& lecture) {
        lectures.push_back(lecture);

        std::cout << "Лекцію успішно додано!" << std::endl;
    }

    void addPractice(
            const std::string& subject,
            const std::string& auditorium,
            const std::string& specialty,
            const std::string& group,
            const std::string& time,
            const std::string& day
    ) {
        Practice practice(subject, auditorium, specialty, group, time, day);

        addPractice(practice);
    }

    void addPractice(const Practice& practice) {
        practices.push_back(practice);

        std::cout << "Практичне заняття успішно додано!" << std::endl;
    }

    void displayStudents() const {
        std::cout << "Список студентів:" << std::endl;
        for (const auto& student : students) {
            std::cout << "Ім'я: " << student.getName() << " | Спеціальність: " << student.getSpecialty()
                      << " | Група: " << student.getGroup() << std::endl;
        }
    }

    void displayLectures() const {
        std::cout << "Список лекцій:" << std::endl;
        for (const auto& lecture : lectures) {
            std::cout << "Дисципліна: " << lecture.getSubject() << " | Аудиторія: " << lecture.getAuditorium()
                      << " | Спеціальність: " << lecture.getSpecialty() << " | Час проведення: " << lecture.getTime()
                      << " | День проведення: " << lecture.getDay() << std::endl;
        }
    }

    void displayPractices() const {
        std::cout << "Список практичних занять:" << std::endl;
        for (const auto& practice : practices) {
            std::cout << "Дисципліна: " << practice.getSubject() << " | Аудиторія: " << practice.getAuditorium()
                      << " | Спеціальність: " << practice.getSpecialty() << " | Група: " << practice.getGroup()
                      << " | Час проведення: " << practice.getTime() << " | День проведення: " << practice.getDay()
                      << std::endl;
        }
    }

    void displayGroups() const {
        std::set<std::string> groups;
        for (const auto& student : students) {
            groups.insert(student.getGroup());
        }

        for (const auto& practice : practices) {
            groups.insert(practice.getGroup());
        }

        std::cout << "Список груп студентів:" << std::endl;
        for (const auto& group : groups) {
            std::cout << group << std::endl;
        }
    }

    void displayStudentsByGroup(const std::string& group) const {
        std::cout << "Студенти з групи " << group << ":" << std::endl;
        for (const auto& student : students) {
            if (student.getGroup() == group) {
                std::cout << "Ім'я: " << student.getName() << " | Спеціальність: " << student.getSpecialty()
                          << std::endl;
            }
        }
    }

    void displaySpecialties() const {
        std::set<std::string> specialties;
        for (const auto& student : students) {
            specialties.insert(student.getSpecialty());
        }

        for (const auto& lecture : lectures) {
            specialties.insert(lecture.getSpecialty());
        }

        for (const auto& practice : practices) {
            specialties.insert(practice.getSpecialty());
        }

        std::cout << "Список спеціальностей:" << std::endl;
        for (const auto& specialty : specialties) {
            std::cout << specialty << std::endl;
        }
    }

    void displayGroupsBySpecialty(const std::string& specialty) const {
        std::set<std::string> groups;
        for (const auto& student : students) {
            if (student.getSpecialty() == specialty) {
                groups.insert(student.getGroup());
            }
        }

        for (const auto& practice : practices) {
            if (practice.getSpecialty() == specialty) {
                groups.insert(practice.getGroup());
            }
        }

        std::cout << "Групи для спеціальності " << specialty << ":" << std::endl;
        for (const auto& group : groups) {
            std::cout << group << std::endl;
        }
    }

    void displayLecturesAndPracticesByDay(const std::string& day) const {
        std::vector<Lesson> lessons;

        for (const auto& lecture : lectures) {
            if (lecture.getDay() == day) {
                lessons.push_back(lecture);
            }
        }

        for (const auto& practice : practices) {
            if (practice.getDay() == day) {
                lessons.push_back(practice);
            }
        }

        std::sort( lessons.begin(), lessons.end(), [](const Lesson &a, const Lesson &b){
            return (a.getTime() < b.getTime());
        });

        std::cout << "Список занять на " << day << ": " << std::endl;

        for (Lesson lesson : lessons)
        {
            std::cout << "Дисципліна: " << lesson.getSubject() << " | Аудиторія: " << lesson.getAuditorium()
                      << " | Час проведення: " << lesson.getTime() << std::endl;
        }

        lessons.clear();
    }

    ~Faculty()
    {
        students.clear();
        lectures.clear();
        practices.clear();
    }
};

int main() {
    Faculty faculty;
    int choice;

    while (true) {
        std::cout << "Оберіть операцію:" << std::endl;
        std::cout << "1. Додати студента" << std::endl;
        std::cout << "2. Додати лекцію" << std::endl;
        std::cout << "3. Додати практичне заняття" << std::endl;
        std::cout << "4. Переглянути список студентів" << std::endl;
        std::cout << "5. Переглянути список лекцій" << std::endl;
        std::cout << "6. Переглянути список практичних занять" << std::endl;
        std::cout << "7. Переглянути список груп студентів" << std::endl;
        std::cout << "8. Переглянути студентів з певної групи" << std::endl;
        std::cout << "9. Переглянути список спеціальностей студентів" << std::endl;
        std::cout << "10. Переглянути групи для певної спеціальності" << std::endl;
        std::cout << "11. Переглянути графік занять на день" << std::endl;
        std::cout << "0. Вийти" << std::endl;

        std::cout << "Оберіть операцію: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string name, group, specialty;
            std::cout << "Введіть ім'я студента: ";
            std::cin >> name;
            std::cout << "Введіть спеціальність студента: ";
            std::cin >> specialty;
            std::cout << "Введіть групу студента: ";
            std::cin >> group;
            faculty.addStudent(name, group, specialty);
        } else if (choice == 2) {
            std::string subject, auditorium, specialty, time, day;
            std::cout << "Введіть назву дисципліни лекції: ";
            std::cin >> subject;
            std::cout << "Введіть спеціальність: ";
            std::cin >> specialty;
            std::cout << "Введіть аудиторію: ";
            std::cin >> auditorium;
            std::cout << "Введіть день проведення лекції: ";
            std::cin >> day;
            std::cout << "Введіть чвс проведення лекції: ";
            std::cin >> time;
            faculty.addLecture(subject, auditorium, specialty, time, day);
        } else if (choice == 3) {
            std::string subject, auditorium, specialty, group, time, day;
            std::cout << "Введіть назву дисципліни практичного заняття: ";
            std::cin >> subject;
            std::cout << "Введіть спеціальність: ";
            std::cin >> specialty;
            std::cout << "Введіть групу: ";
            std::cin >> group;
            std::cout << "Введіть аудиторію: ";
            std::cin >> auditorium;
            std::cout << "Введіть день проведення практичного заняття: ";
            std::cin >> day;
            std::cout << "Введіть чвс проведення практичного заняття: ";
            std::cin >> time;
            faculty.addPractice(subject, auditorium, specialty, group, time, day);
        } else if (choice == 4) {
            faculty.displayStudents();
        } else if (choice == 5) {
            faculty.displayLectures();
        } else if (choice == 6) {
            faculty.displayPractices();
        } else if (choice == 7) {
            faculty.displayGroups();
        } else if (choice == 8) {
            std::string group;
            std::cout << "Введіть назву групи: ";
            std::cin >> group;
            faculty.displayStudentsByGroup(group);
        } else if (choice == 9) {
            faculty.displaySpecialties();
        } else if (choice == 10) {
            std::string specialty;
            std::cout << "Введіть назву спеціальності: ";
            std::cin >> specialty;
            faculty.displayGroupsBySpecialty(specialty);
        } else if (choice == 11) {
            std::string day;
            std::cout << "Введіть день проведення занять: ";
            std::cin >> day;
            faculty.displayLecturesAndPracticesByDay(day);
        } else if (choice == 0) {
            break;
        } else {
            std::cout << "Невірний вибір. Спробуйте ще раз." << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}

// Тестування
//int main() {
//    Student student1("Сікорський Ігор Іванович", "Група А", "Комп'ютерні науки");
//    Student student2("Нечай Михайло Потапович", "Група Б", "Електротехніка");
//
//    Lecture lecture1(
//            "Лекція з математики",
//            "101",
//            "Комп'ютерні науки",
//            "10:00",
//            "Понеділок"
//    );
//    Lecture lecture2(
//            "Лекція з фізики",
//            "201",
//            "Електротехніка",
//            "02:00",
//            "Середа"
//    );
//
//    Practice practice1(
//            "Практична з комп'ютерних наук",
//            "303",
//            "Комп'ютерні науки",
//            "Група А",
//            "09:00",
//            "Вівторок"
//    );
//    Practice practice2(
//            "Практична з електротехніки",
//            "405",
//            "Електротехніка",
//            "Група Б",
//            "11:00",
//            "Четвер"
//    );
//
//    Faculty faculty;
//
//    std::cout << "Перевірка операції №1. Додання студента." << std::endl;
//
//    faculty.addStudent(student1);
//    faculty.addStudent(student2);
//
//    std::cout << std::endl;
//
//    std::cout << "Перевірка операції №2. Додання лекції." << std::endl;
//
//    faculty.addLecture(lecture1);
//    faculty.addLecture(lecture2);
//
//    std::cout << std::endl;
//
//    std::cout << "Перевірка операції №3. Додання практичного заняття." << std::endl;
//
//    faculty.addPractice(practice1);
//    faculty.addPractice(practice2);
//
//    std::cout << std::endl;
//
//    std::cout << "Перевірка операції №4. Перегляд списку студентів." << std::endl;
//
//    faculty.displayStudents();
//
//    std::cout << std::endl;
//
//    std::cout << "Перевірка операції №5. Перегляд списку лекцій." << std::endl;
//
//    faculty.displayLectures();
//
//    std::cout << std::endl;
//
//    std::cout << "Перевірка операції №6. Перегляд списку практичних занять." << std::endl;
//
//    faculty.displayPractices();
//
//    std::cout << std::endl;
//
//    std::cout << "Перевірка операції №7. Перегляд списку груп студентів." << std::endl;
//
//    faculty.displayGroups();
//
//    std::cout << std::endl;
//
//    std::cout << "Перевірка операції №8. Перегляд списку студентів у заданій групі (виконую пошук за групою \""
//              << student2.getGroup() << "\")" << std::endl;
//
//    faculty.displayStudentsByGroup(student2.getGroup());
//
//    std::cout << std::endl;
//
//    std::cout << "Перевірка операції №9. Перегляд списку спеціальностей." << std::endl;
//
//    faculty.displaySpecialties();
//
//    std::cout << std::endl;
//
//    std::cout << "Перевірка операції №10. Перегляд списку груп студентів певної спеціальності "
//              << "(виконую пошук за спеціальністю \"" << student1.getSpecialty() << "\")" << std::endl;
//
//    faculty.displayGroupsBySpecialty(student1.getSpecialty());
//
//    std::cout << std::endl;
//
//    std::cout << "Перевірка операції №11. Перегляд графіку заннять на день "
//              << "(виконую пошук за днем \"" << lecture2.getDay() << "\")" << std::endl;
//
//    faculty.displayLecturesAndPracticesByDay(lecture2.getDay());
//
//    std::cout << std::endl;
//
//    return 0;
//}

