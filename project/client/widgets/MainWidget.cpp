#include "MainWidget.h"
#include <QtWidgets>
#include <iostream>

MainWidget::MainWidget(std::string &name, std::string &device, std::string &sync_folder, QWidget *parent) :
        m_name(name),
        m_device(device),
        m_sync_folder(sync_folder),
        QWidget(parent) {
    m_button = new QPushButton(tr("Push Me!"));
//    m_dialog = new QFileDialog();

    m_line_edits.resize(3);
    for (auto &m_line_edit: m_line_edits) {
        m_line_edit = new QLineEdit();
    }

    m_labels.push_back(new QLabel("User name:"));
    m_labels.push_back(new QLabel("Device name:"));
    m_labels.push_back(new QLabel("Sync folder:"));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(m_button,3,1);
    for (size_t i = 0; i < m_line_edits.size(); ++i) {
        mainLayout->addWidget(m_line_edits[i], i, 1);
    }
    for (size_t i = 0; i < m_labels.size(); ++i) {
        mainLayout->addWidget(m_labels[i], i, 0);
    }
    setLayout(mainLayout);
    setWindowTitle(tr("SkyData"));
    connect(m_button, SIGNAL(released()), this, SLOT(onButtonReleased()));
}

// Destructor
MainWidget::~MainWidget()
{
//    delete button_;
//    delete label_;
//    delete edit_line_;
}

void MainWidget::onButtonReleased() {
    m_name = m_line_edits[0]->text().toStdString();
    m_device = m_line_edits[1]->text().toStdString();
    m_sync_folder = m_line_edits[2]->text().toStdString();
    close();
}


