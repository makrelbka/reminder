#ifndef ADD_NOTE_WINDOW_H
#define ADD_NOTE_WINDOW_H

#include <QMainWindow>
#include <QLineEdit>

class AddNoteWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit AddNoteWindow(QWidget *parent = nullptr);
    ~AddNoteWindow();

signals:
    void noteAdded(const QString &note); 

private:
    void write();
    QLineEdit *input; 

};

#endif // ADD_NOTE_WINDOW_H
