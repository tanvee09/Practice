// Single core CPU, task has id, execution time, and queue time.
// List of tasks, pick task with minimum execution time, give order of execution order, make class

#include<bits/stdc++.h>
using namespace std;

struct task {
    int id, exec_time, queue_time;
    task(int task_id, int task_exec_time, int task_queue_time) {
        id = task_id;
        queue_time = task_queue_time;
        exec_time = task_exec_time;
    }
};

bool cmp_queue_time(const task &t1, const task &t2) {
    if (t1.queue_time == t2.queue_time)
        return t1.exec_time < t2.exec_time;
    return t1.queue_time < t2.queue_time;
}

struct cmp_exec_time {
    bool operator() (const task &t1, const task &t2) {
        if (t1.exec_time == t2.exec_time)
            return t1.queue_time > t2.queue_time;
        return t1.exec_time > t2.exec_time;
    }
};

vector<task> orderOfExecution(vector<task> tasks) {
    sort(tasks.begin(), tasks.end(), cmp_queue_time);
    int idx = 0;
    int currTime = 0;
    vector<task> execOrder;
    priority_queue<task, vector<task>, cmp_exec_time> helper;
    helper.push(tasks[idx++]);
    while(!helper.empty()) {
        task curr = helper.top();
        helper.pop();
        currTime += curr.exec_time;
        execOrder.push_back(curr);
        for (; idx < tasks.size() && tasks[idx].queue_time <= currTime; idx++)
            helper.push(tasks[idx]);
        if (helper.empty() && idx < tasks.size())
            helper.push(tasks[idx++]);
    }
    return execOrder;
}

void printOrder(vector<task> execOrder) {
    cout << "ID\tExTime\tQTime" << endl;
    for (task t : execOrder) {
        cout << t.id << "\t" << t.exec_time << "\t" << t.queue_time << endl;
    }
}

int main()
{
    task t1(1,4,1), t2(2,3,3), t3(3,2,4);
    vector<task> tasks = {t1, t2, t3};
    // for (int i = 0; i < n; i++) {
    //     int exec_time, id, queue_time;
    //     cin >> id >> queue_time >> exec_time;
    //     task t(id, exec_time, queue_time);
    //     tasks.push_back(t);
    // }
    printOrder(orderOfExecution(tasks));
    return 0;
}