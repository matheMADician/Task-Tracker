#include<iostream>
#include<fstream>
#include"../include/json.h"
#include"../include/task.h"
#include"../include/cli.h"

/*
commands:
    ./task_manager add "Buy groceries"
    ./task_manager update 0 "Clean house"
    ./task_manager delete 0
    ./task_manager mark-in-progress 0
    ./task_manager mark-done 0
    ./task_manager list
    ./task_manager list done
    ./task_manager list todo
    ./task_manager list in-progress
*/

struct Command {
    Command(int _argc, char* _args[]) {
        args.assign(_args, _args + _argc);
    }
    std::vector<std::string> args;
};

int main(int argc, char* args[]) {
    std::vector<Task> tasks;
    std::string filename = "file.json";
    cli CLI;
    if(argc <= 1) {
        printf("Error: Not enough arguments.\n");
        return 0;
    }
    Command command(argc, args);
    if(command.args[1] == "add") {
        CLI.add_task(command.args[2]);
    }else if(command.args[1] == "update") {
        CLI.update(command.args[3], stoi(command.args[2]));
    }else if(command.args[1] == "delete") {
        CLI.delete_task(stoi(command.args[2]));
    }else if(command.args[1] == "mark-in-progress") {
        CLI.mark_in_progress(stoi(command.args[2]));
    }else if(command.args[1] == "mark-done") {
        CLI.mark_done(stoi(command.args[2]));
    }else if(command.args[1] == "list") {
        if(argc == 2) {
            CLI.list_all();
        }else if(command.args[2] == "done") {
            CLI.list_done();
        }else if(command.args[2] == "todo") {
            CLI.list_todo();
        }else if(command.args[2] == "in-progress") {
            CLI.list_in_progress();
        }else printf("Error: Command not found.");
    }else {
        printf("Error: Command not found.");
    }
    CLI.save();
    return 0;
}

/*
mingw32-make
./task_manager list
*/