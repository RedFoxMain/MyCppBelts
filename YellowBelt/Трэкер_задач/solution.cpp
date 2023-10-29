
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

enum class TaskStatus
{
	NEW,		 // новая
	IN_PROGRESS, // в разработке
	TESTING,	 // на тестировании
	DONE		 // завершена
};

using TasksInfo = map<TaskStatus, int>;

class TeamTasks
{
	map<string, TasksInfo> team;

  public:
	const TasksInfo &GetPersonTasksInfo(const string &person)
	{
		return team[person];
	}

	void AddNewTask(const string &person)
	{
		if (team[person].empty())
		{
			team[person].insert({{TaskStatus::NEW, 1}, {TaskStatus::IN_PROGRESS, 0}, {TaskStatus::TESTING, 0}, {TaskStatus::DONE, 0}});
		}
		else
		{
			team[person][TaskStatus::NEW]++;
		}
	}

	tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string &person, int task_count)
	{
		TasksInfo update, untouched;
		if (team.count(person) == 0)
		{
			return make_tuple(update, untouched);
		}
		
		TasksInfo &tasks = team[person];
		
		if(tasks[TaskStatus::NEW] > 0){
			int to_move = min(tasks[TaskStatus::NEW], task_count);
			tasks[TaskStatus::NEW] -= to_move;
			tasks[TaskStatus::IN_PROGRESS] += to_move;
		}
		if(tasks[TaskStatus::IN_PROGRESS] > 0){
			int to_move = min(tasks[TaskStatus::IN_PROGRESS], task_count);
			tasks[TaskStatus::IN_PROGRESS] -= to_move;
			tasks[TaskStatus::TESTING] += to_move;
		}
		if(tasks[TaskStatus::TESTING] > 0){
			int to_move = min(tasks[TaskStatus::TESTING], task_count);
			tasks[TaskStatus::TESTING] -= to_move;
			tasks[TaskStatus::DONE] += to_move;
		}
		
		for(auto &[status, count]: tasks){
			if(count > 0){
				if(status != TaskStatus::DONE){
			update[static_cast<TaskStatus>(static_cast<int>(status)+1)] = count;
				}
				untouched[status] = count;
			}
			
		}
		
		return make_tuple(update, untouched);
	}
};

void PrintTasksInfo(TasksInfo tasks_info)
{
	cout << tasks_info[TaskStatus::NEW] << " new tasks"
		 << ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress"
		 << ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested"
		 << ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main()
{
	TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  
  TasksInfo updated_tasks, untouched_tasks;
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
	
}