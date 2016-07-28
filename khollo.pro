QT += widgets sql

FORMS += \
    mainwindow.ui \
    managers/studentsmanager.ui \
    managers/updatestudentdialog.ui \
    managers/groupsmanager.ui \
    managers/subjectsmanager.ui \
    managers/kholleursmanager.ui \
    managers/updateteacherdialog.ui \
    managers/updatekholleurdialog.ui \
    managers/usersgroupsmanager.ui \
	managers/coursesmanager.ui \
    managers/eventsmanager.ui \
    managers/updateeventdialog.ui \
    managers/selectgroupsdialog.ui \
	managers/kholloscopewizard.ui \
    managers/KholloscopeWizardPages/subjectspage.ui \
    managers/KholloscopeWizardPages/userspage.ui \
    managers/KholloscopeWizardPages/generatepage.ui \
    interface/interfacedialog.ui

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
    storedData/teacher.h \
    managers/updateteacherdialog.h \
    managers/updatekholleurdialog.h \
    managers/usersgroupsmanager.h \
	managers/coursesmanager.h \
    storedData/course.h \
    managers/eventsmanager.h \
    storedData/event.h \
    managers/updateeventdialog.h \
    managers/selectgroupsdialog.h \
	managers/kholloscopewizard.h \
    managers/KholloscopeWizardPages/subjectspage.h \
    managers/KholloscopeWizardPages/userspage.h \
    managers/KholloscopeWizardPages/generatepage.h \
    storedData/timeslot.h \
    storedData/kholle.h \
    interface/interfacedialog.h

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
    storedData/teacher.cpp \
    managers/updateteacherdialog.cpp \
    managers/updatekholleurdialog.cpp \
    managers/usersgroupsmanager.cpp \
	managers/coursesmanager.cpp \
    storedData/course.cpp \
    managers/eventsmanager.cpp \
    storedData/event.cpp \
    managers/updateeventdialog.cpp \
    managers/selectgroupsdialog.cpp \
	managers/kholloscopewizard.cpp \
    managers/KholloscopeWizardPages/subjectspage.cpp \
    managers/KholloscopeWizardPages/userspage.cpp \
    managers/KholloscopeWizardPages/generatepage.cpp \
    storedData/timeslot.cpp \
    storedData/kholle.cpp \
    interface/interfacedialog.cpp
