#ifndef GENERATEPAGE_H
#define GENERATEPAGE_H

#include <QWizardPage>
#include <QtSql>
#include <QMessageBox>
#include <QQueue>
#include <QMap>
#include <QListWidget>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QStandardPaths>
#include <QPdfWriter>
#include <QPainter>
#include <QtConcurrentRun>
#include <math.h>
#include "storedData/subject.h"
#include "storedData/student.h"
#include "storedData/timeslot.h"
#include "storedData/kholleur.h"
#include "storedData/kholle.h"
#include "tools/database.h"
#include "tools/notepad.h"
#include "kholloscopewizard.h"
#include "mainwindow.h"
#include "tools/printpdf.h"
#include "utilities.h"
#include "GLPK/glpk.h"
#include "lpmethod.h"
#include "fivewavesmethod.h"
#include "generationwaitingdialog.h"

namespace Ui {
class GeneratePage;
}

class GeneratePage : public QWizardPage
{
    Q_OBJECT

public:
    explicit GeneratePage(QSqlDatabase *db, QWidget *parent = 0);
    ~GeneratePage();
    void initializePage();
    void cleanupPage();
    //void setPupilsOnTimeslots();

    //QList<Subject *> *testAvailability();

    //void set_constraint_row(glp_prob *P, int i, QVector<int> vect);
    //bool generate();

    //void setStatus();
    //bool exchange(int index, ExchangeType type, int score_limit);

    void display(int *errors, int *warnings);
    void displayCollision(int *collisions);
    void displayConclusion(int errors, int warnings, int collisions);

    //void freeKholles();

public slots:
    void finished(int status);
    void saveKholles();
    void show_notepad_collisions();
    void show_notepad_khollo();

signals:
    void interfaceTriggered(QDate, int);

private:
    Ui::GeneratePage *ui;
    QSqlDatabase *m_db;
    DataBase *m_dbase;
    GenerationMethod *m_genMethod;
    int m_week;
    QDate m_date;

    //QMap<int, QMap<int, QMap<int, float>* > > probabilities;
    //QList<Kholle*> kholloscope;

    //QMap<int, bool> m_downgraded;
    QString timestamp;
    QString khollo_message;
    QString collisions_message;

    GenerationWaitingDialog *m_box;
};

#endif // GENERATEPAGE_H
