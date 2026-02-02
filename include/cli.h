#ifndef CLI_H
#define CLI_H

#include <string>
#include <vector>
#include "json.h"
#include "task.h"

class cli{
    public:
        cli();
        void add_task(const std::string& _name);
        void update(const std::string& _name, int idx);
        void delete_task(int idx);
        void mark_done(int idx);
        void mark_in_progress(int idx);
        void list_all();
        void list_todo();
        void list_done();
        void list_in_progress();
        void save();
    private:
        std::vector<Task> tasks;

};

#endif