#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QByteArray>
#include <QTimer>
#include <QtGlobal>
#include <QDesktopServices>
#include "managers/studentsmanager.h"
#include "managers/groupsmanager.h"
#include "managers/subjectsmanager.h"
#include "managers/kholleursmanager.h"
#include "managers/usersgroupsmanager.h"
#include "managers/tribesmanager.h"
#include "managers/introtimeslots.h"
#include "managers/eventsmanager.h"
#include "generator/kholloscopewizard.h"
#include "managers/groupsswappingsmanager.h"
#include "interface/interfacedialog.h"
#include "interface/introinterface.h"
#include "managers/lastchanges.h"
#include "aboutitdialog.h"
#include "tools/reviewdialog.h"
#include "tools/kscopemanager.h"
#include "settingsdialog.h"
#include "tools/notepad.h"
#include "managers/timetablemanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    bool eventFilter(QObject *obj, QEvent *event);

public slots:
    void openStudentsManager();
    void openGroupsManager();
    void openSubjectsManager();
    void openKholleursManager();
    void openUsersGroupsManager();
    void openCoursesManager();
    void openGroupsSwappingsManager();
    void openTribesManager();
    void openTimeslotsManager();
    void openEventsManager();
    void openInterface();
    void openInterfaceWithDate(QDate date, int id_week);
	void openKholloscope();
    void openReview();
    void openLastChanges();
    void openHelp();
    void openAboutIt();

    void createKhollo();
    void openKhollo();
    void openKhollo(QString filename);
    void openSettings();
    void updateWindow();
    void record(bool start = true);
    void updateRecord();

private:
    Ui::MainWindow *ui;
    KScopeManager kscopemanager;
    QTimer* m_timer;
    int m_idRecord;
    QStringList args;
    QAction* m_shortcutNotepad;
};

#endif // MAINWINDOW_H
