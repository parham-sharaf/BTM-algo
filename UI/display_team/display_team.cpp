#include "display_team.h"
#include "ui_display_team.h"
#include <iostream>

display_team::display_team(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::display_team)
{
    this->showMaximized();
    ui->setupUi(this);

    login conn;

    QSqlQueryModel * modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.informationDb);
    qry->prepare("Select TeamName, ArenaName, Conference, Division, StadiumCapacity, JoinedLeague, Coach from GeneralInfo");
    qry->exec();

    ui->tableView->verticalHeader()->setHidden(true);
    modal->setQuery(*qry);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setModel(modal);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    login conn1;
    QSqlQueryModel *modal1 = new QSqlQueryModel();

    conn1.connOpen();

    QSqlQuery* qry1 = new QSqlQuery(conn1.informationDb);

    qry1->exec("select TeamName FROM GeneralInfo");

    modal1->setQuery(*qry1);
    ui->combo_team->setModel(modal1);

    conn1.connClose();

    modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Team Name"));
    modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Arena Name"));
    modal->setHeaderData(2, Qt::Horizontal, QObject::tr("Conference"));
    modal->setHeaderData(3, Qt::Horizontal, QObject::tr("Division"));
    modal->setHeaderData(4, Qt::Horizontal, QObject::tr("Stadium Capacity"));
    modal->setHeaderData(5, Qt::Horizontal, QObject::tr("Year Joined"));
    modal->setHeaderData(6, Qt::Horizontal, QObject::tr("Coach"));

    connect(ui->combo_sort, SIGNAL(currentTextChanged(QString)), this, SLOT(on_combo_sort_activated(QString)));
    connect(ui->division_comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(on_division_comboBox_activated(QString)));
    connect(ui->combo_team, SIGNAL(currentTextChanged(QString)), this, SLOT(on_combo_team_activated(QString)));
    connect(ui->team_name_checkBox, SIGNAL(stateChanged(int)), this, SLOT(on_team_name_checkBox_state_changed()));
    connect(ui->arena_checkBox, SIGNAL(stateChanged(int)), this, SLOT(on_arena_checkBox_state_changed()));
    connect(ui->capacity_checkBox, SIGNAL(stateChanged(int)), this, SLOT(on_capacity_checkBox_state_changed()));
    connect(ui->year_checkBox, SIGNAL(stateChanged(int)), this, SLOT(on_year_checkBox_state_changed()));
    connect(ui->coach_checkBox, SIGNAL(stateChanged(int)), this, SLOT(on_coach_checkBox_state_changed()));

    QPixmap bkgnd("./images/bball_everybody.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
    this->setWindowTitle("Team Information");
}

display_team::~display_team()
{
    delete ui;
}

void display_team::on_reload_button_clicked()
{
    login conn;
    QSqlQueryModel *modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.informationDb);

    qry->prepare("Select TeamName, ArenaName, Conference, Division, StadiumCapacity, JoinedLeague, Coach from GeneralInfo");
    qry->exec();
    modal->setQuery(*qry);

    qDebug() << (modal->rowCount());

    modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Team Name"));
    modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Arena Name"));
    modal->setHeaderData(2, Qt::Horizontal, QObject::tr("Conference"));
    modal->setHeaderData(3, Qt::Horizontal, QObject::tr("Division"));
    modal->setHeaderData(4, Qt::Horizontal, QObject::tr("Stadium Capacity"));
    modal->setHeaderData(5, Qt::Horizontal, QObject::tr("Year Joined"));
    modal->setHeaderData(6, Qt::Horizontal, QObject::tr("Coach"));

    ui->tableView->setModel(modal);
}

void display_team::on_combo_sort_activated(const QString &arg1)
{
    login conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.informationDb);

    int entry = 0;
    sql = "SELECT ";
    for (const auto& item: headers) {
        sql += item;
    }
    sql = sql.substr(0, sql.length() - 2);
    sql += " FROM GeneralInfo ORDER BY ";

    if (ui->combo_sort->currentText() == "Team Name") sql += "TeamName";
    else if (ui->combo_sort->currentText() == "Arena Name") sql += "ArenaName";
    else if (ui->combo_sort->currentText() == "Capacity") sql += "StadiumCapacity";
    else if (ui->combo_sort->currentText() == "Year Joined") sql += "JoinedLeague";

    qry->prepare(sql.c_str());
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    for (const auto& item: headers) {
        if (item == "TeamName, ")
            modal->setHeaderData(entry++, Qt::Horizontal,
                                 QObject::tr("Team Name"));
        if (item == "ArenaName, ")
            modal->setHeaderData(entry++, Qt::Horizontal,
                                 QObject::tr("Arena Name"));
        if (item == "StadiumCapacity, ")
            modal->setHeaderData(entry++, Qt::Horizontal,
                                 QObject::tr("Stadium Capacity"));
        if (item == "JoinedLeague, ")
            modal->setHeaderData(entry++, Qt::Horizontal,
                                 QObject::tr("Year Joined"));
        if (item == "Coach, ")
            modal->setHeaderData(entry++, Qt::Horizontal,
                                 QObject::tr("Coach"));
    }

    qDebug() << (modal->rowCount());
}

void display_team::on_eastern_conf_Button_clicked()
{
    login conn;
    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.informationDb);

    sql = "SELECT TeamName FROM GeneralInfo WHERE Conference = 'Eastern'";
    qry->prepare(sql.c_str());

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Team Name"));

    qDebug() << (modal->rowCount());

}

void display_team::on_western_conf_Button_clicked()
{
    login conn;
    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.informationDb);

    sql = "SELECT TeamName FROM GeneralInfo WHERE Conference = 'Western'";
    qry->prepare(sql.c_str());

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Team Name"));
    qDebug() << (modal->rowCount());
}


void display_team::on_division_comboBox_activated(const QString &arg1)
{
    login conn;
    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.informationDb);
    std::string div = ui->division_comboBox->currentText().toStdString();

    std::string sqlAdd = " AND Division = '"+div+"'";
    std::cout << sql << std::endl;
    qry->prepare((sql + sqlAdd).c_str());

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Team Name"));

    qDebug() << (modal->rowCount());
}


void display_team::on_combo_team_activated(const QString &arg1)
{

    login conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.informationDb);

    sql = "SELECT TeamName, ArenaName, StadiumCapacity, Location, Conference, "
          "Division, JoinedLeague, Coach From GeneralInfo WHERE TeamName = "
          "'"+ui->combo_team->currentText().toStdString()+"'";


    qry->prepare(sql.c_str());

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Team Name"));
    modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Arena Name"));
    modal->setHeaderData(2, Qt::Horizontal, QObject::tr("Stadium Capacity"));
    modal->setHeaderData(6, Qt::Horizontal, QObject::tr("Year Joined"));

}

void display_team::on_push_souvenirs_clicked()
{
    QString teamName = ui->combo_team->currentText();

    // set variable to the team name selected in the combo box
//    ui->labelTeamS->setText(teamName + " Souvenir's");

    login conn;
    QSqlQueryModel *modal = new QSqlQueryModel;

    conn.connOpen();

    QSqlQuery* qry = new QSqlQuery(conn.informationDb);

    sql = "SELECT SouvenirName, Price FROM Souvenirs WHERE TeamName='"+teamName.toStdString()+"'";
    // select the souvenir and the price for the team selected in the combo box
    qry->prepare(sql.c_str());
    qry->exec();
    modal->setQuery(*qry);

    // set the headers for the table
    modal->setHeaderData(0, Qt::Horizontal, tr("Souvenir"));
    modal->setHeaderData(1, Qt::Horizontal, tr("Price"));


    ui->tableView->setModel(modal);
    conn.connClose();
}


void display_team::on_clear_plan_clicked()
{
    ui->team_name_checkBox->setCheckState(Qt::Unchecked);
    ui->arena_checkBox->setCheckState(Qt::Unchecked);
    ui->capacity_checkBox->setCheckState(Qt::Unchecked);
    ui->year_checkBox->setCheckState(Qt::Unchecked);
    ui->coach_checkBox->setCheckState(Qt::Unchecked);
    ui->combo_sort->setCurrentIndex(0);
    ui->division_comboBox->setCurrentIndex(0);
    ui->combo_team->setCurrentIndex(0);
    ui->totalTeamCapacityLabel->setText("-");
    headers.clear();
}

void display_team::on_team_name_checkBox_state_changed() {
    if (ui->team_name_checkBox->checkState() == Qt::Checked) headers.emplace_back("TeamName, ");
}
void display_team::on_arena_checkBox_state_changed() {
    if (ui->arena_checkBox->checkState() == Qt::Checked) headers.emplace_back("ArenaName, ");
}

void display_team::on_capacity_checkBox_state_changed() {
    if (ui->capacity_checkBox->checkState() == Qt::Checked) headers.emplace_back("StadiumCapacity, ");
    int totalCap = 0;
    login conn;
    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.informationDb);
    qry->prepare("SELECT * FROM GeneralInfo");
    qry->exec();
    while (qry->next()) {
        totalCap += qry->value(6).toInt();
    }
    conn.connClose();
    ui->totalTeamCapacityLabel->setText(QString::number(totalCap));

}
void display_team::on_year_checkBox_state_changed() {
    if (ui->year_checkBox->checkState() == Qt::Checked) headers.emplace_back("JoinedLeague, ");
}
void display_team::on_coach_checkBox_state_changed() {
    if (ui->coach_checkBox->checkState() == Qt::Checked) headers.emplace_back("Coach, ");
}
