/**
* Assignment 3: CPU Scheduler
 * @file scheduler_fcfs.h
 * @author Kyrstn Hall & Elaeth Lilagan 
 * @brief This Scheduler class implements the SJF scheduling algorithm.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#ifndef ASSIGN3_SCHEDULER_SJF_H
#define ASSIGN3_SCHEDULER_SJF_H

#include "scheduler.h"
#include <vector>
#include <queue>
#include <algorithm>

class SchedulerSJF : public Scheduler {
  private:
    // TODO: add necessary member variables here for your implementation
    queue<PCB> Q; // queue of PCBs 
    vector<PCB> done; // PCBs done in queue, mainly to display
    int count; // to count how many processes there are
    double total_turnaround; // sum of turnaround times for all processes
    double total_wait; // sum of waiting times for all processes

  public:
    /**
     * @brief Construct a new SchedulerSJF object
     */
    SchedulerSJF();
    /**
     * @brief Destroy the SchedulerSJF object
     */
    ~SchedulerSJF() override;
    /**
     * @brief This function is called once before the simulation starts.
     *        It is used to initialize the scheduler.
     * @param process_list The list of processes in the simulation.
     */
    void init(std::vector<PCB>& process_list) override;
    /**
     * @brief This function is called once after the simulation ends.
     *        It is used to print out the results of the simulation.
     */
    void print_results() override;
  
    /**
     * @brief This function simulates the scheduling of processes in the ready queue.
     *        It stops when all processes are finished.
     */
    void simulate() override;
};
#endif //ASSIGN3_SCHEDULER_SJF_H
