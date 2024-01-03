#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QStandardPaths>
#include <QMessageBox>
#include <QMainWindow>

// Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ok) // Creating the user interface
{
    ui->setupUi(this);

    // File path where tasks will be stored
    QFile file(path);
    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(0,"error",file.errorString()); // Show error message if file opening fails
    }

    QTextStream in(&file);

    // Read tasks from the file and populate the QListWidget
    while (!in.atEnd()){
        QListWidgetItem* item= new QListWidgetItem(in.readLine(),ui->listWidget);
        ui->listWidget->addItem(item);
        item->setFlags(item->flags()|Qt::ItemIsEditable); // Make each task editable
    }

    file.close(); // Close the file
    connect(ui->txtTask, &QLineEdit::returnPressed, this, &MainWindow::on_btnAdd_clicked); // Connect Enter key press to Add button
}

// Destructor
MainWindow::~MainWindow()
{
    delete ui; // Release memory occupied by the UI

    // Open the file for writing
    QFile file(path);
    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(0,"error",file.errorString()); // Show error message if file opening fails
    }

    QTextStream out(&file);

    // Write tasks from QListWidget to the file
    for(int i=0; i<ui->listWidget->count(); i++){
        out << ui->listWidget->item(i)->text() << "\n";
    }

    file.close(); // Close the file
}

// Slot for handling the "Add" button click or Enter key press
void MainWindow::on_btnAdd_clicked()
{
    QString taskText = ui->txtTask->text().trimmed(); // Remove leading/trailing whitespaces

    if (!taskText.isEmpty()) {
        QListWidgetItem* item = new QListWidgetItem(taskText, ui->listWidget);
        ui->listWidget->addItem(item);
        item->setFlags(item->flags() | Qt::ItemIsEditable); // Make the new task editable
        ui->txtTask->clear();
        ui->txtTask->setFocus();
    } else {
        // Optionally, show a message or take some action when the input is empty
        QMessageBox::information(this, "Empty Task", "Please enter a non-empty task.");
    }
}

// Slot for handling the "Remove" button click
void MainWindow::on_btnRemove_clicked()
{
    int currentRow = ui->listWidget->currentRow();
    if (currentRow >= 0) {
        QListWidgetItem* item = ui->listWidget->takeItem(currentRow);
        delete item; // Release memory occupied by the removed task

        updateFile(); // Call a function to update the file
    }
}

// Function to update the file with the current contents of the QListWidget
void MainWindow::updateFile()
{
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QMessageBox::information(0, "Error", file.errorString()); // Show error message if file opening fails
        return;
    }

    QTextStream out(&file);

    // Write tasks from QListWidget to the file
    for (int i = 0; i < ui->listWidget->count(); ++i) {
        out << ui->listWidget->item(i)->text() << "\n";
    }

    file.close(); // Close the file
}

// Slot for handling the "Remove All" button click
void MainWindow::on_btnRemoveAll_clicked()
{
    ui->listWidget->clear(); // Clear the QListWidget

    // Open the file in WriteOnly mode to clear its content
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QMessageBox::information(0, "Error", file.errorString()); // Show error message if file opening fails
        return;
    }

    file.close(); // Close the file
}
