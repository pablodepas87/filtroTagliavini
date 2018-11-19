#ifndef PARAMETRI_H
#define PARAMETRI_H

#include <QAbstractListModel>

class SingoloParametro{

public:
    QString nomeParametro;
    int value;
    int valMin;
    int valMax;
    int tipoParam;        // mi serve per il qml e che tipo di popUp visualizzare
    bool FornoTronik;
    bool Forno1;
    bool Forno2;
    int livello;
    QVariantList formato;


};


class parametri : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit parametri(QObject *parent = nullptr);

    enum ParametriRole{
        NomePar=Qt::UserRole+1,
        Value,
        Livello,
        FornoTronik,
        Forno1,
        Forno2,
        Formato

    };  // ci andrebbero anche il resto dei role se utili nel qml

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role)  Q_DECL_OVERRIDE;
    QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE;

private:

    QList<SingoloParametro> m_ParametriList;


};

#endif // PARAMETRI_H
