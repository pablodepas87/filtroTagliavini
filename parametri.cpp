#include "parametri.h"

parametri::parametri(QObject *parent)
    : QAbstractListModel(parent)
{

    // appendo alcuni parametri
    SingoloParametro singParametro;
    singParametro.nomeParametro="Par1";
    singParametro.livello=0;
    singParametro.tipoParam=0;
    singParametro.valMin=0;
    singParametro.valMax=10;
    singParametro.value=5;
    singParametro.FornoTronik=true;
    singParametro.Forno1=false;
    singParametro.Forno2=true;
    singParametro.formato={"uno","due","tre"};

    m_ParametriList.append(singParametro);

    singParametro.nomeParametro="Par2";
    singParametro.livello=0;
    singParametro.tipoParam=0;
    singParametro.valMin=0;
    singParametro.valMax=10;
    singParametro.value=5;
    singParametro.FornoTronik=true;
    singParametro.Forno1=true;
    singParametro.Forno2=false;
    singParametro.formato={"quattro","uno","due"};

    m_ParametriList.append(singParametro);

    singParametro.nomeParametro="Par3";
    singParametro.livello=0;
    singParametro.tipoParam=0;
    singParametro.valMin=0;
    singParametro.valMax=10;
    singParametro.value=5;
    singParametro.FornoTronik=false;
    singParametro.Forno1=true;
    singParametro.Forno2=true;
    singParametro.formato={"banana","cipolle","carote"};

     m_ParametriList.append(singParametro);

}

int parametri::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    Q_UNUSED(parent);
    return m_ParametriList.count();

    // FIXME: Implement me!
}

QVariant parametri::data(const QModelIndex &index, int role) const
{



    if (index.row() < 0 || index.row() >= m_ParametriList.count())
        return QVariant();

    const SingoloParametro &paraTemp= m_ParametriList[index.row()];

    switch (role) {

      case NomePar:
        return paraTemp.nomeParametro;
      case Value:
        return paraTemp.value;
      case Livello:
        return paraTemp.livello;
      case FornoTronik:
        return paraTemp.FornoTronik;
      case Forno1:
        return paraTemp.Forno1;
      case Forno2:
        return paraTemp.Forno2;
      case Formato:
        return paraTemp.formato;
      default: break;

    }



    // FIXME: Implement me!
    return QVariant();
}

bool parametri::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
        return false;
    if(index.row()> m_ParametriList.size() || index.row() < 0)
        return false ;

    SingoloParametro &parTemp= m_ParametriList[index.row()];

    switch (role) {


    case NomePar:
        parTemp.nomeParametro=value.toString();
        break;
    case Value:
       parTemp.value=value.toInt();
        break;
    default: break;



    }

    /***** 1° metodo**********/
     emit dataChanged(index, index, { role } );

    /***** 2° metodo **********/
    //QModelIndex top=createIndex(0,0);
    //QModelIndex bottom= createIndex(rowCount()-1,0);
    //emit dataChanged(top,bottom);

    return true;
}

QHash<int, QByteArray> parametri::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NomePar] = "nomePar";
    roles[Value]="Value";
    roles[Livello] = "livello";
    roles[FornoTronik] = "frTronik";
    roles[Forno1] = "fr1";
    roles[Forno2] = "fr2";

    return roles;
}
