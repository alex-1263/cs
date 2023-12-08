#include <stdio.h>

struct ProcessControlBlock
{
    int processID;
    int arrivalTime;
    int serviceTime;
    int priority;
    int startTime;
    int endTime;
};

// 函数声明
void initializeProcessQueue(struct ProcessControlBlock *processes, int numProcesses);
void FCFS(struct ProcessControlBlock *processes, int numProcesses);
void priorityScheduling(struct ProcessControlBlock *processes, int numProcesses);

// 初始化进程队列
void initializeProcessQueue(struct ProcessControlBlock *processes, int numProcesses)
{
    // 示例：初始化三个进程
    processes[0] = (struct ProcessControlBlock){1, 0, 5, 2, 0, 0};
    processes[1] = (struct ProcessControlBlock){2, 2, 3, 1, 0, 0};
    processes[2] = (struct ProcessControlBlock){3, 4, 2, 3, 0, 0};
}

// 先来先服务调度算法
void FCFS(struct ProcessControlBlock *processes, int numProcesses)
{
    printf("FCFS Scheduling:\n");

    int currentTime = 0;
    for (int i = 0; i < numProcesses; ++i)
    {
        processes[i].startTime = currentTime;
        processes[i].endTime = currentTime + processes[i].serviceTime;
        currentTime = processes[i].endTime;

        printf("Process %d starts at time %d and ends at time %d\n",
               processes[i].processID, processes[i].startTime, processes[i].endTime);
    }
    printf("\n");
}

// 优先级调度算法
void priorityScheduling(struct ProcessControlBlock *processes, int numProcesses)
{
    printf("Priority Scheduling:\n");

    // 按照优先级排序
    for (int i = 0; i < numProcesses - 1; ++i)
    {
        for (int j = 0; j < numProcesses - i - 1; ++j)
        {
            if (processes[j].priority > processes[j + 1].priority)
            {
                // 交换两个进程的位置
                struct ProcessControlBlock temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    int currentTime = 0;
    for (int i = 0; i < numProcesses; ++i)
    {
        processes[i].startTime = currentTime;
        processes[i].endTime = currentTime + processes[i].serviceTime;
        currentTime = processes[i].endTime;

        printf("Process %d starts at time %d and ends at time %d\n",
               processes[i].processID, processes[i].startTime, processes[i].endTime);
    }
    printf("\n");
}

// 主函数
int main()
{
    struct ProcessControlBlock processes[3];
    initializeProcessQueue(processes, 3);

    // 调用先来先服务算法
    FCFS(processes, 3);

    // 调用优先级调度算法
    priorityScheduling(processes, 3);

    return 0;
}
