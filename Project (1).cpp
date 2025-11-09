#include <iostream>
#include <queue>
#include <string>
#include <ctime>

struct PrintJob {
    std::string user;
    int priority;
    time_t timestamp;
    
    bool operator<(const PrintJob& other) const {
        return priority < other.priority;
    }
};

struct PrintStats {
    std::string user;
    time_t printTime;
};

class PrinterQueue {
private:
    std::priority_queue<PrintJob> queue;
    std::queue<PrintStats> stats;

public:
    void addJob(const std::string& user, int priority) {
        PrintJob job;
        job.user = user;
        job.priority = priority;
        job.timestamp = time(0);
        queue.push(job);
    }

    void processJob() {
        if (queue.empty()) return;
        
        PrintJob job = queue.top();
        queue.pop();
        
        PrintStats stat;
        stat.user = job.user;
        stat.printTime = time(0);
        stats.push(stat);
        
        std::cout << "Printed: " << job.user << " (priority: " << job.priority << ")" << std::endl;
    }

    void showStats() {
        std::cout << "Print statistics:" << std::endl;
        std::queue<PrintStats> temp = stats;
        
        while (!temp.empty()) {
            PrintStats stat = temp.front();
            temp.pop();
            std::cout << "User: " << stat.user << " at " << ctime(&stat.printTime);
        }
    }

    void showQueue() {
        std::cout << "Current queue:" << std::endl;
        std::priority_queue<PrintJob> temp = queue;
        
        while (!temp.empty()) {
            PrintJob job = temp.top();
            temp.pop();
            std::cout << "User: " << job.user << " Priority: " << job.priority << std::endl;
        }
    }
};

int main() {
    PrinterQueue printer;
    
    printer.addJob("User1", 3);
    printer.addJob("User2", 1);
    printer.addJob("User3", 5);
    printer.addJob("User4", 2);
    
    printer.showQueue();
    
    printer.processJob();
    printer.processJob();
    printer.processJob();
    
    printer.showStats();
    
    return 0;
}