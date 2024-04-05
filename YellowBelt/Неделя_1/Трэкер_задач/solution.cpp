#include <iostream>
#include <map>

// Перечислимый тип для статуса задачи
enum class TaskStatus{
	NEW,		 // новая
	IN_PROGRESS, // в разработке
	TESTING,	 // на тестировании
	DONE		 // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = std::map<TaskStatus, int>;

class TeamTasks{
  public:
	// Получить статистику по статусам задач конкретного разработчика
	const TasksInfo &GetPersonTasksInfo(const std::string &person) const{
		return team.at(person);
	}

	// Добавить новую задачу (в статусе NEW) для конкретного разработчитка
	void AddNewTask(const std::string &person){
		if (team.empty()){
			team[person].insert({{TaskStatus::NEW, 1}, {TaskStatus::IN_PROGRESS, 0}, {TaskStatus::TESTING, 0}, {TaskStatus::DONE, 0}});
		}
		else{
			team[person][TaskStatus::NEW]++;
		}
	}

	// Обновить статусы по данному количеству задач конкретного разработчика,
	std::tuple<TasksInfo, TasksInfo> PerformPersonTasks(const std::string &person, int task_count){
		TasksInfo update, untouched;
        if (team.count(person) == 0){
        	return std::make_tuple(update, untouched);
        }
		TasksInfo tasks = team[person];
		if(tasks[TaskStatus::NEW] > 0){
			int min = std::min(tasks[TaskStatus::NEW], task_count);
			tasks[TaskStatus::NEW] -= min;
			tasks[TaskStatus::IN_PROGRESS] += min;
		}
		if(tasks[TaskStatus::IN_PROGRESS] > 0){
			int min = std::min(tasks[TaskStatus::IN_PROGRESS], task_count);
			tasks[TaskStatus::IN_PROGRESS] -= min;
			tasks[TaskStatus::TESTING] += min;
		}
		if(tasks[TaskStatus::TESTING] > 0){
			int min = std::min(tasks[TaskStatus::TESTING], task_count);
			tasks[TaskStatus::TESTING] -= min;
			tasks[TaskStatus::DONE] += min;
		}
		
		for(auto &[status, count]: tasks){
        	if(count > 0){
            	if(status != TaskStatus::DONE){
                	update[static_cast<TaskStatus>(static_cast<int>(status)+1)] = count;
                }
                    untouched[status] = count;
            }

        }
		
		return std::make_tuple(update, untouched);
	}

  private:
	std::map<std::string, TasksInfo> team;
};

void PrintTasksInfo(TasksInfo tasks_info) {
  std::cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << std::endl;
}

int main(){
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  std::cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  std::cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  
  TasksInfo updated_tasks, untouched_tasks;
  
  std::tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  std::cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  std::cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  
  std::tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  std::cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  std::cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}