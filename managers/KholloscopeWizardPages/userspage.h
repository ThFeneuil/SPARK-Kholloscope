#ifndef USERSPAGE_H
#define USERSPAGE_H

#include <QWizardPage>
#include <QtSql>
#include <QMessageBox>
#include <QQueue>
#include <QMap>
#include <QListWidget>
#include <QListWidgetItem>
#include <QVBoxLayout>
#include "storedData/subject.h"
#include "storedData/student.h"
#include "managers/kholloscopewizard.h"

namespace Ui {
class UsersPage;
}

class UsersPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit UsersPage(QSqlDatabase *db, QWidget *parent = 0);
    ~UsersPage();
    void initializePage();
    void cleanupPage();
    void get_selected_subjects();
    void populate(QListWidget *list, int id_subject);

public slots:
    void selection_changed();

private:
    Ui::UsersPage *ui;
    QSqlDatabase *m_db;
    QList<Subject*> *list_selected_subjects;
};

#endif // USERSPAGE_H
