#ifndef TEST_MAINWIDGET_H
#define TEST_MAINWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QLine>
#include <QLabel>
#include <QFileDialog>
#include <string>

class QPushButton;
class QLineEdit;
class QLabel;
class QFileDialog;

// This is the declaration of our MainWidget class
// The definition/implementation is in mainwidget.cpp
class MainWidget : public QWidget {
    Q_OBJECT
public:

    explicit MainWidget(std::string &name, std::string &device, std::string &sync_folder, QWidget *parent = 0);

    ~MainWidget();

private slots:

    void onButtonReleased(); // Handler for button presses

private:
    std::string &m_name;
    std::string &m_device;
    std::string &m_sync_folder;
    QPushButton* m_button;
    QFileDialog* m_dialog;
    std::vector<QLineEdit*> m_line_edits;
    std::vector<QLabel*> m_labels;
};


#endif //TEST_MAINWIDGET_H
