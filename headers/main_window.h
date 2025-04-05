#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QVBoxLayout>
#include <QTableWidget>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void addNote();
    void editNote();
    void delNote();
    QLineEdit *input; 
    QVBoxLayout *layout;
    QVBoxLayout *notes_layout;

};


#endif // MAIN_WINDOW_H
