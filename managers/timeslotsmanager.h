#ifndef TIMESLOTSMANAGER_H
#define TIMESLOTSMANAGER_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include <QQueue>
#include <QListWidget>
#include <QListWidgetItem>
#include <QGridLayout>
#include <QStringList>
#include "storedData/kholleur.h"
#include "storedData/timeslot.h"

namespace Ui {
class TimeslotsManager;
}

class TimeslotsManager : public QDialog
{
    Q_OBJECT

public:
    explicit TimeslotsManager(QSqlDatabase *db, QWidget *parent = 0);
    ~TimeslotsManager();
    void getKholleurs();
    void freeKholleurs();
    void update_list_timeslots(int id_kholleur);
    void free_timeslots();

public slots:
    void onSelection_change();
    void deleteTimeslot();
    void addTimeslot();

private:
    Ui::TimeslotsManager *ui;
    QSqlDatabase *m_db;
    QQueue<Kholleur*> queue_displayedKholleurs;
    QQueue<Timeslot*> queue_displayedTimeslots;
    QStringList days;
};

#endif // TIMESLOTSMANAGER_H