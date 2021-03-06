#include "groupsswappingsmanager.h"
#include "ui_groupsswappingsmanager.h"

GroupsSwappingsManager::GroupsSwappingsManager(QSqlDatabase *db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GroupsSwappingsManager)
{
    ui->setupUi(this);
    m_db = db;
    m_listGroups = new QList<Group*>();

    QSqlQuery query(*m_db);
    query.exec("SELECT `id`, `name` FROM `tau_groups` ORDER BY UPPER(`name`)");
    while(query.next()) {
        Group* grp = new Group();
        grp->setId(query.value(0).toInt());
        grp->setName(query.value(1).toString());
        m_listGroups->append(grp);
    }

    for(int i=0; i<m_listGroups->count(); i++) {
        Group* grp = m_listGroups->at(i);
        ui->comboBox_group1->addItem(grp->getName(), (qulonglong) grp);
        ui->comboBox_group2->addItem(grp->getName(), (qulonglong) grp);
    }

    connect(ui->pushButton_valid, SIGNAL(clicked(bool)), this, SLOT(swapGroups()));
    m_shortcutNotepad = Notepad::shortcut();
    this->addAction(m_shortcutNotepad);
}

GroupsSwappingsManager::~GroupsSwappingsManager() {
    while(!m_listGroups->isEmpty()) {
        delete m_listGroups->takeFirst();
    }
    delete m_listGroups;

    delete ui;
    this->removeAction(m_shortcutNotepad);
    delete m_shortcutNotepad;
}

bool GroupsSwappingsManager::swapGroups() {
    Group* gr1 = (Group*) ui->comboBox_group1->currentData().toLongLong();
    Group* gr2 = (Group*) ui->comboBox_group2->currentData().toLongLong();
    bool swapStudents = ui->radioButton_swapStudents->isChecked();

    if(gr1 == NULL || gr2 == NULL) {
        QMessageBox::critical(NULL, "Echange impossible", "Veuillez sélectionner des groupes à échanger...");
        return false;
    } else if(gr1->getId() == gr2->getId()) {
        QMessageBox::critical(NULL, "Echange impossible", "Vous avez sélectionné le même groupe.");
        return false;
    } else if(swapStudents) {
        int res = QMessageBox::information(NULL, "Echange de groupes",
                "Vous êtes sur le point d'échanger les <strong>élèves</strong> entre le groupe <strong>"+gr1->getName()+"</strong> et le groupe <strong>"+gr2->getName()+"</strong>. <br />"
                "Voulez-vous continuez ?", QMessageBox::Yes |QMessageBox::Cancel);
        if(res == QMessageBox::Yes) {
            int numRowsAffected = 0;
            QSqlQuery query(*m_db);

            //Defer foreign keys for change --> foreign key only checked when commit() is called -->
            // allows to set id_groups to 0
            query.exec("PRAGMA defer_foreign_keys = 1");
            m_db->transaction();

            query.prepare("UPDATE `tau_groups_users` SET `id_groups` = 0 WHERE `id_groups` = :idGrp1");
            query.bindValue(":idGrp1", gr1->getId());
            query.exec();
            query.prepare("UPDATE `tau_groups_users` SET `id_groups` = :idGrp1 WHERE `id_groups` = :idGrp2");
            query.bindValue(":idGrp1", gr1->getId());
            query.bindValue(":idGrp2", gr2->getId());
            query.exec();
            numRowsAffected += query.numRowsAffected();
            query.prepare("UPDATE `tau_groups_users` SET `id_groups` = :idGrp2 WHERE `id_groups` = 0");
            query.bindValue(":idGrp2", gr2->getId());
            query.exec();
            numRowsAffected += query.numRowsAffected();

            //Commit and turn off deferring
            m_db->commit();
            query.exec("PRAGMA defer_foreign_keys = 0");


            ui->infoArea->setPlainText("Echange effectué : " + QString::number(numRowsAffected) + " élèves affectés...");
        }
    } else {
        int res = QMessageBox::information(NULL, "Echange de groupes",
                "Vous êtes sur le point d'échanger les <strong>cours</strong> entre le groupe <strong>"+gr1->getName()+"</strong> et le groupe <strong>"+gr2->getName()+"</strong>. <br />"
                "Voulez-vous continuez ?", QMessageBox::Yes |QMessageBox::Cancel);
        if(res == QMessageBox::Yes) {
            int numRowsAffected = 0;
            QSqlQuery query(*m_db);

            //Defer foreign keys for change --> foreign key only checked when commit() is called -->
            // allows to set id_groups to 0
            query.exec("PRAGMA defer_foreign_keys = 1");
            m_db->transaction();

            query.prepare("UPDATE `tau_courses` SET `id_groups` = 0 WHERE `id_groups` = :idGrp1");
            query.bindValue(":idGrp1", gr1->getId());
            query.exec();
            query.prepare("UPDATE `tau_courses` SET `id_groups` = :idGrp1 WHERE `id_groups` = :idGrp2");
            query.bindValue(":idGrp1", gr1->getId());
            query.bindValue(":idGrp2", gr2->getId());
            query.exec();
            numRowsAffected += query.numRowsAffected();
            query.prepare("UPDATE `tau_courses` SET `id_groups` = :idGrp2 WHERE `id_groups` = 0");
            query.bindValue(":idGrp2", gr2->getId());
            query.exec();
            numRowsAffected += query.numRowsAffected();

            //Commit and turn off deferring
            m_db->commit();
            query.exec("PRAGMA defer_foreign_keys = 0");

            ui->infoArea->setPlainText("Echange effectué : " + QString::number(numRowsAffected) + " horaires de cours affectés...");
        }
    }

    return true;
}
