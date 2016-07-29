#ifndef KHOLLOTABLE_H
#define KHOLLOTABLE_H

#include <QGraphicsScene>
#include <QMessageBox>
#include <QSql>
#include <QSqlQuery>
#include <QPainter>
#include <QPixmap>
#include <QMap>
#include <QVariant>
#include <QQueue>
#include "storedData/kholleur.h"
#include "storedData/student.h"
#include "storedData/timeslot.h"
#include "storedData/course.h"

class KholloTable : public QGraphicsScene
{
    Q_OBJECT
    enum DataImg { BeginDays, BeginHours, BetweenDays, BetweenHours };

public:
    KholloTable(QSqlDatabase* db);
    ~KholloTable();

public slots:
    void displayKholleur(Kholleur* kll);
    void displayStudent(Student* stud);

private:
    QSqlDatabase* m_db;
    QMap<DataImg, int> sizeImg;
    Kholleur* m_kholleur;
    Student* m_student;
};

#endif // KHOLLOTABLE_H