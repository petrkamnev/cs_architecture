#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
#include <random>
#include <vector>

std::mutex doctor1_mutex;
std::mutex doctor2_mutex;
std::mutex dentist_mutex;
std::mutex surgeon_mutex;
std::mutex therapist_mutex;
std::mutex cout_mutex;
std::mutex rnd_mutex;
std::mutex id_mutex;

std::mt19937 rnd(std::time(0));
std::chrono::time_point start = std::chrono::steady_clock::now();

class doctor {
public:
    doctor(std::string name_) {
        name = name_;
    }

    int getRefferal(int visitorID) {
        {
            std::lock_guard<std::mutex> cml(cout_mutex);
            std::cout << "ЧАСЫ: " << std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::steady_clock::now() - start).count() << std::endl;
            std::cout << name << " принимает пациента " << visitorID << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds());
        int refferal;
        int sleepfor;
        {
            std::lock_guard<std::mutex> rml(rnd_mutex);
            refferal = rnd() % 3;
            sleepfor = 3 + rnd() % 3;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepfor));
        return refferal;
    }

private:
    std::string name;
};

class specialist {
public:
    specialist(std::string name_) {
        name = name_;
    }

    void seePatient(int visitorID) {
        {
            std::lock_guard<std::mutex> cml(cout_mutex);
            std::cout << "ЧАСЫ: " << std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::steady_clock::now() - start).count() << std::endl;
            std::cout << name << " принимает пациента " << visitorID << std::endl;
        }
        int sleepfor;
        {
            std::lock_guard<std::mutex> rml(rnd_mutex);
            sleepfor = 3 + rnd() % 3;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepfor));
    }

private:
    std::string name;
};

doctor doctor1("Врач1");
doctor doctor2("Врач2");
specialist dentist("Стоматолог");
specialist surgeon("Хирург");
specialist therapist("Терапевт");
int id = 0;

void patient_thread() {
    int currentID;
    {
        std::lock_guard<std::mutex> iml(id_mutex);
        currentID = id;
        id++;
    }
    int doctorID;
    {
        std::lock_guard<std::mutex> rml(rnd_mutex);
        doctorID = 1 + rnd() % 2;
    }
    {
        std::lock_guard<std::mutex> cml(cout_mutex);
        std::cout << "ЧАСЫ: " << std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::steady_clock::now() - start).count() << std::endl;
        std::cout << "Пациент" << currentID << " занимает очередь к Врачу" << doctorID << std::endl;
    }
    int refferal;
    if (doctorID == 1) {
        std::lock_guard<std::mutex> d1l(doctor1_mutex);
        refferal = doctor1.getRefferal(currentID);
    } else {
        std::lock_guard<std::mutex> d2l(doctor2_mutex);
        refferal = doctor2.getRefferal(currentID);
    }
    {
        std::lock_guard<std::mutex> cml(cout_mutex);
        std::cout << "ЧАСЫ: " << std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::steady_clock::now() - start).count() << std::endl;
        std::cout << "Пациент" << currentID << " получил направление типа " << refferal
                  << " и занимает очередь к специалисту\n";
    }
    specialist *specialistPtr;
    std::mutex *mutexPtr;
    if (refferal == 0) {
        specialistPtr = &dentist;
        mutexPtr = &dentist_mutex;
    } else if (refferal == 1) {
        specialistPtr = &surgeon;
        mutexPtr = &surgeon_mutex;
    } else {
        specialistPtr = &therapist;
        mutexPtr = &therapist_mutex;
    }
    {
        std::lock_guard<std::mutex> sl(*mutexPtr);
        specialistPtr->seePatient(currentID);
    }
    {
        std::lock_guard<std::mutex> cml(cout_mutex);
        std::cout << "ЧАСЫ: " << std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::steady_clock::now() - start).count() << std::endl;
        std::cout << "Пациент" << currentID << " покидает клинику..."
                  << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Введите число пациентов, которых должна принять клиника:\n";
    std::cin >> n;
    std::vector<std::thread> threads;
    std::cout << "ЧАСЫ: 0\nКлиника начинает свою работу\n";
    start = std::chrono::steady_clock::now();
    for (int i = 0; i < n; i++) {
        threads.push_back(std::thread(patient_thread));
        int sleepfor;
        {
            std::lock_guard<std::mutex> rml(rnd_mutex);
            sleepfor = rnd() % 4;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepfor));
    }
    for (std::thread &t: threads) {
        t.join();
    }
    std::cout << "FINISH!" << std::endl;
    return 0;
}
