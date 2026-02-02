#include "../include/task.h"

Task::Task(std::string _name, std::string _status): name(_name), status(_status) {}

std::string Task::getname() {return name;}

std::string Task::getstatus() {return status;}

bool Task::is_done() {
    return status == "done";
}

bool Task::is_in_progress() {
    return status == "in progress";
}

bool Task::is_todo() {
    return status == "todo";
}

bool Task::is_deleted() {
    return status == "deleted";
}

void Task::set_status(const std::string& _status) {
    status = _status;
}

void Task::rename(const std::string& _name) {
    name = _name;
}

void Task::print() {
    std::cout<< name<< ' '<< status<< std::endl;
}