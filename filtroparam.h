#ifndef FILTROPARAM_H
#define FILTROPARAM_H

#include <QObject>
#include <QSortFilterProxyModel>
#include <parametri.h>
#include <QDebug>
class filtroparam :  public QSortFilterProxyModel
{
  Q_OBJECT



public:
    filtroparam(QObject* parent = nullptr);
   ~filtroparam();

    Q_PROPERTY(int tipoFornoSel READ tipoFornoSel WRITE setTipoFornoSel NOTIFY tipoFornoSelChanged)

    // QSortFilterProxyModel interface

    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;

    // QAbstractItemModel interface

    //bool setData(const QModelIndex &index, const QVariant &value, int role); // puo non essere ridefinito e chiamato dal qml


public slots:

    void setTipoFornoSel(int tipoFornoSel);
     int tipoFornoSel() const;

signals:

     void tipoFornoSelChanged();

private:
      int m_tipoFornoSel;


};

#endif // FILTROPARAM_H
