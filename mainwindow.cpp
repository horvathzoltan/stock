#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "devicewidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->plainTextEdit_status->setVisible(false);
    ui->progressBar->setVisible(false);
    ui->label_progress->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::set_StatusLine(const MainViewModel::StringModel &m)
{
    if(m.txt.isEmpty()) return;

    QString u;
    for(auto&a:m.txt){
        if(a == '\r'){
            QTextCursor cursor = ui->plainTextEdit_status->textCursor();
            cursor.movePosition(QTextCursor::End);
            cursor.select(QTextCursor::LineUnderCursor);
            cursor.removeSelectedText();
            cursor.deletePreviousChar(); // Added to trim the newline char when removing last line
            ui->plainTextEdit_status->setTextCursor(cursor);
        } else if (a == '\n') {
            if(!u.isEmpty()){
                ui->plainTextEdit_status->appendPlainText(u);//a.join('\n'));//setPlainText(a.join('\n'));
                u.clear();
            }
        }
        else{
            u.append(a);
        }
    }
    if(!u.isEmpty()){
        ui->plainTextEdit_status->appendPlainText(u);
    }
}


void MainWindow::set_ItemList(const MainViewModel::StringListModel& m)
{
    ui->listWidget_items->clear();
    if(!m.txts.isEmpty()){
        ui->listWidget_items->addItems(m.txts);
    }
}

void MainWindow::set_StorageList(const MainViewModel::StringListModel &m)
{
    ui->listWidget_storages->clear();
    if(!m.txts.isEmpty()){
        ui->listWidget_storages->addItems(m.txts);
    }
}


void MainWindow::on_pushButton_exit_clicked()
{
    emit ExitActionTriggered(this);
}


void MainWindow::on_pushButton_log_clicked()
{
    bool visible = ui->plainTextEdit_status->isVisible();
    ui->plainTextEdit_status->setVisible(!visible);
}

