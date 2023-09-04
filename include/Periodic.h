#ifndef PERIODIC_H
#define PERIODIC_H

class PeriodicAction {
  public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void run() = 0;
};


class Periodic {
  protected:
    PeriodicAction* _action;
    unsigned long _period;
    unsigned long _duration;
    bool _running;
    unsigned long _lastRun;
    unsigned long _startedAt;
  public:
    Periodic(PeriodicAction* action, unsigned long period, unsigned long duration);
    void start();
    void run(); // to be called in loop()
};

#endif // PERIODIC_H
