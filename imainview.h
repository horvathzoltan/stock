#ifndef IMAINVIEW_H
#define IMAINVIEW_H

#include "mainviewmodel.h"

#include <QColor>
#include <QPointF>
#include <QRect>
#include <QSet>

class IMainView
{
public:
    virtual void set_StatusLine(const MainViewModel::StringModel& m) = 0;
    virtual void set_ItemList(const MainViewModel::StringListModel& m) = 0;
    virtual void set_StorageList(const MainViewModel::StringListModel& m) = 0;

public: // signals
    virtual void ExitActionTriggered(IMainView *sender) = 0;
};

#endif // IMAINVIEW_H
