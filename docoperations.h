#ifndef DOCOPERATIONS_H
#define DOCOPERATIONS_H

#include <QDialog>
#include <QTableView>
#include <QSqlRelationalTableModel>

class DocOperations
{
public:
    DocOperations();

    static void saveAs(QDialog *form, QSqlRelationalTableModel *model, int row);
    static void open(QDialog *form, QSqlRelationalTableModel *model, int row);
    static int getRowIndex (QDialog *form, QTableView *table, QString whomIsSelected);
};

#endif // DOCOPERATIONS_H
