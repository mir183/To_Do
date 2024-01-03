#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardPaths>

QT_BEGIN_NAMESPACE
namespace Ui {
class ok;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // void saveTasksToFile();

private slots:
    void on_btnAdd_clicked();

    void on_btnRemove_clicked();

    // void on_pushButton_3_clicked();

    void on_btnRemoveAll_clicked();
    void updateFile();

private:
    Ui::ok *ui;
    QString path =QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"\\toDoFile.txt";
};
#endif // MAINWINDOW_H
