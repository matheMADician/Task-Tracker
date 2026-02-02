#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>

class Task{
    public:
        Task();
        Task(std::string _name, std::string _status);
        std::string getname();
        std::string getstatus();
        bool is_done();
        bool is_in_progress();
        bool is_todo();
        bool is_deleted();
        void set_status(const std::string& _status);
        void rename(const std::string& _name);
        void print();
    private:
        std::string name;
        std::string status;
};

#endif