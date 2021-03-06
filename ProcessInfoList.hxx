// Class declarations for a priority queue of process info objects

#ifndef PROCESSINFOLIST_HXX
#define PROCESSINFOLIST_HXX

#include "ProcessInfo.hxx"

struct ProcessNode
{
  ProcessInfo myProcess = ProcessInfo(0, 0);
  ProcessNode *next;
};

typedef ProcessNode* NodePtr;

class ProcessInfoList
{
public:

  ProcessInfoList();

  ~ProcessInfoList();

  size_t size();

  void listAdd(ProcessInfo newProcess);

  ProcessInfo listFront();

  void listDequeue();

private:
  size_t listSize;
  NodePtr myFront;
};

#endif
