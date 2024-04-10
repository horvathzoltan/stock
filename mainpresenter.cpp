#include "mainpresenter.h"
#include "mainviewmodel.h"
//#include "dowork.h"

#include <QFileDialog>
#include <QDateTime>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QElapsedTimer>
#include <QCoreApplication>



//#include <bi/imagestorage.h>

#include <helpers/processhelper.h>

extern ProcessHelper _processHelper;

MainPresenter::MainPresenter(QObject *parent) :QObject(parent)
{
    /*connect(&_devicePollTimer, &QTimer::timeout, this, [this](){
        _pollingCounter++;
        _presenterState.handleInput(this, PresenterState::PollDevices);
    });*/

    //QObject::connect(&_deviceStorage, SIGNAL(initFinished()),
    //                 this, SLOT(processInitFinished()));

}

void MainPresenter::appendView(IMainView *w)
{
    if(_views.contains(w)) return;
    _views.append(w);

    auto *view_obj = dynamic_cast<QObject*>(w);

/*    QObject::connect(view_obj, SIGNAL(ReadActionTriggered(IMainView*)),
                     this, SLOT(processReadAction(IMainView*)));

    QObject::connect(view_obj, SIGNAL(WriteActionTriggered(IMainView*)),
                     this, SLOT(processWriteAction(IMainView*)));
*/
    QObject::connect(view_obj, SIGNAL(ExitActionTriggered(IMainView*)),
                     this, SLOT(processExitAction(IMainView*)));

    refreshView(w);
}

void MainPresenter::refreshView(IMainView *w)
{
    Q_UNUSED(w)
}

void MainPresenter::processExitAction(IMainView *sender)
{
    QCoreApplication::quit();
}

void MainPresenter::initView(IMainView *w) {    

    _devicePollTimer.start(5000);
};





