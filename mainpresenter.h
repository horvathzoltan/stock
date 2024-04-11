#ifndef MAINPRESENTER_H
#define MAINPRESENTER_H

//#include "actions.h"
//#include "updates.h"

#include <QElapsedTimer>
#include <QList>
#include <QObject>
#include <QTimer>
//#include <bi/devicestorage.h>
//#include <bi/imagestorage.h>
#include "imainview.h"

class IMainView;

class MainPresenter : public QObject
{
    Q_OBJECT

public:
    QElapsedTimer _t;
    explicit MainPresenter(QObject *parent = nullptr);
    void appendView(IMainView *w);
    void initView(IMainView *w);
private:
    QByteArray _stdErr;
    QList<IMainView*> _views;
    //ImageStorage _imageStorage;
    //DeviceStorage _deviceStorage;
    MainViewModel::WriteStatusWM _wm;
    qlonglong _writeBytesAll=0;
    int _writeBlockSize=0;
    qlonglong _writeBytes=0;
    qlonglong _writeBytes2=0;
    QElapsedTimer _writeTimer;

    void SetRemainingTime();
    void SetTotalTime();

    void refreshView(IMainView *w);

    QTimer _storagePollTimer;
    //bool isFreeForOperation();
    quint32 _pollingCounter = 0;

    void PollDevices();


private slots:
    void processExitAction(IMainView *sender);

};

#endif // MAINPRESENTER_H
