CXX = g++
FLAGS = -O2 -Iinclude

task_manager: obj/main.o obj/json.o obj/task.o obj/cli.o
	$(CXX) $(FLAGS) $^ -o $@

obj/main.o: src/main.cpp include/json.h include/task.h include/cli.h
	if not exist $(@D) mkdir $(@D)
	$(CXX) $(FLAGS) -c $< -o $@

obj/json.o: src/json.cpp include/json.h include/task.h
	if not exist $(@D) mkdir $(@D)
	$(CXX) $(FLAGS) -c $< -o $@

obj/task.o: src/task.cpp include/task.h
	if not exist $(@D) mkdir $(@D)
	$(CXX) $(FLAGS) -c $< -o $@

obj/cli.o: src/cli.cpp include/cli.h include/json.h include/task.h
	if not exist $(@D) mkdir $(@D)
	$(CXX) $(FLAGS) -c $< -o $@

