#include "../include/cli.h"

cli::cli() { parsefile("file.json", tasks); }

void cli::add_task(const std::string& _name) {
    Task new_task(_name, "todo");
    tasks.push_back(new_task);
}

void cli::update(const std::string& _name, int idx) {
    if(idx >= tasks.size()) {
        std::cerr<< "Index out of bound.\n";
        return;
    }
    tasks[idx].rename(_name);
}

void cli::delete_task(int idx) {
    tasks[idx].set_status("deleted");
}

void cli::mark_done(int idx) {
    tasks[idx].set_status("done");
}

void cli::mark_in_progress(int idx) {
    tasks[idx].set_status("in progress");
}

void cli::list_all() {
    for(auto& t: tasks) {
        std::cout<< t.getname()<< ' '<< t.getstatus()<< std::endl;
    }
}

void cli::list_todo() {
    for(auto& t: tasks) {
        if(t.is_todo()) std::cout<< t.getname()<< ' ';
    }
    std::cout<< std::endl;
}

void cli::list_done() {
    for(auto& t: tasks) {
        if(t.is_done()) std::cout<< t.getname()<< ' ';
    }
    std::cout<< std::endl;
}

void cli::list_in_progress() {
    for(auto& t: tasks) {
        if(t.is_in_progress()) std::cout<< t.getname()<< ' ';
    }
    std::cout<< std::endl;
}

void cli::save() {
    write("file.json", tasks);
}