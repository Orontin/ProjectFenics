#include "eventabstractschemechartscenesetcolorthread.h"

#include "Scheme/Oblique/Chart/schemeobliquechartscene.h"

EventAbstractSchemeChartSceneSetColorThread::EventAbstractSchemeChartSceneSetColorThread(SchemeObliqueChartScene &scene, const int &numberThread, const QBrush &brushNext, const QBrush &brushBack):
    Event(scene),
    numberThread(numberThread),
    brushNext(brushNext),
    brushBack(brushBack)
{

}

EventAbstractSchemeChartSceneSetColorThread::~EventAbstractSchemeChartSceneSetColorThread()
{

}

void EventAbstractSchemeChartSceneSetColorThread::next()
{
    scene.editFromHistory(numberThread, brushNext);
}

void EventAbstractSchemeChartSceneSetColorThread::back()
{
    scene.editFromHistory(numberThread, brushBack);
}
