QT += widgets sql concurrent network

FORMS += \
    mainwindow.ui \
    managers/studentsmanager.ui \
    managers/updatestudentdialog.ui \
    managers/groupsmanager.ui \
    managers/subjectsmanager.ui \
    managers/kholleursmanager.ui \
    managers/updatekholleurdialog.ui \
    managers/usersgroupsmanager.ui \
    managers/eventsmanager.ui \
    managers/updateeventdialog.ui \
    managers/selectgroupsdialog.ui \
    generator/kholloscopewizard.ui \
    generator/subjectspage.ui \
    generator/userspage.ui \
    generator/generatepage.ui \
    interface/interfacedialog.ui \
    interface/interfacetab.ui \
    interface/introinterface.ui \
    managers/timeslotsmanager.ui \
    managers/introtimeslots.ui \
    managers/copytimeslots.ui \
    aboutitdialog.ui \
    tools/reviewdialog.ui \
    managers/lastchanges.ui \
    managers/updatetimeslotdialog.ui \
    managers/groupsswappingsmanager.ui \
    tools/notepad.ui \
    settingsdialog.ui \
    managers/updatesubjectdialog.ui \
    interface/interfacedialog_mac.ui \
    interface/interfacetab_mac.ui \
    managers/timetablemanager.ui \
    managers/mergekholleursmanager.ui \
    managers/tribesmanager.ui \
    generator/generationwaitingdialog.ui

HEADERS += \
    mainwindow.h \
    storedData/student.h \
    storedData/group.h \
    managers/studentsmanager.h \
    managers/updatestudentdialog.h \
    managers/groupsmanager.h \
    managers/subjectsmanager.h \
    storedData/subject.h \
    managers/kholleursmanager.h \
    storedData/kholleur.h \
    managers/updatekholleurdialog.h \
    managers/usersgroupsmanager.h \
    storedData/course.h \
    managers/eventsmanager.h \
    storedData/event.h \
    managers/updateeventdialog.h \
    managers/selectgroupsdialog.h \
    generator/kholloscopewizard.h \
    generator/subjectspage.h \
    generator/userspage.h \
    generator/generatepage.h \
    storedData/timeslot.h \
    storedData/kholle.h \
    interface/interfacedialog.h \
    interface/khollotable.h \
    interface/interfacetab.h \
    interface/introinterface.h \
    managers/timeslotsmanager.h \
    managers/introtimeslots.h \
    managers/copytimeslots.h \
    tools/database.h \
    aboutitdialog.h \
    tools/reviewdialog.h \
    tools/printpdf.h \
    managers/lastchanges.h \
    managers/updatetimeslotdialog.h \
    tools/kscopemanager.h \
    managers/groupsswappingsmanager.h \
    tools/notepad.h \
    settingsdialog.h \
    generator/utilities.h \
    interface/interfaceactionsrecord.h \
    managers/updatesubjectdialog.h \
    managers/timetablemanager.h \
    managers/timetable.h \
    tools/onlinedatabase.h \
    managers/mergekholleursmanager.h \
    managers/tribesmanager.h \
    managers/studentsimportmanager.h \
    generator/generationmethod.h \
    generator/fivewavesmethod.h \
    generator/lpmethod.h \
    generator/generationwaitingdialog.h \
    storedData/storeddata.h


SOURCES += \
    mainwindow.cpp \
    main.cpp \
    storedData/student.cpp \
    storedData/group.cpp \
    managers/studentsmanager.cpp \
    managers/updatestudentdialog.cpp \
    managers/groupsmanager.cpp \
    managers/subjectsmanager.cpp \
    storedData/subject.cpp \
    managers/kholleursmanager.cpp \
    storedData/kholleur.cpp \
    managers/updatekholleurdialog.cpp \
    managers/usersgroupsmanager.cpp \
    storedData/course.cpp \
    managers/eventsmanager.cpp \
    storedData/event.cpp \
    managers/updateeventdialog.cpp \
    managers/selectgroupsdialog.cpp \
    generator/kholloscopewizard.cpp \
    generator/subjectspage.cpp \
    generator/userspage.cpp \
    generator/generatepage.cpp \
    storedData/timeslot.cpp \
    storedData/kholle.cpp \
    interface/interfacedialog.cpp \
    interface/khollotable.cpp \
    interface/interfacetab.cpp \
    interface/introinterface.cpp \
	managers/timeslotsmanager.cpp \
    managers/introtimeslots.cpp \
    managers/copytimeslots.cpp \
    tools/database.cpp \
    aboutitdialog.cpp \
    tools/reviewdialog.cpp \
    tools/printpdf.cpp \
    managers/lastchanges.cpp \
    managers/updatetimeslotdialog.cpp \
    tools/kscopemanager.cpp \
    managers/groupsswappingsmanager.cpp \
    tools/notepad.cpp \
    settingsdialog.cpp \
    generator/utilities.cpp \
    interface/interfaceactionsrecord.cpp \
    managers/updatesubjectdialog.cpp \
    managers/timetablemanager.cpp \
    managers/timetable.cpp \
    tools/onlinedatabase.cpp \
    managers/mergekholleursmanager.cpp \
    managers/tribesmanager.cpp \
    managers/studentsimportmanager.cpp \
    generator/generationmethod.cpp \
    generator/fivewavesmethod.cpp \
    generator/lpmethod.cpp \
    generator/generationwaitingdialog.cpp \
    storedData/storeddata.cpp
	
DISTFILES +=

RESOURCES += \
    khollo.qrc

VERSION = 1.3
DEFINES += "APP_VERSION='$$VERSION'"
QMAKE_TARGET_PRODUCT = "SPARK Kholloscope\0"

win32:RC_ICONS += "images/iconApp.ico"
macx {
    QMAKE_INFO_PLIST = Info.plist
    ICON = "images/iconApp.icns"
}

win32: LIBS += -L$$PWD/GLPK/ -lglpk_4_64
macx: LIBS += -L$$PWD/GLPK/ -lglpk.40

INCLUDEPATH += $$PWD/GLPK
DEPENDPATH += $$PWD/GLPK
