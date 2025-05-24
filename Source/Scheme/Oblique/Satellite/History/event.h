#ifndef EVENT_H
#define EVENT_H

class SchemeObliqueChartScene;

class Event
{
public:
    Event(SchemeObliqueChartScene &scene);
    virtual ~Event();
    virtual void next() = 0;
    virtual void back() = 0;

protected:
    SchemeObliqueChartScene &scene;
};

#endif // EVENT_H
