#include "../include/json.h"

// Create file if file do not exist
// Turn json file into vector of tasks
void parsefile(const std::string& file_name, std::vector<Task>& tasks) {
    std::ifstream json_file;
    json_file.open(file_name);
    if(!json_file) {
        std::cout<< "Creating file...\n";
        json_file.open(file_name,  std::fstream::in | std::fstream::out | std::fstream::trunc);
    }

    if(!json_file.is_open()) {
        std::cerr<< "Failed to open json file.\n";
        return;
    }
    std::string file_content(
        (std::istreambuf_iterator<char>(json_file)),
        std::istreambuf_iterator<char>()
    );
    size_t idx = 0, file_size = file_content.size();
    while(idx < file_size) {
        if(file_content[idx]=='{') {
            size_t end = file_content.find('}', idx);
            size_t name_idx = idx+18;
            size_t status_idx = file_content.find(',', idx)+20;
            tasks.push_back(
                Task(
                    file_content.substr(name_idx, file_content.find('"', name_idx)-name_idx),
                    file_content.substr(status_idx, file_content.find('"', status_idx)-status_idx)
                )
            );
            idx = end+1;
        }
        else idx++;
    }
    json_file.close();
}

// Write tasks into json file
/*
[
    {
        "name": "Buy groceries"
        "status": "In progress"
    },
    .
    .
    .
]
*/
void write(const std::string& file_name, std::vector<Task>& tasks) {
    std::ofstream json_file(file_name, std::ios::trunc);
    if(!json_file.is_open()) {
        std::cerr<< "Failed to open json file.\n";
        return;
    }
    std::string file_content = "";
    bool flag_is_first = true;
    int num_tasks = tasks.size();
    for(int i = 0; i < num_tasks; i++) {
        if(tasks[i].is_deleted()) continue;
        if(flag_is_first) flag_is_first = false;
        else file_content += ",\n";
        file_content +=
        "   {\n"
        "       \"name\": \""   + tasks[i].getname()   + "\",\n"
        "       \"status\": \"" + tasks[i].getstatus() + "\"\n"
        "   }";
    }
    file_content = "[\n" + file_content + "\n]";
    json_file << file_content;
    json_file.close();
}
