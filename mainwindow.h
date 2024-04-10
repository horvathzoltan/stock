#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "devicewidget.h"
#include "imainview.h"
#include "qlistwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public IMainView
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    void set_StatusLine(const MainViewModel::StringModel& m);
    void set_ItemList(const MainViewModel::StringListModel& m);
    void set_StorageList(const MainViewModel::StringListModel& m);
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void ExitActionTriggered(IMainView *sender);
private slots:    
    void on_pushButton_exit_clicked();
    void on_pushButton_log_clicked();
};
#endif // MAINWINDOW_H
