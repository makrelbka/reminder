#include "main_window.h"
#include "add_note_window.h"
#include "get_notes_window.h"
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QHeaderView>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    
    this->setStyleSheet(R"(
        QWidget {
            background-color: rgb(0, 0, 0);
        }
        QLineEdit, QPushButton {
            background-color: rgb(0, 0, 0);
            border: 1px solid rgb(255, 255, 255);
            border-radius: 4px;
            padding: 5px 10px;
            font: 14px Arial;
            color: white;
            min-width: 100px;
        }
    )");

    setWindowTitle("Write to remember!");
    layout = new QVBoxLayout; 
    notes_layout = new QVBoxLayout;
    layout->addLayout(notes_layout);
    
    QVBoxLayout *input_layout = new QVBoxLayout; 
    input = new QLineEdit(this); 

    input_layout->addWidget(input);
    
    layout->addLayout(input_layout);

    QWidget *centralWidget = new QWidget(this); 
    centralWidget->setLayout(layout);  
    setCentralWidget(centralWidget);

    connect(input, &QLineEdit::returnPressed, this, &MainWindow::addNote);
}

void MainWindow::addNote() {
    QString text = input->text();
    input->clear();
    
    QWidget* row = new QWidget();
    QHBoxLayout* note_layout = new QHBoxLayout(row);
    note_layout->setContentsMargins(0, 0, 0, 0);
    
    QPushButton* completedButton = new QPushButton("<><");
    completedButton->setFixedWidth(completedButton->sizeHint().width());
    QPushButton* editButton = new QPushButton(text);
    
    note_layout->addWidget(editButton);
    note_layout->addWidget(completedButton);
    note_layout->addWidget(editButton, 4);   
    note_layout->addWidget(completedButton, 1);
    
    notes_layout->addWidget(row); 
    connect(completedButton, &QPushButton::clicked, this, &MainWindow::delNote);
    connect(editButton, &QPushButton::clicked, this, &MainWindow::editNote);
}


void MainWindow::editNote() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QWidget* row = button->parentWidget();
    if (!row) return;

    QHBoxLayout* rowLayout = qobject_cast<QHBoxLayout*>(row->layout());
    if (!rowLayout) return;

    QString currentText = button->text();

    QLineEdit* lineEdit = new QLineEdit(currentText, row);


    rowLayout->replaceWidget(button, lineEdit);
    button->hide(); 

    connect(lineEdit, &QLineEdit::returnPressed, this, [=]() {
        QString newText = lineEdit->text();

        button->setText(newText);

        rowLayout->replaceWidget(lineEdit, button);
        button->show();

        lineEdit->deleteLater();
    });
}

void MainWindow::delNote() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QWidget* row = button->parentWidget();
    
    layout->removeWidget(row);
    row->deleteLater(); 
    
    QTimer::singleShot(0, this, [this]() {
        adjustSize();
        setMinimumSize(QSize(0, 0));
    });
}

MainWindow::~MainWindow() {}
