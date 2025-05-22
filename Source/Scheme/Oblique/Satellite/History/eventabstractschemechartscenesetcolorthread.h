#ifndef EVENTABSTRACTSCHEMECHARTSCENESETCOLORTHREAD_H
#define EVENTABSTRACTSCHEMECHARTSCENESETCOLORTHREAD_H

#include "event.h"

#include <QBrush>

class SchemeObliqueChartScene;

class EventAbstractSchemeChartSceneSetColorThread: public Event
{
public:
    EventAbstractSchemeChartSceneSetColorThread(SchemeObliqueChartScene &scene,
                                            const int &numberThread,
                                            const QBrush &brushNext,
                                            const QBrush &brushBack);
    ~EventAbstractSchemeChartSceneSetColorThread();

    void next();
    void back();

private:
    const int numberThread;
    const QBrush brushNext;
    const QBrush brushBack;
};

#endif // EVENTABSTRACTSCHEMECHARTSCENESETCOLORTHREAD_H
