// Class definitions for a priority queue of process info objects

#include <stdexcept>
#include <iostream>
#include "ProcessInfoList.hxx"


// creates an empty list of ProcessInfo objects
ProcessInfoList::ProcessInfoList(): listSize(0), myFront(0)
{
  // nothing to do
}

// destroys a list of ProcessInfo objects
ProcessInfoList::~ProcessInfoList()
{
  while(size() != 0)
    listDequeue();
}

// returns the number of elements in the list
size_t ProcessInfoList::size()
{
  return listSize;
}

// adds a new ProcessInfo object to the list in sorted order
void ProcessInfoList::listAdd(ProcessInfo newProcess)
{
  NodePtr myNode = new ProcessNode;
  myNode->myProcess = newProcess;

  NodePtr prev = 0;
  NodePtr curr = myFront;

  while ((curr != 0) && (myNode->myProcess.getCpuUsage() <= curr->myProcess.getCpuUsage()))
  {
    prev = curr;
    curr = curr->next;
  }

  if (prev == 0)
    myFront = myNode;
  else
    prev->next = myNode;
  
  myNode->next = curr;

  listSize++;
}

// returns the ProcessInfo object at the head of the list
ProcessInfo ProcessInfoList::listFront()
{
  return myFront->myProcess;
}

// pops the first ProcessInfo object off the list
void ProcessInfoList::listDequeue()
{
  if (size() == 0)
    throw std::underflow_error("Process Info List is already empty");
  else
  {
    NodePtr newPtr = myFront;
    myFront = myFront->next;
    listSize--;
    delete newPtr;
  }
}


