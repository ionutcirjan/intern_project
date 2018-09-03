#ifndef LOGOBSERVER_H
#define LOGOBSERVER_H
#include <iostream>
#include <iomanip>
#include <mutex>
#include "observer.h"
#include "utils.h"

class LogObserver : public Observer
{
public:
    LogObserver();
    std::mutex mutex;
    ARequestPList failed_requests;
    ARequestPList successful_requests;
    // Observer interface
public:
    void update(unsigned int, std::shared_ptr<Action>) override;
};

#endif // LOGOBSERVER_H
