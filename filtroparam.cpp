#include "filtroparam.h"


filtroparam::filtroparam(QObject *parent): QSortFilterProxyModel(parent)
        , m_tipoFornoSel(0)
{

}

filtroparam::~filtroparam()
{

}

bool filtroparam::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{

        QModelIndex singoloParametro = sourceModel()->index(source_row,0, source_parent); // vado a leggere singolarmente ogni riga del modello
        int livello=sourceModel()->data(singoloParametro,parametri::Livello).toInt(); // vado a prendermi il campo LIVELLO E LO converto in int data restituisce un QVariant

        if(livello==0) {

          switch(m_tipoFornoSel) {

           case 0:{
            bool fornoTronik= sourceModel()->data(singoloParametro,parametri::FornoTronik).toBool();
            if(fornoTronik==true)
                return true;
            else
                return false;
           }
           case 1: {

              bool forno1= sourceModel()->data(singoloParametro,parametri::Forno1).toBool();
              if(forno1==true)
                  return true;
              else
                  return false;
           }
           case 2: {

              bool forno2= sourceModel()->data(singoloParametro,parametri::Forno2).toBool();
              if(forno2==true)
                  return true;
              else
                  return false;
            }

          }


        }

        return  false;
}

//bool filtroparam::setData(const QModelIndex &index, const QVariant &value, int role)
//{
//    QModelIndex sourceIdx = mapToSource(index);
//    sourceIdx.data(parametri::NomePar);

//    qDebug()<< index.data(parametri::NomePar).toString();
      /*** metodo equivalente ***/
//    qDebug()<< sourceIdx.data(parametri::NomePar).toString();

//    bool success = sourceModel()->setData(sourceIdx, value, role);  // puo essere usato anche il parametro d'ingresso index
//    return success;

//}

int filtroparam::tipoFornoSel() const
{
    return m_tipoFornoSel;
}

void filtroparam::setTipoFornoSel(int tipoFornoSel)
{
    if (m_tipoFornoSel == tipoFornoSel)
        return;

    m_tipoFornoSel = tipoFornoSel;
    invalidateFilter();         // cosi rivaluto il modello legato al filtro e si aggiorna il qml
    emit tipoFornoSelChanged();

}


