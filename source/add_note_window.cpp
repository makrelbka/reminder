#include "add_note_window.h"
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLineEdit>

AddNoteWindow::AddNoteWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle("Welcome to hell");
    input = new QLineEdit(this); 
    QHBoxLayout *layout = new QHBoxLayout;
    QPushButton *buttonWrite = new QPushButton("Write");
    layout->addWidget(input);
    layout->addWidget(buttonWrite);

    QWidget *centralWidget = new QWidget(this); 
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(buttonWrite, &QPushButton::clicked, this, &AddNoteWindow::write);
    connect(input, &QLineEdit::returnPressed, this, &AddNoteWindow::write);

}

void AddNoteWindow::write() {
    QString text = input->text();
    emit noteAdded(text); 
}

AddNoteWindow::~AddNoteWindow() {}
